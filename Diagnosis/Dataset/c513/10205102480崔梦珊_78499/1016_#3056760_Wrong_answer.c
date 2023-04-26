#include<stdio.h>
int main()
{
    int n,r;
    scanf("%d %d",&n,&r);
    int res[100];
    int i=0;
    while(n)
    {
        /*printf("%d",n);*/
        if(n>=0)
        {
            res[i]=n%r;
            n=(n-res[i])/r;
            i++;
        }
        else
        {
            res[i]=-(n%r);
            n=(n-res[i])/r;
            /*printf("bb%d:%d  n=%d\n",i,res[i],n);*/
            i++;
        }
    }
    char s[16]="0123456789ABCDEF";
    for(int j=i-1;j>=0;j--)
    {
        printf("%c",s[res[j]]);
    }

}
