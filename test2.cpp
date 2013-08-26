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
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      
        //if (start == end) return 0;

        queue<pair<string, int> > q;
        unordered_map<string, unordered_set<string>> pres;
        unordered_map<string, unordered_set<string>> nexts;
        build(nexts, dict);
        stack<string> used;
        
        q.push(make_pair(start, 1));
        
        int level = 1;
        
        int max_level = 0;
        bool found = false;
        
        
        while (!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();
            
            if (found && p.second > max_level) continue;
            
            if (p.second > level) {
                level = p.second;
                while (!used.empty()) {
                    dict.erase(used.top());
                    used.pop();
                }
            }
            
            string cur = p.first;
            for (auto it = nexts[cur].begin(); it != nexts[cur].end(); it++) {
                string temp = *it;
                if (temp == end) {
                    if (!found) max_level = p.second;
                    found = true;
                    pres[end].insert(p.first);
                }
                else {
                    q.push(make_pair(temp, p.second+1));
                    pres[temp].insert(p.first);
                    used.push(temp);
                }
            }
            dict.erase(cur);
        }
        return laddersWithPres(pres, end, start);
    }
private:
    void build(unordered_map<string, unordered_set<string>> &nexts, unordered_set<string> &dict) {
        for (auto it = dict.begin(); it != dict.end(); it++) {
            string temp = *it;
            for (int i = 0; i < temp.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    char t_c = temp[i];
                    
                    if (t_c != c) {
                        temp[i] = c;
                        if (dict.find(temp) != dict.end()) {
                            nexts[*it].insert(temp);
                        }
                        temp[i] = t_c;
                    }
                    
                }
            }
        }
    }
    vector<vector<string>> laddersWithPres(unordered_map<string, unordered_set<string>> &pres, 
        string &end, string &start) {
        
        vector<vector<string>> r;
        
        vector<string>path;
        
        recursive_ladders(pres, end, start, r, path);
        
        return r;
    }
    void recursive_ladders(unordered_map<string, unordered_set<string>> &pres, 
        string &end, string &start, vector<vector<string>> &r, vector<string> &path)
    {
         if (end == start) {
            path.push_back(end);
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            r.push_back(temp);
            path.pop_back();
            return;
        }
        cout << end << endl;
        for (auto it = pres[end].begin(); it != pres[end].end(); it++) {
            string pre = *it;
            path.push_back(end);
            recursive_ladders(pres, pre, start, r, path);
            path.pop_back();
            
        }   
    }
};

int main() {
    // Start typing your code here...
    unordered_set<string> dict = {"hot","cog","dog","tot","hog","hop","pot","dot"};
    vector<int> a = {3,6,5,7,4,8,1,0};
    string sa = "hot";
    string sb = "dog";
    cout << Solution().findLadders(sa, sb, dict).size() << endl;
    
    
    return 0;
}