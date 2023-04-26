#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    char s[100];int i=0;
    if(a==0) printf("0");
    while(a!=0)
    {
        int r=a%b;
        if(r<0)
        {
            r=r-b;
            if(r>=10) s[i++]=r-10+'A';
            else s[i++]=r+'0';
            a=a/b+1;
        }
        else
        {
            if(r>10) s[i++]=r-10+'A';
            else s[i++]=r+'0';
            a=a/b;
        }
    }
    for(int j=i-1;j>=0;j--)
    {
        printf("%c",s[j]);
    }
    return 0;
}
