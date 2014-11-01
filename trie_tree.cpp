#include<iostream>
#include <string.h>
#include<string>
using namespace std;

typedef struct tree_node
{
    bool end;
    int t;
    struct tree_node* s[26];
    tree_node()
    {
        end=false;
        t=0;
        memset((void*)s,0,sizeof(tree_node*)*26);
    }
}node_t;

node_t* init_tree()
{
    node_t* root = new node_t();
    return root;
}

void insert_tree(node_t* tree,string& word)
{
    int len=word.size();
    node_t* node=tree;
    for(int i=0;i<len;i++)
    {
        if((node->s)[word[i]-'a'])
        {
            node=(node->s)[word[i]-'a'];
            node->t++;
        }
        else
        {
            (node->s)[word[i]-'a']=new node_t();
            node=(node->s)[word[i]-'a'];
            node->t++;
        }
    }
    node->end=true;
}

int count(node_t* tree,string& word)
{
    node_t *node=tree;
    int len=word.size();
    for(int i=0;i<len;i++)
    {
        if((node->s)[word[i]-'a'])
        {
            node=(node->s)[word[i]-'a'];
        }
        else
        {
            return 0;
        }
    }
    return node->t;
}

void destroy(node_t *tree)
{
    if(tree)
    {
        for(int i=0;i<26;i++)
        {
            destroy((tree->s)[i]);
        }
        delete tree;
//        tree=NULL;
    }
}

int main()
{
    int n,m;
    string word;
    node_t* tree=init_tree();
    cin>>n;
    while(n>0)
    {
        cin>>word;
        insert_tree(tree,word);
        --n;
    }
    cin>>m;
    while(m>0)
    {
        cin>>word;
        cout<<count(tree,word)<<endl;
        m--;
    }
    destroy(tree);
    return 0;
}
