//1. compare with r.back().end ! not intervals[i-1].end !
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
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<Interval> r;
        
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
        
            return a.start < b.start;
            
        });
        
        for (int i = 0; i < intervals.size(); i++) {
            
            if (i - 1 >= 0 && intervals[i].start <= r.back().end) {
                r.back().end = max(r.back().end, intervals[i].end);
                continue;
            }
            
            r.push_back(intervals[i]);
            
        }
        
        return r;
    }
};