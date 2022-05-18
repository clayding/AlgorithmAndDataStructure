
class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int total = 0;
        for(auto& num:nums)
            total += num;

        int sum = 0;
        // left_sum = right_sum = total - left_sum - num[i]
        // sum = total -sum -num[i]
        // 2sum + num[i] = total
        for (int i = 0; i < nums.size(); ++i) {
            if (2 * sum + nums[i] == total) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};

//leetcode
class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (2 * sum + nums[i] == total) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};


// 会超时
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_memo(n, INT_MAX);
        vector<int> right_memo(n, INT_MAX);
        
       for(int i = 0; i < n; i++) {
           int left_sum = 0;
           if (i != 0) {
                for(int j = 0; j < i;j++) {
                    if (left_memo[j] != INT_MAX) {
                        left_sum = left_memo[j];
                        continue;
                    }
                    left_sum += nums[j];
                    left_memo[i-1] = left_sum;

                }
            }
           int right_sum = 0;
           if (i != n -1) {
                for(int j = i+1; j < n;j++) {
                    if (right_memo[j] != INT_MAX) {
                        right_sum = right_memo[j];
                        continue;
                    }
                    right_sum += nums[j];
                }
            }
           if (left_sum == right_sum) {
               return i;
           }
       }
        
        return -1;
    }
};
// 最简单的暴力
class Solution {
public:
    int pivotIndex(vector<int> nums) {

        for(int i=0;i<nums.size();i++){
        	int left = 0;
        	int right = 0;
        	for(int j=0;j<i;j++){
        		left+=nums[j];
        	}
        	for(int j=i+1;j<nums.size();j++){
        		right+=nums[j];
        	}
        	
        	if(left == right){
        		return i;
        	}
        }
        return -1;
	}
};