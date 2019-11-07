## 1. [Codeforces 1238 E. Keyboard Purchase](https://codeforces.com/contest/1238/problem/E)  

Tags： 状压dp  

转至：[Spy97](https://blog.nowcoder.net/n/765f50fffbd048bba68960d38d474b6d)  

### 题意：

给出长为n的字符序列，集合大小为m，要求给字符编号（即一种m的排列），定义代价为相邻字符编号差的绝对值，求最小代价

### 题解：

不妨设按照 <img src="http://latex.codecogs.com/gif.latex?\1 \sim m" /> 的顺序给字符编号，每次确定一个字符，代价为它到之前已经确定的字符的代价和。  

但是，我们无法保留确定的顺序，如何求解？  

不妨假设所有字符一开始标号均为1，那么，当编号1确定时，将其他编号都设为2，当编号2确定时，将没确定的都设为3，以此类推。  

每确定一个编号的过程，代价更新，就是，已确定的和尚未确定的两两代价之和

例如 <img src="http://latex.codecogs.com/gif.latex?\ abcd " />  

当确定a为编号1时，那么 <img src="http://latex.codecogs.com/gif.latex?\ bcd " />的编号距离a至少为1，所以要加上dis(a, b)，dis(a, c)，dis(a, d)的代价  

当确定b为编号2时，那么cd的编号距离a至少为2，距离b至少为1，所以加上dis(b, c)，dis(b, d)的代价  

此外又因为上次加过a到其他字符的代价，这次新增加的距离为1，所以再加上 dis(a, c)，dis(a, d)的代价，实际上这两个代价都是是1+1  

当确定c为编号3时，那么d的编号距离a至少为3，距离b至少为2，距离c至少为1，新增加的代价都是1。此外，再加上 dis(a, d)，dis(b, d)，dis(c, d)的代价  

---

## [F. The Maximum Subtree](https://codeforces.com/contest/1238/problem/F)  

Tags: 树形dp，dfs  

转至：[LLTYYC](https://www.cnblogs.com/LLTYYC/p/11643197.html)  

### 题意：  

~~给出一颗树，求这颗树的最大[毛毛虫](https://www.luogu.org/problem/P3174, "洛谷P3174 [HAOI2009]毛毛虫")~~ 划掉误。  

给出一棵树，求一颗最大的good子树。  

x轴上给出一些线段，编号1-n，当线段x与线段y存在交点时，点x与点y之间连上一条边。最后会变成一个图，可能存在环。当没有环时，这棵树就是good的。  

从给出的树中找出一颗最大子树。还原为一些区间后，这些区间按上述操是否满足是一颗good树  

### 题解：  

实际上画出来后，这样的树是一个[毛毛虫](https://www.luogu.org/problem/P3174, "洛谷P3174 [HAOI2009]毛毛虫")图，最大的毛毛虫就是求树上最长直径。  

根据图论握手定理：<img src="http://latex.codecogs.com/gif.latex?\  {\Sigma}_{i}^{n}d_{(v_i)} = 2m"/>度数和=2倍边数和，一棵树顶点数和-1=边数和。

设[毛毛虫](https://www.luogu.org/problem/P3174, "洛谷P3174 [HAOI2009]毛毛虫")顶点集合<img src="http://latex.codecogs.com/gif.latex?\  V"/>（包括足），<img src="http://latex.codecogs.com/gif.latex?\  2(|V| - 1) = {\Sigma}_{u \in V} d_{u} => |V| = {\Sigma}_{u \in V} (d_{u} - 1) + 2"/>  

dfs做法：  

第一次dfs随机一点，求出叶子点p，满足叶子点到该店距离最长（这里指的是边权和最大）。  

第二次dfs从p点出发，求一个最大的边权和。  

树形dp做法：  

考虑dp[u]表示点u的最长路径（不包括u点）。  

转移方程：dp[u] = max{dp[v] + d[v]}  

最大的毛毛虫对于u点来说即是最大路径+次大的路径+到这两条路径的代价。  

在dfs的过程中每次求出u点到vi点的最大路径，更新给max2，当max2比max1大时，交换它们的值，即达到了求次大的目的。  

---

使用vector建图TLE2  

改用[链式前向星](https://malash.me/200910/linked-forward-star/)建图TLE5

dfs搜索用了vis标记TLE6

总结一下，TLE在大量的memset操作上



<img src="http://latex.codecogs.com/gif.latex?\  "/