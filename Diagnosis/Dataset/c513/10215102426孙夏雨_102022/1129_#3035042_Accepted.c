#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[10001]={0};
    scanf("%s",s);
    int len=strlen(s),len1=0,ci=0;
    char pian[10001]={0};
    for(int i=0;i<len;i++){
        if(isalpha(s[i])){
            if(ci>0){
                pian[len1]=0;
                for(int k=0;k<ci;k++) printf("%s",pian);
                for(int w=0;w<len1;w++) pian[w]=0;
                len1=0;
                ci=0;
            }
            pian[len1++]=s[i];
        }
        else if(isdigit(s[i])){
            ci=ci*10+s[i]-'0';
        }
        if(i==len-1){
            pian[len1]=0;
            for(int k=0;k<ci;k++) printf("%s",pian);
            if(ci==0) printf("%s",pian);
            for(int w=0;w<len1;w++) pian[w]=0;
            len1=0;
        }
    }
    printf("\n");
    return 0;
}
