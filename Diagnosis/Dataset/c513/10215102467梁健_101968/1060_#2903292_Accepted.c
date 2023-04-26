#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
int main()
{
    char s[101];
    scanf("%s",s);
    int RES=0,res=0;;
    for(int i=0;i<strlen(s);i++){
        int juds=0;
        if(isdigit(s[i])&&s[i]!='0')juds++;
        if(juds!=0){
            res++;
            for(int m=i+1;m<strlen(s);m++){
                if(isdigit(s[m]))res++;
                if(isalpha(s[m]))break;
            }
            if(res>RES)RES=res;
            res=0;
        }
    }
    printf("%d",RES);
    return 0;
}
