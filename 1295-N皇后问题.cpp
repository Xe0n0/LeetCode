#include <iostream>
#include <vector>

using namespace std;


vector<vector<bool> > board;
vector<bool> cols;

bool isValid(int x, int y) {
    
    for (int i = x-1; i >= 0; i--) {
        
        int j = y;
        
        if (board[i][j])
            return false;
        
        if ((j = y - (x-i)) >= 0 and board[i][j])
            return false;
        
        if ((j = y + (x-i)) < board.size() and board[i][j])
            return false;
    }
    
    return true;
    
}

void searchAt(int idx, int &r) {
    
    if (idx == board.size()) {
        r++;
        return;
    }
    
    for (int i = 0; i < board.size(); i++) {
        
        if (!cols[i] && isValid(idx, i)) {
            board[idx][i] = true;
            cols[i] = true;
            searchAt(idx + 1, r);
            cols[i] = false;
            board[idx][i] = false;
        }
        
    }
}



int main(){
    
    
    int n;
    
    cin >> n;
    
    if (n <= 7){
        
        cout << 0 << endl;
        return 0;
        
    }
    
    board.resize(n, vector<bool>(n, false));
    cols.resize(n, false);
    
    int r = 0;
    
    searchAt(0, r);
    
    cout << r << endl;
    
    return 0;
    
}