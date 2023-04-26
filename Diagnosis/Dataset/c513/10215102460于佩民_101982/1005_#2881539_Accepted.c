#include <stdio.h>
#include <string.h>

int main(){
    int num,a=0;
    scanf("%d",&num);
    while(a<num){
        char Octal[55],decimal[155];
        scanf("%s",Octal);
        int numbers=0,len,digit,j,temp;
        len=strlen(Octal)-1;
        for(;len!=1;--len){
            digit=Octal[len]-'0';
            j=0;
            do{
                if(j<numbers){
                    temp=digit*10+decimal[j]-'0';
                }
                else{
                    temp=digit*10;
                }
                decimal[j++]=temp/8+'0';
                digit = temp%8;
            }
            while(digit||j<numbers);
            numbers=j;
        }
        decimal[numbers]='\0';
        printf("case #%d:\n",a);
        printf("0.");
        for(j=0;j<strlen(decimal)-1;j++){
            printf("%c",decimal[j]);
        }
        printf("%c\n",decimal[j]);
        a++;
    }
    return 0;
} 