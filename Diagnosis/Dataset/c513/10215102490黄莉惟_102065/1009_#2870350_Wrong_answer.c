#include<stdio.h>
#include<string.h>
int main(){
    int n,i,j,num,num1;
    char s[300];
    scanf("%d",&n);
    int m=0;
    while(m<n){
        num=0;
        scanf("%s",s);
        for(i=0;i<strlen(s);i++){
            for(j=0;j<=31;j++){
                if((s[i]&(1<<j))!=0){
                    num++;
                }
            }
        }
        
        printf("%d/%d\n",num,num1);
        printf("%d",strlen(s));
        m++;
    }
}