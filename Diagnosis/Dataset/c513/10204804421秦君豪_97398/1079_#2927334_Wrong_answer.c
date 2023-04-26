#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void *b)
{
    long long int *a1=(long long int*)a;
    long long int *a2=(long long int*)b;
    return ((*a1)>(*a2))?1:-1;
}

int main()
{
    int T,k;
    int n,m,j,i,len,L=0,U=0;
    scanf("%d",&T);
    for(k=0;k<T;k++)
    {
        scanf("%d%d",&n,&m);
        long long int  a[1001]={0};
        long long int* b=(long long int*)malloc(500501*(sizeof(long long int)));
        memset(b,0,500501);
        int cnt =0;
        for(j=1;j<=n;j++)
        {
            scanf("%d",a+j);
            a[j]+=a[j-1];
        }
        for(len=1;len<=n;len++)
        {
            for(i=1;i<=n-len+1;i++)
            {
            	
                b[++cnt]=a[i+len-1]-a[i-1];
//                printf("b[%d]=%d\n",cnt,b[cnt]);
            }
        }
        qsort(b,cnt+1,sizeof(b[0]),cmp);
//        for(i=0;i<=cnt;i++) printf("b[%d]=%d\n",i,b[i]);
        for(i=1;i<=cnt;i++) b[i]+=b[i-1];
        printf("case #%d:\n",k);
        for(j=1;j<=m;j++)
        {
        	scanf("%d%d",&L,&U);
//        	printf("L=%d,u=%d\n",L,U) ;
            printf("%d\n",b[U]-b[L-1]);
        }
        free(b);
    }
    
    return 0; 
}
