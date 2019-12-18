/* *
 *    Author:   Akasaka
 *    FileName: 32.4-8.exercise.cpp
 *    Created:  2019.12.18(UTC+0800) 14.36.52(星期三)
 * */

#include <bits/stdc++.h>

using namespace std;

const int _max = 1 << 10;

int DELTA[_max][128];

int& delta(int q, char a)
{
    return DELTA[q][a];
}

bool is_suffix(char P[], int k, int q, char a)
{
    if(k <= 0) return true;
    if(P[k - 1] != a) return false;
    for(k -= 2, q--; k >= 0; k--, q--)
        if(P[k] != P[q]) return false;
    return true;
}

vector<int> compute_prefix_function(char P[])
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
    vector<int> pi = compute_prefix_function(P);
    int q = 0;
    for(int i = 0; i < n; i++)
    {
        while(q > 0 && P[q] != T[i]) q = pi[q - 1];
        if(P[q] == T[i]) q++;
        if(q == m)
        {
            printf("Pattern occurs with shift %d.\n", i + 2 - m);
            q = pi[q - 1];
        }
    }
}

void compute_transition_function(char P[], vector<char> Sigma)
{
    int m = strlen(P);
    vector<int> pi = compute_prefix_function(P);
    for(int q = 0; q <= m; q++)
    {
        for(int i = 0; i < Sigma.size(); i++)
        {
            char& a = Sigma[i];
            //int k = min(m, q + 1);
            //while(!is_suffix(P, k, q, a)) k--;
            int k = q;
            while(k > 0 && P[k] != a) k = pi[k - 1];
            if(P[k] == a) k++;
            delta(q, a) = k;
        }
    }
    for(int q = 0; q <= m; q++)
    {
        for(int i = 0; i < Sigma.size(); i++)
            printf("%d ", delta(q, Sigma[i]));
        putchar(10);
    }
}

void finite_automation_matcher(char T[], int m)
{
    int n = strlen(T);
    int q = 0;
    for(int i = 0; i < n; i++)
    {
        q = delta(q, T[i]);
        if(q == m)
            printf("Pattern occurs with shift %d.\n", i + 2 - m);
    }
}

int main()
{
    char T[_max] = "abababacababaca";
    char P[_max] = "ababaca";
    vector<char> Sigma({'a', 'b', 'c'});
    compute_transition_function(P, Sigma);
    finite_automation_matcher(T, strlen(P));
    KMP_matcher(T, P);
    return 0;
}
