#include <stdlib.h>
#include <stdio.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int t=0;t<cnt;t++)
    {
        int n=0,m=0;
        long long int res=1;
        scanf("%d %d",&n,&m);
        int num=n;
        int *L =(int*)malloc(m*sizeof(int));
        for(int i=0;i<m;i++) L[i]=num--;
        for(int k=1;k<=m;k++)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(L[j]%k==0) {
					L[j]=L[j]/k;
					break; 
				}
            }
        }
        for(int i=0;i<m;i++) res=res*L[i];
        printf("case #%d:\n",t);
        printf("%lld\n",res);
        free(L);
    }
 	return 0;
}