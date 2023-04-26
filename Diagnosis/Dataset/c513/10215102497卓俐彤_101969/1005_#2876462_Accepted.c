#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxline 150


int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        char Octal[maxline],Decimal[maxline];
        scanf("%s",Octal);
        int number = 0,temp;
        unsigned long int len = strlen(Octal)-1;
        for(;len>1;len--){
            int digit=Octal[len]-'0';
            int j=0;
            do{
                if(j<number)temp=digit*10+Decimal[j]-'0';
                else temp=digit*10;
                Decimal[j++]=temp/8+'0';
                digit=temp%8;
            }while(j<number||digit);
            number=j;
        }
        Decimal[number]='\0';
        char *p=Decimal;
        printf("0.");
        while(*p)printf("%c",*p++);
        printf("\n");
    }
    return 0;
}
