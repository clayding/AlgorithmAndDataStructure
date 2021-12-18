//思路比较简单  但是实现比较复杂的
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> index;
        int index_pos = 0;
        vector<int> result;

        if (size == 0) { return result; }

        for (auto i = 0; i < size; i++) {
            index.push_back(i);
            if (index.size() >= k + index_pos) {
                int max = nums[index[index_pos]];
                for (int j = index_pos;j < k + index_pos; j++) {
                    int pos = index[j];
                    if (nums[pos] > max) {
                        max = nums[pos];
                    }
                }
                index_pos++;
                result.push_back(max);
            }
        }

        return result;
    }
};



// 使用优先队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();

        //最大值问题我们可以采用大顶堆，具体就是维护一个大顶堆
        priority_queue<pair<int, int>> myqueue;

        //初始的时候将0～k-1的元素加入堆中，存入的是值和索引的键值队
        int count = 0;
        for (auto& num: nums) {
            myqueue.emplace(num, count++);
            if (count > k - 1) {
                break;
            }
        }

        //把堆对顶的最大元素 放入res
        vector<int> res = {myqueue.top().first};

        //然后滑动窗口从从索引为k的元素开始遍历，将新进入滑动窗口的元素加堆中
        for(int i = count; i < size; i++) {
            myqueue.emplace(nums[i], i);
            //当堆顶元素不在滑动窗口中的时候，不断删除堆顶元素，直到最大值在滑动窗口里
            while(myqueue.top().second <= i -k) {
                myqueue.pop(); //删除对顶元素
            }

            res.push_back(myqueue.top().first);
        }

        return res;
    }
};

