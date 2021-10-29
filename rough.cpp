#include <bits/stdc++.h>
using namespace std;

int max(int a, int b);

int lcs( string X,string Y,int m,int n)
{
	if (m == 0 || n == 0)
		return 0;
	if (X[m-1] == Y[n-1])
		return 1 + lcs(X, Y, m-1, n-1);
	else
		return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}


int max(int a, int b)
{
	return (a > b)? a : b;
}


int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int minAns = 0;
    for (int i = 0; i < s1.length();i++){
        if(s1[i] != s2[i]){
            minAns++;
        }
    }

    reverse(s2.begin(), s2.end());
    
    int ans = lcs(s1, s2, s1.length(),s2.length());

    int res = s1.size() - ans;
    int c;
    cin >> c;
    int finalAn = res + c;

    
    cout << min(finalAn,minAns);
    return 0;
}


