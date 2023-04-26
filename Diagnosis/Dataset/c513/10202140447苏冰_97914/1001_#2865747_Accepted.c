#include <stdio.h>
int main()
{
    int T,flag=0;
    scanf("%d",&T);
    int n,r,a[40];
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=1;i<=T;i++)
    {
        scanf("%d %d",&n,&r);
        int j=0;
        if(n<0)
        {
            n=-n;
            flag=1;
        }
         do
        {
            a[j]=n%r;
            n=n/r;
            j++;
        }while(n!=0);
        if(flag)  printf("-");
        for(int k=j-1;k>=0;k--)
        {
            int m=a[k];
            printf("%c",table[m]);
        }
        printf("\n");
        flag=0;
    }
    return 0;
}
