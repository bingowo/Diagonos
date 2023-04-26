#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n,fb=0,tb,ans=0,max_ans=0,flag=1;
        unsigned int b=1;
        b=b<<31;
        scanf("%d",&n);
        while((b&n)==0) b=b>>1;
        // fb=1;b=b>>1;
        while(b!=0)
        {
            tb=(b&n)==0?0:1;
            if((tb+fb)==1)   ans++;
            else
            {
                max_ans=max_ans>ans?max_ans:ans;
                ans=0;
                flag=0;
            }
            fb=tb;
            b=b>>1;
        }
        max_ans=max_ans>ans?max_ans:ans;
        if(!flag)   max_ans++;
        printf("case #%d:\n%d\n",i,max_ans);

    }
}