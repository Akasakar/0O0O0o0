## [Codeforces 1236 B. Alice and the List of Presents](https://codeforces.com/contest/1236/problem/B)  

n个礼物，m个盒子，要求n个礼物在这些盒子里各自至少出现一次。求有多少种装礼物的方法。  

被自己的智商折服，组合数还是弱。  

考虑一个礼物，每个盒子都有放和不放两种情况，它放进盒子的情况共2^m种再减去空集。每种礼物都有2^m -1种，所以答案是(2^m - 1)^n。  

---

## [Codeforces 1236 C. Labs](https://codeforces.com/contest/1236/problem/C)  

1～n^2构造一个数字矩阵。每行一组。f(u, v)表示u组中每个元素大于多少个v组元素的总和。最后总和要求最小。  

蛇形构造即可。例如：

|  1   |  8   |  9   |  16  |
| :--: | :--: | :--: | :--: |
|  2   |  7   |  10  |  15  |
|  3   |  6   |  11  |  14  |
|  4   |  5   |  12  |  13  |

---

## [Codeforces 1236 D. Alice and the Doll](https://codeforces.com/contest/1236/problem/D)  

大模拟写吐了。T了好几发，暴力找的区间，没记录行列可以访问的区间。  

1e5 * 1e5的图，每个格子只能访问一次，只能右转方向。  

---

