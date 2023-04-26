#include <stdio.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    int *L1;
    int *L2;
    int m=0,n=0;
    for(int i=0;i<cnt;i++)
    {
        int t=0;
        int L[10];
        scanf("%d %d",&m,&n);
        if(m<0){
            printf('-');
        }
        while(m!=0)
        {
            int q=m%n;
            L1[i]=m/n;
            L[t]=q;
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
    return 0;
}