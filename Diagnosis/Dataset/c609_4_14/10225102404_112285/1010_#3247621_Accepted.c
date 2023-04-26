#include<stdio.h>
/*余数为负数时，商加一，余数减除数得新的余数*/
int main()
{
    int n,r,k=0;
    char s[21]="0123456789ABCDEFGHIJ",c[100];
    scanf("%d %d",&n,&r);
    if(n==0)
    {
        printf("%d",0);
        return 0;
    }
    while(n)/*N>0*/
    {
        if(n%r>=0)
        {
            c[k]=s[n%r];
            n/=r;
        }
        else
        {
            c[k]=s[n%r-r];
            n/=r;
            n++;
        }
        k++;
    }
    for(int i=k-1;i>=0;i--)
    {
        printf("%c",c[i]);
    }
    return 0;

}
