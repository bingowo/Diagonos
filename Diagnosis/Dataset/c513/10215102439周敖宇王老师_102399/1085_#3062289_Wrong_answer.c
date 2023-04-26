#include<stdio.h>
#include<string.h>
typedef struct
{
    int digit;
    char num[600];
}BIGINT;

int main()
{
    BIGINT a,b,c;
    int ans[600]={0},i,j;
    while(scanf("%s%s",a.num,b.num)!=EOF)
    {
        //getchar();
        a.digit=strlen(a.num);
        b.digit=strlen(b.num);
        if(strcmp(a.num,b.num)<0)
        {
            printf("-");
            c=a;
            a=b;
            b=c;
        }
        for(i=0;i<a.digit;i++)
        {
            if(i<b.digit)  ans[a.digit-1-i]=a.num[a.digit-1-i]-b.num[b.digit-1-i];
            if(ans[a.digit-1-i]<0)
            {
                ans[a.digit-1-i]+=10;
                ans[a.digit-1-i-1]--;
            }
        }
        for(i=0;i<a.digit;i++)
        {
            while(ans[i]==0) i++;
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}