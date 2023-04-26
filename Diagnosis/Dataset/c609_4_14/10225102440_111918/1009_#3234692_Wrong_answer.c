#include <stdio.h>
#include <stdlib.h>
int num(int x){
    int n=0;
    if(x==0)return 0;
    while(x){
        n+=x%2;
        x=x/2;
    }
    return n;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][120],i,j,t,x[n],k;
    char c;
    c=getchar();
    for(i=0;i<n;i++){
        j=0;
        while((c=getchar())!='\n'){
            a[i][j]=c;
            j++;
        }
        x[i]=j;
    }
    for(i=0;i<n;i++){
        t=0;
        j=0;
        for(j=0;j++;j<x[i]){
            printf("%d\n",a[i][j]);
            t=t+num(a[i][j]);
        }
        k=x[i]*8;
        for(j=t;j>1;j--){
            if((t%j==0)&&(k%j==0)){
                t=t/j;
                k=k/j;
            }
        }
        printf("%d/%d\n",t,k);
    }
    return 0;
}
