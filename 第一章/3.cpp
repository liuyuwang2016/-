#include<cstdio>  
#include<cstring>  
using namespace std;  
const int N = 210;  
char num1[N],num2[N];  
int ans1[N * 2];  
char * strrev(char * s){  
    char * h = s,*t = s, ch;  
    while(*t++){}  
    t--; t--;  
    while(h < t){  
        ch = *h;  
        *h++ = *t;  
        *t-- = ch;  
    }  
    return s;  
}  
int main(){  
    scanf("%s",num1);  
    scanf("%s",num2);  
    memset(ans1,0,sizeof(ans1));  
    strrev(num1); strrev(num2);  
    int tmp;  
    int len1 = strlen(num1),len2 = strlen(num2);  
    for(int i = 0; i < len1; ++i){  
        for(int j = 0; j < len2; ++j){  
            ans1[i + j] += (num1[i] - '0') * (num2[j] - '0');  
        }  
    }  
    for(int i = 0; i < len1 + len2; i++){  
        if(ans1[i] >= 10){  
            ans1[i+1]+= ans1[i]/10;  
            ans1[i] %= 10;  
        }  
    }  
    int idx = len1 + len2;  
    while(ans1[idx] == 0 && idx >= 0) idx--;  
    if(idx < 0) putchar('0');  
    else {  
        for(int i = idx; i >= 0; i--){  
            printf("%d",ans1[i]);  
        }  
    }  
    putchar('\n');  
    return 0;  
}  