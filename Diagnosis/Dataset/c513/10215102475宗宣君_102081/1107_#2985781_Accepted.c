#include <stdio.h>
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    for(k = 0;k<T;k++)
    {
        int a[3][3],n[3][3];
        for(i = 0;i<3;i++)
        {for(j = 0;j<3;j++)
            {scanf("%d",&a[i][j]);
            n[i][j] = 0;}}
        for(i = 0;i<3;i++)
            for(j = 0;j<3;j++)
        {
            if(a[i][j]%2==1)
            {
                n[i][j]++;
                if(i==0) {n[i+1][j]++;}
                if(i==1) {n[i+1][j]++;n[i-1][j]++;}
                if(i==2) {n[i-1][j]++;}
                if(j==0) {n[i][j+1]++;}
                if(j==1) {n[i][j-1]++;n[i][j+1]++;}
                if(j==2) {n[i][j-1]++;}


            }
        }
        printf("case #%d:\n",k);
        for(i = 0;i<3;i++)
            {for(j = 0;j<3;j++)
                if(n[i][j]%2==1) printf("0 ");
                else printf("1 ");
                printf("\n");}
    }
    return 0;
}
