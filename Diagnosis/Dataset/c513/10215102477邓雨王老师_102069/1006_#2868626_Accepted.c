#include<stdio.h>
#include<string.h>
int main(){
    int chance;
    scanf("%d",&chance);
    int i;
    for(i=0;i<chance;i++){
        printf("case #%d:\n",i);
        int sum=0;
        char s[100];
        scanf("%s",&s);
        int j;
        for(j=0;j<strlen(s);j++){
            if(s[j]=='-') sum=sum*3+(-1);
            else if(s[j]=='1') sum=sum*3+1;
            else sum=sum*3+0;
        }
        printf("%d\n",sum);
    }
}