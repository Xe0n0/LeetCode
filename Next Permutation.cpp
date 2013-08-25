class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        multiset<int> avals;
        multiset<int>::iterator it;
        
        int i;
        int t;
        
        for (i = num.size() - 1; i >= 0; i--) {
            t = num[i];
            
            if (i + 1 < num.size() && num[i] < num[i+1]) {
                it = avals.upper_bound(t);
                num[i++] = *it;
                avals.erase(it);
                avals.insert(t);
                break;
            }
            
            avals.insert(t);
        }
        
        it = avals.begin();
        
        if (i < 0) i++;
        
        while(i < num.size()) {
            if (it == avals.end()) it = avals.begin();
            num[i++] = *it++;
        }
        return;
    }
};