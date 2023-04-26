#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int f=0;f<t;f++)
    {
        int s[9]={0};
        for(int i=0;i<9;i++)
        {
            scanf("%d",&s[i]);
        }
        int b=0;
        printf("case #%d:\n",f);
        for(int i=0;i<9;i++)
        {
            if(s[i]==0) continue;
            else if(s[i]==1&&b==1&&i!=8) printf("+"),b=1;
            else if(s[i]==1&&i!=8) b=1;
            else if(s[i]==1&&i==8) printf("+1");
            else if(s[i]==-1&&i!=8) printf("-"),b=1;
            else if(s[i]>1&&b==1) printf("+%d",s[i]),b=1;
            else if(s[i]<-1) printf("%d",s[i]),b=1;
            else printf("%d",s[i],b=1);
            if(i==8) ;
            else if(i==7) printf("x");
            else printf("x^%d",8-i);
        }
        if(b==0) printf("0");
        printf("\n");
    }
    return 0;
}