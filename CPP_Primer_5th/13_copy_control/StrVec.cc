/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-10 12:59:36
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-10 12:59:58
 * @Description: file content
 */

#include "StrVec.h"

#include <string>
using std::string;

#include <memory>
using std::allocator;

// errata fixed in second printing --
// StrVec's allocator should be a static member not an ordinary member

// definition for static data member
allocator<string> StrVec::alloc;

// all other StrVec members are inline and defined inside StrVec.h
