/* *
 *    Author:   Akasaka
 *    FileName: 32.KMP_matcher.cpp
 *    Created:  2019.12.13(UTC+0800) 21.30.20(星期五)
 * */

#include <bits/stdc++.h>

using namespace std;

vector<int> compute_prefix_fuction(char P[])
{
    int m = strlen(P);
    vector<int> pi(m);
    int k = 0;
    for(int q = 1; q < m; q++)
    {
        while(k > 0 && P[k] != P[q]) k = pi[k - 1];
        if(P[k] == P[q]) k++;
        pi[q] = k;
    }
    for(int i = 0; i < pi.size(); i++)
        printf("%d ", pi[i]);
    putchar(10);
    return pi;
}

void KMP_matcher(char T[], char P[])
{
    int n = strlen(T);
    int m = strlen(P);
    vector<int> pi = compute_prefix_fuction(P);
    int q = 0;
    for(int i = 0; i < n; i++)
    {
        while(q > 0 && P[q] != T[i]) q = pi[q - 1];
        if(P[q] == T[i]) q++;
        if(q == m)
        {
            printf("Pattern occurs with shitf %d\n", i + 1 - m + 1);
            q = pi[q - 1];
        }
    }
}

int main()
{
    const int _max = 128;
    char T[_max] = "abababacababaca";
    char P[_max] = "ababaca";
    KMP_matcher(T, P);
    return 0;
}
