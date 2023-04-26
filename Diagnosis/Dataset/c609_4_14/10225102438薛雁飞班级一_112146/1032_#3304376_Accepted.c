#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[51];
    scanf("%s",s);
    int len=strlen(s);
    if(len==1)printf("1");
    else{
        int k=0,m=0;
        for(int i=0;i<len;i++){
            if(s[i]!=s[i+1]){
                k++;
                if(k>m)m=k;
            }
            else{
                k++;
                if(k>m)m=k;
                k=0;
            }
        }
        printf("%d",m);
    }
    return 0;
}
