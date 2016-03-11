class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<int> r = digits;

        int carry = 1;

        int n = digits.size();

        assert (n > 0);

        for (int i = n - 1; i >= 0; --i) {
        	if (carry == 0) break;

        	r[i] += carry;

        	carry = r[i] / 10;
        	r[i] %= 10;
        }

        if (carry) r.insert(r.begin(), 1);

        return r;
    }
};