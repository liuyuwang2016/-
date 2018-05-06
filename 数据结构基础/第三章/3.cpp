#include<iostream>  
#include<stdio.h>  
#include<string.h>  
using namespace std;  
  
char s[1000100];  
int  next[1000100];  
  
int t=1;  
int main()  
{       int N;  
    while(scanf("%d",&N)!=EOF&&N!=0)  
    {  
  
        cin>>s;  
        int i;  
  
        memset(next,0,sizeof(next));  
        next[0] = 0;  
        for(i=1; i<N; i++)  
        {  
            int j = next[i-1];// j 表示当前匹配了多少位  
  
            while(j&&s[j]!=s[i])  
                j = next[j-1];  
            if(s[i]==s[j])  
                next[i]=j+1;  
            else next[i] = 0;  
        }  
       cout<<"Test case #"<<t++<<endl;  
        for(i=2 ; i<=N; i++)  
        {  
            if(i%(i-next[i-1])==0&&i/(i-next[i-1])>1)  
               cout<<i<<" "<<i/(i-next[i-1])<<endl;  
        }  
       cout<<endl;  
  
    }  
  
    return 0;  
}  
