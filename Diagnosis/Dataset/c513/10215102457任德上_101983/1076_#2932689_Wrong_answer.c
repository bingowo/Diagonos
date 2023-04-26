#include<stdio.h>
char s1[200]={0};
int cal(char *s,int k){
    char *c;
    c=s;
    if(k==-1)return 0;
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
        int key;
        char s[200];
        scanf("%s",s);
        s1[0]=s[0];
        key=cal(s+1,0);
        if(key==0)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}