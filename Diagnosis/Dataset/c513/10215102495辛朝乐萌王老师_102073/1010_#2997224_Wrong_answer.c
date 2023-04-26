#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void itob(unsigned n,char s[])
{
    int i;
    for (i=98; n&&i; n/=2) {
        s[i--]=(((n%2)<10)?'0':'A'-10);
    }
    memmove(s, s+i+1, 99-i-1);
    s[99-i-1]='\0';
}

void printbit(char s[],int length)
{
    int len=strlen(s);
    if (len<length) {
        for (int i=0; i<(length-len); i++) {
            printf("0");
        }
    }
    printf("%s",s);
}

int main()
{
    char s[501],temp[100];
    scanf("%s",s);
    int tempnum=0,len = strlen(s);
    itob(len, temp);
    printf("0001");
    for (int i=0; i<len; i++) {
        tempnum=tempnum*10+(s[i]-'0');
        if(i%3==2){
            itob(tempnum, temp);
            printbit(temp,10);
            tempnum=0;
        }
    }
    if(tempnum%3==1){
        itob(tempnum, temp);
        printbit(temp,4);
        tempnum=0;
    }
    else if(tempnum%3==2){
        itob(tempnum, temp);
        printbit(temp,7);
        tempnum=7;
        
    }
    return 0;
}
    
