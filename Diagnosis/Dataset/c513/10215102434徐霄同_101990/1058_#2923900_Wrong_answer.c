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
            if(i<l-1&&s[i]=='/'&&s[i+1]=='/'&&f==0)
                f=1;
            else if(i<l-1&&s[i]=='/'&&s[i+1]=='*'&&f==0)
                f=2;
            else if(s[i]=='"'&&f==0)
                f=3;
            else if(i>1&&s[i-1]=='/'&&s[i-2]=='*'&&f==2)
                f=0;
            else if(s[i]=='"'&&f==3)
                f=0;
            if(f==0||f==3)
                printf("%c",s[i]);
            i++;
        }
        if(f==0||f==1){
            printf("\n");
            f=0;
        }
    }
    return 0;
}
