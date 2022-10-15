#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

float vectorMax(std::vector<float> &numbers) {
	float max = -INFINITY;

	for (float n: numbers) {
		if (n > max) {
			max = n;
		}
	}

	return max;
}
