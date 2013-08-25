//It's wrong to divide this problem to n-1 and 1 subproblem.
//There seems to be differences between Permutation problem and dividable problem
class Solution {
private:
    vector<string> r;
    void generateAt(string& s, int level, int num, int n) {
        if (level == 0 && num == 0) {
            r.push_back(s);
            return;
        }

        if (n > 0)
        {
            s.append("(");
            generateAt(s, level + 1, num - 1, n - 1);
            s.pop_back();
        }
        if (level > 0)
        {
            s.append(")");
            generateAt(s, level - 1, num - 1, n); 
            s.pop_back();
        }
        
       
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        r.resize(0);
        //set<string, mycompare> s;
        string seed("");
        generateAt(seed, 0, 2 * n, n);
        return r;
    }
};