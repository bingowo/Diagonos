#include <stdio.h>
#include <string.h>

int main() {
    char s[85];
    char res[201][85];
    while (scanf("%s",s)!=EOF){
        memset(res,0,sizeof (res));
        int len= strlen(s);
        int line=100,col=1,maxline=100,minline=100;
        res[line][col]=s[0];
        res[line][0]++;
        for(int i=1;i<len;i++){
            if(s[i]>s[i-1]){
                line++;
                col++;
                if(line>maxline)
                    maxline=line;
                if(line<minline)
                    minline=line;
                res[line][col]=s[i];
                for(int j=res[line][0]+1;j<col;j++)
                    res[line][j]=' ';
                res[line][0]=col;
            } else if(s[i]<s[i-1]){
                line--;
                col++;
                if(line>maxline)
                    maxline=line;
                if(line<minline)
                    minline=line;
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
        for(int i=maxline;i>=minline;i--) {
            for (int j = 1; j <= res[line][0]; j++)
                printf("%c", res[i][j]);
            printf("\n");
        }
    }
    return 0;
}
