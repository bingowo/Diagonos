#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef long long ll;
typedef unsigned long long ull;

char s[1000001];
int in=0;

int Find(char* s, char* tar){
    int i;
    for(i=0;s[i]!='\0'&&tar[i]!='\0';i++)
        if(s[i]!=tar[i])
            return 0;
    return tar[i]=='\0';
}

int main(){
    while(gets(s)){
        for(int i=0;s[i]!='\0';i++){
            if(in==1){
                    printf("%c",s[i]);
                if(Find(s+i,"\\\"")){
                    printf("\"");
                    i++;
                }
                else if(s[i]=='\"')
                    in=0;
            }
            else if(in==-1){
                if(Find(s+i,"*/"))
                    in=0,i++;
            }
            else{
                if(Find(s+i,"/*"))
                    in=-1;
                else if(Find(s+i,"//"))
                    break;
                else{
                    printf("%c",s[i]);
                    if(s[i]=='\"') in=1;
                }
            }
        }
        if(in!=-1) printf("\n");
    }


    return 0;
}
