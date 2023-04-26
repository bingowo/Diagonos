#include <stdlib.h>
#include <stdio.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int t=0;t<cnt;t++)
    {
        int n=0,m=0;
        long long int res=1,left=1;
        scanf("%d %d",&n,&m);
        int num=n;
        int *L =(int*)malloc(m*sizeof(int));
        for(int i=0;i<m;i++) L[i]=num--;
        for(int k=m;k>=1;k--)
        {
        	int flag=1;
            for(int j=0;j<m-1;j++)
            {
                if(L[j]%k==0) {
					L[j]=L[j]/k;
					flag=0;
					break; 
				}
            }
            if(flag==1) left=left*k; 
            //for(int i=0;i<m;i++) printf("%d ",L[i]);
        	//printf("\n");
        }
        for(int i=0;i<m;i++) res=res*L[i];
        printf("case #%d:\n",t);
        printf("%lld\n",res/left);
        free(L);
    }
 	return 0;
}