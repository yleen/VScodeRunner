/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array
 * [medium]
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
// 快排思想 快速选择
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        srand(time(NULL));
        return quickFind(nums, n - k, start, end); //****注意是n-k
    }

    int quickFind(vector<int> &nums, int k, int start, int end)
    {
        int pivot = rand() % (end - start + 1) + start; //使用随机索引可以将期望降低到O(n)
        swap(nums[pivot], nums[end]);                       //这里其实是  end指向的值是比标志位大 但不一定就是最终位置 所以每次需要将他回归到待排数列中  此时标志位位于end位置
        pivot = end;
        int cur_val = nums[pivot];
        int left = start, right = end - 1;

        if (start == end && start == k)
        {
            return nums[start];
        } //*****注意别丢了

        while (left < right)
        {
            while (left < right && nums[left] < cur_val)//这里是While!!!多次写成if
            {
                left++;
            }

            while (left < right && nums[right] >= cur_val)
            { //*****注意大于等于
                right--;
            }

            if (left < right)
            {
                swap(nums[left], nums[right]);
            }
        }
        if (nums[right] < cur_val)
            left = end;                //特殊情况，当标志值比其他都大时  可能会产生left一直移动到right  第二个while没有执行。 此时直接将left设到end
        swap(nums[pivot], nums[left]); //这一步是把标志位从end回归到排序后确定的位置
        pivot = left;
        if (pivot == k)
            return nums[pivot];
        return pivot > k ? quickFind(nums, start, pivot - 1, k) : quickFind(nums, pivot + 1, end, k);
    }
};

//堆排序 法一：大根堆
//该方法思路为 先进行堆排序，然后将排序过的顶点一个个删除  直到k为止

class Solution2
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int heapsize = nums.size();
        buildMaxHeap(nums, heapsize);

        for (int i = nums.size() - 1; i >= nums.size() - k + 1; i--)
        {
            swap(nums[0], nums[i]);
            --heapsize;
            SiftDownRecursive(nums, 0, heapsize);
        }

        return nums[0];
    }

    void buildMaxHeap(vector<int> &nums, int heapsize)
    {
        int length = nums.size();
        for (int i = length / 2; i >= 0; i--)
        {
            SiftDownRecursive(nums, i, heapsize);
        }
    }
    /*
[4:27 PM] Zhongyuan Li
    而且你这个函数的命名，假如真的是SiftDown操作的话
​[4:27 PM] Zhongyuan Li
    可以命名成SiftDownRecur或者SiftDownRecursive
​[4:27 PM] Zhongyuan Li
    这样，你看到Recur，就知道发生递归了。逻辑上也就清楚哪些是终止条件，哪些是递归体
*/
    void SiftDownRecursive(vector<int> &nums, int i, int heapsize)
    { //
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int curr = i;
        if (left < heapsize && nums[left] > nums[curr])
        {
            curr = left; //要注意一点 当这里执行后  curr已经是left了  下面的比较其实是两个子节点值的比较
        }
        if (right < heapsize && nums[right] > nums[curr])
        {
            curr = right;
        }

        if (curr != i)
        {
            swap(nums[curr], nums[i]);
            SiftDownRecursive(nums, curr, heapsize);
        }
    }
    //迭代创建堆
    void siftDown(vector<int> &heap, int i, int heapSize)
    {
        while (2 * i + 1 < heapSize)
        {
            int j = 2 * i + 1;
            if (j + 1 < heapSize && priorityThan(heap[j + 1], heap[j]))
            {
                j++;
            }
            if (priorityThan(heap[i], heap[j]))
            {
                break;
            }
            swap(heap[i], heap[j]);
            i = j;
        }
    }
    bool priorityThan(int v1, int v2) { return v1 > v2; }
};

//堆排序  法二
//使用小根堆 建立k个节点的小根堆，然后依次加入剩余的数组值，遍历完毕后顶点为第k大的数
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // 对前k个元素建成小根堆
        for (int i = 0; i < k; i++)
        {
            siftUp(nums, i);
        }
        // 剩下的元素与堆顶比较，若大于堆顶则去掉堆顶，再将其插入
        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > nums[0])
            {
                swap(nums[0], nums[i]);
                siftDown(nums, 0, k);//注意这个k
            }
        }
        // 结束后第k个大的数就是小根堆的堆顶
        return nums[0];
    }

private:
    // 若v1比v2优先度高，返回true
    bool priorityThan(int v1, int v2) { return v1 < v2; }

    // 上浮 从下到上调整堆
    void siftUp(vector<int> &heap, int i)
    {
        while (i > 0 && priorityThan(heap[i], heap[(i - 1) / 2]))
        {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // 下沉 从上到下调整堆
    void siftDown(vector<int> &heap, int i, int N)
    {
        while (2 * i + 1 < N)
        {
            int j = 2 * i + 1;
            if (j < N && priorityThan(heap[j + 1], heap[j]))
            {
                j++;
            }
            if (priorityThan(heap[i], heap[j]))
            {
                break;
            }
            swap(heap[i], heap[j]);
            i = j;
        }
    }
};
// @lc code=end

