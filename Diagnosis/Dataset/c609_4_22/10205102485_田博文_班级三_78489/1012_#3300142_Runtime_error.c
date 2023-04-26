#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main(){
    int ques_num=0;

    scanf("%d",&ques_num);
    for(int mmm=0;mmm<ques_num;mmm++)
    {
        char Octal[55], decimal[155];
        int numbers,temp;
        int len=strlen(Octal)-1;
        for(;len!=1;--len)
        {
            int digit=Octal[len]-'0';
            int j=0;
            do{
                if(j<numbers)
                    temp=digit*10+decimal[j]-'0';
            else
                temp=digit*10;
            decimal[j++]=temp/8+'0';
            digit=temp%8;
            }while(digit||j<numbers);
            numbers=j;
        }
        decimal[numbers]='\0';


        printf("case #%d:\n",mmm);

        for(int ppp=0;ppp<numbers;ppp++) printf("%c",decimal[ppp]);
    }
    }



