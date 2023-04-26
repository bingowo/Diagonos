#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    int l,i,f;
    f=0;
    while(gets(s)!=NULL){
        l=strlen(s);
        i=0;
        while(i<l){
            if(i<l-1&&s[i]=='/'&&s[i+1]=='/'&&f==0){
                f=1;
                i=i+2;
            }
            else if(i<l-1&&s[i]=='/'&&s[i+1]=='*'&&f==0){
                f=2;
                i=i+2;
            }
            else if(i>0&&s[i-1]!='\\'&&s[i]=='\"'&&f==0)
                f=3;
            else if(i<l-1&&s[i]=='*'&&s[i+1]=='/'&&f==2){
                f=0;
                i=i+2;
            }
            else if(i>0&&s[i-1]!='\\'&&s[i]=='\"'&&f==3)
                f=0;
            else if(i>0&&s[i-1]!='\\'&&s[i]=='\''&&f==0)
                f=4;
            else if(i>0&&s[i-1]!='\\'&&s[i]=='\''&&f==4)
                f=0;
            if(f==0||f==3||f==4){
                printf("%c",s[i]);
                i++;
            }
        }
        if(f==0||f==1){
            printf("\n");
            f=0;
        }
    }
    return 0;
}
