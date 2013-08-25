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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval>::iterator lower = lower_bound(intervals.begin(), 
            intervals.end(),
            newInterval,
            [](const Interval &a, const Interval &b){
            return a.start < b.start;
        });
        
        intervals.insert(lower, newInterval);
        
        vector<Interval> r;
        
        for (int i = 0; i < intervals.size(); i++) {
            
            if (!r.empty() && intervals[i].start <= r.back().end) {
                r.back().end = max(intervals[i].end, r.back().end);
            }
            else
                r.push_back(intervals[i]);
            
        }
        
        return r;
    }
};