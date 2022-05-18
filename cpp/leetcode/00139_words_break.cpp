//看官方的解答写的, 动态规划

/*  s 串能否分解为单词表的单词（前 s.length 个字符的 s 串能否分解为单词表单词）
    将大问题分解为规模小一点的子问题：
        前 i 个字符的子串，能否分解成单词
        剩余子串，是否为单个单词。
    dp[i]：长度为i的s[0:i-1]子串是否能拆分成单词。题目求:dp[s.length]

状态转移方程
    类似的，我们用指针 j 去划分s[0:i] 子串，如下图：
    s[0:i] 子串对应 dp[i+1] ，它是否为 true（s[0:i]能否 break），取决于两点：
        它的前缀子串 s[0:j-1] 的 dp[j]，是否为 true。
        剩余子串 s[j:i]，是否是单词表的单词。
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();

        unordered_set<string> sset;
        for(auto& word:wordDict) {
            sset.insert(word);
        }

        vector<bool> dp(size, false);
        dp[0] = true;

        //dp[i] = dp[j] && s[j, i-1]
        /* 为什么 i = 1 开始？
         * 答：因为dp[i] 代表的s[0:i-1], 而s[0, 0] 已经确定 也就等于s[0, -1] (当i = 0),
         * 因此从 i = 1 开始. 同理  i == size 也就代表了 s[0, size -1] 
         * 
         * 那为什么j = 0 开始？ 因为在转移方程中 我们用 指针 j 去划分s[0:i], 
         * 也就是把s[0:i] 划分为 s[0:j-1] 和 s[j:i]，其中s[0:j-1]也就是dp[j],
         * s[j:i] 就是下面获取的子串 s.substr(j, i-j)
         * */
        for(int i = 1; i <= size;i++) {
            for(int j = 0; j < i;j++) {
                if (dp[j] && sset.find(s.substr(j, i-j)) != sset.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[size];
    }
};

// DFS
class Solution {
    unordered_set<string> myset;
    int n;
    array<int, 301> memo;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        memo.fill(-1);
        for(auto& word: wordDict) {
            myset.insert(word);
        }

        return canBreak(s, 0);
    }

    //  |------------------|-------------|
    //start                i             n
    //  0
    // 判断整个区间 0-n 能分割成特定子字符串， 也就是判断start =0 时 [start:i-1] 和[i-n]
    // 是不是特定字符串中的。其中当start == n ---> i 从start+ 1开始， 而[start:i-1] ---> s[n:n] 是空 也就返回true
    bool canBreak(string& s, int start) {
        if (start == n) {
            return true;
        }

        if (memo[start] != -1) return memo[start];

        // i 就是右边界，依次往右移动
        for(int i = start + 1; i <= n; i++) {
            string s1 = s.substr(start, i - start);
            if (myset.find(s1) != myset.end() && canBreak(s, i)) {
                memo[start] = 1;
                return true;
            }
        }

        memo[start] = 0;
        return false;
    }
};


// BFS
class Solution {
    unordered_set<string> myset;
    int n;
    queue<int> myq;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        array<int, 301> visited;
        visited.fill(0);
        n = s.size();

        for(auto& word: wordDict) {
            myset.insert(word);
        }
        myq.push(0);

        while (!myq.empty()) {
            int start = myq.front();
            myq.pop();

            if(visited[start]) continue;
            visited[start] = 1;
            // i 就是右边界
            for(int i = start + 1; i <= n;i++) {
                const string s1 = s.substr(start, i - start);
                if (myset.find(s1) != myset.end()) {
                    if (i < n) {
                        myq.push(i);
                    } else {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

// 动态规划 再来一次
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        unordered_set<string> wset;

        for(auto word:wordDict) {
            wset.insert(word);
        }

        vector<bool> dp(size + 1, false); 
        dp[0] = true;
        for(int i = 1; i <= size; i++) {
            for(int j = 0; j < i; j++ ) {
                string ss = s.substr(j, i - j);
                if(dp[j] && wset.find(ss) != wset.end()) {
                    dp[i] = true; 
                }
            }
        }

        return dp[size];
    }
};
