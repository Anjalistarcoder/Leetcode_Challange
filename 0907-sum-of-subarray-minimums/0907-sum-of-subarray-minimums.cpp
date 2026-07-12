#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long total_sum = 0;
        long long MOD = 1e9 + 7;
        
        // Stack will store indices of the elements
        stack<int> st;
        
        // We iterate from 0 to n inclusive to process remaining elements in the stack at the end
        for (int i = 0; i <= n; ++i) {
            // Use a dummy value of 0 at the end (i == n) to flush out all remaining elements
            int current_val = (i == n) ? 0 : arr[i];
            
            while (!st.empty() && arr[st.top()] > current_val) {
                int mid = st.top();
                st.pop();
                
                // Determine the boundaries
                int left_boundary = st.empty() ? -1 : st.top();
                int right_boundary = i;
                
                // Count of subarrays where arr[mid] is the minimum
                long long left_count = mid - left_boundary;
                long long right_count = right_boundary - mid;
                
                // Add to total contribution
                total_sum = (total_sum + left_count * right_count % MOD * arr[mid] % MOD) % MOD;
            }
            st.push(i);
        }
        
        return total_sum;
    }
};
