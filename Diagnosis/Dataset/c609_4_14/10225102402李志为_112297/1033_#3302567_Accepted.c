#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char Base[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};
int main()
{
    int n;
    char s[101];
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        gets(s);
        printf("case #%d:\n",i);
        int index=0,len=strlen(s);
        char ch;
        int pos=0,bits=0,temp[5],t1=0;
        while(index<len){
            ch=s[index];
            temp[pos++]=(ch>>(2+bits))+(t1<<(6-bits));
            bits += 2;
            t1 = ch%(1<<bits);
            index++;
            if(bits==6){
                temp[pos]=t1;
                for(int j=0;j<=pos;j++) printf("%c",Base[temp[j]]);
                pos = 0,bits=0,t1=0;
            }
        }
        if(bits==2){
            temp[pos]=t1<<(6-bits);
            for(int j=0;j<=pos;j++) printf("%c",Base[temp[j]]);
            printf("==\n");
        }
        else if(bits==4){
            temp[pos]=t1<<(6-bits);
            for(int j=0;j<=pos;j++) printf("%c",Base[temp[j]]);
            printf("=\n");
        }
        else printf("\n");
    }
    return 0;
}