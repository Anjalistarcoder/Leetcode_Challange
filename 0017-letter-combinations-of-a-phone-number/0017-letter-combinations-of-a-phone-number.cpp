class Solution {
public:
    void solve(string digits, string output, int index,
               vector<string>& ans, string mapping[]) {

        // Base case
        if (index == digits.length()) {
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];

        for (int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);
            solve(digits, output, index + 1, ans, mapping);
            output.pop_back(); // backtracking
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;

        if (digits.empty())
            return ans;

        string output = "";

        string mapping[10] = {
            "",      // 0
            "",      // 1
            "abc",   // 2
            "def",   // 3
            "ghi",   // 4
            "jkl",   // 5
            "mno",   // 6
            "pqrs",  // 7
            "tuv",   // 8
            "wxyz"   // 9
        };

        solve(digits, output, 0, ans, mapping);

        return ans;
    }
};