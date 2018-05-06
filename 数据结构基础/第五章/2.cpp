#include <iostream>  
using namespace std;  
struct node  
{  
    int info;  
    node *l, *r;  
};  
void pre(node *root)  
{  
    if (root)  
    {  
        cout << root->info << ' ';  
        pre(root->l);  
        pre(root->r);  
    }  
}  
int main()  
{  
    int temp;  
    node *root = new node,*cur,*next;  
    cin >> temp;  
    root->info = temp;  
    root->l = NULL;  
    root->r = NULL;  
    while (cin >> temp)  
    {  
        next = root;  
        cur = new node;  
        cur->info = temp;  
        cur->l = NULL;  
        cur->r = NULL;  
        while (next)  
        {  
            if (temp == next->info)  
                break;  
            if (temp < next->info)  
            {  
                if (next->l)  
                    next = next->l;  
                else  
                {  
                    next->l = cur;  
                    break;  
                }  
            }  
            else  
            {  
                if (next->r)  
                    next = next->r;  
                else  
                {  
                    next->r = cur;  
                    break;  
                }  
            }  
        }  
    }  
    pre(root);  
    return 0;  
}  