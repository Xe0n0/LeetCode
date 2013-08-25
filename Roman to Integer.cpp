//1. convert string to integers
//2. iterate over to plus or minus
class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> numbers;
        numbers.reserve(s.size());
        
        for (int i = 0; i < s.size(); i++) {
            switch(s[i]) {
                case 'I':
                    numbers.push_back(1);
                    break;
                case 'V':
                    numbers.push_back(5);
                    break;
                case 'X':
                    numbers.push_back(10);
                    break;
                case 'L':
                    numbers.push_back(50);
                    break;
                case 'C':
                    numbers.push_back(100);
                    break;
                case 'D':
                    numbers.push_back(500);
                    break;
                case 'M':
                    numbers.push_back(1000);
                    break;
                default:
                    break;
            }
        }
        
        int r = 0;
        
        for (int i = 0; i < numbers.size(); i++) {
            if (i + 1 < numbers.size() && numbers[i+1] > numbers[i])
                r -= numbers[i];
            else
                r += numbers[i];
        }
        
        return r;
    }
};