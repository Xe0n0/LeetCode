//1. Roman is basically added up by digits, build it part by part
class Solution {
private:
    string romanAt(int num, int base, char one, char five, char ten) {
        
        string roman;
        
        int c = num / base;
        c %= 10;
        
        if (c >= 5 && c <= 8 || c <= 3) {
            if (c >= 5) {
                roman.push_back(five);
                c -= 5;
            }
            
            while (c--) {
                roman.push_back(one);
            }
        }
        else if (c == 4) {
            roman.push_back(one);
            roman.push_back(five);
        }
        else if (c == 9) {
            roman.push_back(one);
            roman.push_back(ten);
        }
        
        return roman;
    }
    
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string roman;
        

        roman.append(romanAt(num, 1000, 'M', 'Z', 'Z'));
        roman.append(romanAt(num, 100, 'C', 'D', 'M'));
        roman.append(romanAt(num, 10, 'X', 'L', 'C'));
        roman.append(romanAt(num, 1, 'I', 'V', 'X'));
        
        return roman;
    }
};