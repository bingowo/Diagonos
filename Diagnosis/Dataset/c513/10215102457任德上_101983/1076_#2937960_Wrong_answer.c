#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int key=0,k=0;
        char s[101]={0},*c1,*c2,s1[101]={0};
        scanf("%s",s);
        s1[0]=s[0];
        c2=s;
        c2++;
        while(*c2){
            if(k<0&&(*c2=='{'||*c2=='('||*c2=='[')){k=0;s1[k]=*c2;}
            else if(k<0)key=1;
            else switch(*c2){
            case '{':{
                if(s1[k]=='('||s1[k]=='}')s1[++k]=*c2;
                else key=1;
                break;
            }
            case '(':{
                if(s1[k]==')'||s1[k]=='[')s1[++k]=*c2;
                else key=1;
                break;
            }
            case '[':{
                if(s1[k]==']'||s1[k]=='{')s1[++k]=*c2;
                else key=1;
                break;
            }
            case '}':{
                if(s1[k]=='{')s1[k--]=0;
                else key=1;
                break;
            }
            case ']':{
                if(s1[k]=='[')s1[k--]=0;
                else key=1;
                break;
            }
            case ')':{
                if(s1[k]=='(')s1[k--]=0;
                else key=1;
                break;
            }
            default:break;
            }
            c2++;
            if(key==1)break;
        }
        if(key==0)printf("Yes\n");
        else printf("No\n");
        for(int m=0;m<101;m++)s1[m]='\0';
    }
    return 0;
}