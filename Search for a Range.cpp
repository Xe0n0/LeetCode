class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        pair<int *, int *> bounds;
        bounds = equal_range(A, A+n, target);
        vector<int> temp;

        if (bounds.first != bounds.second)
        {
            temp.push_back(bounds.first-A);
            temp.push_back(bounds.second-A-1);
        }
        else {
            temp.resize(2, -1);
        }
        
        return temp;
    }
};