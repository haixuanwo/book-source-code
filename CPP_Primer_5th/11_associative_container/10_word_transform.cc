/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-18 14:50:04
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-18 23:45:24
 * @Description: file content
 */

#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>

using std::map;
using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::getline;
using std::runtime_error;
using std::istringstream;

map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map;   // holds the transformations
    string key;    // a word to transform
	string value;  // phrase to use instead
	// read the first word into key and the rest of the line into value
	while (map_file >> key && getline(map_file, value))
		if (value.size() > 1) // check that there is a transformation
        	trans_map[key] = value.substr(1); // skip leading space
		else
			throw runtime_error("no rule for " + key);
	return trans_map;
}

const string &transform(const string &s, const map<string, string> &m)
{
    auto map_it = m.find(s);
    if (map_it != m.end())
    {
        return map_it->second;
    }
    else
    {
        return s;
    }
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);
    cout << "Here is our transformation map: \n\n";
    for (auto entry : trans_map)
    {
        cout << "key: " << entry.first
            << "\tvalue: " << entry.second << endl;
    }
    cout << "\n\n";

    string text;
    while (getline(input, text))
    {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word)
        {
            if (firstword)
            {
                firstword = false;
            }
            else
            {
                cout << " ";
            }
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
        throw runtime_error("wrong number of arguments");

    ifstream map_file(argv[1]);
    if (!map_file)
    {
        throw runtime_error("no transformation file");
    }

    ifstream input(argv[2]);
    if (!input)
    {
        throw runtime_error("no inpuit file");
    }

    word_transform(map_file, input);
    return 0;
}
