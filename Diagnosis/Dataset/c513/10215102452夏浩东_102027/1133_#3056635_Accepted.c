#include <stdio.h>
int L[2<<15];
int main()
{
    int num=0,k=1;
    scanf("%d",&num);
    L[0]=0;
    for(int i=0;i<num;i++){
        for(int j=k;j<2*k;j++){
            L[j]= L[j-k]==0?1:0;
        }
        k=k*2;
    }
    for(int i=0;i<k;i++){
        printf("%d",L[i]);
    }
    return 0;
}