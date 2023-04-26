#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t=0;
    int i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n=0,r=0;
        scanf("%d%d",&n,&r);
        char s[1000]={0};
        int sign=1;
        if(n<0)
        {
            sign=-1;
            n=-n;
        }
        int m=0;
        j=0;
        while(n)
        {
            m=n%r;
            n/=r;
            if(m<10)
                s[j++]=m+'0';
            if(m>=10)
                s[j++]=(m-10)+'A';
        }
        s[j]='\n';
        if(sign<0)
            printf("-");
        for(int k=j-1;j>=0;j--)
        {
            printf("%c",s[k]);
        }
        printf("\n");
    }
    //printf("Hello world!\n");
    return 0;
}
