#include<stdio.h>
#include<string.h>
int cal(char *s,int k,char *s1){
    if(*s==0)return 0;
    if(k==-1&&*s!=0){
        k=0;
        s1[k]=*s;
        return cal(s+1,k);
    }  
    switch(*s){
        case '{':{
            if((s1[k])=='('||s1[k]=='}'){
                s1[++k]='{';
                return cal(s+1,k);
            }
            return 1;
        }
        case '[':{
            if((s1[k])=='{'||s1[k]==']'){
                s1[++k]='[';
                return cal(s+1,k);
            }
            return 1;
        }
        case '(':{
            if((s1[k])=='['||s1[k]==')'){
                s1[++k]='(';
                return cal(s+1,k);
            }
            return 1;
        }
        case '}':{
            if (s1[k]=='{'){
                s1[k--]=0;
                return cal(s+1,k);
            }
            return 1;
        }
        case ')':{
            if (s1[k]=='('){
                s1[k--]=0;
                return cal(s+1,k);
            }
            return 1;
        }
        case ']':{
            if (s1[k]=='['){
                s1[k--]=0;
                return cal(s+1,k);
            }
            return 1;
        }
    }

}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int key;
        char *s,s1[200]={0};
        s=(char*)malloc(200*sizeof(char));
        scanf("%s",s);
        s1[0]=s[0];
        key=cal(s+1,0,s1);
        if(key==0)printf("Yes\n");
        else printf("No\n");
        free(s);
    }
    return 0;
}