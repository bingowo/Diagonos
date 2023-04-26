#include<stdio.h>
//stack[i]为目前要填充的状态,[i-1]当前所处状态
int main(){
    int T;
    scanf("%d",&T);
    for(int k=0;k<T;k++){
        char s[101],*c;
        int state=1,flag=0,i=1,stack[250];
        scanf("%s",s);
        c=s;
        stack[0]=1;
        while(*c!=0){
            switch(state){
            case 1:{           //外部
                if(*c=='{')state=2;
                else if(*c=='[')state=3;
                else if(*c=='(')state=4;
                else flag=1;
                stack[i++]=state;
                break;
            }
            case 2:{            //大括号内
                if(*c=='[')state=3;
                else flag=1;
                stack[i++]=state;
                break;
            }
            case 3:{           //中括号内
                if(*c=='(')state=4;
                else flag=1;
                stack[i++]=state;
                 break;
            }
            case 4:{          //小括号内
                if(*c=='{'){
                    state=2;
                    stack[i++]=state;
                }
                else if(*c==')'){
                    i--;
                    if(stack[i-1]!=1)state=5;
                    else state=1;
                }
                else flag=1;
                 break;
            }
            case 5:{          //返回的中括号内
                if(*c=='('){
                    state=4;
                    stack[i++]=state;
                }
                else if(*c==']'){
                    i--;
                    if(stack[i-1]!=1)state=6;
                    else state=1;
                }
                else flag=1;
                break;
            }
            case 6:{         //返回的大括号内部
                if(*c=='['){
                    state=3;
                    stack[i++]=state;
                }
                else if(*c=='}'){
                    i--;
                    if(stack[i-1]!=1)state=4;
                    else state=1;
                }
                else flag=1;
                 break;

            }
            default:break;
            }
            c++;
            if(flag==1){
                printf("No\n");
                break;
            }
        }
        if(flag==0&&stack[i-1]==1)printf("Yes\n");
        else printf("No\n")
    }
    return 0;
}
