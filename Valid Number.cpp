class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s == NULL) return false;

        vector<vector<int>> states({
            {-1,  0,  3,  1,  2, -1},
            {-1,  8, -1,  1,  4,  5},
            {-1, -1, -1,  4, -1, -1},
            {-1, -1, -1,  1,  2, -1},
            {-1,  8, -1,  4, -1,  5},
            {-1, -1,  6,  7, -1, -1},
            {-1, -1, -1,  7, -1, -1},
            {-1,  8, -1,  7, -1, -1},
            {-1,  8, -1, -1, -1, -1},
        });

        int idx = 0;
        int state = 0;

        while (*s != '\0') {
            switch(*s) {
                case ' ':
                    idx = 1;
                    break;
                case '+':
                case '-':
                    idx = 2;
                    break;
                case '.':
                    idx = 4;
                    break;
                case 'e':
                    idx = 5;
                    break;
                default:
                    idx = 0;
                    if (*s >= '0' and *s <= '9')
                        idx = 3;
                    break;
            }
            state = states[state][idx];
            if (state == -1) return false;

            s++;
        }
        return state == 1 || state == 4 || state == 7 || state == 8;
    }
};