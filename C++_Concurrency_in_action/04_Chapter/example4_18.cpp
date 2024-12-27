/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-11-19 17:28:35
 * @LastEditors: Clark
 * @LastEditTime: 2024-11-19 17:28:47
 * @Description: file content
 */

#include <string>
void process_login(std::string const& username,std::string const& password)
{
    try
    {
        user_id const id=backend.authenticate_user(username,password);
        user_data const info_to_display=backend.request_current_info(id);
        update_display(info_to_display);
    }
    catch(std::exception& e)
    {
        display_error(e);
    }
}
