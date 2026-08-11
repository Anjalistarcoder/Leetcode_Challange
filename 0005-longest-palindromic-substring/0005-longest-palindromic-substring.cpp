class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxLength = 1;
        
        for (int i = 0; i < s.length(); i++) {
            // Case 1: Odd-length palindromes (e.g., "aba", center is 'b')
            expandAroundCenter(s, i, i, start, maxLength);
            
            // Case 2: Even-length palindromes (e.g., "abba", center is between 'b' and 'b')
            expandAroundCenter(s, i, i + 1, start, maxLength);
        }
        
        return s.substr(start, maxLength);
    }

private:
    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLength) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            int currentLength = right - left + 1;
            
            if (currentLength > maxLength) {
                maxLength = currentLength;
                start = left;
            }
            left--;
            right++;
        }
    }
};
