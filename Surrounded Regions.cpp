class Solution {
private:

    set<pair<int, int>> set_v;
    set<pair<int, int>> area;
    queue<pair<int, int>> q;
    bool isOpenArea;
    int width;
    int height;
    
    bool visit_if_could(int i, int j, vector<vector<char>> &board) {
 
        if (i < 0 || i >= width || j < 0 || j >= height) return false;

        if (board[i][j] == 'O' && set_v.find(make_pair(i, j)) == set_v.end()) {

            pair<int, int> p = make_pair(i, j);
            
            area.insert(p);

            set_v.insert(p);

            q.push(p);


            if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
                isOpenArea = true;
            }
        }

        return true;
    }
    void enqueue_if_needed(int i, int j, vector<vector<char>> &board){

        // if (i < 0 || i >= width || j < 0 || j >= height) return;

        q.push(make_pair(i, j));
            
        return;
    }
    void searchAt(int i, int j, vector<vector<char>> &board) {
        
        isOpenArea = false;
        
        visit_if_could(i, j, board);
        
        
        while(q.size() > 0) {
            pair<int, int> point = q.front();
            q.pop();
            // visit(point);
            visit_if_could(point.first-1, point.second, board);
            visit_if_could(point.first+1, point.second, board);
            visit_if_could(point.first, point.second-1, board);
            visit_if_could(point.first, point.second+1, board);
        }
        
        if (!isOpenArea) {
            set<pair<int, int>>::iterator i = area.begin();
            while(i != area.end()) {
                pair<int, int> point = *i;
                board[point.first][point.second] = 'X';
                i++;
            }
        }
        area.clear();
    }
public:

    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        isOpenArea = false;

        height = board.size();
        
        if (height <= 0) return;
        
        width = board[0].size();
        
        
        for (int i = 1; i < board.size() - 1; i++) {
            
            vector<char> &row = board[i];
            
            for (int j = 1; j < row.size() - 1; j++) {
                
                if (row[j] == 'O')
                    
                    searchAt(i, j, board);
            }
        }
        
        set_v.clear();
        isOpenArea = false;
    }
};