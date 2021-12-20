
//官方的解答code
class Solution {
private:
    vector<vector<int>> f;
    vector<vector<string>> ret;
    vector<string> ans;
    int n;

public:
    void dfs(const string& s, int i) {
        if (i == n) {
            ret.push_back(ans);
            return;
        }
        for (int j = i; j < n; ++j) {
            if (f[i][j]) {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                //如果不pop_back， ans回越来越大。因此在递归 ret.push_back(ans);返回以后删除元素
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        f.assign(n, vector<int>(n, true));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }

        dfs(s, 0);
        return ret;
    }
};



// 步骤：
// 1. 使用深度搜索 找出s中的每一个子串
// 2. 在找出的子串中判断其是否是回文字符串

class Solution {
    vector<vector<string>> result;
    vector<string> ans;
    int n; // the length of target string
public:
    // 使用双指针判断是否是回文
    bool isPal(string &s) {
        int size = s.size();

        int left = 0;
        int right = size -1;
        while(left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void dfs(string &s, int left_index) {
        if (left_index >= n) {
            result.push_back(ans);
            return;
        }

        //这个长度len， 也就是深度搜索每次递归深度的步进值
        /* 以aab 为例:
         * 1st dfs:
                len = 1; left_index = 0 --> a
                判断a是否是回文----> 是 -----> push 到ans中
                ----> 继续从 a的下一个 也就是第二个a为索引，开始递归dfs
                        len = 1; left_index = 1 --> a
                        判断a是否是回文----> 是 -----> push 到ans中
                        ----> 继续从 a的下一个 也就是第三个b为索引，开始递归dfs
                                len = 1; left_index = 2 --> b
                                判断b是否是回文----> 是 -----> push 到ans中
                                ----> 继续从 b的下一个，没有了，但还是调用dfs
                                        len = 1; left_index = 3 ---> left_index >= n(s的长度)
                                        ----> result.push_back(ans);
                                        返回
                                返回， 并且删除 b， 因为ans已经加入到result中， 没有必要在ans中存值
                                len = 2; left_index = 2 --> left_index +len > n, 此次搜索结束
                        返回， 并且删除 a， 理由同上
                        len = 2; left_index = 1 --> ab
                        判断ab是否是回文----> 否 -----> 跳过
                        len = 3; left_index = 1 --> left_index +len > n, 此次搜索结束
                返回 ，并且删除 a

                len = 2, left_index = 0 --> aa
                判断aa是否是回文----> 是 -----> push 到ans中
                ----> 继续从 第一个a的下一个的下一个(len 为2) 也就是第二个b为索引，开始递归dfs

                len = 3. left_index = 0 ---> aab
                判断aa是否是回文----> 不是 -----> 跳过

                len = 4. left_index = 0 ----> left_index +len > n, 搜索结束
         */

        for(int len = 1; left_index + len <= n ;len++) {
            string subs = s.substr(left_index, len);
            if (isPal(subs)) {
                ans.push_back(subs);
                dfs(s, left_index + len);
                ans.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        dfs(s, 0);
        return result;
    }
};


class Solution {
    vector<vector<string>> result;
    vector<string> ans;
    int n; // the length of target string
    vector<vector<int>> dp;
public:
    // 使用动态规划判断是否是回文
    bool isPal(int left, int right) {
        return dp[left][right];
    }

    void dfs(string &s, int left_index) {
        if (left_index >= n) {
            result.push_back(ans);
            return;
        }

        for(int len = 1; left_index + len <= n ;len++) {
            if (isPal(left_index, left_index + len - 1)) {
                string subs = s.substr(left_index, len);
                ans.push_back(subs);
                dfs(s, left_index + len);
                ans.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        n = s.size();

        //对dp进行初始化处理
        dp.assign(n, vector<int>(n, true));

        for (int i = n-1; i >=0 ; --i) {
            for(int j = i+1; j < n;++j) {
                dp[i][j] = s[i] == s[j]  && dp[i+1][j-1];
            }
        }

        dfs(s, 0);
        return result;
    }
};
