class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0;
        int max_element=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                c++;
            }
            else{
                c=0;
            }
            max_element=max(c,max_element);
        }
        return max_element;
    }
};