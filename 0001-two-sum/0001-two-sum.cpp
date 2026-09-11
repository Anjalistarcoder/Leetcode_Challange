class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int a=target-nums[i];
            if (mp.find(a)!=mp.end()){
                int j=mp[a];
                ans.push_back(i);
                ans.push_back(j);
            }
            else{
                mp[nums[i]]=i;
            }
        }
        return ans;
    }
};