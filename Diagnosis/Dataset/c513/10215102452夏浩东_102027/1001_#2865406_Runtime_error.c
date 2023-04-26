#include <stdio.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        int m=0,n=0,t=0;
        int L[32];
        scanf("%d %d",&m,&n);
        if(m<0){
            printf('-');
        }
        while(m!=0)
        {
            int q=m%n;
            m=m/n;
            L[t]=q;
            t++;
        }
        for(int k=0;k<t;k++)
        {
            if(L[k]>9){
                printf("%c",(char)(L[k]-10+'A'));
            }
            else{
                printf("%d",L[k]);
            }
            if(k==t) printf("\n");
        }
    }
    return 0;
}
