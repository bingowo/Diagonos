#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int judge[128];
int main()
{
    char s[1000001];
    scanf("%s",s);
    int startp=0,endp=0,len=0,S=0,E=0;
    for(int i=0;i<strlen(s);i++){
        for(int k=0;k<128;k++)judge[k]=0;
        startp=i;endp=0;
        for(int j=i;j<strlen(s);j++){
            if(judge[s[j]]++!=0)break;
            endp=j;
        }
        if((endp-startp)>len){
            len=endp-startp;
            S=startp;E=endp;
        }
    }
    for(int i=S;i<=E;i++)printf("%c",s[i]);
    return 0;
}