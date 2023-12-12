
#include <iterator>
using std::begin;
using std::end;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <cstddef>
using std::size_t;

int main()
{
    int ia1[3][4];
    int arr[10][20][30] = {0};

    ia1[2][3] = arr[0][0][0];
    int (&row)[4] = ia1[1];

    int ia2[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };

    int ia3[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int ia4[3][4] = {{0}, {4}, {8}};
    int ix[3][4] = {0, 3, 6, 9};

    cout << ix[0][3] << ' ' << ix[1][0] << ' ' << ix[2][0] << endl;

    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia[rowCnt][colCnt];

    for (size_t i = 0; i != rowCnt; i++)
    {
        for (size_t j = 0; j != colCnt; j++)
        {
            ia[i][j] = i * colCnt + j;
        }
    }

    // 1. using nested range for loops
    for (const auto &row : ia)
    {
        for (auto col : row)
        {
            cout << col << endl;
        }
    }
    cout << ia[0][0] << ' ' << ia[2][3] << endl;

    // 2. using pointers and a traditional for loop
    // with pointer arithmetic to calculate the end pointers
    for (auto p = ia; p != ia + rowCnt; ++p)
    {
        for (auto q = *p; q != *p + colCnt; ++q)
        {
            cout << *q << ' ';
        }
        cout << endl;
    }

    // 3. using pointers and a traditional for loop
    // while the library begin and end functions to manage the pointers
    for (auto p = begin(ia); p != end(ia); ++p)
    {
        for (auto q = begin(*p); q != end(*p); ++q)
        {
            cout << *q << ' ';
        }
        cout << endl;
    }

    // 4. using a type alias to declare the loop control variable
    using int_array = int[4];
    for (int_array *p = ia; p != ia +3; ++p)
    {
        for (int *q = *p; q != *p + 4; ++q)
        {
            cout << *q << ' ';
        }
        cout << endl;
    }

    int alt_ia[rowCnt][colCnt];
    size_t cnt = 0;
    for (auto &row : alt_ia)
    {
        for (auto &col : row)
        {
            col = cnt;
            ++cnt;
        }
    }

    for (const auto &row : alt_ia)
    {
        for (auto col : row)
        {
            cout << col << endl;
        }

    }

    return 0;
}
