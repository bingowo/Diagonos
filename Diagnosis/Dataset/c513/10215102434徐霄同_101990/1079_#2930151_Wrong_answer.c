#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    return(*(int*)a-*(int*)b);
}
int main()
{
    int a[1000],b[500500];
    int t,i,j,k,p,s,n,m,l,u;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d%d",&n,&m);
        for(j=0;j<n;j++){
            scanf("%d",&a[j]);
            if(j>0)
                a[j]=a[j]+a[j-1];
        }
        p=0;
        for(j=0;j<n;j++)
            for(k=j;k<n;k++){
                if(k==j)
                    b[p]=a[j];
                else
                    b[p]=a[k]-a[j];
                p++;
            }
        qsort(b,p,sizeof(b[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<m;j++){
            scanf("%d%d",&l,&u);
            s=0;
            for(k=l-1;k<u;k++)
                s=s+b[k];
            printf("%d\n",s);
        }
    }
    return 0;
}
