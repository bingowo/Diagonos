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
        int line=90;
        int a=90,b=90;
        ss[90][0]=s[0];
        for(int i=1;i<len;i++){
            if(s[i]>s[i-1]){
                line=line-1;
                ss[line][i]=s[i];
            }
            if(s[i]<s[i-1]){
                line=line+1;
                ss[line][i]=s[i];
            }
            if(s[i]==s[i-1])ss[line][i]=s[i];
            if(line<a)a=line;
            if(line>b)b=line;
        }
        for(int i=a;i<=b;i++){
            for(int j=0;j<len;j++){
                printf("%c",ss[i][j]);
                if(ss[i][j]!=' ')break;
            }
            printf("\n");
        }
    }
    return 0;
}
