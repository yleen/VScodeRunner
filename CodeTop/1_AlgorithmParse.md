# 在实际开发中，为什么快速排序要比堆排序性能好

我觉得主要有两方面的原因。

**第一点，堆排序数据访问的方式没有快速排序友好。**

对于快速排序来说，数据是顺序访问的。而对于堆排序来说，数据是跳着访问的。 比如，堆排序中，最重要的一个操作就是数据的堆化。比如下面这个例子，对堆顶节点进行堆化，会依次访问数组下标是 1，2，4，81，2，4，8 的元素，而不是像快速排序那样，局部顺序访问，所以，这样对 CPU 缓存是不友好的。

<img src="https://i.loli.net/2021/05/18/2pKa3oDGhVqwnz6.png" alt="image.png"  />

**第二点，对于同样的数据，在排序过程中，堆排序算法的数据交换次数要多于快速排序。**

我们在讲排序的时候，提过两个概念，有序度和逆序度。对于基于比较的排序算法来说，整个排序过程就是由两个基本的操作组成的，比较和交换（或移动）。快速排序数据交换的次数不会比逆序度多。

但是堆排序的第一步是建堆，建堆的过程会打乱数据原有的相对先后顺序，导致原数据的有序度降低。比如，对于一组已经有序的数据来说，经过建堆之后，数据反而变得更无序了。

![image.png](https://i.loli.net/2021/05/18/HxFmXL3MfKCosue.png)

对于第二点，你可以自己做个试验看下。我们用一个记录交换次数的变量，在代码中，每次交换的时候，我们就对这个变量加一，排序完成之后，这个变量的值就是总的数据交换次数。这样你就能很直观地理解我刚刚说的，堆排序比快速排序交换次数多。
# 关于二叉树前序中序后序层序遍历使用的数据结构
前中后都用栈 层序用队列
前
```C++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> treeNum;
        if(root==nullptr)
            return treeNum;
        stack<TreeNode*> skNode;
        skNode.push(root);
        while(!skNode.empty()){
            TreeNode* node = skNode.top();skNode.pop();
            treeNum.push_back(node->val);
            if(node->right) skNode.push(node->right);
            if(node->left)  skNode.push(node->left);
        }
        return treeNum;
    }
};
```
中
```C++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> treeNum;
        if(root==nullptr)
            return treeNum;
        stack<TreeNode*> skNode;
        while(!skNode.empty()||root!=nullptr){
            while(root!=nullptr){
                skNode.push(root);
                root=root->left;
            }
            root=skNode.top();
            treeNum.push_back(root->val);
            skNode.pop();
            root=root->right;
        }
        return treeNum;
    }
};
```
后
```c++
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> treeNum;
        if(root==nullptr)
            return treeNum;
        stack<TreeNode*> skNode;
        skNode.push(root);
        while(!skNode.empty()){
            TreeNode* node=skNode.top();skNode.pop();
            treeNum.push_back(node->val);
            if(node->left)skNode.push(node->left);//注意与前序遍历的区别 此处先push left
            if(node->right)skNode.push(node->right);
        }
        reverse(treeNum.begin(),treeNum.end());//最后要逆转
        return treeNum;
    }
};
```


# 数据结构的存储方式

**数据结构的存储方式只有两种：数组（顺序存储）和链表（链式存储）**。

这句话怎么理解，不是还有散列表、栈、队列、堆、树、图等等各种数据结构吗？

我们分析问题，一定要有递归的思想，自顶向下，从抽象到具体。你上来就列出这么多，那些都属于「上层建筑」，而数组和链表才是「结构基础」。因为那些多样化的数据结构，究其源头，都是在链表或者数组上的特殊操作，API 不同而已。

## 二叉树的三种遍历方式

```c
void traverse(TreeNode root) {
    // 前序遍历代码
    traverse(root.left);
    // 中序遍历代码
    traverse(root.right);
    // 后序遍历代码
}
```

# 什么是 LRU 算法

就是一种缓存淘汰策略。

计算机的缓存容量有限，如果缓存满了就要删除一些内容，给新内容腾位置。但问题是，删除哪些内容呢？我们肯定希望删掉哪些没什么用的缓存，而把有用的数据继续留在缓存里，方便之后继续使用。那么，什么样的数据，我们判定为「有用的」的数据呢？

LRU 缓存淘汰算法就是一种常用策略。LRU 的全称是 Least Recently Used，也就是说我们认为最近使用过的数据应该是是「有用的」，很久都没用过的数据应该是无用的，内存满了就优先删那些很久没用过的数据。

### **LRU 算法描述**

LRU 算法实际上是让你设计数据结构：首先要接收一个 capacity 参数作为缓存的最大容量，然后实现两个 API，一个是 put(key, val) 方法存入键值对，另一个是 get(key) 方法获取 key 对应的 val，如果 key 不存在则返回 -1。

注意哦，get 和 put 方法必须都是 `O(1)` 的时间复杂度，我们举个具体例子来看看 LRU 算法怎么工作。

```java
/* 缓存容量为 2 */
LRUCache cache = new LRUCache(2);
// 你可以把 cache 理解成一个队列
// 假设左边是队头，右边是队尾
// 最近使用的排在队头，久未使用的排在队尾
// 圆括号表示键值对 (key, val)

cache.put(1, 1);
// cache = [(1, 1)]
cache.put(2, 2);
// cache = [(2, 2), (1, 1)]
cache.get(1);       // 返回 1
// cache = [(1, 1), (2, 2)]
// 解释：因为最近访问了键 1，所以提前至队头
// 返回键 1 对应的值 1
cache.put(3, 3);
// cache = [(3, 3), (1, 1)]
// 解释：缓存容量已满，需要删除内容空出位置
// 优先删除久未使用的数据，也就是队尾的数据
// 然后把新的数据插入队头
cache.get(2);       // 返回 -1 (未找到)
// cache = [(3, 3), (1, 1)]
// 解释：cache 中不存在键为 2 的数据
cache.put(1, 4);    
// cache = [(1, 4), (3, 3)]
// 解释：键 1 已存在，把原始值 1 覆盖为 4
// 不要忘了也要将键值对提前到队头
```

### **LRU 算法设计**

分析上面的操作过程，要让 put 和 get 方法的时间复杂度为 O(1)，我们可以总结出 cache 这个数据结构必要的条件：查找快，插入快，删除快，有顺序之分。

那么，什么数据结构同时符合上述条件呢？哈希表查找快，但是数据无固定顺序；链表有顺序之分，插入删除快，但是查找慢。所以结合一下，形成一种新的数据结构：哈希链表。

![image.png](https://i.loli.net/2021/05/18/L3AzqijdklTtm2P.png)

# 全序关系和偏序关系

参考：https://www.zhihu.com/question/36758436/answer/555298363

偏序与完全序（离散数学知识）

**（1）偏序与完全序的概念：**

偏序关系、全序关系都是公理集合论中的一种二元关系。 

​	• 偏序集合：配备了偏序关系的集合。 

偏序：只对部分要元素成立关系（部分可比）

集合内只有部分元素之间在这个关系下是可以比较的。 

比如：比如复数集中并不是所有的数都可以比较大小，那么“大小”就是复数集的一个偏序关系。

​	• 全序集合：配备了全序关系的集合。

全序：对集合中任意两个元素都有关系

集合内任何一对元素在在这个关系下都是相互可比较的。 

比如：有限长度的序列按字典序是全序的。最常见的是单词在字典中是全序的。

**（2）偏序与完全序的定义:**

​	• 偏序的定义：

设R是集合A上的一个二元关系，若R满足： 

Ⅰ 自反性：对任意x∈A，有xRx； 

Ⅱ 反对称性（即反对称关系）：对任意x,y∈A，若xRy，且yRx，则x=y； 

Ⅲ 传递性：对任意x, y,z∈A，若xRy，且yRz，则xRz。 

则称R为A上的偏序关系。

​	• 全序的定义：

设集合X上有一全序关系，如果我们把这种关系用 ≤ 表述，则下列陈述对于 X 中的所有 a, b 和 c 成立： 

如果 a ≤ b 且 b ≤ a 则 a = b (反对称性) 

如果 a ≤ b 且 b ≤ c 则 a ≤ c (传递性) 

a ≤ b 或 b ≤ a (完全性)

**注意**：

完全性本身也包括了自反性。 所以，全序关系必是偏序关系。

# A*搜索算法

A* 搜索算法（A* search algorithm）是一种在图形平面上，有多个节点的路径，求出最低通过成本的算法。常用于游戏中的NPC的移动计算，或网络游戏的BOT的移动计算上。

该算法综合了最良优先搜索和Dijkstra算法的优点：在进行启发式搜索提高算法效率的同时，可以保证找到一条最优路径（基于评估函数）。

A*算法通过下面这个函数来计算每个节点的优先级。


其中：

$f(n)=g(n)+h(n)$

f(n)是节点n的综合优先级。当我们选择下一个要遍历的节点时，我们总会选取综合优先级最高（值最小）的节点。

g(n) 是节点n距离起点的代价。

h(n)是节点n距离终点的预计代价，这也就是A*算法的启发函数。关于启发函数我们在下面详细讲解。

A*算法在运算过程中，每次从优先队列中选取f(n)值最小（优先级最高）的节点作为下一个待遍历的节点。

另外，A*算法使用两个集合来表示待遍历的节点，与已经遍历过的节点，这通常称之为open_set和close_set。

完整的A*算法描述如下：

* 初始化open_set和close_set；
* 将起点加入open_set中，并设置优先级为0（优先级最高）；
* 如果open_set不为空，则从open_set中选取优先级最高的节点n：
    * 如果节点n为终点，则：
        * 从终点开始逐步追踪parent节点，一直达到起点；
        * 返回找到的结果路径，算法结束；
    * 如果节点n不是终点，则：
        * 将节点n从open_set中删除，并加入close_set中；
        * 遍历节点n所有的邻近节点：
            * 如果邻近节点m在close_set中，则：
                * 跳过，选取下一个邻近节点
            * 如果邻近节点m也不在open_set中，则：
                * 设置节点m的parent为节点n
                * 计算节点m的优先级
                * 将节点m加入open_set中

这个公式遵循以下特性：

如果$g(n)$为0，即只计算任意顶点$n$到目标的评估函数$h(n)$，而不计算起点到顶点$n$的距离，则算法转化为使用贪心策略的最良优先搜索，速度最快，但可能得不出最优解；

如果$h(n)$不大于顶点$n$到目标顶点的实际距离，则一定可以求出最优解，而且$h(n)$越小，需要计算的节点越多，算法效率越低，常见的评估函数有——欧几里得距离、曼哈顿距离、切比雪夫距离；

如果$h(n)$为0，即只需求出起点到任意顶点$n$的最短路径$g(n)$，而不计算任何评估函数$h(n)$，则转化为单源最短路径问题，即Dijkstra算法，此时需要计算最多的顶点

参考：

https://zhuanlan.zhihu.com/p/54510444

https://zh.wikipedia.org/wiki/A%E6%90%9C%E5%B0%8B%E6%BC%94%E7%AE%97%E6%B3%95

https://www.gamedev.net/reference/articles/article2003.asp

# 斐波那契数列及其变形

## 斐波那契数列

[509. 斐波那契数](https://leetcode-cn.com/problems/fibonacci-number/)

*写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：*

*F(0) = 0, F(1) = 1*
*F(N) = F(N - 1) + F(N - 2), 其中 N > 1.*

1. 基于递归实现

```c++
class Solution {
public:
    int Fibonacci(int n) {
		if(n==1||n==0)
			return n;
		return Fibonacci(n-1)+Fibonacci(n-2);
    }
};
```

递归效率奇低，因为会有大量的重复计算

![image.png](https://i.loli.net/2021/05/18/PdYSQg81JsKOiay.png)

2. 用循环的方式可以减少重复

```c++
class Solution {
public:
    int Fibonacci(int n) {
		int p=0,q=1,r=0;
        for(int i=1;i<=n;i++){
            p=q;
            q=r;
            r=p+q;
        }
        return r;
    }
};
```

## 变形1：爬楼梯

[70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)

*假设你正在爬楼梯。需要 n 阶你才能到达楼顶。*

*每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？*

设F(n)为上台阶的数目，从后往前看，最后一步可能爬了1阶或2阶，则F(n)=F(n-1)+F(n-2)

1. 递归

```c++
class Solution {
public:
    int climbStairs(int n) {
		if(n==1||n==2)
			return n;
		return climbStairs(n-1)+climbStairs(n-2);
    }
};
```

超时了，优化一下，使用数组记录数据，减少重复计算

```c++
class Solution {
public:
    int climbStairs(int n) {
        vector<int> rember(n+1,0);
        return fib(n,rember);
    }

    int fib(int n,vector<int>& rember){
        if(n==1||n==2)
			return n;
        if(rember[n]==0)
            rember[n]=fib(n-1,rember)+fib(n-2,rember);
		return rember[n];
    }
};
```

2. 迭代

类似斐波那契的循环方法

```c++
class Solution {
public:
    int climbStairs(int n) {
		int p=0,q=0,r=1;
        for(int i=0;i<n;i++){
            p=q;
            q=r;
            r=p+q;
        }
        return r;
    }
};
```

3. 动态规划*

也是循环方法，区别是此方法可以扩展

```c++
class Solution {
public:
    int climbStairs(int n) {
        if(n==1||n==2)
            return n;
		int dp[n];
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
};
```

## 变形2：青蛙跳台阶变态版

*一只青蛙一次可以跳1级台阶，也可以一次跳2级台阶，...，也可以一次跳n级台阶。求这只青蛙跳上一个n级台阶总共有多少办法？*

![image.png](https://i.loli.net/2021/05/18/JxiuXjk3b2dlnMT.png)

思考：如题所说，
$$
f(n)=f(n-1)+f(n-2)+f(n-3)+...+f(1)+f(0)
$$
也可以列出
$$
f(n-1)=f(n-2)+f(n-3)+...+f(1)+f(0)
$$
两式相减得
$$
f(n)-f(n-1)=f(n-1)
$$

$$
f(n)=2f(n-1)
$$

推广有
$$
f(1)=1
$$

$$
f(n)=2^{n-1}
$$

则可用代码表示

```c++
class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return n;
		return pow(2,n-1);
    }
};
```

当然也可以不这么复杂，直接累加即可

```c++
class Solution {
public:
    int climbStairs(int n) {
        if(n==1||n==2)
            return n;
		int dp[n];
		dp[0]=1;
		dp[1]=2;
		for(int i=2;i<n;i++){
			for(int j=0;j<i;j++){
				dp[i]+=dp[j];
			}
		}
		return dp[n-1];
    }
};
```

### 变形2 的推广

*一只青蛙一次可以跳1级台阶，也可以一次跳2级台阶，...，也可以一次跳m级台阶，但m不一定等于n*

1. n<=m 同上
2. n>m

$$
f(n)=f(n-1)+f(n-2)+f(n-3)+...+f(n-m)
$$

$$
f(n-1)=f(n-2)+f(n-3)+...+f(n-1-m)
$$

两式相减得
$$
f(n)-f(n-1)=f(n-1)-f(n-1-m)
$$
可得
$$
f(n)=2f(n-1)-f(n-1-m)
$$

## 变形3：限制跳

*一只青蛙一次可以跳1级台阶，也可以一次跳2级台阶，但是出于体力因素不允许连着两次跳2级台阶。求这只青蛙跳上一个n级台阶总共有多少办法？*

思考：考虑不能连续跳2级台阶，从后往前看，假设最后一步是1级的个数是g(n),是2级的个数是h(n)。则
$$
f(n)=g(n)+h(n)
$$
由于最后两级台阶g(n)走了两步，h(n)走了一步则
$$
h(n)=g(n-2)
$$
g(n)的前一步即当最后一步是1级时倒数第二步是2级的个数为h(n-1),倒数第二步为1级的个数是g(n-1)，则
$$
g(n)=g(n-1)+h(n-1)
$$
带入f(n)，可得
$$
f(n)=g(n-1)+g(n-3)+g(n-2)
$$

$$
f(n-1)=g(n-1)+h(n-1)=g(n-1)+g(n-3)
$$

两式相减有
$$
f(n)-f(n-1)=g(n-2)=g(n-3)+h(n-3)=f(n-3)
$$
则可知
$$
f(n)=f(n-1)+f(n-3)
$$
代码表示为

```c++
class Solution {
public:
    int climbStairs(int n) {
        if(n==1||n==2||n==3)
            return n;
		int dp[n];
        dp[0]=1;
        dp[1]=2;
        dp[2]=3;
        for(int i=3;i<n;i++){
            dp[i]=dp[i-1]+dp[i-3];
        }
        return dp[n-1];
    }
};
```

## 矩形覆盖
*我们可以用 2×1 的小矩形横着或者竖着去覆盖更大的矩形。请问 n 个 2×1 的小矩形无重叠地覆盖 2×n 的大矩形，总共有多少种方法？*

![image.png](https://i.loli.net/2021/05/18/Ce4lv6xs5McN3RL.png)

思考：这道题其实很简单，把它类比到爬楼梯即可，有两种情况

![image.png](https://i.loli.net/2021/05/18/sVICUeRn49Z5X73.png)

第一种可以看作爬一阶楼梯，

![image.png](https://i.loli.net/2021/05/18/jr9uzm4YDxIKF3N.png)

第二种看作爬二阶楼梯。结果呼之欲出！

```c++
class Solution {
public:
    int RectCover(int n) {
        if(n==1||n==2)
            return n;
		int dp[n];
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
};
```
# 并查集
https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-2/unionfind-suan-fa-xiang-jie
