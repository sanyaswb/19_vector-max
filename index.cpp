#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

float vectorMax(std::vector<float> &numbers) {
	float minNum = -INFINITY;

	for (int i = 0; i < numbers.size(); ++i) {
		if (numbers[i] > minNum) {
			minNum = numbers[i];
		}
	}

	return minNum;
}
