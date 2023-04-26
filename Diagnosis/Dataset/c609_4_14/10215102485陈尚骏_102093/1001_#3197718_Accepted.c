#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    int n,r,i;
    while(t--){
    while(scanf("%d %d",&n,&r)!=EOF)
    {
        if(n<0)
        {
            printf("-");n=-n;
        }
        if(n==0){printf("0\n");continue;}
        int c=0,a[100];
        while(n)
        {
            a[c]=(n%r);
            c++;
            n/=r;
        }
        for(i=c-1;i>=0;i--)
        {
            if(a[i]>=10)
            {
                printf("%c",'A'+a[i]-10);
            }
            else printf("%d",a[i]);
        }
        printf("\n");
    }
    }
    return 0;
}