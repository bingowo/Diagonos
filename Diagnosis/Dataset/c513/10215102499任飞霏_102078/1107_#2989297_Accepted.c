#include <stdio.h>
#include <stdlib.h>

int change(int x)
{
    if(x==1)return 0;
    else
        return 1;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int a[3][3],b[3][3];
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                a[j][k]=1;
                scanf("%d",&b[j][k]);
            }
        }
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                int t=b[j][k]%2;
                if(t==1){
                    a[j][k] = change(a[j][k]);
                    if(j>0)a[j-1][k] = change(a[j-1][k]);
                    if(j<2)a[j+1][k] = change(a[j+1][k]);
                    if(k>0)a[j][k-1] = change(a[j][k-1]);
                    if(k<2)a[j][k+1] = change(a[j][k+1]);
                }
            }

        }
        for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    printf("%d ",a[j][k]);
                }
                printf("\n");
        }
    }
    return 0;
}
