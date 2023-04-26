#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef struct{int cnt,v[334];}BIGINT;
BIGINT int2BIG(int x)
{
    BIGINT R={0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    }
    while(x>0);
    return R;
}
BIGINT ADD(BIGINT S,BIGINT T)
{
    BIGINT R={0};
    int i,carry=0;
    for(i=0;i<S.cnt&&i<T.cnt;i++)
    {
        int temp=(S.v[i]+T.v[i]+carry);
        R.v[i]=temp%10;
        carry=temp/10;
    }
    while(i<S.cnt)
    {
        int temp=S.v[i]+carry;
        R.v[i++]=temp%10;
        carry=temp/10;
    }
    while(i<T.cnt)
    {
        int temp=T.v[i]+carry;
        R.v[i++]=temp%10;
        carry=temp/10;
    }
    if(carry)
    {
        R.v[i++]=carry%10;
    }
    R.cnt=i;
    return R;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a[5][5],x,y,z;
        for(x=0;x<5;x++)for(y=0;y<5;y++)a[x][y]=1;
        for(x=1;x<=3;x++)for(y=1;y<=3;y++)
        {
            scanf("%d",&z);
            if(z%2==1){a[x][y]=1-a[x][y];a[x-1][y]=1-a[x-1][y];a[x+1][y]=1-a[x+1][y];a[x][y-1]=1-a[x][y-1];a[x][y+1]=1-a[x][y+1];}
        }
        printf("case #%d:\n",i);
        for(x=1;x<=3;x++)
        {
            for(y=1;y<=2;y++)printf("%d ",a[x][y]);
            printf("%d\n",a[x][y]);
        }

    }
}
