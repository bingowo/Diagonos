#include <stdio.h>
#include <stdlib.h>
typedef struct {int in;int out;} order;
int main()
{int n;
scanf("%d",&n);
int t=0;
for(t=0;t<n;t++)
{
    int a;
    scanf("%d",&a);
    order b[100];
    for(int i=0;i<a;i++)
    {
        scanf("%d%d",&b[i].in,&b[i].out);

    }
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<a;j++)
        {
          if(b[i].in==b[j].out){printf("Poor dxw!\n");return 0;}
        }
    }
   printf("Lucky dxw!\n");
   return 0;
}
}

