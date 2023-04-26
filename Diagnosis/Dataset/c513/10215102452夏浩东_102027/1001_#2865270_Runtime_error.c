#include <stdio.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    int *L1;
    int *L2;
    L1 = (int*)malloc(cnt*sizeof(int));
    L2 = (int*)malloc(cnt*sizeof(int));
    for(int i=0;i<cnt;i++)
    {
        int t=0;
        int L[10];
        scanf("%d %d",&L1[i],&L2[i]);
        if(L1[i]<0){
            printf("-");
        }
        while(L1[i]!=0)
        {
            int m=L1[i]%L2[i];
            L1[i]=L1[i]/L2[i];
            L[t]=m;
            t++;
        }
        for(int k=t;k>0;k--)
        {
            if(L[k]>9){
                printf((char)(L[k]-10+'A'));
            }
            else{
                printf(L[k]);
            }
            if(k==0) printf("\n");
        }
    }
    free(L1);
    free(L2);
    return 0;
}