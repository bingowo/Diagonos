#include<stdio.h>
#define N 201
int slo(int d,char c)
{
    d=d>=360?d%360:d;
    d/=90;
    if(c=='L'&&d)d=4-d;
    return d;
}
int main()
{
    int w,h,d,i,j,p,q;
    char c;
    int a[N][N]={0};
    scanf("%d %d %d ",&w,&h,&d);
    c=getchar();
    for(i=1;i<=h;++i)
    	for(j=1;j<=w;++j)
			scanf("%d",&a[i][j]);
    d=slo(d,c);
    switch (d)
    {
        case 0:
        {
            printf("%d %d\n",w,h);
            for(i=1;i<=h;++i)
            {
                for(j=1;j<=w;++j)
                    printf("%d ",a[i][j]);
                printf("\n");
            }
            return 0;
        }
        case 1:
        {
            printf("%d %d\n",h,w);
            for(i=1;i<=w;++i)
            {
                for(j=h;j>0;--j)
                	printf("%d ",a[j][i]);
                printf("\n");
            }
            return 0;
        }
        case 2:
        {
            printf("%d %d\n",w,h);
            for(i=h;i>0;--i)
            {
                for(j=w;j>0;--j)
                    printf("%d ",a[i][j]);
                printf("\n");
            }
            return 0;
        }
        case 3:
        {
            printf("%d %d\n",h,w);
            for(i=w;i>0;--i)
            {
                for(j=1;j<=h;++j)
                    printf("%d ",a[j][i]);
                printf("\n");
            }
            return 0;
        }
    }
}