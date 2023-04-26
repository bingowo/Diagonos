#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
struct p
{
    double len;
    double arch;
} a[1001];
int cmp(const void*a,const void*b)
{
    double a1=((struct p*)a)->arch,b1=((struct p*)b)->arch;
    double a2=((struct p*)a)->len,b2=((struct p*)b)->len;
    if (a1>=b1+0.0001) return 1;
    else if(b1>=a1+0.0001) return -1;
    else if (a2>=b2+0.0001) return -1;
    else if(b2>=a2+0.0001) return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    double x,y;
    char x1[20],y1[20];
    for (int i=0; i<t; i++)
    {
        int n;
        scanf("%d",&n);
        for (int j=0; j<n; j++)
        {
            scanf("%s%s",&x1,&y1);
            x=atof(x1);
            y=atof(y1);
            a[j].len=sqrt(x*x+y*y);
            if (x<=-0.001||x>=0.0001)
            {
                a[j].arch=atan(y/x);
                if (a[j].arch<0.0&&y<-0.0001) a[j].arch+=3.14159265354*2.0000000;
                if (a[j].arch<0.0&&x<-0.0001||(a[j].arch==0.0&&x<0.0)) a[j].arch+=3.14159265354;
                if (x<0.0&&y<0.0) a[j].arch+=3.14159265354;
            }
            else if (y>0.0001)
            {
                a[j].arch=3.14159265354/2.00000;
            }
            else
            {
                a[j].arch=3.14159265354*1.500000;
            }

        }
        printf("case #%d:\n",i);
        qsort(a,n,sizeof(a[0]),cmp);
        for (int j=0; j<n; j++)
            printf("(%.4lf,%.4lf)\n",a[j].len,a[j].arch);
    }
    return 0;
}