#include<stdio.h>  
#define MAX 300  
int main()  
{  
    int houzi[MAX+10],n,m;  
    int i;  
    int count,sum;      //sum记录猴子总数,count记录当前数到的猴子数  
  
    while(scanf("%d%d",&n,&m)&&(n||m))  
    {  
    for(i=0;i<n;i++)  
        houzi[i]=i+1;//数组赋值  
    i=0;        //从第一只猴子开始  
    sum=n;        
    while(sum>1) //当猴子总数超过1时继续操作  
    {   count=0;  
        while(count<m)  
        {  
                  
            if(i>=n)  
                i%=n;   //下标，当i大于n-1时，回到起点  
            if(houzi[i])    //如果猴子未出圈，则数进去  
                count++;  
            i++;  
          
        }  
        if(i-1<0)    //注意下标，当数到第n-1只猴子时，下标i会变为0，i-1小于0  
            houzi[n-1]=0; //于是第n-1只猴子出圈而不是第i-1只，因为i-1<0  
        else  
            houzi[i-1]=0;  
        sum--;      //出圈一只，则猴子总数减一  
  
  
    }  
    for(i=0;i<n;i++) //找到没出圈的那只猴子，输出下标  
        if(houzi[i])  
        {  
            printf("%d\n",i+1);  
            break;  
        }  
    }  
    return 0;  
}  