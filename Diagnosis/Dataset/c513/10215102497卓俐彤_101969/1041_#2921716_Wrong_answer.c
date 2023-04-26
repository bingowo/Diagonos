#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[51];
    scanf("%s",str);
    int maxlen=0,len=0;
    int flag=0;
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='-'){
            if(!flag){
                flag=1;len=1;continue;
            }else{
                if(flag==1){
                    maxlen=maxlen>len?maxlen:len;
                    len=1;
                }else if(flag==2){
                    flag=1;len++;continue;
                }
            }
        }
        else if(str[i]=='|'){
            if(!flag){
                flag=2;len=1;continue;
            }else{
                if(flag==2){
                    maxlen=maxlen>len?maxlen:len;
                    len=1;
                }else if(flag==1){
                    flag=2;len++;continue;
                }
            }
        }
    }
    printf("%d\n",maxlen);
    return 0;
}

