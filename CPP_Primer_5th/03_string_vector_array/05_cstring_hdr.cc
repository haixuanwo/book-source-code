/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-11 10:02:03
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-11 10:12:12
 * @Description: file content
 */

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <cstring>
#include <cstddef>
using std::size_t;

int main()
{
    string s1 = "A string example";
    string s2 = "A different string";

    if (s1 < s2)
        cout << s1 << endl;
    else
        cout << s2 << endl;

    const char ca1[] = "A string example";
    const char ca2[] = "A different string";

    if (strcmp(ca1, ca2) < 0)
        cout << s1 << endl;
    else
        cout << s2 << endl;

    const char *cp1 = ca1, *cp2 = ca2;
    cout << strcmp(cp1, cp2) << endl;
    cout << strcmp(cp2, cp1) << endl;
    cout << strcmp(cp1, cp1) << endl;

    cout << strlen(cp1) << endl;

    const unsigned sz = 16 + 18 + 2;
    char largeStr[sz];
    strcpy(largeStr, ca1);
    strcat(largeStr, " ");
    strcat(largeStr, ca2);
    cout << largeStr << endl;

    strncpy(largeStr, ca1, sz);
    if (strlen(ca1) > sz)
        largeStr[sz-1] = '\0';
    strncat(largeStr, " ", 2);
    strncat(largeStr, ca2, sz - strlen(largeStr));
    cout << largeStr << endl;

    string large_string = s1 + " " + s2;
    cout << large_string << endl;

    return 0;
}
