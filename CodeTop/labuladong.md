[labuladong的算法小抄](https://labuladong.gitbook.io/algo/)
# 手把手链表
## 递归反转链表的一部分
LeetCode 相关：92
## k个一组反转
LeetCode 相关：25
## 回文链表
LeetCode 相关：234
# 手把手二叉树
## 一
```C++
/* 二叉树遍历框架 */
void traverse(TreeNode root) {
    // 前序遍历
    traverse(root.left)
    // 中序遍历
    traverse(root.right)
    // 后序遍历
}
```
### 二叉树的重要性
我们的经典算法「快速排序」和「归并排序」，对于这两个算法，你有什么理解？如果你告诉我，快速排序就是个二叉树的前序遍历，归并排序就是个二叉树的后序遍历，那么我就知道你是个算法高手了。
快速排序的代码框架如下：
```C++
void sort(int[] nums, int lo, int hi) {
    /****** 前序遍历位置 ******/
    // 通过交换元素构建分界点 p
    int p = partition(nums, lo, hi);
    /************************/

    sort(nums, lo, p - 1);
    sort(nums, p + 1, hi);
}
```
先构造分界点，然后去左右子数组构造分界点，你看这不就是一个二叉树的前序遍历吗？
再说说归并排序的逻辑，若要对 nums[lo..hi] 进行排序，我们先对 nums[lo..mid] 排序，再对 nums[mid+1..hi] 排序，最后把这两个有序的子数组合并，整个数组就排好序了。
归并排序的代码框架如下：
```C++
void sort(int[] nums, int lo, int hi) {
    int mid = (lo + hi) / 2;
    sort(nums, lo, mid);
    sort(nums, mid + 1, hi);

    /****** 后序遍历位置 ******/
    // 合并两个排好序的子数组
    merge(nums, lo, mid, hi);
    /************************/
}
```
先对左右子数组排序，然后合并（类似合并有序链表的逻辑），你看这是不是二叉树的后序遍历框架？另外，这不就是传说中的分治算法嘛，不过如此呀。

### 实践

#### [226. 翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/)

