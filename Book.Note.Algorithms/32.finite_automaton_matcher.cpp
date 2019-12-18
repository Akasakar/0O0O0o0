/* *
 *    Author:   Akasaka
 *    FileName: 32.finite_automaton_matcher.cpp
 *    Created:  2019.12.18(UTC+0800) 17.20.39(星期三)
 * */

#include <bits/stdc++.h>

using namespace std;

const int _max = 1 << 10;
const int _sigma = 1 << 7;

int DELTA[_max][_sigma];

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

void compute_transition_function(char P[], vector<char> Sigma)
{
    int m = strlen(P);
    for(int q = 0; q <= m; q++)
        for(int i = 0; i < Sigma.size(); i++)
        {
            char& a = Sigma[i];
            int k = min(m, q + 1);
            while(!is_suffix(P, k, q, a)) k--;
            delta(q, a) = k;
        }
    
    for(int q = 0; q <= m; q++)
    {
        for(int i = 0; i < Sigma.size(); i++)
            printf("%d ", delta(q, Sigma[i]));
        putchar(10);
    }
}

void finite_automaton_matcher(char T[], int m)
{
    int n = strlen(T);
    int q = 0;
    for(int i = 0; i < n; i++)
    {
        q = delta(q, T[i]);
        if(q == m)
            printf("Pattern occurs with shift %d.\n", i + 1 - m + 1);
    }
}

int main()
{
    char T[_max] = "abababacababacabca";
    char P[_max] = "ababaca";
    vector<char> Sigma({'a', 'b', 'c'});
    compute_transition_function(P, Sigma);
    finite_automaton_matcher(T, strlen(P));
    return 0;
}
