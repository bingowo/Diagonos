#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
    int t;scanf("%d\n",&t);
    int idx=0;
    while(t--){
        char s[205];
        gets(s);
        char alpha[26]={0};int k=0;
        for(int i=0;i<strlen(s);i++){
            if(isalpha(s[i]))alpha[s[i]-'A']++;
        }
        printf("case #%d:\n",idx++);
        for(int i=0;i<strlen(s);i++){
            if(isalpha(s[i])){
                while(alpha[k]==0)k++;
                putchar(k+'A');
                alpha[k]--;
            }
            else putchar(s[i]);
        }
        putchar('\n');
    }
}