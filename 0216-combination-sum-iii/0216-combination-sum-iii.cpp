class Solution {
private:
    vector<vector<int>> ans;
    vector<int> t;

    void dfs(int start, int k, int n) {
        if (n == 0 && t.size() == k) {
            ans.push_back(t);
            return;
        }
        if (n < 0 || t.size() > k || start > 9) {
            return;
        }
        
        for (int i = start; i <= 9; ++i) {
            t.push_back(i);
            dfs(i + 1, k, n - i);
            t.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        t.clear();
        dfs(1, k, n);
        return ans;
    }
};
