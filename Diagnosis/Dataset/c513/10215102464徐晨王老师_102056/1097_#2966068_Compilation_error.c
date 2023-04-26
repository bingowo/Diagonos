#include <stdio.h>
#include <string.h>
int main(){
    char s[90];
    while(scanf("%s",s)!=EOF){
        int len=strlen(s);
        char ss[180][len+1];
        for(int i=0;i<180;i++){
            for(int j=0;j<len;j++){
                ss[i][j]=' ';
            }
        }
        int a=90,b=90;
        ss[90][0]=s[0];
        for(int i=1;i<len;i++){
            if(s[i]>s[i-1]){
                a=a-1;
                ss[a][i]=s[i];
            }
            if(s[i]<s[i-1]){
                b=b+1;
                ss[b][i]=s[i];
            }
        }
        for(int i=a;i<=b;i++){
            for(int j=0;j<len;j++){
                printf("%c",s[i][j]);
                if(s[i][j]!=' ')break;
            }
        }
    }
    return 0;
}