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
                if(*p!='['){flag=1;break;}
            }
            else if(*p=='['){
                p++;
                if(*p!='('){flag=1;break;}
            }
            else if(*p=='('){
                p++;
                if(*p!='{'&&*p!=')'){flag=1;break;}
            }
            if(*p==')'){
                p++;
                if(*p==')'||*p=='}'){flag=1;break;}
            }
            if(*p==']'){
                p++;
                if(*p==']'||*p==')'){flag=1;break;}
            }
            if(*p=='}'){
                p++;
                if(*p=='}'||*p==']'){flag=1;break;}
            }
            if(flag)break;
        }
        if(flag)printf("No\n");
        else printf("Yes\n");
    }
}