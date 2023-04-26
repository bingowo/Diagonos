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
            if(s[j]!=' '&&j!=strlen(s)-1){
                s1[num]=s[j];
                num++;
            }else if(s[j]==' '){
                word++;
                num=0;
                if(strlen(s1)==1&&(s1[0]=='A'||s1[0]=='a')){
                    word--;
                }
                if(strlen(s1)==2&&(s1[0]=='A'||s1[0]=='a')&&(s1[1]=='n'||s1[1]=='N')){
                    word--;
                }
                if(strlen(s1)==2&&(s1[0]=='O'||s1[0]=='o')&&(s1[1]=='F'||s1[1]=='f')){
                    word--;
                }
                if(strlen(s1)==3&&(s1[0]=='T'||s1[0]=='t')&&(s1[1]=='H'||s1[1]=='h')&&(s1[2]=='E'||s1[2]=='e')){
                    word--;
                }
                if(strlen(s1)==3&&(s1[0]=='F'||s1[0]=='f')&&(s1[1]=='O'||s1[1]=='o')&&(s1[2]=='R'||s1[2]=='r')){
                    word--;
                }
                if(strlen(s1)==3&&(s1[0]=='A'||s1[0]=='a')&&(s1[1]=='N'||s1[1]=='n')&&(s1[2]=='D'||s1[2]=='d')){
                    word--;
                }
                //printf("%s\n",s1);
                memset(s1,0,sizeof(s1));
            }else if(j==strlen(s)-1){
                s1[num]=s[j];
                word++;
                if(strlen(s1)==1&&(s1[0]=='A'||s1[0]=='a')){
                    word--;
                }
                if(strlen(s1)==2&&(s1[0]=='A'||s1[0]=='a')&&(s1[1]=='n'||s1[1]=='N')){
                    word--;
                }
                if(strlen(s1)==2&&(s1[0]=='O'||s1[0]=='o')&&(s1[1]=='F'||s1[1]=='f')){
                    word--;
                }
                if(strlen(s1)==3&&(s1[0]=='T'||s1[0]=='t')&&(s1[1]=='H'||s1[1]=='h')&&(s1[2]=='E'||s1[2]=='e')){
                    word--;
                }
                if(strlen(s1)==3&&(s1[0]=='F'||s1[0]=='f')&&(s1[1]=='O'||s1[1]=='o')&&(s1[2]=='R'||s1[2]=='r')){
                    word--;
                }
                if(strlen(s1)==3&&(s1[0]=='A'||s1[0]=='a')&&(s1[1]=='N'||s1[1]=='n')&&(s1[2]=='D'||s1[2]=='d')){
                    word--;
                }
                //printf("%s\n",s1);
                
            }
        }
        printf("case #%d:\n",i);
        if(i==t) word--;
        printf("%d\n",word);
    }
}