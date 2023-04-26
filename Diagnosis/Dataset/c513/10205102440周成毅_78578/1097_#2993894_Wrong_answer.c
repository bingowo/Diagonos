#include <stdio.h>
#include <string.h>

int main() {
    char s[85];
    char res[100][85];
    while (scanf("%s",s)!=EOF){
        memset(res,0,sizeof (res));
        int len= strlen(s);
        int line=0,col=1;
        res[line][col]=s[0];
        res[line][0]++;
        for(int i=1;i<len;i++){
            if(s[i]>s[i-1]){
                line++;
                col++;
                res[line][col]=s[i];
                for(int j=res[line][0]+1;j<col;j++)
                    res[line][j]=' ';
                res[line][0]=col;
            } else if(s[i]<s[i-1]){
                line--;
                col++;
                res[line][col]=s[i];
                for(int j=res[line][0]+1;j<col;j++)
                    res[line][j]=' ';
                res[line][0]=col;
            } else{
                col++;
                res[line][col]=s[i];
                res[line][0]=col;
            }
        }
        for(int i=line;i>=0;i--)
            printf("%s\n",res[line]+1);
    }
    return 0;
}
