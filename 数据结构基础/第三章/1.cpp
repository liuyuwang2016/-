#include <string.h>  
#include <stdlib.h>  
#include <stdio.h>  
//using namespace std;  
int main()  
{  
    int n,i,j,k;  
    char str[100];  
    while (scanf("%d\n",&n)!=EOF)  
    {  
        for (i=0;i<n;i++)  
        {  
            gets(str);  
            for (j=0;j<strlen(str);j++)  
            {  
                if ((str[j]>='a'&&str[j]<='y')||(str[j]>='A'&&str[j]<='Z'))  
                {  
                    str[j]=str[j]+1;  
                }  
                else if (str[j]=='Z'||str[j]=='z')  
                {  
                    str[j]=str[j]-25;  
                }  
            }  
            puts(str);  
        }  
    }  
    return 1;  
}  
/************************************************************** 
    Problem: 1134 
    User: Carvin 
    Language: C++ 
    Result: Accepted 
    Time:0 ms 
    Memory:1020 kb 
****************************************************************/  