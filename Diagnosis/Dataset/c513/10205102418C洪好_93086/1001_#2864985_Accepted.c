#include <stdio.h>
#include <stdlib.h>

void trans(int x,int r)
{
    int a[100],cnt=0;
    while(x!=0)
    {
        a[cnt]=(x%r);
        cnt++;
        x/=r;
    }
    for(int i=cnt-1;i>=0;i--)
    {
        if(a[i]>=10)
            printf("%c",(a[i]-10+'A'));
        else printf("%d",a[i]);
    }
}

int main()
{
    int t;scanf("%d",&t);
    //getchar();
    for(int i=0;i<t;i++)
    {
        int n;scanf("%d",&n);getchar();
        int r;scanf("%d",&r);
        if(n<0)
        {
            int temp=-n;printf("-");
            trans(temp,r);
        }
        else if(n==0) printf("0");
        else trans(n,r);
        printf("\n");
    }
    return 0;
}
