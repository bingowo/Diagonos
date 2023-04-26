#include<stdio.h>//边判断边输出
#include<string.h>
#include<ctype.h>
int main(){
    char s[10001];
    scanf("%s",s);
    char pre[10001];int k=0;
    for(int i=0;i<strlen(s);){
        if(s[i]>='a'&&s[i]<='z'){pre[k]=s[i];k++;i++;}
        else{
            int num=0;
            while(i<strlen(s)&&s[i]>='0'&&s[i]<='9'){
                num=num*10+s[i]-'0';i++;
            }
            pre[k]='\0';
            for(int j=0;j<num;j++){
                printf("%s",pre);
            }
            k=0;
        }
    }
    pre[k]='\0';
    printf("%s",pre);
}