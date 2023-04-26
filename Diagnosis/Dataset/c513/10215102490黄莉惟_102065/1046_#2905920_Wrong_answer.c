#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main(){
    int t,word;
    int i,j,num;
    char s[1000];
    char s1[1000];
    scanf("%d",&t);
    char c = getchar();	
    for(i=0;i<t;i++){
        num=0;
        word=0;
        gets(s);
        for(j=0;j<strlen(s);j++){
            if(s[j]!=' '){
                s1[num]=s[j];
                num++;
            }else if(s[j]==' '){
                word++;
                num=0;
                printf("%s\n",s1);
                memset(s1,0,sizeof(s1));
            }else if(j==strlen(s)-1){
                printf("%s\n",s1);
            }
        }
        //printf("%d\n",word);
    }
}