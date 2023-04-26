#include<stdio.h>
#include<string.h>
char s1[200]={0};
int cal(char *s,int k,int len1,int len2){
    if(k==-1&&len2==(len1+1))return 0;
    else if(k==-1){
        s1[++k]=*s;
        return cal(s+1,k,len1,len2+1);
    }
    len2++;
    switch(*s){
        case '{':{
            if((s1[k])=='('||s1[k]=='}'){
                s1[++k]='{';
                return cal(s+1,k,len1,len2);
            }
            return 1;
        }
        case '[':{
            if((s1[k])=='{'||s1[k]==']'){
                s1[++k]='[';
                return cal(s+1,k,len1,len2);
            }
            return 1;
        }
        case '(':{
            if((s1[k])=='['||s1[k]==')'){
                s1[++k]='(';
                return cal(s+1,k,len1,len2);
            }
            return 1;
        }
        case '}':{
            if (s1[k]=='{'){
                s1[k--]=0;
                return cal(s+1,k,len1,len2);
            }
            return 1;
        }
        case ')':{
            if (s1[k]=='('){
                s1[k--]=0;
                return cal(s+1,k,len1,len2);
            }
            return 1;
        }
        case ']':{
            if (s1[k]=='['){
                s1[k--]=0;
                return cal(s+1,k,len1,len2);
            }
            return 1;
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
        int len1=strlen(s),len2=1;
        s1[0]=s[0];
        key=cal(s+1,0,len1,len2);
        if(key==0)printf("Yes\n");
        else printf("No\n");
        for(int m=0;m<200;m++)s1[m]=0;
    }
    return 0;
}