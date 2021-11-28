#ifdef TW_SUM_CPP
#include <iostream>
#include <array>
#include <vector>
#include <unordered_map>

//时间复杂度 O(n2)
std::vector<int> two_sum(std::vector<int>& nums, int target)
{
    int size = nums.size();

    for(int i = 0; i < size-1; i++) {
        for(int j = i + 1; j < size; j++) {
            if (target == nums[i] + nums[j]) {
                return {i, j};
            }
        }
    }

    return {};
}

// hash table O(n)
std::vector<int> two_sum_hash(std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> hashtable;

    for(int i = 0; i < nums.size(); i++) {
       auto it = hashtable.find(target - nums[i]);
       if (it != hashtable.end()) {
           return {it->second, i};
       }
       //先把前面得元素放进hashtable，
       //一旦找到第二个元素，第一个肯定已经在hashtable中
       hashtable[nums[i]] = i;
    }

    return {};
}

int main(void)
{
    std::vector<int> nums1 {2, 7, 11, 15};
    std::vector<int> nums2 {3, 2, 4};
    int target1 = 9;
    int target2 = 6;
    std::vector<int> ret1 = two_sum(nums1, target1);
    std::cout << ret1[0] << "," << ret1[1] << std::endl;
    std::vector<int> ret2 = two_sum_hash(nums2, target2);
    std::cout << ret2[0] << "," << ret2[1] << std::endl;
    getchar();
    return 0;
}
#endif //TW_SUM_CPP
