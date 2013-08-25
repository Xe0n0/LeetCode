class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      
        //if (start == end) return 0;

        queue<pair<string, int> > q;
        unordered_multiset<string, string> pres;
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
            
            string temp = p.first;
                                        
            for (int i = 0; i < temp.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    
                    char t_c = temp[i];
                    
                    if (t_c != c) {
                        temp[i] = c;
                        if (temp == end) {
                            if (!found) max_level = p.second;
                            found = true;
                            pres.insert(make_pair(end, p.first));
                        }
                        else if (dict.find(temp) != dict.end()) {
                            q.push(make_pair(temp, p.second+1));
                            pres.insert(make_pair(temp, p.first));
                            used.push(temp);
                        }
                        temp[i] = t_c;
                    }
                    
                }
            }
            
        }
        return laddersWithPres(pres, end);
    }
private:
    vector<vector<string>> laddersWithPres(unordered_multiset<string, string> &pres, 
        string &end) {
        
        vector<vector<string>> r;
        
        if (pres.find(end) == pres.end()) {
            r.push_back(vector<string>(1, end));
            return r;
        }
        
        auto range = pres.equal_range(end);
        for_each(range.first, range.second, [&r](const string &pre){
        
            vector<vector<string>> next = laddersWithPres(pres, pre);
            for (int i = 0; i < next.size(); i++) {
                next[i].push_back(end);
                r.push_back(next[i]);
            }
            
        });
        
        return r;
    }
};