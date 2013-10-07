#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    	vector<Interval> res;
    	int i;
    	for( i = 0; i<intervals.size(); i++){
    		if (newInterval.start > intervals[i].end){
    			res.push_back(intervals[i]);
    		}else if(newInterval.end < intervals[i].start){
    			break;
    		}else{
    			newInterval.end = max(intervals[i].end, newInterval.end);
    			newInterval.start = min(intervals[i].start, newInterval.start);
    		}
    	}
    	res.push_back(newInterval);
    	while(i<intervals.size()){
    		res.push_back(intervals[i++]);
    	}
    	return res;
    }
};
