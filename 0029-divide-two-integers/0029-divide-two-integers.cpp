class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;

        long long dd = llabs((long long)dividend);
        long long dv = llabs((long long)divisor);

        long long ans = 0;

        while (dd >= dv) {
            long long sum = dv;
            long long count = 1;

            while ((sum << 1) <= dd) {
                sum <<= 1;
                count <<= 1;
            }

            dd -= sum;
            ans += count;
        }

        if ((dividend < 0 && divisor > 0) ||
            (dividend > 0 && divisor < 0))
            ans = -ans;

        return (int)ans;
    }
};