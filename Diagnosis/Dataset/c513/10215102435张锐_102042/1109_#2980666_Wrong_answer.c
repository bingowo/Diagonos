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
            else if(i==8&&b&&s[i]>0) printf("+%d",s[i]);
            else if(i==8&&b&&s[i]<0) printf("%d",s[i]);
            else if(s[i]==1&&b==0) printf("x^%d",8-i),b=1;
            else if(s[i]==1&&b) printf("+x^%d",8-i),b=1;
            else if(s[i]==1&&b==0) printf("x^%d",8-i),b=1;
            else if(s[i]==-1) printf("-x^%d",8-i),b=1;
            else if(s[i]>0&&b) printf("+%dx^%d",s[i],8-i),b=1;
            else if(s[i]>0&&b==0) printf("+%dx^%d",s[i],8-i),b=1;
            else if(s[i]<0) printf("%dx^%d",s[i],8-i),b=1;
        }
        if(b==0) printf("0");
        printf("\n");
    }
    return 0;
}
