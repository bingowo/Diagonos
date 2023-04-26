#include<stdio.h>
#define C 101
int main()
{
    int T,i,j,n;scanf("%d",&T);
    for(int cas=0;cas<T;++cas)
    {
        scanf("%d",n);int a[C],b[C],flag=1;
        for(i=0;i<n;++i)
        {
            scanf("%d",&b[i]);
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;++i)
        {
            for(j=0;j<n;++j)
                if(a[i]==b[i]){printf("Poor dxw!\n");flag=0;break;}
            if(!flag)break;
        }
        if(flag)printf("Lucky dxw!\n");
    }
    return 0;
}