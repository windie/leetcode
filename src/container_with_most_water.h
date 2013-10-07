#include <iostream>
using namespace std;

class Solution {
public:
	int maxArea(vector<int> &height) {
		int begin = 0, end = height.size() - 1;
		int max = 0;
		while (begin < end) {
			if (height[begin] < height[end]) {
				int area = height[begin] * (end - begin);
				if (area > max) {
					max = area;
				}
				begin++;
			} else {
				int area = height[end] * (end - begin);
				if (area > max) {
					max = area;
				}
				end--;
			}
		}
		return max;
	}
};
