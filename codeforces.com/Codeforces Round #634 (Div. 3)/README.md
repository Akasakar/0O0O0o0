## [Codeforces 1335 E2. Three Blocks Palindrome (hard version)](https://codeforces.com/contest/1335/problem/E2)

给出一个数字序列，找出最大的三段回文的子序列（形如xyx，例如：aa...a, bb...b, aa...a）。

其中x/y段的序列可以为空。

序列中数字集 $ \Sigma $ 最大200。整个序列昌都2e5。

首先求第一段x，位置l，显然第三段的x位置r也可以确定。

然后加上y段的所有情况。即是解。

pre[x, i]表示元素x的前缀和。y段可以表示为pre[y, r + 1] - pre[y, l]。

位置可以预处理出每个元素的位置pos[x]表示元素x的位置集。大小xsize

 l = pos[x, i]那么r = pos[x, xsize - 1 - i] 

x段的长度可以用i表示。

## [Codeforces 1335 F. Robots on a Grid](https://codeforces.com/contest/1335/problem/F)

给出一个01矩阵图，0表示黑色，1表示白色，和一个方向图，表示当前在当前格子下移动下一步的方向。大小n*m

在上面尽可能多的放一些机器人，使得机器人每移动一步，都不会占据同一个格子上。求机器人数量，和尽可能多的黑色占据的数量

https://codeforces.com/blog/entry/75993

用到了二进制提升 *This technique is called binary lifting.*