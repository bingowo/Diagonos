#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
    char Octal[55],decimal[155];
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%c",Octal);
        int numbers=0;
        int len=strlen(Octal)-1;
        for(;len!=1;--len){
            int digit=Octal[len]-'0';
            int j=0;
            int temp;
            do{
                if(j<numbers){
                    temp=digit*10+decimal[j]-'0';
                }
                else{
                    temp=digit*10;
                }
                decimal[j++]=temp/8+'0';
                digit=temp%8;
            }while(digit||j<numbers);
            numbers=j;
        }
        decimal[numbers]='\0';
        printf("case #%d:",i);
        for(int k=0;k<numbers;k++){
            printf("%c",decimal[k]);
        }
    }
    return 0;
}
