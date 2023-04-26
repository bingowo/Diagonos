#include <stdio.h>
#include <stdlib.h>
#define N 5000
int main()
{
    int t,arr[N][2];
    char rslt[N][100];
    int i=0,j=0;
    scanf("%d",&t);
    while(i<t)
    {
        scanf("%d%d",(*(arr+i)),(*(arr+i)+1));
        int n=*(*(arr+i)),r=*(*(arr+i)+1);
        if(n>0)
        do
        {
            rslt[i][j++]=(n%r)>=10?(char)(n%r-10+'A'):(char)(n%r+'0');
        }while(n/=r);
        else if(n<0)
        {
            n=abs(n);
            do
            {
                rslt[i][j++]=(n&r)>=10?(char)(n%r-10+'A'):(char)(n%r+'0');
            }while(n/=r);
            rslt[i][j++]='-';
        }
        rslt[i][j]=0;
        i++,j=0;
    }
    i=j=0;
    for(;i<t;i++)
    {
        while(rslt[i][++j]);
        for(;j>=0;)
        {
            printf("%c",rslt[i][--j]);
        }
        printf("\n");
        j=0;
    }
    return 0;
}
