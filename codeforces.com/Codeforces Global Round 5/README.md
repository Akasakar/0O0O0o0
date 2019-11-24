## [Codeforces 1237 B. Balanced Tunnel](https://codeforces.com/contest/1237/problem/C2)  

B序列中的的x，它后面是否有一个y，并且A序列中的这个y在是在x的前面的。这个x就是fined的。统计有多少个这样的x  

可以考虑一个1-n的序列，当前统计位置pos。  

1，2，3，4，5  

x，x，1，x，2  

序列B按顺序枚举1-n，前面的元素出现在后面，前面就会产生一个空隙，原本后面的元素必定会超越它，比如1前面有两个空位。2前面和之前的1相比又多出一个空隙，所以必定有3个元素是fined的。  

---

## [Codeforces 1237 C2. Balanced Removals (Harder)](https://codeforces.com/contest/1237/problem/C2)    

3维坐标上，任意两个点构成一个闭合的box，边界为各个维度的最小和最大值。  

每次找出的box中不能含有其它的点，显然如果两个点很近，中间还有其它点的话，显然这个点离它们更近。所以最近的两个点，符合要求。  

考虑数据5e4，上述显然不行。  

转至：[LLTYYC](https://www.cnblogs.com/LLTYYC/)    

---

## [Codeforces 1237 D. Balanced Playlist](https://codeforces.com/contest/1237/problem/D)  

1. 循环完一圈，出现最大值，如果所有数在这个最值下都无法stop，将永远不会停止。  
2. 从1开始，在pos位置结束，从2开始时，必定是在pos位置及其之后才有可能结束。每次结束条件都是是从该位置到新的结束位置，记录这个区间的最大值，后满足题意结束。  

单调队列满足这个要求。  

> 初次使用，在队列为空的地方，RE多次。

转至：[LLTYYC](https://www.cnblogs.com/LLTYYC/p/11693124.html)    

---

## [Codeforces 1237 E. Balanced Binary Search Trees](https://codeforces.com/contest/1237/problem/E)  

n个点构造的BST，要求：  

1. 左右子树深度相差小于等于1。
2. 一个顶点r，左子树v的key与r的key奇偶不同，右子树w的key与r的key奇偶一致。

太难了QAQ完全不会。。。  

树形dp的话是个卷积形式的转移，n和模数都很大。

数学的话是个结论，比较难想到。大部分都是0，少数只能是1。  

这棵树有以下特点。

如果根节点key是数字r，左子树有1～r-1个顶点，右子树有r+1～n顶点。可以把右子树key-r，key平移后变成1～n-r。key=n的点只能是右子树，如果是左子树，那它的父亲key显然应该大于n。n平移后是n-r，这个数显然是偶数的。  

这种树左右子树顶点数量相差小于等于1，右子树顶点数量是偶数，左右子树递归定义，当顶点数为1或2，显然是BBST的。

转至：[LLTYYC](https://www.cnblogs.com/LLTYYC/p/11697348.html)  ，[Pat](https://www.cnblogs.com/Patt/p/11692230.html)

---

## [Codeforces 1237 F. Balanced Domino Placements](https://codeforces.com/contest/1237/problem/F)  

转至：[LLTYYC](https://www.cnblogs.com/LLTYYC/p/11697525.html)，[洛谷CF1237F Balanced Domino Placements 题解](https://www.luogu.org/problemnew/solution/CF1237F)  

看完大佬的题解，感觉妙不可言。  

**题意：** 2格骨牌可以水平或垂直的摆放，每行每列都只能出现一个骨牌，已经有一些骨牌摆放好了，求共有多少种方式摆放0个或更多骨牌。  

---

