//区间树

#include <iostream>
using namespace std;

typedef struct tree_node
{
    int L;
    int R;
    struct tree_node *left;
    struct tree_node *right;
    int min;
    tree_node()
    {
        L=0;
        R=0;
        left=right=NULL;
        min=0xFFFFFFFF;
    }
}node_t;

int init_tree(int* array,int L,int R,node_t* tree)
{
    if(L==R)
    {
        tree->L=L;
        tree->R=R;
        tree->min=array[L];
        return array[L];
    }
    else
    {
        int mid=(L+R)/2;
        tree->L=L;
        tree->R=R;
        tree->left=new node_t();
        tree->right=new node_t();
        int min_l=init_tree(array,L,mid,tree->left);
        int min_r=init_tree(array,mid+1,R,tree->right);
        tree->min=(min_l<min_r?min_l:min_r);
        return tree->min;
    }
}

int search(node_t* tree,int L, int R)
{
    if(L==tree->L && R==tree->R)
    {
        return tree->min;
    }
    int mid=(tree->L+tree->R)/2;
    if(R<=mid)
    {
        return search(tree->left,L,R);
    }
    else if(L>mid)
    {
        return search(tree->right,L,R);
    }
    else
    {
        int min_l=search(tree->left,L,mid);
        int min_r=search(tree->right,mid+1,R);
        return min_l<min_r?min_l:min_r;
    }
}

int change_tree(node_t* tree,int i,int k)
{
    if(tree->L==i && tree->R==i)
    {
        tree->min=k;
        return k;
    }
    int mid=(tree->L+tree->R)/2;
    if(i<=mid)
    {
        int min_l=change_tree(tree->left,i,k);
        int min_r=tree->right->min;
        tree->min=min_l<min_r?min_l:min_r;
        return tree->min;
    }
    if(i>mid)
    {
        int min_r=change_tree(tree->right,i,k);
        int min_l=tree->left->min;
        tree->min=min_l<min_r?min_l:min_r;
        return tree->min;
    }
}

void destroy(node_t* tree)
{
    if(tree->left)
        destroy(tree->left);
    if(tree->right)
        destroy(tree->right);
    delete tree;
}

int main()
{
    int N,Q;
    int o,l,r;
    int array[10000];
    cin>>N;
    for(int i=0;i<N;++i)
    {
        cin>>array[i];
    }
    node_t* tree=new node_t();
    init_tree(array,0,N-1,tree);
    cin>>Q;
    while(Q--)
    {
        cin>>o>>l>>r;
        if(o==0)
        {
            cout<<search(tree,l-1,r-1)<<endl;
        }
        else if(o==1)
        {
            change_tree(tree,l-1,r);
        }
    }
    destroy(tree);
    return 0;
}
