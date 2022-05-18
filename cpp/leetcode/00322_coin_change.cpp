//DFS 按照官方的code写的
//自顶向下
class Solution {
    vector<int> count;
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        count.resize(amount, 0);
        return dp(coins, amount);
    }

    int dp(vector<int>& coins, int rem) {

        if (rem == 0) {
            return 0;
        }

        if (rem < 0) {
            return -1;
        }
        //cout << "rem=" << rem <<  " count[rem -1]:" << count[rem -1] <<endl;
        if (count[rem -1] != 0) return count[rem-1];

        int Min = INT_MAX;
        for(auto& coin:coins) {
            int g = rem - coin;
            int res = dp(coins, g);

            if (res >= 0 && res < Min) {
                Min = res + 1;
            }
        }

        count[rem-1] = Min == INT_MAX? -1:Min;
        return count[rem-1];
    }
};

//动态规划注释版
//自底向上
class Solution {
    public int coinChange(int[] coins, int amount) {
        if(amount == 0) return 0;
        if(amount <= 0) return -1;
        return coindp(coins,amount);
    }

    //状态：金额      
    //转移：一个硬币，这个硬币的金额在coins[]数组中遍历   
    //dp函数：输入金额，返回最少硬币数
    public int coindp(int[] coins, int amount){
        int[] dp = new int[amount+1];//最多的硬币情况是全部是1元，共有amount个硬币，共有amount+1个状态，amount+1个金额
        Arrays.fill(dp, amount+1);//必须将所有的dp赋最大值，因为要找最小值
        dp[0] = 0;//自底向上，金额为0，最小硬币数为0
        int[] mem = dp;
        for(int am = 1; am <= amount; am++){//自底向上
            for(int coin : coins){//遍历coins的金额
                if(am >= coin)//am-coin 必须大于0，否则数组溢出
                    dp[am] = Math.min(dp[am], dp[am-coin] + 1);//金额为11的最小硬币数 和 金额为(11-一个面值)的最小硬币数+1 比较最小值
            } 
        }
        return dp[amount]>amount? -1: dp[amount];//返回金额为amount的最小硬币数 根据测试用例判断dp[amout]>amount
    }
}

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 为什么 用到这一个？如果硬币全是1元， 则最多有amount个硬币。
        //而dp的状态是从0开始的， 也就是0到amount个硬币共amount + 1个状态
        int MAX = amount +1;
        vector<int> dp(amount + 1, MAX); //为什么amount + 1？要用到dp[amount], 因此要加1

        dp[0] = 0;
        for(int i  = 1; i < dp.size();i++) {
            for(auto& coin: coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] +1);
                }
            }
        }

        return dp[amount] > amount ? -1:dp[amount];
    }
};

//超出时间限制
class Solution {
    vector<int> count;
public:
    int coinChange(vector<int>& coins, int amount) {
        //自顶向下, DFS
        count.resize(amount + 1, -1);
        return dp(coins, amount);
    }

    int dp(vector<int>& coins, int remain) {
        if (remain < 0) {
            return -1;
        }

        if (remain == 0) {
            return 0;
        }

        for(int i = 0; i < coins.size(); i++) {
            int rem = remain - coins[i];
            int res = dp(coins, rem);

            if (res < 0) {
                continue;
            }

            count[remain] = res + 1;
        }

        return count[remain];
    }
};

//2022/01/24
class Solution {
    vector<int> count;
public:
    int coinChange(vector<int>& coins, int amount) {
        count.resize(amount + 1, 0);
        return dp(coins, amount);
    }

    int dp(vector<int>& coins, int remi) {
        
        if (remi < 0) {
            return -1;
        }

        if (remi == 0) {
            return 0;
        }

        if (count[remi] != 0) return count[remi];

        int MIN = INT_MAX;
        for(auto &coin:coins) {
            int remain = remi - coin;
            int res = dp(coins, remain);

            if (res >= 0 && res < MIN) {
                MIN = res + 1;
            }
        }

        count[remi] = MIN == INT_MAX ? -1: MIN;

        return count[remi];
    }
};

//还是不太熟悉
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, amount + 1);
        
        dp[0] = 0;
        for(int i = 1; i < amount + 1; i++) {
            for(auto &coin: coins) {
                if (i >= coin)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] > amount ? -1:dp[amount];
    }
};
