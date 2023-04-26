#include<stdio.h>
#include<string.h>
int main(){
    int t,num,len,digit,j,temp;
    scanf("%d",&t);
    char Octal[55];
    char decimal[155];
    int m=0;
    while(t<m){
        num=0;
        scanf("%s",Octal);
        len=strlen(Octal)-1;
        for(;len!=1;--len){
            digit=Octal[len]-'0';
            j=0;
            do{
                if(j<num){
                    temp=digit*10+decimal[j]-'0';
                }else{
                    temp=digit*10;
                }
                decimal[j++]=temp/8+'0';
                digit=temp%8;
            }while(digit||j<num);
            num=j;
    }
    decimal[numbers]='\0';
    printf("%s",decimal);
    m++;
}