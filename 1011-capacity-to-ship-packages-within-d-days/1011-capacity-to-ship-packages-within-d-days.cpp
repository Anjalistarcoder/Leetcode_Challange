class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int day = 1;
        int load = 0;

        for (int weight : weights) {
            if (load + weight <= capacity) {
                load += weight;
            } else {
                day++;
                load = weight;
            }
        }

        return day <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canShip(weights, days, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};