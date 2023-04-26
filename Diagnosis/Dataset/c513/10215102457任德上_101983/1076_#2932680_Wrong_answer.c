#include<stdio.h>
char s1[101]={0};
int cal(char *s,int k){
    char *c;
    c=s;
    if(*s)return 0;
    switch(*s){
        case '{':{
            if((s1[k])=='('||s1[k]=='}'){
                s1[++k]='{';
                return cal(s+1,k);
            }
            else return 1;
        }
        case '[':{
            if((s1[k])=='{'||s1[k]==']'){
                s1[++k]='[';
                return cal(s+1,k);
            }
            else return 1;
        }
        case '(':{
            if((s1[k])=='['||s1[k]==')'){
                s1[++k]='(';
                return cal(s+1,k);
            }
            else return 1;
        }
        case '}':{
            if (s1[k]=='{'){
                s1[k--]=0;
                return cal(s+1,k);
            }
            else return 1;
        }
        case ')':{
            if (s1[k]=='('){
                s1[k--]=0;
                return cal(s+1,k);
            }
            else return 1;
        }
        case ']':{
            if (s1[k]=='['){
                s1[k--]=0;
                return cal(s+1,k);
            }
            else return 1;
        }
    }

}
int main(){
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++){
        int key=0;
        char s[101];
        scanf("%s",s);
        s1[0]=s[0];
        key=cal(s+1,key);
        if(key==0)printf("Yes\n");
        else printf("No\n");
        for(int m=0;m<101;m++)s1[m]=0;
    }
    return 0;
}