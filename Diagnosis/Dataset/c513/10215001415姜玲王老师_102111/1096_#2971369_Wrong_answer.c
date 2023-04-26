#include <stdio.h>
#include <stdlib.h>
typedef struct {int in;int out;} order;
int main()
{int n;
scanf("%d",&n);
int t=0;
for(t=0;t<n;t++)
{   int c[100]={0},d[100]={0};
    int a,j,i;
    scanf("%d",&a);
    order b[100];
    for( i=0;i<a;i++)
    {
        scanf("%d%d",&b[i].in,&b[i].out);

    }
    for(i=0;i<a;i++)
    {
        c[b[i].in-1]++;
    }
    for(i=0;i<a;i++)
    {
        d[b[i].out-1]++;
    }
    for(i=0;i<100;i++)
    {
        if((c[i]>=1&&d[i]>=1)&&d[i]>=2) {printf("Poor dxw!\n");break;}
    }
    if(i==100)
   {printf("Lucky dxw!\n");}
}
}

