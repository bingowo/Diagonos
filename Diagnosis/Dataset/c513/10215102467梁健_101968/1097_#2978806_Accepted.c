#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF){
        int len=strlen(s);
        char res[200][100]={0};
        res[100][0]=s[0];
        int line=100,bottom=100,top=100,count=1;
        for(int i=1;i<len;i++,count++){
            if(s[i]>s[i-1]){
                line++;if(line>top)top=line;
                for(int m=0;m<count;m++){
                    if(!isprint(res[line][m]))res[line][m]=' ';
                    res[line][count]=s[i];
                }
            }
            if(s[i]==s[i-1]){
                res[line][count]=s[i];
            }
            if(s[i]<s[i-1]){
                line--;if(bottom>line)bottom=line;
                for(int m=0;m<count;m++){
                    if(!isprint(res[line][m]))res[line][m]=' ';
                    res[line][count]=s[i];
                }
            }
        }
        for(int i=top;i>=bottom;i--)
            printf("%s\n",res[i]);
    }
    return 0;
}
