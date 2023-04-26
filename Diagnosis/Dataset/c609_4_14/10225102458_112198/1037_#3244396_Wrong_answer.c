#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[1000001];
    scanf("%s",s);
    int len=strlen(s);
    int cnt=1,max=1,flag,i,j,start=0,be,en=len;
    for(j=1;j<len;j++){
        flag=1;
        for(i=start;i<j;i++){
            if(s[i]==s[j]){
                flag=0;
                if(start==0){max=j;en=j;}
                start=i+1;
                if(cnt>max){max=cnt;be=start-1;en=j;}
                cnt=1;
                break;}
        }
        if(flag)cnt++;
    }
    if(cnt>max){max=cnt;be=start;}
    for(int k=be;k<en;k++)printf("%c",s[k]);
    printf("\n");
    return 0;
}
