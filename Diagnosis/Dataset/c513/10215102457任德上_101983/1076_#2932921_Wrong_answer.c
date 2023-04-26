#include<stdio.h>
#include<string.h>
#include<malloc.h>
int cal(char *s,int k,char *s1){
    if(*s==0)return 0;
    if(k==-1&&*s!=0){
        k=0;
        s1[k]=*s;
        return cal(s+1,k,s1);
    }  
    switch(*s){
        case '{':if((s1[k])=='('||s1[k]=='}'){
                        s1[++k]='{';
                        return cal(s+1,k,s1);
                    }
                    return 1;
                    break;
        case '[':if((s1[k])=='{'||s1[k]==']'){
                    s1[++k]='[';
                    return cal(s+1,k,s1);
                }
                return 1;
                break;
        case '(':if((s1[k])=='['||s1[k]==')'){
                    s1[++k]='(';
                    return cal(s+1,k,s1);
                }
                return 1;
                break;
        case '}':if (s1[k]=='{'){
                    s1[k--]=0;
                    return cal(s+1,k,s1);
                }
                return 1;
                break;
        case ')':if (s1[k]=='('){
                    s1[k--]=0;
                    return cal(s+1,k,s1);
                }
                return 1;
                break;
        case ']':if (s1[k]=='['){
                    s1[k--]=0;
                    return cal(s+1,k,s1);
                }
                return 1;
                break;
        default:return 0;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int key;
        char s[101]={0},s1[101]={0};
        scanf("%s",s);
        s1[0]=s[0];
        key=cal(s+1,0,s1);
        if(key==0)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}