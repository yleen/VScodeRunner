/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        srand(time(NULL));
        QuickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void QuickSort(vector<int> &nums, int start, int end)
    {
        if (start < end)
        {
            int index = randomIndex(nums, start, end);
            QuickSort(nums, start, index - 1);
            QuickSort(nums, index + 1, end);
        }
    }

    int randomIndex(vector<int> &nums, int start, int end)
    {
        int index = rand() % (end - start + 1) + start;
        swap(nums[index], nums[end]);
        return partition(nums, start, end);
    }

    int partition(vector<int> &nums, int start, int end)
    {
        int target = nums[end];
        while (start < end)
        {
            while (start < end && nums[start] < target)
                start++;
            nums[end] = nums[start];
            while (start < end && nums[end] >= target)
                end--;
            nums[start] = nums[end];
        }

        nums[start] = target;

        return start;
    }
};
// @lc code=end
