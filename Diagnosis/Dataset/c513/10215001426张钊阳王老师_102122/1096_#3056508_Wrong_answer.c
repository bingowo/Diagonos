#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int z=0;z<T;z++)//每组数据都会出一个答案
    {
        int n;
        scanf("%d",&n);
        int *a=(int *)malloc(sizeof(int)*n);
        int *b=(int *)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++)
        {
            scanf("%d %d",&a[j],&b[j]);
            int flag0=1;
            for(int g=0;g<j;g++)
            {
                if(a[g]==a[j]&&b[g]==b[j]) flag0=0;
            }
            if(flag0==0) j--;
        }
        int in[100]={0},out[100]={0};//变成同一个数字那就不影响 所以可以先预处理 去重

        for(int j=0;j<n;j++)
        {
            in[a[j]]++;
            out[b[j]]++;
        }
        int flag=0;
        for(int i=1;i<=100;i++)
        {
            if(in[i]>=2||(in[i]>=1&&out[i]>=1)) {flag=1;break;}
            else ;
        }
        if(flag==0) printf("Lucky dxw!\n");
        else if(flag==1) printf("Poor dxw!\n");
        free(a);
        free(b);
    }
    return 0;
}
