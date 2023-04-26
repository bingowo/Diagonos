#include<stdio.h>

int main()
{
    int n,r,k=0;
    char s[17]="0123456789ABCDEF",c[100];
    scanf("%d %d",&n,&r);
    while(n)
    {
        c[k]=s[n%r];
        n/=r;
        k++;
    }
    for(int i=k-1;i>=0;i--)
    {
        printf("%c",c[i]);
    }
    return 0;

}
