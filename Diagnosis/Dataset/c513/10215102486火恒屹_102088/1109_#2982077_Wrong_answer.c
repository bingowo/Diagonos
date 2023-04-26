#include <stdio.h>
#include <stdlib.h>
void f(int keisu,int flag,int jiou)
{
    if(flag==1&&keisu>0&&keisu!=1) printf("%d",keisu);
    else if(flag==1&&keisu>0&&keisu==1) ;
    else if(keisu>0&&keisu!=1) printf("+%d",keisu);
    else if(keisu>0&&keisu==1) printf("+");
    else if(keisu!=-1) printf("%d",keisu);
    else printf("-");
    if(jiou!=1) printf("x^%d",jiou);
    else if(jiou==1) printf("x");
    else if(jiou==0&&keisu==1) printf("1");
    else if(jiou==0&&keisu==-1) printf("-1");
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int num[10]={0};
        for(int j=0;j<9;j++) scanf("%d",&num[j]);
        int j=0;
        while(num[j]==0) {j++;if(j==9) break;}
        if(j==9) {printf("0\n");continue;}
        f(num[j],1,8-j);
        for(int k=j+1;k<=8;k++)
        {
            if(num[k]!=0) f(num[k],0,8-k);
        }
        printf("%c",10);
    }
    return 0;
}
