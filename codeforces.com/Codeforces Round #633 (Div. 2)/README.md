## [Codeforces 1339 B. Sorted Adjacent Differences](https://codeforces.com/contest/1339/problem/B)

给出一个序列，要求重排后 满足$ |a_1 - a_2| \leq |a_2 - a_3| \leq ... \leq |a_{n-1} - a_n| $ 

假设序列有序，显然该式成立 $ |a_n - a_1| \geq | a_1 - a_{n - 1}| \geq ... \geq | a_{\frac{n}{2}} - a_{\frac{n}{2} - 1} | $ 

## [Codeforces 1339 C. Powered Addition](https://codeforces.com/contest/1339/problem/C)

给出一个序列，可以进行如下操作：

* 选择一些 $ i_1, i_2, ... i_k $ 在$ 1 \sim n$ 之间且每个 $ i_x $ 不相同，在第$ x $ 秒对序列 $ l \sim r $ 之间每个元素 $ + 2^{x - 1}$ 

最后要求整个序列非降序。

找到每个升序列的最大值，然后在后面找一个最小值，对每次这样的操作选择一个最大的差值，显然只要该差值满足了，整个序列肯定满足。