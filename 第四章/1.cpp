#include<iostream>  
using namespace std;  
#define MaxNum 65536  
int InOrder[MaxNum], PostOrder[MaxNum];  
struct Node  
{  
    int data;  
    Node *leftChild, *rightChild;  
};  
Node* BuildTree(int In_Start, int In_End, int Post_Start, int Post_End)  
{  
    Node *root = new Node;  
    root->data = PostOrder[Post_End];  
    root->leftChild = NULL;  
    root->rightChild = NULL;  
    int n = 0;  
    while (InOrder[In_Start + n] != root->data)  
        n++;  
    if (n >= 1)  
        root->leftChild = BuildTree(In_Start, In_Start + n - 1, Post_Start, Post_Start + n - 1);  
    if (In_Start + n < In_End)  
        root->rightChild = BuildTree(In_Start + n + 1, In_End, Post_Start + n, Post_End - 1);  
    return root;  
}  
void Pre_Travel(Node *root)  
{  
    if(root)  
    {  
        cout << root->data << ' ';  
        Pre_Travel(root->leftChild);  
        Pre_Travel(root->rightChild);  
    }  
}  
void delete_Tree(Node *root)  
{  
    while (root)  
    {  
        delete_Tree(root->leftChild);  
        delete_Tree(root->rightChild);  
        delete[] root;  
        root = NULL;  
    }  
}  
int main()  
{  
    int i = 0,num = 0;  
    while (cin >> InOrder[i++])  
    {  
        if (cin.get() != ' ')   //遇到回车则停止输入  
            break;  
    }  
    i = 0;  
    while (cin >> PostOrder[i++])  
    {  
        if (cin.get() != ' ')   //遇到回车则停止输入  
            break;  
    }  
    num = i - 1;  
    Node *root = BuildTree(0, num, 0, num);  
    Pre_Travel(root);  
    delete_Tree(root);  
    return 0;  
}  
