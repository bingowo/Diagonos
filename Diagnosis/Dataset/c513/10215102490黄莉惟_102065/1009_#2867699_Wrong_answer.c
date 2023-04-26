#include<stdio.h>
#include<string.h>
int main(){
    int n,i,j;
    char s[120];
    scanf("%d",&n);
    int m=0;
    while(m<n){
        scanf("%s",s);
        for(i=0;i<strlen(s);i++){
            for(j=0;j<=7;j++){
                printf("%d\n",s[i]&(1<<j));
            }
        }
        
        m++;
    }
}