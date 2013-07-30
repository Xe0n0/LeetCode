//1. what if string has non-numerical char? what if out of range?
//2. first find the first char that is numerical or '-'/only ignore whitespace
//3. for all subsequent numerical char, save for number
//4. what if "+-1" or "-+1"？
//5. you forget increase p again!
class Solution {
public:
    int atoi(const char *str) {
        const char * p = str;
        
        int left, right;
        
        left = right = -1;
        
        int i = 0;
        
        bool start = false;
        
        while (*p != '\0') {
            
            if (*p == '+' or *p == '-') {
                if (start) return 0;
                else start = true;
            }
            if (*p >= '0' and *p <= '9' or *p == '+' or *p == '-')
            
            {
                if (left < 0) right = left = i;
                else right = i;
            }
            else if (left >= 0) break;
            else if (*p != ' ' and left < 0 ) return 0;
            i++;
            p++;
        }
        
        int r = 0;
        
        if (left < 0 or right < 0) return r;
        
        bool isPositive = true;
        
        for (i = left; i <= right; i++) {
            if (str[i] == '+') continue;
            if (str[i] == '-') {isPositive = false; continue;}
            
            int c = str[i] - '0';
            
            int prev = r;
            
            if (abs(r) >= 214748365) return isPositive?INT_MAX:INT_MIN;
            
            r *= 10;
            
            if (isPositive)
                r += c;
            else r -= c;
            
            if (prev > 0 and r < 0) return INT_MAX;
            
            if (prev < 0 and r > 0) return INT_MIN;
        }
        
        return r;
    }
};