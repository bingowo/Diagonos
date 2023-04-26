#include <stdio.h>

int main()
{
    int l[5][5];
    int t,i,j,k,x;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        for(j=0;j<5;j++)
            for(k=0;k<5;k++)
                l[j][k]=1;
        for(j=1;j<4;j++)
            for(k=1;k<4;k++){
                scanf("%d",&x);
                if(x%2==1){
                    l[j][k]=l[j][k]*(-1);
                    l[j-1][k]=l[j-1][k]*(-1);
                    l[j][k-1]=l[j][k-1]*(-1);
                    l[j+1][k]=l[j+1][k]*(-1);
                    l[j][k+1]=l[j][k+1]*(-1);
                }
            }
        printf("case #%d:\n",i);
        for(j=1;j<4;j++)
            for(k=1;k<4;k++){
                if(l[j][k]==1)
                    printf("1");
                else
                    printf("0");
                if(k==3)
                    printf("\n");
                else
                    printf(" ");
            }
    }
    return 0;
}
