

/*
条款14：在资源管理类中小心 coping 行为

当资源管理类涉及到拷贝行为时，需要特别注意如何合理地处理资源的复制。
通常有三种策略：
1、禁止复制
2、使用引用计数共享资源
3、深拷贝资源
*/

class SmartPointer {
public:
    SmartPointer(const SmartPointer& other) : ptr(other.ptr), ref_count(other.ref_count) {
        (*ref_count)++;
    }
    ~SmartPointer() {
        if (--(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
    }
private:
    Resource* ptr;
    int* ref_count;  // 引用计数
};
