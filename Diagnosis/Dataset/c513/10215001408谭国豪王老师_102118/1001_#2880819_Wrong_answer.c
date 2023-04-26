#include <stdio.h>
#include <stdlib.h>

int main()
{
    int  i,j,t,m,n,x[20],a=0;
    char y[10];
    scanf("%d",&t);
    for(i=0;i<2*t;i++)
    {
      scanf("%d",&x[i]);
    }
    for(j=0;j<t;j++)
    {
        if(x[2*j+1]>10)
            {x[2*j+1]=16;}
            if(x[2*j]<0)
            {
                x[2*j]=-x[2*j];a=1;
            }

        for(m=0;x[2*j]!=0;m++)
        {
            n=x[2*j]%x[2*j+1];
            if(n<10){y[m]='0'+n;}
            else{y[m]=n-10+'A';}
            x[2*j]=x[2*j]/x[2*j+1];
        }
        if(a==1)printf("-");
        for(;m>=0;m--)
        {

          printf("%c",y[m-1]);}
          printf("\n");


    }

    return 0;
}
