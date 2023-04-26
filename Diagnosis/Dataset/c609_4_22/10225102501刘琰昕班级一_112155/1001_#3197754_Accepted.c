#include <stdio.h>
#include <stdlib.h>

char base[]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N,R,num=1,sign=0;
        char ans[1000]={0};
        scanf("%d %d",&N,&R);
        if(N<0)N=-N,sign=1;
        else if(N==0)ans[99]='0';
        while(N)
        {
            ans[1000-num]=base[N%R];
            N/=R;
            num++;
        }
        if(sign==1)printf("-");
        for(int j=1000-num+1;j<1000;j++)
            printf("%c",ans[j]);
        printf("\n");
    }
    return 0;
}
