//rev.2 pre build adjacent graph, but take longer time on leetcode
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        if (start == end) return 0;

        queue<pair<string, int> > q;
        unordered_map<string, unordered_set<string> > adj;
        
        buildAdjacent(dict, adj, start, end);
        
        q.push(make_pair(start, 1));
        
        while (!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();
            
            string temp = p.first;
            
            if (temp == end)
                return p.second;
                                        
            for (auto it = adj[temp].begin(); it != adj[temp].end(); it++) {
                
                if (dict.find(*it) != dict.end()) {
                    q.push(make_pair(*it, p.second+1));
                    dict.erase(*it);
                }
                  
            }
            
        }
        
        return 0;
        
    }
private:
    void buildAdjacent(unordered_set<string> &dict, unordered_map<string, unordered_set<string>> &adj, string &start, string &end) {
        
        //dict.insert(start);
        
        for (auto it = dict.begin(); it != dict.end(); it++) {
            
            string temp = *it;
            
            for (int i = 0; i < temp.size(); i++) {
                
                char c_t = temp[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    
                    if (c == c_t) continue;
                
                    temp[i] = c;
                    
                    if (dict.find(temp) != dict.end()) {
                        adj[*it].insert(temp);
                    }
                    temp[i] = c_t;
                }
                
                
            }
            
        }
    }
};
// rev.1
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        if (start == end) return 0;

        queue<pair<string, int> > q;
        
        q.push(make_pair(start, 1));
        
        while (!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();
            
            string temp = p.first;
            
            if (temp == end)
                return p.second;
                                        
            for (int i = 0; i < temp.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    
                    char t_c = temp[i];
                    if (t_c != c) {
                        temp[i] = c;
                        if (dict.find(temp) != dict.end()) {
                            q.push(make_pair(temp, p.second+1));
                            dict.erase(temp);
                        }
                        temp[i] = t_c;
                    }
                    
                }
            }
            
        }
        
        return 0;
        
    }
};