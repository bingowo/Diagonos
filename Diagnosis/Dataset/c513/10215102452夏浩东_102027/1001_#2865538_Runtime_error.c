#include <stdio.h>
int main()
{
    int cnt=0;
    int L1[10000];
    int L2[10000];
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        int t=0;
        int L[32];
        scanf("%d %d",&L1[i],&L2[i]);
        if(L1[i]<0){
            printf('-');
        }
        while(L1[i]!=0)
        {
            int q=L1[i]%L2[i];
            L1[i]=L1[i]/L2[i];
            L[t]=q;
            t++;
        }
        for(int k=t-1;k>=0;k--)
        {
            if(L[k]>9){
                printf("%c",(char)(L[k]-10+'A'));
            }
            else{
                printf("%d",L[k]);
            }
            if(k==0) printf("\n",L[k]);
        }
    }
    return 0;
}
