#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[1000000];
    char c='\0';
    int len=0;
    int shan=1;
    while((c=getchar())!=EOF){
        s[len]=c;
        len++;
    }
    s[len]=0;
    printf("%s\n",s);
    int i=0;
    while(i<len){
        if(s[i]=='/'&&shan==1){
            if(s[i+1]=='/') {
                while(s[i]!='\n') i++;
            }
            else if(s[i+1]=='*'){
                i++;
                while(1) {
                    i++;
                    if(s[i]=='/'&&s[i-1]=='*') break;
                }
                i++;
            }
        }
        else if(s[i]=='"'){
            printf("%c",s[i]);
            i++;
            while(1){
                if(s[i]=='"'&&s[i-1]!='\\') break;
                else if(s[i]=='"'&&s[i-1]=='\\'&&s[i-2]=='\\') break;
                printf("%c",s[i]);
                i++;
            }
            printf("%c",s[i]);
            i++;
        }
        else if(s[i]=='\''){
            printf("%c",s[i]);
            i++;
            while(1){
                if(s[i]=='\''&&s[i-1]!='\\') break;
                else if(s[i]=='\''&&s[i-1]=='\\'&&s[i-2]=='\\') break;
                printf("%c",s[i]);
                i++;
            }
            printf("%c",s[i]);
            i++;
        }
        else {
            printf("%c",s[i]);
            i++;
        }
    }
    return 0;
}
