/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-15 16:01:58
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-15 16:03:15
 * @Description: file content
 */

#include <cstring>
using std::strcmp;

#include <iostream>
using std::cout;
using std::endl;

// first version; can compare any two types
template <typename T>
int compare(const T&, const T&);

// second version to handle string literals
template<size_t N, size_t M>
int compare(const char (&)[N], const char (&)[M]);

// specialized verson of the first template, handles character arrays
template <>
int compare(const char* const &, const char* const &);

template <typename T>
int compare(const T& v1, const T& v2)
{
    cout << "base template" << endl;

    if (v1 < v2)
    {
        return -1;
    }

    if (v2 < v1)
    {
        return 1;
    }

    return 0;
}

template<size_t N, size_t M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
    cout << "array template" << endl;
    return strcmp(p1, p2);
}

// special version of compare to handle pointers to character arrays
template <>
int compare(const char* const &p1, const char* const &p2)
{
    cout << "specialized template" << endl;
    return strcmp(p1, p2);
}

int main()
{
	const char *p1 = "hi", *p2 = "mom";
	compare(p1, p2);      // calls the first template
	compare("hi", "mom"); // calls the template with two nontype parameters
}
