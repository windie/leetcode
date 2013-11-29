/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    bool isInSameLine(Point &p1, Point &p2, Point &l){
        return (l.y - p2.y) * (p2.x-p1.x) == (l.x-p2.x) * (p2.y-p1.y);
    }
public:
    int maxPoints(vector<Point> &points) {
        if(points.size()==0 || points.size()==1){
            return points.size();
        }
        int res=0;
        vector<vector<Point> > lines;
        for(int i = 0; i<points.size(); i++){
            int samecnt = 1;
            for(int j = i+1; j < points.size(); j++){
                if(points[i].x == points[j].x && points[i].y == points[j].y){
                    samecnt++;
                    continue;
                }
                vector<Point> line;
                line.push_back(points[i]);
                line.push_back(points[j]);
                lines.push_back(line);
            }
            res = max(res, samecnt);
        }
        vector<int> cnt(lines.size(), 0);
        for(int i = 0; i<lines.size(); i++){
            for(int j = 0; j < points.size(); j++){
                 if(isInSameLine(lines[i][0], lines[i][1], points[j])){
                     cnt[i]++;
                 }
            }
            res = max(res, cnt[i]);
        }
        return res;
    }
};
