#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void reversestr(char *str)
{
    int i = 0;
    char temp;
    char *s1,*s2;
    while(*str != '\0')
    {
        i++;str++;
    }
    str -= sizeof(char)*i;
    s1 = str;
    s2 = str + sizeof(char)*i - 1;
    for(s1=str;s1<s2;s1++,s2--)
    {
        temp = *s1;
        *s1=*s2;
        *s2=*s1;
    }
}



int ishuiwenshu(int n){
    char s1[100]={'\0'};
    char s2[100]={'\0'};
    itoa(n,s1,10);
    strcpy(s2,s1);
    reversestr(s1);
    if(!strcmp(s1,s2)) return 1;
    else return 0;
}
void f(int n){
    int cnt=0;
    while(!ishuiwenshu(n)){
        int m=0;
        char str[100]={'\0'};

        itoa(n,str,10);
        reversestr(str);
        m=atoi(str);
        n=n+m;
        cnt++;
    }
}



int main(){
    int n;
    scanf("%d/n",&n);
    f(n);
    return 0;
}