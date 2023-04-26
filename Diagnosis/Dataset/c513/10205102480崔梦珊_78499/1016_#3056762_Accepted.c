#include<stdio.h>
int main()
{
    int n,r;
    scanf("%d %d",&n,&r);
    int res[100];
    int i=0;
    do
    {
        res[i]=(n%r-r)%r;
        i++;
    }while(n=(n-res[i-1])/r);
    char s[36]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int j=i-1;j>=0;j--)
    {
        printf("%c",s[res[j]]);
    }

}
