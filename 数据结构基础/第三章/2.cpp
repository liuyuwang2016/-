#include<iostream>  
#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
#include<assert.h>  
#include<ctype.h>  
#include<stdlib.h>  
#define min(a,b) (a)>(b)?(b):(a)  
using namespace std;  
  
struct word{  
    int shunxu;  
    char str[20];  
};  
struct node  
{  
    word wo;  
    struct node* child[16];//最多15个字符  
}*root;  
  
  
int  flag=0;  
word ans[3000];  
int anst=0;  
int cal_juli(char *a,char *b)//计算编辑距离  
{  
    int   la = strlen(a);  
    int   lb = strlen(b);  
    int i,j;  
    int s[20][20];  
    for(i=0; i<=la ; i++)  
        s[i][0] = i;  
    for(i=0; i<=lb; i++)  
        s[0][i] = i;  
    for(i = 1; i <= la; i++)  
        for(j = 1; j <= lb; j++)  
        {  
            int cost;  
            if(a[i-1] == b[j-1])cost = 0;  
            else  cost = 1;  
            s[i][j] = min(min(s[i][j-1]+1,s[i-1][j] + 1),s[i-1][j-1]+cost);  
        }  
    return s[la][lb];  
}  
node* newnode( )//初始化节点。  
{  
    node *t;  
    t =(node*)malloc(sizeof(node));  
    for(int i=0; i<=15; i++)  
        t->child[i] = NULL;  
    return t;  
}  
  
void insert( node *T ,word ss)//照算法建树  
{  
    int juli = cal_juli(T->wo.str,ss.str);  
    if( !T->child[juli] )  
    {  
        T->child[juli] = newnode();  
        T->child[juli]->wo = ss;  
    }  
    else  
    {  
        insert( T->child[juli],ss);  
    }  
  
}  
void query( node * T,char *str1 )  
{  
    if(!T)return;  
    int juli = cal_juli(T -> wo.str,   str1 );  
    if( juli == 0 )  
    {  
        flag = 1;  
        printf("%s is correct",str1);  
    }  
    else  
    {  
        if(juli == 1){  
            ans[anst++] = T->wo;}  
        if(!flag) for(int i=juli-1; i<=juli+1&&i<=15; i++)  
                if(T->child[i])  
                    query(T->child[i],str1);  
    }  
}  
bool cmp(word a, word b)  
{  
    return a.shunxu < b.shunxu;  
}  
int main()  
{  
    //freopen("in.txt","r",stdin);  
    root = newnode();  
    scanf("%s",root->wo.str);  
    root->wo.shunxu = 0;  
    word temp;  
    int cnt=1;  
    while(scanf("%s",temp.str)&&temp.str[0] != '#')  
    {  
        temp.shunxu = cnt++;  
        insert(root,temp);  
    }  
    char dd[20];  
    while(scanf("%s",dd)&&dd[0] != '#')  
    {  
        flag = 0;  
        anst=0;  
        query( root, dd);  
        if(!flag)  
        {  
            printf("%s:",dd);  
            sort(ans,ans+anst,cmp);//因为插入时是无序的 需要按要求排序输出。。  
            for(int i = 0; i < anst; i++)  
            printf(" %s",ans[i].str);  
  
        }  
        printf("\n");  
    }  
    return 0;  
}  