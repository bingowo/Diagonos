#include <stdio.h>
#include <stdlib.h>

int main()
{
    int  i,j,t,m,n,x[20];
    char y[10];
    scanf("%d",&t);
    for(i=0;i<2*t;i++)
    {
      scanf("%d",&x[i]);
    }
    for(j=0;j<t;j++)
    {
        if(x[2*j]>10)
            {x[2*j]=16;}
        for(m=0;x[j]!=0;m++)
        {
            n=x[j]%x[2*j];
            if(n<10){y[m]='0'+n;}
            else{y[m]=n-10+'A';}
            x[j]=x[j]/x[2*j];
        }
        for(;m>=0;m--)
        {

          printf("%c",y[m]);}
          printf("\n");


    }

    return 0;
}