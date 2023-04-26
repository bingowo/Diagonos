#include<stdio.h>
#include<string.h>
int main() {
    char c[1024];
    int FLAG=0;
    int quote=-1;
    int HasPrint=0;

    while(gets(c)) {
        HasPrint=0;
        for(int i=0; i<strlen(c); i++) {
            if(FLAG) {
                if(c[i]=='*'&&c[i+1]=='/') {
                    FLAG=0;
                    i++;
                    continue;
                }
            } else {
                if(c[i]=='"')quote*=-1;
                if(quote==-1) { 
                    if(c[i]=='/'&&c[i+1]=='/') { 
                    }
                    if(c[i]=='/'&&c[i+1]=='*') {
                        FLAG=1;
                    }
                }
                if(!FLAG) {
                    putchar(c[i]);
                    HasPrint=1;
                }
            }

        }
        if(HasPrint)printf("\n");
    }
    return 0;
}