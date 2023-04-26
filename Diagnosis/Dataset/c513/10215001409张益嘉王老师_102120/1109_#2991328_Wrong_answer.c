#include <stdio.h>
#include <stdlib.h>

int flag;

void shuchu(int xi,int mi)
{
    if(xi==0) return;
    if((xi>0)&&(flag)) {if((xi!=1)||(mi==0)) printf("+%d",xi);else printf("+");}
    else if(xi>0) {if(xi!=1) printf("%d",xi);}
    else if((xi<0)&&(flag)) {if((xi!=-1)||(mi==0)) printf("%d",xi);else printf("-");}
    else if(xi<0) {if(xi!=-1) printf("%d",xi); else printf("-");}

    if(mi==0) return;
    else if(mi==1) printf("x");
    else printf("x^%d",mi);
    flag=1;
}

int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int xi[10],j,k;
        flag=0;
        memset(xi,0,sizeof(int)*10);
        for(j=0;j<9;j++)
        {
            scanf("%d",&xi[j]);
        }
        printf("case #%d:\n",i);
        for(j=0;j<9;j++)
        {
            shuchu(xi[j],8-j);
        }
        if(flag==0) printf("0");
        printf("\n");
    }
    return 0;
}
