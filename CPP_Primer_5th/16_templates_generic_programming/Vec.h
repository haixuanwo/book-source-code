/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-15 17:05:19
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-15 17:05:33
 * @Description: file content
 */

#ifndef VEC_H
#define VEC_H

#include <algorithm>
#include <memory>
#include <utility>
#include <initializer_list>

// simplified-implementation of memory allocation strategy for a vector-like class
template <typename T>
class Vec
{
public:
    Vec() = default;
	Vec(const Vec&);                 // copy constructor
	Vec(Vec&&) noexcept;             // move constructor
	Vec &operator=(const Vec&);      // copy assignment
	Vec &operator=(Vec&&) noexcept;  // move assignment
	~Vec() noexcept;                 // destructor

	// list assignment
	Vec &operator=(std::initializer_list<T>);

	// add elements
    void push_back(const T&);
    void push_back(T&&);
	template <class... Args> void emplace_back(Args&&...);

	// size and capacity
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }

	// element access
    T& operator[](size_t n) { return elements[n]; }
    const T& operator[](size_t n) const { return elements[n]; }

	// iterator interface
	T *begin() const { return elements; }
	T *end() const { return first_free; }
private:
    static std::allocator<T> alloc; // allocates the elements
	// used by functions that add elements to the Vec
	void chk_n_alloc() { if (first_free == cap) reallocate(); }

    // utilities used by copy constructor, assignment operator, and destructor
	std::pair<T*, T*>
	  alloc_n_copy(const T*, const T*);
	void free();
    void reallocate(); // get more space and copy existing elements
    T* elements = nullptr;   // pointer to first element in the array
    T* first_free = nullptr; // pointer to first free element in the array
    T* cap = nullptr;        // pointer to one past the end of the array
};


//definition for the static data member
template <typename T> std::allocator<T> Vec<T>::alloc;

template <typename T>
inline
Vec<T>::~Vec() noexcept { free(); }

template <typename T>
inline
std::pair<T*, T*>
Vec<T>::alloc_n_copy(const T *b, const T *e)
{
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}

template <typename T>
inline
Vec<T>::Vec(Vec &&s) noexcept :
	// take over resources from s
	elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	// leave s in a state in which it is safe to run the destructor
	s.elements = s.first_free = s.cap = nullptr;
}

template <typename T>
inline
Vec<T>::Vec(const Vec &s)
{
	// call copy to allocate exactly as many elements as in s
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template <typename T>
inline
void Vec<T>::free()
{
    // destroy the old elements in reverse order
	for (auto p = first_free; p != elements; /* empty */)
		alloc.destroy(--p);  // destroy elements in reverse order

    // deallocate cannot be called on a 0 pointer
	if (elements)
		alloc.deallocate(elements, cap - elements);
}

template <typename T>
inline
Vec<T> &Vec<T>::operator=(std::initializer_list<T> il)
{
	// copy allocates space and copies elements from the given range
	auto data = alloc_n_copy(il.begin(), il.end());

	free();   // destroy the elements in this object and free the space

	elements = data.first; // update data members to point to the new space
	first_free = cap = data.second;

	return *this;
}

template <typename T>
inline
Vec<T> &Vec<T>::operator=(Vec &&rhs) noexcept
{
	// direct test for self-assignment
	if (this != &rhs)
		free();  // free existing elements if appropriate

	elements = rhs.elements;  // take over resources from rhs
	first_free = rhs.first_free;
	cap = rhs.cap;

	// leave rhs in a destructible state
	rhs.elements = rhs.first_free = rhs.cap = nullptr;

	return *this;
}

template <typename T>
inline
Vec<T> &Vec<T>::operator=(const Vec &rhs)
{
	// call copy to allocate exactly as many elements as in rhs
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template <typename T>
inline
void Vec<T>::reallocate()
{
    // we'll allocate space for twice as many elements as current size
    auto newcapacity = size() ? 2 * size() : 2;

	// allocate new space
	auto first = alloc.allocate(newcapacity);
	auto dest = first;
	auto elem = elements;

	// move the elements
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();  // free the old space once we've moved the elements

    // update our data structure point to the new elements
    elements = first;
    first_free = dest;
    cap = elements + newcapacity;
}

template <typename T>
inline
void Vec<T>::push_back(const T& s)
{
    chk_n_alloc(); // reallocates the Vec if necessary
    // construct a copy s in the element to which first_free points
    alloc.construct(first_free++, s);
}

template <typename T>
inline
void Vec<T>::push_back(T&& s)
{
    chk_n_alloc(); // reallocates the Vec if necessary
	alloc.construct(first_free++, std::move(s));
}

template <typename T>
template <class... Args>
inline
void Vec<T>::emplace_back(Args&&... args)
{
    // any space left?
    chk_n_alloc(); // reallocates the Vec if necessary
	alloc.construct(first_free++, std::forward<Args>(args)...);
}

#endif
