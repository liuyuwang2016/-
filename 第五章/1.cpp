#include <cstdio>  
#include <iostream>  
#include <queue>  
#include <cstring>  
using namespace std;  
  
int t,n;  
priority_queue<int,vector<int>,greater<int>> q;  
  
int main()  
{  
    cin >> t;  
    while(t--) {  
        cin >> n;  
        while(n--) {  
            int a;  
            cin >> a;  
            q.push(a);  
        }  
        int sum = 0;  
        while(!q.empty()) {  
            int a = q.top();q.pop();  
            if(!q.empty()){  
                int b = q.top();q.pop();  
                sum += a+b;  
                q.push(a+b);  
            }  
        }  
        cout << sum << endl;  
    }  
    return 0;  
}  