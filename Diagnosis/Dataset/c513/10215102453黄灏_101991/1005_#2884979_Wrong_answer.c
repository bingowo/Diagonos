#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trans(char o[],char d[]){
    int numbers=0,len,digit,temp;
    len=strlen(o)-1;
    for(;len!=1;--len){
        digit=o[len]-'0';
        int j=0;
        do{
            if(j<numbers)
                temp=digit*10+d[j]-'0';
            else
                temp=digit*10;
            d[j++]=temp/8+'0';
            digit=temp%8;
        }while(digit!=0 || j<numbers);
        numbers=j;
    }
    d[numbers]='\0';
}

int main()
{
    int T;
    for(int i=0;i<T;i++){
        char oct[55];
        char dec[155];
        while(scanf("%s",oct)!=EOF);
        printf("case #%d:\n",i);
        trans(oct,dec);
        printf("0.");
        for(int k=0;k<strlen(dec);k++){
            printf("%c",dec[k]);
        }
        printf("\n");
    }
    return 0;
}
