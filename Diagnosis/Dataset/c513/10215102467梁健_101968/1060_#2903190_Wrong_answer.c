#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
int main()
{
    char s[101];
    char res[101];
    scanf("%s",s);
    int max=0,startp=0,endp=0;
    int judnum=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(isalpha(s[i])&&isdigit(s[i+1]))startp=i+1;
        else continue;
        for(int m=i+1;m<strlen(s);m++){
            if(isdigit(s[m])!=0)endp=m;
            else break;
        }
        int step=0;
        for(int p=startp;p<=endp;p++){
            res[step++]=s[p];
        }
        if(atoi(res)>judnum)judnum=atol(res);
    }
    int RES=0;
    if(judnum==0)RES=1;
    while(judnum>0){
        RES++;
        judnum/=10;
    }
    printf("%d",RES);
    return 0;
}
