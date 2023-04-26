#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
char a[MAX];
char str[36]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int main()
{
    int n,x,k,flag,i,j,T;
    scanf("%d",&T);
    while(scanf("%d%d",&n,&x)!=EOF){
        flag=0;
        if(n<0){
            flag=1;
            n=-n;
        }
        i=0;
        while(n){
            k=n%x;
            a[i]=str[k];
            n/=x;
            i++;
        }
        if(flag){
            printf("-");
        }
        for(j=i-1;j>=0;j--){
            printf("%c",a[j]);
        }
        printf("\n");
    }
    return 0;
}
