
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, long long> mp;

        mp[0] = 1;

        int prefix = 0;
        long long ans = 0;

        for(int i = 0; i < nums.size(); i++) {

            prefix = prefix ^ nums[i];

            ans += mp[prefix];

            mp[prefix]++;
        }

        return ans;
    }
};
