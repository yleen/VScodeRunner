/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        heapSort(nums);
        return nums;
    }
    //冒泡排序
    void BubbleSort(vector<int> &nums)
    {
        bool isOver = false;
        while (!isOver)
        {
            isOver = true;
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] < nums[i - 1])
                {
                    isOver = false;
                    swap(nums[i], nums[i - 1]);
                }
            }
        }
    }
    //选择排序
    void SelectSort(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int min = i;
            for (int j = i + 1; j < nums.size(); j++)
            {
                min = nums[j] < nums[min] ? j : min;
            }
            if (min != i)
                swap(nums[min], nums[i]);
        }
    }
    //插入排序
    void InsertSort(vector<int> &nums){
        for (int i = 0; i < nums.size(); i++)
        {
             int target=nums[i];
             int j=i-1;
             while (j>=0&&nums[j]>target)
             {
                 nums[j+1]=nums[j];
                 j--;
             }
             nums[j+1]=target;
             
        }
        
    }
    //快速排序
    void quickSort(vector<int>& nums,int start,int end){
        if(start >= end){
            return;
        }
        int pivor = rand() % (end - start + 1) + start;
        swap(nums[pivor], nums[end]);
        pivor = end;
        int left = start;
        int right = end;
        int curr_val = nums[pivor];
        while(left < right){
            while(left < right && nums[left] < curr_val){
                left++;
            }
            nums[right] = nums[left];
            while(left < right && nums[right] >= curr_val){
                right--;
            }
            nums[left] = nums[right];
        }

        nums[left] = curr_val;
        pivor = left;
        quickSort(nums, start, pivor - 1);
        quickSort(nums, pivor + 1, end);
    }
    //归并排序
    vector<int> tmp;
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) >> 1;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int i = l, j = mid + 1;
        int cnt = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[cnt++] = nums[i++];
            }
            else {
                tmp[cnt++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[cnt++] = nums[i++];
        }
        while (j <= r) {
            tmp[cnt++] = nums[j++];
        }
        for (int i = 0; i < r - l + 1; ++i) {
            nums[i + l] = tmp[i];
        }
    }

    //堆排序
    void heapSort(vector<int> &nums){
        for (int i = nums.size() / 2 - 1; i >= 0; i--)//?? 为啥要从中间开始
        {
            maxHeapify(nums, nums.size(), i);
        }

        for (int j = nums.size() - 1; j > 0; j--)
        {
            swap(nums[j], nums[0]);
            maxHeapify(nums, j, 0);
        }
        
        
    }


    void maxHeapify(vector<int> &nums,int heapSize,int rootIdx){
        int left = rootIdx * 2 + 1;
        int right = rootIdx * 2 + 2;
        int currIdx = rootIdx;
        if(left < heapSize && nums[left] > nums[currIdx]){
            currIdx = left;
        } 
        if(right < heapSize && nums[right] > nums[currIdx]){
            currIdx = right;
        } 
        if(currIdx != rootIdx){
            swap(nums[currIdx], nums[rootIdx]);
            maxHeapify(nums, heapSize, currIdx);
        }
    }

};
// @lc code=end
