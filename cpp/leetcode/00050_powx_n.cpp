//根据官方解析写的code
class Solution {
public:

    double posPow(double x, long long n) {
        if (n > 0) {
            // 当n为偶数 2^n = 2^(n/2) * 2^(n/2);
            // 当n为奇数 2^n = 2^(n/2) * 2^(n/2) * 2;
            double subx = myPow(x, n/2);
            return n % 2 == 0? subx*subx : subx*subx*x;
        }

        return 1.0; //当n等于0
    }

    double myPow(double x, int n) {
        if (n >= 0) {
            return posPow(x, n);
        }

        //当n < 0
        long long ln = n;
        return 1.0 / posPow(x, -ln);
    }
};
