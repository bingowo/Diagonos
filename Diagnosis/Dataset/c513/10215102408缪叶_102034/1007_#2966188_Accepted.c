#include<stdio.h>
#include<string.h>

int main()
{
    int t;scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,p=0,cnt=1,res=0;scanf("%d",&n);
        char bin[33];
        while (n!=0)
        {
            bin[p++]=n%2;
            n/=2;
        }
        for(int t=p-1;t>=0;t--)
        {
            if(bin[t]!=bin[t-1] && t!=0) cnt++;
            else
            {
                if(cnt>res) {res=cnt;cnt=1;}
                else cnt=1;
            }
        }
        printf("case #%d:\n%d\n",i,res);
    }

    return 0;
}
