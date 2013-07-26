//1. should begin search at begin() + i + 1, not begin() + i!
//2. a bound condition is target is twice as one number, you should
// have two
//3. in binary search, can we discard checked numbers to speed up?
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        // first native solution
        // vector<int> idx;
        // for (int i = 0; i< numbers.size(); i++) {
            
        //     vector<int>::iterator it = find(numbers.begin() + i + 1, numbers.end(), target - numbers[i]);
            
        //     if (it != numbers.end()) {
        //         idx.push_back(i + 1);
        //         idx.push_back(it - numbers.begin() + 1);
        //         return idx;
        //     }
        // }
        vector<int> idx;
        multiset<int> sorted = numbers;

        // sort(sorted.begin(), sorted.end());

        for (int i = 0; i < numbers.size(); i++) {
            multiset<int>::iterator it = sorted.find(numbers[i]);
            // erase the one instance of numbers[i] to avoid be found as target - numbers[i]
            sorted.erase(it); 

            it = sorted.find(target - numbers[i]);
            if (it != sorted.end()) {
                it = find(numbers.begin() + i + 1, numbers.end(), *it)
                idx.push_back(i + 1);
                idx.push_back(it - numbers.begin() + 1);
                return idx;
            }
        }
    }
};