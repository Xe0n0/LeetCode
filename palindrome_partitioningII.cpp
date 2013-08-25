class Solution {
public:
    int* count;
    bool isPalindrome(const string &s, int start, int index){
        int i = start, j = index - 1;
        
        while (i < j){
            if (s[i] != s[j]){
                //cout << s[i] << s[j] << i << j << endl;
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    int minCutAt(int index, const string& s){
        if (index < s.size()){
            
            if (count[index] < 0){
                
                if (isPalindrome(s, index, s.size()))
                {
                    count[index] = 0;
                    return 0;
                }

                int minThrehold = s.size() - index;
                for (int i = s.size() - 1; i > index; i--){
                
                
                    if (isPalindrome(s, index, i)) {
                    
                        minThrehold = min(minCutAt(i, s) + 1, minThrehold);
                        if (minThrehold <= 1) break;
                    }
                }
                count[index] = minThrehold;
                
            }
            return count[index];
             
        }
        return 0;
    }
    int minCut(string& s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      
            
            count = new int[s.size()];
            for (int i = 0; i < s.size(); i++){
                count[i] = -1;
            }
      
        
        return minCutAt(0, s);
    }
};