#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cas,i,j,k,l,n,m,start,end,flag,tmp[1007],ans[1007];
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        flag = 0;
        scanf("%d%d",&n,&m);
        tmp[0] = n;
        l = 0;
        k = 1;
        while(n)
        {
            ans[l++] = n*10/m;
            n = n*10%m;
            for(j = 0; j < k; j++)
            {
                if(n == tmp[j])
                {
                    start = j+1;
                    end = k;
                    flag = 1;
                    break;
                }
            }
            tmp[k++] = n;
            if(flag == 1)break;
        }
        printf("case #%d:\n0.",i);
        for(j = 0; j < l; j++)printf("%d",ans[j]);
        printf("\n");
        if(flag == 1)printf("%d-%d\n",start,end);
    }
    return 0;
}