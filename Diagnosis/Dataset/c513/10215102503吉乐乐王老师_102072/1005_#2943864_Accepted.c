#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int t;
    scanf("%d",&t);getchar();
    int cas=0;
    while(t--){
        char octal[100];
        scanf("%s",octal);getchar();
        int dec[200]={0};
        int digit=0;
        for(int i=strlen(octal)-1;octal[i]!='.';i--){
            int number=0;
            int temp=octal[i]-'0';
            do{
                if(number<digit)temp=temp*10+dec[number];
                else temp*=10;
                dec[number++]=temp/8;
                temp%=8;
            }while(temp||number<digit);
            digit=number;
        }
        printf("case #%d:\n0.",cas++);
        for(int i=0;i<digit;i++){
            printf("%d",dec[i]);
        }
        putchar('\n');
    }
}