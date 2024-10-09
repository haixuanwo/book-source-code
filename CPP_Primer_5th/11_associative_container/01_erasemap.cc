
#include <map>
using std::map;

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void show_map(const std::map<string, size_t> &m)
{
    cout << "Size of map: " << m.size() << endl;

    for (const auto &pair : m)
    {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }
}

int main()
{
    map<string, size_t> word_count;
    string word;

    while (cin >> word)
    {
        ++word_count[word];
    }
    show_map(word_count);

    string removal_word = "the";

    // 1. by key
    if (word_count.erase(removal_word))
    {
        cout << "ok: " << removal_word << " removed\n";
    }
    else
    {
        cout << "oops: " << removal_word << " not found\n";
    }
    show_map(word_count);

    // 2. by removing an iterator to the element we want removed
    removal_word = "The";
    map<string, size_t>::iterator where;
    where = word_count.find(removal_word);

    if (where == word_count.end())
    {
        cout << "oops: " << removal_word << " not found!\n";
    }
    else
    {
        word_count.erase(where);
        cout << "ok: " << removal_word << " removed!\n";
    }

    return 0;
}
