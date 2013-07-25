class Solution {
private:
    bool isPalindrome(string s){
        int i = 0, j = s.size() - 1;
        while (i < j){
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string>> partitions;
        
        if (s.size() > 0){
            for (int i = 1; i <= s.size(); i++){
                string a = s.substr(0, i);
                if (isPalindrome(a)) {
                    
                    vector<vector<string>> yapartions = partition(s.substr(i));
                    for (int j = 0; j < yapartions.size(); j++){
                        vector<string> temp;
                        temp.push_back(a);
                        for (int k = 0; k < yapartions[j].size(); k++){
                            temp.push_back(yapartions[j][k]);
                        }
                        partitions.push_back(temp);
                    }
                }
            }
        }
        else {
            vector<string> temp;
            //temp.push_back(s);
            partitions.push_back(temp);
        }
        return partitions;
    }
};