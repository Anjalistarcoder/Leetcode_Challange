class Solution {
public:
    
    int countPartitions(vector<int>& nums, int maxSum) {
        int partitions = 1;
        long long currSum = 0;

        for(int num : nums) {
            if(currSum + num <= maxSum) {
                currSum += num;
            }
            else {
                partitions++;
                currSum = num;
            }
        }

        return partitions;
    }

    int splitArray(vector<int>& nums, int k) {
        
        int low = *max_element(nums.begin(), nums.end());

        long long high = 0;
        for(int num : nums)
            high += num;

        while(low <= high) {

            long long mid = low + (high - low) / 2;

            int partitions = countPartitions(nums, mid);

            if(partitions <= k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};