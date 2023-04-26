#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){
    int t,sum;
    int m=0;
    int k,i;
    char s[100];
    scanf("%d",&t);
    while(m<t){
        k=1;
        sum=0;
        scanf("%s",s);
        for(i=strlen(s)-1;i>=0;i--){
            if(s[i]=='1'){
                sum=sum+k;
            }
            if(s[i]=='-'){
                sum=sum-k;
            }else{
                sum=sum;
            }
            k*=3;
        }
        printf("case #""%d",m);
        printf(":");
        printf("\n");
        printf("%d\n",sum);
        m++;
    }
}