//1. clear carry flag, if use condition to set carry
//2. zero condition

class Solution {
private:
    string add(string &a, string &b) {
        string r;
        
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        
        while (i >= 0 && j >= 0) {
            
            int c = a[i] + b[j] - 2 * '0' + carry;
            carry = c / 10;
            c = c % 10;
            r.push_back(c + '0');
            
            i--;
            j--;
        }
        
        while (i >= 0) {
            int c = a[i] - '0' + carry;
            carry = c / 10;
            c = c % 10;
            r.push_back(c + '0');
            i--;
        }
        
        while (j >= 0) {
            int c = b[j] - '0' + carry;
            carry = c / 10;
            c = c % 10;
            r.push_back(c + '0');
            j--;
        }
        if (carry) r.push_back('1');
        
        reverse(r.begin(), r.end());
        
        return r;
    }
    
    string multiplyChar(string &a, char b) {
        
        int t = b - '0';
        int carry = 0;
        string r;
        
        for (int i = a.size() - 1; i >= 0; i--) {
            int c = (a[i] - '0') * t + carry;
            carry = c / 10;
            c = c % 10;
            r.push_back(c + '0');
        }
        
        if (carry) r.push_back(carry + '0');
        
        reverse(r.begin(), r.end());
        
        return r;
    }
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num1 == "0" || num2 == "0") return string("0");
        string r;
        
        for (int i = num2.size() - 1; i >= 0; i--) {
            string t = multiplyChar(num1, num2[i]);
            r = add(r, t);
            num1.push_back('0');
        }
        
        return r;
    }
};