#include<iostream>  
#include<algorithm>  
#include<queue>  
using namespace std;  
struct cmp  
{  
    bool operator()(int a, int b)  
    {  
        return a > b;  
    }  
};  
int main()  
{  
    int t,n,type,num;  
    cin >> t;  
    for (int i = 0; i < t; ++i)  
    {  
        cin >> n;  
        priority_queue<int,vector<int>,cmp> pQueue;  
        for (int j = 0; j < n; ++j)  
        {  
            cin >> type;  
            if (type == 1)  
            {  
                cin >> num;  
                pQueue.push(num);  
            }  
            else  
            {  
                cout << pQueue.top() << endl;  
                pQueue.pop();  
            }  
        }  
    }  
    return 0;  
}  