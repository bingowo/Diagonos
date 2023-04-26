#include <stdio.h>
#include <stdlib.h>


int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int n,m,i,j,all=0,wei;
        scanf("%d%d",&n,&m);
        int n2=n*(n+1)/2;
        int s1[n],s2[n2];
        for(i=0;i<n2;i++)
            s2[i]=0;
        for(i=0;i<n;i++)
            scanf("%d",&s1[i]);
        for(wei=1;wei<=n;wei++)
        {
            for(i=0,j=0;i<n;i++)
            {
                s2[all]+=s1[i];
                j++;
                if(j==wei)
                {
                    all++;
                    j=0;
                    if(i+1==n)
                        break;
                    i=i-wei+1;
                }
            }
        }
        qsort(s2,n2,sizeof(s2[0]),cmp);
        for(i=0;i<m;i++)
        {
            int l,u,x=0;
            scanf("%d%d",&l,&u);
            l--,u--;
            while(l<=u)
            {
                x+=s2[l];
                l++;
            }
            printf("%d\n",x);
        }
    }
    return 0;
}
