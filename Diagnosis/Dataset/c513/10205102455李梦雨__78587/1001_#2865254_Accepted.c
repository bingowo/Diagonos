#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    char a[27];
    for(int i=0;i<26;i++)
    {
        a[i]='A'+i;
    }
    for(int i=0;i<T;i++)
    {
        int n,r;
        scanf("%d %d",&n,&r);
        int b[50],k=0;
        if(n<0)
        {
            printf("-");
            n=-n;
        }
        while(n>0){
            b[k]=n%r;
            k++;
            n=n/r;
        }
        k--;
        for(;k>=0;k--)
        {
            if(b[k]<=9)
                printf("%d",b[k]);
            else{
                int j=b[k];
                printf("%c",a[j-10]);
            }
        }
        printf("\n");
    }
    return 0;
}
