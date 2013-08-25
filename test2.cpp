#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return maxAreaAtRange(height, 0, height.size());
    }
private:
    int maxAreaAtRange(vector<int> &height, int start, int end) {
        
        if (start >= end) return 0;
        
        vector<int>::iterator it = min_element(height.begin() + start, height.begin() + end);
        
        
        int area_l = maxAreaAtRange(height, start, it - height.begin());
        int area_r = maxAreaAtRange(height, it-height.begin() + 1, end);
        
        return max(max(area_l, area_r), *it * (end - start - 1));
    }
};

int main() {
    // Start typing your code here...
    unordered_set<string> dict = {"hot","cog","dog","tot","hog","hop","pot","dot"};
    vector<int> a = {3,6,5,7,4,8,1,0};
    cout << Solution().largestRectangleArea(a) << endl;
    
    
    return 0;
}