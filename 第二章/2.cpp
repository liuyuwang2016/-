#include <map>  
#include <set>  
#include <ctime>  
#include <queue>  
#include <vector>  
#include <cstdio>  
#include <cctype>  
#include <string>  
#include <cstring>  
#include <sstream>  
#include <cstdlib>  
#include <iostream>  
#include <algorithm>  
  
  
  
  
using namespace std;  
  
  
#define pb push_back  
#define mp make_pair  
#define fillchar(a, x) memset(a, x, sizeof(a))  
#define copy(a, b) memcpy(a, b, sizeof(a))  
#define S_queue<P> priority_queue<P, vector<P>,greater<P> >  
  
  
typedef long long LL;  
typedef pair<int, int > PII;  
typedef unsigned long long uLL;  
template<typename T>  
void print(T* p, T* q, string Gap = " "){int d = p < q ? 1 : -1;while(p != q){cout << *p;p += d;if(p != q) cout << Gap; }cout << endl;}  
template<typename T>  
void print(const T &a, string bes = "") {int len = bes.length();if(len >= 2)cout << bes[0] << a << bes[1] << endl;else cout << a << endl;}  
  
const int INF = 0x3f3f3f3f;  
const int MAXM = 1e5;  
const int MAXN = 1e4 + 5;  
int A[MAXN];  
  
int main(){  
    int n;  
    scanf("%d", &n);  
    int ans = 1;  
    for(int i = 1;i <= n;i ++){  
        ans = 2 * (2 * (i - 1) + 1) * ans / (i + 1);  
    }  
    print(ans);  
    return 0;  
}  