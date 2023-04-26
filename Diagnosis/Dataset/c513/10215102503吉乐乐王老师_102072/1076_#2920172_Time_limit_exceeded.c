#include<stdio.h>
#include<string.h>
int main(){
    int t;
    scanf("%d",&t);getchar();
    while(t--){
        char s[101];
        gets(s);
        char *p=s;
        int sm,md,lg;
        sm=md=lg=0;
        int flag=0;
        while(*p){
            if(*p=='{'){
                while(*p=='{'){
                    lg++;p++;
                }
                if(*p=='('){flag=1;break;}
            }
            else if(*p=='['){
                while(*p=='['){
                    md++;p++;
                }
                if(*p=='{'){flag=1;break;}
            }
            else if(*p=='('){
                while(*p=='('){
                    sm++;p++;
                }
                if(*p=='['){flag=1;break;}
            }
            while(*p==')'){
                while(*p==')'){
                    sm--;p++;
                }
                if(*p=='}'){flag=1;break;}
                while(*p==']'){
                    md--;p++;
                }
                if(*p==')'){flag=1;break;}
                while(*p=='}'){
                    lg--;p++;
                }
                if(*p==']'){flag=1;break;}
            }
            if(flag)break;
        }
        if(flag||sm!=0||md!=0||lg!=0)printf("No\n");
        else printf("Yes\n");
    }
}