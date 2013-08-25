//1. set(ordered) is merely logn when finding, if wanna specific range, use binary_search instead
//2. carefully check when iterator is xxx.end()

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > triplets;


        if (num.size() < 3) return triplets;

        sort(num.begin(), num.end());

        int target;
        
        int prev0 = num[0];
        int prev1 = num[1];
        
        for (int i = 0; i < num.size(); i++) {
            if (i > 0 && num[i] == prev0) continue;
            else prev0 = num[i];
            for (int j = i + 1; j < num.size(); j++) {
                if (j > 1 && num[j] == prev1) continue;
                else prev1 = num[j];
                
                target = -num[i] - num[j];
                if (binary_search(num.begin() + j + 1, num.end(), target)) {
                    vector<int> temp;
                    temp.push_back(num[i]);
                    temp.push_back(num[j]);
                    temp.push_back(target);

                    triplets.push_back(temp);
                }
                cout  << endl;
            }
        }
        return triplets;
    }
};
