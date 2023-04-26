#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    int *A=(int*)a;
    int *B=(int*)b;
    return(*B-*A);
}
int main()
{
    int n=1,m=1;
    while(n!=0 && m!=0)
    {
        scanf("%d %d",&n,&m);
        int a=0,b=0,c=0;
        int *L=(int*)malloc(n*sizeof(int));
        int *L1=(int*)malloc(n*sizeof(int));
        for(int t=0;t<n;t++) L[t]=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(c==1) {L[a-1]+=3;L[b-1]-=1;}
            else if(c==-1){L[a-1]-=1;L[b-1]+=3;}
            else {L[a-1]+=1;L[b-1]+=1;}
        }
        for(int i=0;i<n;i++) L1[i]=L[i];
        qsort(L1,n,sizeof(int),cmp);
        for(int i=0;i<n;i++)
		{
			for(int k=0;k<n;k++)
			{
				if(L[k]==L1[i])
				{
					if(i==n-1) printf("%d\n",k);
					else printf("%d ",k);
				}
			}
		} 
        free(L);
    }
    return 0;
}