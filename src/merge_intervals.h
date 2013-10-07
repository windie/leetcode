/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval a, Interval b) {
	return a.start < b.start;
}
class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> res;
		sort(intervals.begin(), intervals.end(), cmp);
		if (intervals.size() == 0) {
			return res;
		}
		Interval tmp = intervals[0];
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i].start > tmp.end) {
				res.push_back(tmp);
				tmp = intervals[i];
			} else {
				tmp.end = max(tmp.end, intervals[i].end);
			}
		}
		res.push_back(tmp);
		return res;
	}
};

//bool cmp(Interval a, Interval b){
//	return a.start < b.start;
//}
//class Solution {
//public:
//    vector<Interval> merge(vector<Interval> &intervals) {
//    	sort(intervals.begin(), intervals.end(), cmp);
//    	vector<Interval> res;
//    	if(intervals.size()==0){
//    		return res;
//    	}
//    	Interval newInterval;
//    	newInterval.start = intervals[0].start;
//    	newInterval.end = intervals[0].end;
//    	for(int i=1; i<intervals.size(); i++){
//			if (newInterval.start > intervals[i].end) {
//				res.push_back(intervals[i]);
//			} else if (newInterval.end < intervals[i].start) {
//				res.push_back(newInterval);
//				newInterval.start = intervals[i].start;
//				newInterval.end = intervals[i].end;
//			} else {
//				newInterval.end = max(intervals[i].end, newInterval.end);
//				newInterval.start = min(intervals[i].start, newInterval.start);
//			}
//    	}
//    	res.push_back(newInterval);
//    	return res;
//    }
//};
