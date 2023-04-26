#include<stdio.h>
#include<string.h>
int main(){
    int t;
    scanf("%d",&t);getchar();
    while(t--){
        char s[101];
        gets(s);
        char *p=s;
        int flag=0;
        while(*p){
            if(*p=='{'){
                p++;
                if(*p=='\0')break;
                if(*p=='[')continue;
                else {flag=1;break;}
            }
            if(*p=='['){
                p++;
                if(*p=='\0')break;
                if(*p=='(')continue;
                else {flag=1;break;}
            }
            if(*p=='('){
                p++;
                if(*p=='\0')break;
                if(*p=='{'||*p==')')continue;
                else {flag=1;break;}
            }
            if(*p==')'){
                p++;
                if(*p=='\0')break;
                if(*p==')'||*p=='}'){flag=1;break;}
                else continue;
            }
            if(*p==']'){
                p++;
                if(*p=='\0')break;
                if(*p==']'||*p==')'){flag=1;break;}
                else continue;
            }
            if(*p=='}'){
                p++;
                if(*p=='\0')break;
                if(*p=='}'||*p==']'){flag=1;break;}
                else continue;
            }
        }
        if(flag)printf("No\n");
        else printf("Yes\n");
    }
}