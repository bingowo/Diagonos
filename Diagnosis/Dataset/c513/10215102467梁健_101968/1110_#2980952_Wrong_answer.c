#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    char s[100];scanf("%s",s);
    int eqplace=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='=')eqplace=i;
        break;
    }
    return 0;
}
