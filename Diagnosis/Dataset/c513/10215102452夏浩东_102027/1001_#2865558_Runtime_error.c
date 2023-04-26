#include <stdio.h>
int main()
{
    int cnt=0;
    int L1[100];
    int L2[100];
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        scanf("%d %d",&L1[i],&L2[i]);
    }
    for(int i=0;i<cnt;i++)
    {
        int t=0;
        int L[100];
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
