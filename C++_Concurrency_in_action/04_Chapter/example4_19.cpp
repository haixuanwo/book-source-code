/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-19 17:53:58
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-19 17:55:08
 * @Description: file content
 */
#include <future>
#include <string>

std::future<void> process_login(std::string const& username, std::string const& password)
{
    return std::async(std::launch::async,[=](){
        try
        {
            user_id const id=backend.authenticate_user(username,password);
            user_data const info_to_display = backend.request_current_info(id);
            update_display(info_to_display);
        }
        catch(std::exception& e)
        {
            display_error(e);
        }
    });
}
