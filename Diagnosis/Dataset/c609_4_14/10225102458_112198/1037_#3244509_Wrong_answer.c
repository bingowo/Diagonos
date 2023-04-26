#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[1000001];
    int alpa[125];
    scanf("%s",s);
    int len=strlen(s);
    int cnt,max=1,i,j,be=0;
    for(j=0;j<len;j++){
        cnt=0;
        memset(alpa,0,sizeof(alpa));
        for(i=j;i<len;i++){

            if(alpa[s[i]]>0){

                if(cnt>max){max=cnt;be=j;}break;
            }
            cnt++;
            alpa[s[i]]++;
        }
    }
    if(cnt>max){max=cnt;be=j;}
    for(int j=0;j<max;j++)printf("%c",s[be+j]);
    printf("\n");
    return 0;
}