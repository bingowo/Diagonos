#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int s[100];int i=0;
    while(a!=0)
    {
        int r=a%b;
        if(r<0)
        {
            r=abs(r);
            if(r>10) s[i++]=r-10+'A';
            else s[i++]=r;
            a=a/b+1;
        }
        else
        {
            if(r>10) s[i++]=r-10+'A';
            else s[i++]=r;
            a=a/b;
        }
        for(int j=i-1;j>=0;j--)
        {
            printf("%d",s[j]);
        }
    }
    return 0;
}
