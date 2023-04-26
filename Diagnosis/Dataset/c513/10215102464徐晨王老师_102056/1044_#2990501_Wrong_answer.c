#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char c;
    int p[1000];
    int len=0;
    int flag=0;
    int pd=0;
    c=getchar();
    char a=c;
    while((c=getchar())!=EOF&&a!=EOF){
        if(a=='0'&&c=='x'){
            flag=1;
            continue;
        }
        if(flag){
            if(isdigit(c)){
                p[len]=c-48;
                len++;
            }
            else if(c>=97&&c<=102){
                p[len]=c-87;
                len++;
            }
            else{
                flag=0;
                unsigned int sum=0;
                for(int i=0;i<len;i++){
                    sum=sum*16+p[i];
                }
                printf("%ld ",sum);
                pd=1;
                len=0;
                for(int i=0;i<len;i++){
                    p[i]=0;
                }
            }
        }
        a=c;
    }
    if(pd==0)printf("-1");
    return 0;
}