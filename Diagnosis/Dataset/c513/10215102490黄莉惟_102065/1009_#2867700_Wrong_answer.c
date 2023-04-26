#include<stdio.h>
#include<string.h>
int main(){
    int n,i,j,num;
    char s[120];
    scanf("%d",&n);
    int m=0;
    while(m<n){
        num=0;
        scanf("%s",s);
        for(i=0;i<strlen(s);i++){
            for(j=0;j<=7;j++){
                if((s[i]&(1<<j))!=0){
                    num++;
                }
            }
        }
        printf("%d\n",num);
        m++;
    }
}