#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    int l,i,f,f0;
    f=0;
    f0=0;
    while(gets(s)!=NULL){
        l=strlen(s);
        i=0;
        while(i<l){
            if(i<l-1&&s[i]=='/'&&s[i+1]=='/'&&f==0){
                f=1;
                i++;
            }
            else if(i<l-1&&s[i]=='/'&&s[i+1]=='*'&&f==0){
                f=2;
                i++;
            }
            else if(i<l-1&&s[i]=='\\'&&s[i+1]=='\\'&&(f==0||f==3||f==4)){
                printf("%c%c",s[i],s[i+1]);
                i=i+2;
                f0=1;
            }
            else if(i>0&&s[i-1]!='\\'&&s[i]=='\"'&&f==0)
                f=3;
            else if(i>0&&s[i-1]!='\\'&&s[i]=='\''&&f==0)
                f=4;
            else if(i<l-1&&s[i]=='*'&&s[i+1]=='/'&&f==2){
                f=0;
                f0=1;
                i=i+2;
            }
            else if(i>0&&s[i-1]!='\\'&&s[i]=='\"'&&f==3)
                f=0;
            else if(i>0&&s[i-1]!='\\'&&s[i]=='\''&&f==4)
                f=0;
            if((f==0||f==3||f==4)&&f0==0)
                printf("%c",s[i]);
            if(f0==1)
                f0=0;
            else
                i++;
        }
        if(f==0||f==1){
            printf("\n");
            f=0;
        }
    }
    return 0;
}
