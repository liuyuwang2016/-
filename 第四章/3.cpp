#include <iostream>
#include <cstring>
using namespace std;
class node{
public:
    char val;
    node* left, *right;
    node(const char v):val(v){
        left= right = NULL;
    }
};

node* level[100]; //储存当前第i层的node的指针

void hou_order(node* root){// 后序遍历
    if (root!= NULL){
        hou_order(root->left);
        hou_order(root->right);
           cout<<root->val;
    }
}

void zhong_order(node* root){ //中序遍历
    if (root!=NULL) {
        zhong_order(root->left);
                cout<<root->val;
        zhong_order(root->right);
    }

}
int main(){
    int n;
    cin>>n;
    int l;

    int pointer=0;

    while(n--){
        string s;
        node* tmp;
        node* Root=NULL;

        while(cin>>s && s!="0"){

            l= (int)s.length()-1; // l代表有几个'-',即在第几层
            tmp = new node(s[l]);

            if (tmp->val!='*') cout<<tmp->val; // 打印前序

            if(l==0){// length-1=0, 说明是root
                level[l]=tmp;
                if (Root==NULL) Root = tmp;
                continue;
            }

            if(l==pointer+1){// pointer指向上一个node在第几层

                if (tmp->val =='*'){ level[pointer]->left=NULL;}
                else {level[pointer]->left= tmp;}
                level[l]=tmp;
                pointer=l;
                continue;
            }

            if (l<=pointer){ //说明该node一定是上面某层的某个node的右孩子，而非左孩子

                level[l]=tmp;
                level[l-1]->right=tmp;
                pointer=l;
                continue;}
        }
        cout<<endl;

        //打印后序
        if (Root!=NULL){
        hou_order(Root); cout<<endl;
        zhong_order(Root); cout<<endl;
        }
        cout<<endl;
        Root=NULL;
        pointer =0;
    }
    return 0;
}