#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char str[100002];
    scanf("%s",str);
    int flag=1;
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='x'&&i!=0&&str[i-1]=='0'&&i!=strlen(str)-1){
            if(isdigit(str[i+1])||(str[i+1]>='a'&&str[i+1]<='f')){
                flag=0;
                break;
            }
        }
    }
    if(flag)printf("-1\n");
    else{
        flag=1;
        for(int i=1;i<strlen(str)-1;i++){
            unsigned int num=0;
            int k=0;
            if(str[i]=='x'&&str[i-1]=='0'){
                i++;
                if((str[i]<='f'&&str[i]>='a')||isdigit(str[i])){
                    k=1;
                    while(((str[i]<='f'&&str[i]>='a')||isdigit(str[i]))&&k<9){
                        int n=0;
                        if(isdigit(str[i]))n=str[i]-'0';
                        else n=str[i]-'a'+10;
                        num=num*16+n;
                        i++;k++;
                    }
                    if(flag){
                        flag=0;
                        printf("%u",num);
                    }else printf(" %u",num);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
