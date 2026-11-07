
class Solution {
public:

    bool isPalindrome(string str) {
        int left = 0;
        int right = str.size() - 1;

        while(left < right) {
            if(str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }

    void solve(int index, string s, vector<string>& ds, vector<vector<string>>& ans) {

        if(index == s.size()) {
            ans.push_back(ds);
            return;
        }

        for(int i = index; i < s.size(); i++) {

            string part = s.substr(index, i - index + 1);

            if(isPalindrome(part)) {

                ds.push_back(part);

                solve(i + 1, s, ds, ans);

                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> ds;

        solve(0, s, ds, ans);

        return ans;
    }
};
