#include<stdio.h>
#include<string.h>
int main(){
    int n,i,j,num,num1;
    i=0;
    char c1;
    scanf("%d",&n);
    int m=0;
    while(m<n){
        num=0;
        while(scanf("%c",&c1)!=EOF){
            num++;
            printf("%c",c1);
            scanf("%c",&c1);
        }
        printf("%d\n",num);
        m++;
        
    }
}