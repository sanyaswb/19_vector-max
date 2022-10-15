#include "test.h"
#include "../index.h"
#include "termcolor.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string boolString(bool value) {
	return value ? "true" : "false";
}

struct Option {
		float toBe;
		std::vector<float> numbers;
};

Option options[] = {
		{
				5,
				{1, 2, 3, 4, 5}
		},
		{
				-INFINITY,
				{}
		},
		{
				0,
				{0, -6, -35, -91, -152, -21, -96}
		},
		{
				-5,
				{-5, -21, -41, -5, -514, -25, -53}
		},
		{
				22,
				{17, -551, 22}
		},
		{
				INFINITY,
				{22, 54, -72, -8, INFINITY, 22}
		}
};

void printGreen(const string& test, const string& result) {
	cout << termcolor::green << "TEST " << test << " PASSED! RESULT: " << result << "" << endl;
}

void printRed(const string& test, const string& expected, const string& result) {
	cout << termcolor::red << "TEST " << test << " FAILED! EXPECTED: " << expected << " INSTEAD OF " << result << "!" << endl;
}

void test() {
	cout << endl;

	int optionsLength = sizeof(options) / sizeof(options[0]);

	for (int i = 0; i < optionsLength; i++) {
		Option option = options[i];

		float result = vectorMax(option.numbers);
		int roundedResult = int(vectorMax(option.numbers));

		string testStr = "{";

		for (int j = 0; j < option.numbers.size(); j++) {
			if (j < option.numbers.size() - 1) {
				testStr += option.numbers[j] != INFINITY && option.numbers[j] != -INFINITY ? to_string(int(option.numbers[j])) + ", " : to_string(option.numbers[j]) + ", ";
			} else {
				testStr += option.numbers[j] != INFINITY && option.numbers[j] != -INFINITY ? to_string(int(option.numbers[j])) + "}" : to_string(option.numbers[j]) + "}";
			}
		}

		if (option.numbers.empty()) {
			testStr += '}';
		}

		if (result == option.toBe) {
			printGreen(testStr, result != INFINITY && result != -INFINITY ? to_string(roundedResult) : to_string(result));
		} else {
			printRed(testStr, to_string(option.toBe), result != INFINITY && result != -INFINITY ? to_string(roundedResult) : to_string(result));
		}

		cout << endl;
	}
}