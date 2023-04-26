#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cl(int n,int tmp,char a[])
{
    for(int i=3*tmp;i>=0;i--)
    {
        if(n&1)
            a[i]=1+'0';
        else
            a[i]=0+'0';
        n=n>>1;
    }
    a[3*tmp+1]='\0';
}
int main()
{
    char s[505];
    scanf("%s",s);
    int len=strlen(s);
    printf("0001");
    char b[15];
    cl(len,3,b);
    printf("%s",b);
    for(int i=0;i<len;i+=3)
    {
        int n=0,tmp;
        char a[15];
        tmp=len-i;
        tmp=tmp>=3?3:tmp;
        for(int j=i;j<i+tmp;j++)
        {
            n=n*10+s[j]-'0';
        }
      // printf("\n%d\n",n);
        cl(n,tmp,a);
        printf("%s",a);
    }

    return 0;
}
