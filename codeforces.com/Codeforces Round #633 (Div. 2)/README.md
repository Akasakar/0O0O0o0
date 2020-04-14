## [Codeforces 1339 B. Sorted Adjacent Differences](https://codeforces.com/contest/1339/problem/B)

给出一个序列，要求重排后 满足$ |a_1 - a_2| \leq |a_2 - a_3| \leq ... \leq |a_{n-1} - a_n| $ 

假设序列有序，显然该式成立 $ |a_n - a_1| \geq | a_1 - a_{n - 1}| \geq ... \geq | a_{\frac{n}{2}} - a_{\frac{n}{2} - 1} | $ 

## [Codeforces 1339 C. Powered Addition](https://codeforces.com/contest/1339/problem/C)

给出一个序列，可以进行如下操作：

* 选择一些 $ i_1, i_2, ... i_k $ 在$ 1 \sim n$ 之间且每个 $ i_x $ 不相同，在第$ x $ 秒对序列 $ l \sim r $ 之间每个元素 $ + 2^{x - 1}$ 

最后要求整个序列非降序。

找到每个升序列的最大值，然后在后面找一个最小值，对每次这样的操作选择一个最大的差值，显然只要该差值满足了，整个序列肯定满足。对差值求对数即是解。

## [Codeforces 1339 D. Edge Weight Assignment](https://codeforces.com/contest/1339/problem/D)

给无根树赋边权，要求所有叶子节点简单路径边权异或和为0。

求出使用过的值的数量，最小和最大数量f。

可以有如下构造：算了过程不想写了，[题解](https://codeforces.com/blog/entry/75913) 

结论如下：

最小值不会超过3，如果是2，显然路径边数是偶数的，那么使用1种值也可以构造。要检查1是否是合法的，从根到所有叶子节点的路径长度都必须是偶数的。

最大值为 $ e - l + m $ e表示总边数（n - 1），l表示叶子数，m表示叶子的父亲节点数。

## [Codeforces 1339 E. Perfect Triples](https://codeforces.com/contest/1339/problem/E)

用三元组构造一个序列 $ s $ 

1. $ a \oplus b \oplus  c = 0 $  且 $ a, b, c  $ are  not in $ s $ 

2. $ (a_1, b_1, c_1) $ 字典序严格小于 $ (a_2, b_2, c_2) $
3. 将 $ a, b, c $ 添加到 $ s $ 之后
4. 回到 step 1

询问第n个数是什么

只能先打表看看，确实有规律，在四进制下(每两位二进制)

还有一个规律，$ 1 \sim 4^n - 1 $ 全部数字被使用，每个n为一个阶段，在该阶段下，四进制位数长度一致。

对输入n求出它所在阶段a，再求出n在a阶段的三元组第几位，$ x = a + (n - a) / 3 $ 向下取整。

``` c++
    int f[3][4] = {
        {0, 3, 1, 2},
        {0, 1, 2, 3},
        {0, 2, 3, 1}
    };
```

$ f_{(k, x \% 4)} $ k表示n%3