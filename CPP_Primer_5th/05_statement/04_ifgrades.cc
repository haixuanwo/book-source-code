
#include <iostream>
using std::endl;
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <string>
using std::string;

const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
vector<unsigned> grades;

// these functions demonstrate alternative ways to handle the if tests
// function that takes an unsigned value and a string
// and returns a string
string goodVers(string lettergrade, unsigned grade)
{
	// add a plus for grades the end in 8 or 9 and a minus for those ending in 0, 1, or 2
	if (grade % 10 > 7)
		lettergrade += '+';	   // grades ending in 8 or 9 get a '+'
	else
		if (grade % 10 < 3)
			lettergrade += '-';   // those ending in 0, 1, or 2 get a '-'
	return lettergrade;
}

// incorrect version of the function to add a plus or minus to a grade
string badVers(string lettergrade, unsigned grade)
{
	// add a plus for grades the end in 8 or 9 and a minus for those ending in 0, 1, or 2
	// WRONG: execution does NOT match indentation; the else goes with the inner if
	if (grade % 10 >= 3)
		if (grade % 10 > 7)
			lettergrade += '+';  // grades ending in 8 or 9 get a +
	else
		lettergrade += '-'; // grades ending in 3, 4, 5, 6 will get a minus!
	return lettergrade;
}

// corrected version using the same logic path as badVers
string rightVers(string lettergrade, unsigned grade)
{
	// add a plus for grades that end in 8 or 9 and a minus for those ending in 0, 1, or 2
	if (grade % 10 >= 3) {
		if (grade % 10 > 7)
			lettergrade += '+';  // grades ending in 8 or 9 get a +
	} else                  // curlies force the else to go with the outer if
		lettergrade += '-'; // grades ending in 0, 1, or 2 will get a minus
	return lettergrade;
}

int main()
{
	// read a set of scores from the input
	unsigned grade;
	while (cin >> grade)
		grades.push_back(grade);

	// now process those grades
	for (auto it : grades) {   // for each grade we read
		cout << it << " " ;    // print the grade
		string lettergrade;    // hold coresponding letter grade
		// if failing grade, no need to check for a plus or minus

        if (it < 60)
			lettergrade = scores[0];
		else {
            /*
            1. 确定哪个分数字母等级
            2. 每个有三种-、+、无符号
            */
			lettergrade = scores[(it - 50)/10];  // fetch the letter grade
			if (it != 100)  // add plus or minus only if not already an A++
				if (it % 10 > 7)
					lettergrade += '+';   // grades ending in 8 or 9 get a +
				else if (it % 10 < 3)
					lettergrade += '-';   // grades ending in 0, 1, or 2 get a -
		}
		cout << lettergrade << endl;

        // 罗列分数对应的等级与种类
        if (it > 59 && it !=100) {
			cout << "alternative versions: " << it << " ";
			// start over with just the basic grade, no + or -
			lettergrade = scores[(it - 50)/10];
			cout << goodVers(lettergrade, it) << " ";
			cout << badVers(lettergrade, it) << " ";
			cout << rightVers(lettergrade, it) << " ";
			cout << endl;
		}
	}

	return 0;
}
