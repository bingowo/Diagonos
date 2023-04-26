#include<stdio.h>
#include<string.h>
int main()
{
    int N=200;
    int i,j;
    char str[N];
    gets(str);
    do{
        for(i=0;str[i]!=EOF;i++){
            if((str[i]=='/')&&(str[i+1]=='/')){for(;str[i]!=EOF;i++){str[i]='\0';}}



        }

    


        gets(str);
    }while(str != EOF);
printf("%s",str);



return 0;
}
