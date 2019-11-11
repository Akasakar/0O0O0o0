## 1. [Codeforces 1244 C. The Football Season](https://codeforces.com/contest/1244/problem/C)   

p / w = x全部当作胜利次数  

p mod w + wt = dy

t表示从x次胜取st的分数。用来和余数凑，显然y<w，因为y>w时，w次平的分数可以当作d次胜的分数。这样就可以枚举y了。  

---

## 2. [Codeforces 1244 F. Chips](https://codeforces.com/contest/1244/problem/F)  

字符串模拟，出现wbw or bwb时，中间的字符会替换  

1. 形如xx这样的串必定不会改变
2. w < --> B单个出现时会互相转换
3. 假设单个字符c出现的位置距离左右两侧最近的xx的距离为d。
   * k < d 时c随k mod 2取值改变
   * k >= d时 c变成两侧最近的其中一边xx  

---

## 3. [Codeforces 1244 G. Running Pairs](https://codeforces.com/contest/1244/problem/G)  

<img src="http://latex.codecogs.com/gif.latex?\ {\sum}_{i = 1}^{n}max(p_i, q_i)"/>  

两个序列初始都是1-n升序，重新排列qi序列使得上式最大化，但是不能超过k。  

可以构造一个序列  

n, n-1, ... 3, 2, 1序列向右偏移1位  

1,  n,  ...   4, 3, 2对结果而言贡献+(size - p - 1) - p。p+1是本次序列对于初始的偏移量，size是从8到序列尾的大小，也就是贡献可以控制是连续的。  

显然当贡献小于0时，是构造出的序列最大的时候。  

---

总结一下，这是模拟场次，难题稍微加点思维在里面，对细节要求很高  

<img src="http://latex.codecogs.com/gif.latex?\ "/