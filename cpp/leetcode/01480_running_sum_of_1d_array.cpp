//自己写的
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> dsum;

        int i = 0;
        for(auto& nu:nums) {
            if (i == 0)
                dsum.push_back(nu);
            else
                dsum.push_back(dsum[i-1] + nu);
            i++;
        }

        return dsum;
    }
};

//官方的更简洁
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i-1];
        }

        return nums;
    }
};
