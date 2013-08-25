class Solution {

public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<bool> state;
        state.resize(num.size(), true);
        
        return permuteWithState(state, num);
    }
    
private:
    vector<vector<int> > permuteWithState(vector<bool> &state, vector<int> &num) {
        
        vector<vector<int> > vps;
        
        bool not_found = true;
        
        for (int i = 0; i < num.size(); i++) {
            
            if (state[i]) {
                state[i] = false;
                vector<vector<int> > temp = permuteWithState(state, num);
                
                for_each(temp.begin(), temp.end(), [&vps, &num, &i](vector<int> &t){
                   
                   t.insert(t.begin(), num[i]);
                   vps.push_back(t);
                   
                });
                state[i] = true;
                not_found = false;
            }
        }
        
        if (not_found) {
            vps.push_back(vector<int>());
        }
        
        return vps;
    }
};