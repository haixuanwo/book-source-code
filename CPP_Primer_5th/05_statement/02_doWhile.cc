/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-12 11:19:06
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-12 11:25:50
 * @Description: file content
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
    // repeatedly ask the user for a pair of numbers to sum
    string rsp;  // used in the condition; can't be defined inside the do

    do
    {
        cout << "please enter two values: ";
        int val1 = 0, val2 = 0;
        cin  >> val1 >> val2;
        cout << "The sum of " << val1 << " and " << val2
             << " = " << val1 + val2 << "\n\n"
             << "More? Enter yes or no: ";
        cin  >> rsp;
    }while (!rsp.empty() && rsp[0] != 'n');

	cout << endl;

	return 0;
}