#include <stdio.h>
#include<string.h>
//********** Specification of LongestWord **********
void LongestWord(char str[],char result[])
{
    char* start = str;
    int max_len = 0;
    int i;

    char *p = str;
    char *q;
    while(*p)
    {
        while(*p==' '){
           p++; 
        }
        for(q=p; *q && *q!=*(q-1);q++);
        if(q-p > max_len) { max_len = q-p; start = p;}
        p = q;
    }
    for(i=0;i<max_len;i++) result[i] = *start++;
    result[i]='\0';
}


/***************************************************************/
#define N 80
int main()
{   char s[N+1],r[N+1];
    gets(s);  
//********** LongestWord is called here ************
    LongestWord(s,r);
//**************************************************
    printf("%s\n",r);
    return 0;
}