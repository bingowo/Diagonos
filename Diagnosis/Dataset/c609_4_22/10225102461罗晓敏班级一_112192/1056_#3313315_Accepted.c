#include <stdio.h>
int main(){
    int t;scanf("%d",&t);
    long long int num[41][41]={0};
    int i,j;
    for(i=1;i<41;i++){
    	num[i][0]=1;
        num[i][1]=i;
        num[i][i]=1;
    }
    for(i=2;i<41;i++){
        for(j=2;j<41;j++){
            num[i][j]=num[i-1][j-1]+num[i-1][j];
        }
    }
    for(i=0;i<t;i++){
        int m,n;scanf("%d%d",&m,&n);
        printf("case #%d:\n",i);
        printf("%lld\n",num[m][n]); 
    }
}