#include <stdio.h>
#include <stdlib.h>

int count=0;

void walk(int n,int p,int t,int m)
{
    if(m<=0)
    {
        if(p==t)
            count++;
        return;
    }
    else
    {
        if(p==1)
            walk(n,p+1,t,m-1);
        else
        {
            if(p==n)
                walk(n,p-1,t,m-1);
            else
            {
                walk(n,p+1,t,m-1);
                walk(n,p-1,t,m-1);
            }
        }
    }
}

int main()
{
    int cas,question_num;
    scanf("%d",&cas);
    for(question_num=0;question_num<cas;question_num++)
    {
        count=0;
        int n,p,m,t;
        scanf("%d %d %d %d",&n,&p,&m,&t);
        walk(n,p,t,m);
        printf("%d\n",count);
    }
}