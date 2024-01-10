/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-12 13:56:55
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-12 13:57:04
 * @Description: file content
 */

#include <cstddef>
using std::size_t;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#ifndef MAKE_PLURAL_H
#define MAKE_PLURAL_H

// 复数
// return the plural version of word if ctr is greater than 1
inline string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

#endif

