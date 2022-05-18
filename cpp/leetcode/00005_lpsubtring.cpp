#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

#ifdef LPSUBTRING

//比较啰嗦的方法
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int size = s.size();
        char *pbegin = s.data();
        int max_size = 0;
        int x = 0;
        int y = 0;

        for (int i = x; i < size;i++) {
            for (int j = size-1; j > i;j--) {
                if (pbegin[i] != pbegin[j]) {
                    continue;
                }

                // 找到 pbegin[i] == pbegin[j]
                int dsize = j - i;
                std::cout << i << j << dsize << std::endl;
                int m = 0;
                for (; m < (dsize + 1) /2; m++) {
                    if (pbegin[i+m] != pbegin[j-m]) {
                        //但凡有不相等的  直接break
                        break;
                    }
                }

                if (m == (dsize + 1)/ 2) {
                    if (max_size < dsize ) {
                        x = i;
                        y = j;
                        max_size = dsize;
                    }
                }
            }
        }
        return s.substr(x, y -x + 1);
    }
};

//改良版
class Solution2 {
public:
    std::string longestPalindrome(std::string s) {
        int size = s.size();
        char *p = s.data();
        int max_size = 0;
        int x = 0;
        int y = 0;

        for (int i = x; i < size;i++) {
            for (int j = size-1; j > i;j--) {
                if (p[i] != p[j]) {
                    continue;
                }

                // 找到 p[i] == p[j]
                int dsize = j - i;
                //for ()
            }
        }
        return s.substr(x, y -x + 1);
    }
};

// 对于长串超出时间限制的方法，因此需要动态规划
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int begin = 0, end = 0;
        int min_length = 0;

        for(int L=1;L <= n;L++) {
            for(int left = 0;left <= n-1;left++) {
                int right = left+L-1;
                if(right >= n) {
                    continue;
                }

                string ss = s.substr(left, L);
                if (isPal(ss)) {
                    if(L > min_length) {
                        min_length = L;
                        begin = left;
                        end = right;
                    }
                }
            }
        }

        return s.substr(begin, end-begin+1);
    }

    bool isPal(string& s) {
        int size = s.size();
        int left = 0;
        int right = size -1;

        while(left <= right) {
            if(s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};


//动态规划 1, 这个和动态规划2的方法有异曲同工
class Solution3 {
public:
    std::string longestPalindrome(std::string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        std::vector<std::vector<int>> dp(n, std::vector<int>(n)); //dp 就是dynamic planning
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++) {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n) {
                    break;
                }

                if (s[i] != s[j]) { // 根据状态转移方程: P(i,j)=P(i+1,j−1)∧(Si​ ==Sj​ ), 只要 (Si​ !=Sj​ ) 则P(i,j) 不相等
                    dp[i][j] = false;
                } else { //如果 s[i] == s[j]
                    if (j - i < 3) { // j -i < 3 也就是 j -i + 1 < 3 + 1,字串最大长度为3 ( < 4)，除去Si 和Sj 最多还有1个. 比如bab 因此肯定是回文子串
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];// 根据状态转移方程 P(i,j)=P(i+1,j−1)∧(Si​ ==Sj​ )
                        std::cout << "(" << i << " " << j << ") = [" << i+1 << " " << j-1 << "]" << std::endl;
                    }
                }
                std::cout << "(" << i << " " << j << ") = " <<  dp[i][j] << std::endl;

                // 只要 dp[i][j] == true 成立，就表示子串 s[i..j] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) { //这里也可以写成 if (dp[i][j] && L > maxLen) {
                    maxLen = j - i + 1;               // 同样，这里也可以写成 maxLen = L;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};


//中心扩散
class Solution {
public:
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        int start = 0, end = 0;
        for(int i = 0; i < size ; i++) {
            auto [left1, right1] = count(s, i, i);
            auto [left2, right2] = count(s, i, i + 1);

            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }

        return s.substr(start, end - start + 1);
    }

    pair<int, int> count(const string& s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right] ) {
            --left;
            ++right;
        }

        return {left+1, right-1};
    }
};

//once again 中心扩散
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int max_left = 0, max_right = 0;
        for(int i = 0; i < n ;i++) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i+1);

            int max1 = right1 - left1;
            int max2 = right2 - left2;
            int max = max_right - max_left;
            if (max1 > max) {
                max_right = right1;
                max_left  = left1;
            }

            if (max2 > max) {
                max_right = right2;
                max_left  = left2;
            }
        }

        return s.substr(max_left, max_right - max_left + 1);
    }

    pair<int, int> expandAroundCenter(string &s, int left, int right) {
        int n = s.size();
        while(left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }

        return {left + 1, right - 1}; //容易犯错
    }
};

// 动态规划 2; 这个和动态规划1的方法有异曲同工
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;
        int n = s.size();

        if (n <= 1) {
            return s;
        }
        vector<vector<bool>> dp(n, vector<bool>(n));

        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        //这个在做的时候注意i和j的顺序，一开始写的是for(int i = 0; i < n;i--)
        //但是这样有个问题 比如i = 0; j = 3; dp[0][3] = dp[1][2]
        //也就是 dp的i低数字 取决于i的高数字， 因此必须先把i高数字的计算出来，也就是
        //计算dp[0][x] 需要计算出来 dp[1][x-1]
        for(int i = n -1; i >= 0;i--) {
            for(int j = n - 1; j >= i ;j--) {
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j -i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                //cout << " i=" << i << " j=" << j << " dp:" << dp[i][j] << endl;
                if (dp[i][j] && j - i + 1 > maxLen) {
                    //cout << "i=" << i << " j=" << j << " maxLen=" << maxLen << endl;
                    maxLen = j - i +1;
                    start = i;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};


//再次中心扩散
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, stop = 0;
        for(int i = 0; i < n; i++) {
            auto [begin1, end1] = expandAroundCenter(s, i, i);
            auto [begin2, end2] = expandAroundCenter(s, i, i+1);
            if(end1 - begin1 > stop - start) {
                stop = end1;
                start = begin1;
            }
            if(end2 - begin2 > stop - start) {
                stop = end2;
                start = begin2;
            }
        }

        return s.substr(start, stop -start + 1);
    }

    pair<int, int> expandAroundCenter(string s, int left, int right) {
        int n = s.size();
        while(left >=0 &&  right < n && left <= right) {
            if (s[left] != s[right]) {
                break;
            }
            left--;
            right++;
        }

        return {left+1, right-1};
    }
};

int main(void)
{
    std::string s1 {"ac"};
    std::string s2 {"a"};
    std::string s3 {"cbbd"};
    std::string s4 {"babad"};
    std::string s5 {"aacabdkacaa"};
    // std::string s2 {"bbbbb"};
    // std::string s3 {"pwwkew"};
    // std::string s4 {""};
    Solution4 sol;
    /* std::cout << sol.longestPalindrome(s1) << std::endl;
    std::cout << sol.longestPalindrome(s2) << std::endl;
    std::cout << sol.longestPalindrome(s3) << std::endl;
    std::cout << sol.longestPalindrome(s4) << std::endl; */
    std::cout << sol.longestPalindrome(s5) << std::endl;
    getchar();
    return 0;
}

#endif /* LPSUBTRING */
