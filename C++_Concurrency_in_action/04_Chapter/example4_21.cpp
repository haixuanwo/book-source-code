/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-19 17:56:27
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-19 18:32:36
 * @Description: file content
 */

#include <experimental/future>

std::experimental::future<void> process_login(
    std::string const& username,std::string const& password)
{
    return backend.async_authenticate_user(username,password).then(
        [](std::experimental::future<user_id> id){
            return backend.async_request_current_info(id.get());
        }).then([](std::experimental::future<user_data> info_to_display){
            try
            {
                update_display(info_to_display.get());
            }
            catch(std::exception& e)
            {
                display_error(e);
            }
        });
}
