/*
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int i=1;
        int j=sizeof(nums)-1;
        int m=0;

        while (m!=k)
        {
            if(m<k)
                m=quickSort(nums,m,j);
            else if(m>k)
                m=quickSort(nums,i,m);

        }
        
        return nums[k];
    }
    int quickSort(vector<int>& nums,int i, int j){
        int curr=nums[0];
        while (i<j)
        {
            while(nums[i]<curr)
                i++;
            while(nums[j]>=curr)
                j--;
            swap(&nums[i],&nums[j]);
        }
        nums[i]=curr;
        return i;
    }
    


    void swap(int *a,int *b){
        int tmp=*a;
        *a=*b;
        *b=tmp;
    }

    void main(){
        vector<int> num;
        num.push_back(3);
        num.push_back(2);
        num.push_back(1);
        num.push_back(5);
        num.push_back(6);
        num.push_back(4);
        int res=findKthLargest(num,2);
    }

};