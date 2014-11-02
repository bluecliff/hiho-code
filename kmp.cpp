#include <iostream>
#include <string>
using namespace std;

void get_next(string& p,int* next)
{
    int len=p.size();
    next[0]=-1;
    for(int i=1;i<len;i++)
    {
        int j=i-1;
        while(next[j]>=0)
        {
            if(p[next[j]]==p[i-1])
            {
                next[i]=next[j]+1;
                break;
            }
            else
            {
                j=next[j];
            }
        }
        if(j==0)
        {
            next[i]=0;
        }
    }
}

int main()
{
    string s,p;
    int res=0;
    int next[10000];
    int n;
    cin>>n;
    while(n>0)
    {
        res=0;
        --n;
        cin>>p>>s;
        get_next(p,next);
        int i=0;
        int j=0;
        while(i<s.size())
        {
            if(s[i]==s[j])
            {
                ++i;
                ++j;
            }
            else
            {
                j=next[j];
                if(j==-1)
                {
                    ++j;
                    ++i;
                }
            }
            if(j==p.size())
            {
                ++res;
                j=next[j];
            }
        }
        cout<<res<<endl;
   }
   return 0;
}
