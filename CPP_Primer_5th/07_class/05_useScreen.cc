
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "Screen.h"

int main()
{
    Screen myScreen(5, 3);
    myScreen.move(4, 0).set('#');

    Screen nextScreen(5, 5, 'X');
    nextScreen.move(4, 0).set('#').display(cout);

    cout << "\n";
    nextScreen.display(cout);
    cout << endl;

    const Screen blank(5, 3);
    myScreen.set('#').display(cout);
    cout << endl;
    blank.display(cout);
    cout << endl;

    myScreen.clear('Z').display(cout);
    cout << endl;
    myScreen.move(4, 0);
    myScreen.set('#');
    myScreen.display(cout);

    cout << endl;
    myScreen.clear('Z').display(cout);
    cout << endl;

    #if 1
    Screen temp = myScreen.move(4, 0);
    temp.set('#');
    myScreen.display(cout);
    cout << endl;
    #endif
}
