/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-18 17:21:09
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-19 14:59:24
 * @Description: file content
 */

#include <thread>
#include <iostream>

#if 0
#include <thread>
#include <string>

void open_document_and_display_gui(std::string const& filename)
{}

bool done_editing()
{
    return true;
}

enum command_type{
    open_new_document
};


struct user_command
{
    command_type type;

    user_command():
        type(open_new_document)
    {}
};

user_command get_user_input()
{
    return user_command();
}

std::string get_filename_from_user()
{
    return "foo.doc";
}

void process_user_input(user_command const& cmd)
{}

void edit_document(std::string const& filename)
{
    open_document_and_display_gui(filename);
    while(!done_editing())
    {
        user_command cmd=get_user_input();
        if(cmd.type==open_new_document)
        {
            std::string const new_name=get_filename_from_user();
            std::thread t(edit_document,new_name);
            t.detach();
        }
        else
        {
            process_user_input(cmd);
        }
    }
}

int main()
{
    edit_document("bar.doc");
}
#endif

#if 0
// 分离线程以处理其他文档
void edit_document(std::string const& filename)
{
    open_document_and_display_gui(filename);

    while(!done_editing())
    {
        user_command cmd = get_user_input();
        if(cmd.type == open_new_doment)
        {
            std::string const new_name = get_filename_from_user();
            std::thread t(&edit_document, new_name);
            t.detach(); // 线程分离，不等待其结束
        }
        else
        {
            process_user_input(cmd);
        }
    }
}
#endif

void test()
{
    while (1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "test" << std::endl;
    }
}

int main()
{
    std::thread task1(test);
    task1.detach();

#if 1
    if (task1.joinable())
    {
        // 等待线程结束
        task1.join();
    }
#else
    try
    {
        task1.join();
    }
    catch(const std::system_error& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
#endif

    std::cout << "main thread exit" << std::endl;
    return 0;
}
