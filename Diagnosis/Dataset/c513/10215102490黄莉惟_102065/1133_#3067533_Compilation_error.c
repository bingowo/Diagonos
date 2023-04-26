#include<stdio.h>
#include<string.h>
char *anti(char *s,int cnt){
    char s1[35000];
    strcpy(s1,s);
    for(int k=0;k<cnt;k++){
        if(s1[k]=='1'){
            s1[k]='0';
        }else{
            s1[k]='1';
        }
    }
    return s1;
}
int main(){
    int i;
    scanf("%d",&i);
    char s[35000];
    char s1[35000];
    s[0]='0';
    s[1]='1';
    int cnt=1;
    for(int j=0;j<i;j++){
        s1=anti(s,cnt);
        strcat(s,s1);
        cnt*=2;
    }
    printf("%s",s);
    return 0;
}