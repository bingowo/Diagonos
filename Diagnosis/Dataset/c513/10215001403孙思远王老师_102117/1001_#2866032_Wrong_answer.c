#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,t,n,r,j,k=0;
    char m[100];
    int flag=0;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        k=0;
        scanf("%d %d",&n,&r);
        if(n<0){flag=1;n=-n;}
        while(n!=0)
        {
            if(n>=r)
            {
                if(n%r<10)m[k]=n%r+'0';
                else m[k]=n%r+'A'-10;
            n/=r;
            k++;}
            else{
                m[k]=n+'0';
                n=0;
                k++;}
        }
        if(flag)printf("-");
        for(j=k-1;j>=0;j--)
        printf("%c",m[j]);
        printf("\n");
    }
    return 0;
}
