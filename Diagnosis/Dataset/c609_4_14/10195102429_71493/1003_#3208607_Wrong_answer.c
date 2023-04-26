#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int a[10000];
        int n;
        scanf("%d",&n);
        int j=0;
        if(n==0){printf("0\d"); continue;}
        while(n){
        a[j]=n%2333;
        j++;
        n/=2333;
        }
        for(int i=j-1;i>=0;i--){
           if(i!=0){
            printf("%d ",a[i]);}
            else printf("%d\n",a[i]);
        }
    }
    return 0;
}
