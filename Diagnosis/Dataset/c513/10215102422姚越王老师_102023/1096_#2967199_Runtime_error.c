#include<stdio.h>
#define C 101
int main()
{
    int T,i,j,n;scanf("%d",&T);
    for(int cas=0;cas<T;++cas)
    {
        scanf("%d",n);int a[C],b[C],cnt1=0,cnt2=0,flag=1;
        for(i=0;i<n;++i)
        {
            if(i%2)scanf("%d",&b[++cnt2]);
            else scanf("%d",&a[++cnt1]);
        }
        for(i=0;i<cnt1;++i)
        {
            for(j=0;j<cnt2;++j)
                if(a[i]==b[i]){printf("Poor dxw!\n");flag=0;break;}
            if(!flag)break;
        }
        if(flag)printf("Lucky dxw!\n");
    }
    return 0;
}