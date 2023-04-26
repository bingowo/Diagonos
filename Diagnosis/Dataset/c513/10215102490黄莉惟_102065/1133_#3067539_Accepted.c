#include<stdio.h>
#include<string.h>
int main(){
    int i;
    scanf("%d",&i);
    char s[35000];
    char s1[35000];
    s[0]='0';
    s[1]='\0';
    int cnt=1;
    for(int j=0;j<i;j++){
        strcpy(s1,s);
        for(int k=0;k<cnt;k++){
            if(s1[k]=='1'){
                s1[k]='0';
            }else{
                s1[k]='1';
            }
        }
        strcat(s,s1);
        cnt*=2;
    }
    printf("%s",s);
    return 0;
}