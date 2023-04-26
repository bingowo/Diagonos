#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){
    int t,k,j,r,sum;
    scanf("%d",&t);
    int i,num;
    char s[1000];
    char s1[1000];
    int s2[1000];
    for(i=0;i<t;i++){
        scanf("%s",s);
        memset(s1,0,sizeof(s1));
        s1[0]=s[0];
        num=1;
        sum=1;
        for(j=1;j<strlen(s);j++){
            if(s[j]==s[j-1]){
                sum++;
            }
            if(s[j]!=s[j-1]){
                s1[num]=s[j];
                s2[num]=sum;
                num++;
                sum=1;
            }
        }
        printf("case #%d:\n",i);
        for(j=0;j<num;j++){
            printf("%c",s2[j]-'0');
            printf("%c",s1[j]);
        }
        
    }
}