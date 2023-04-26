#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char *s=(char *)malloc(1e5*sizeof(char));
    int a;
    scanf("%s",s);
    a=strstr(s,"0x");
    if(a==0){
        printf("-1");
        return 0;
    }
    //else{

    //}
    return 0;
}
