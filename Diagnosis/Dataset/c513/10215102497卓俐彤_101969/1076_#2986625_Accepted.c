#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge_bracket(char c){
    if(c=='(')return 1;
    else if(c=='[')return 2;
    else if(c=='{')return 3;
    else if(c==')')return 4;
    else if(c==']')return 5;
    else if(c=='}')return 6;
    else return 0;
}

int judge_left(int a,int b){
    if(a==1&&b==3)return 1;
    else if(a-b==1)return 1;
    else return 0;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int isPerfect=1;
        char s[101];
        scanf("%s",s);
        int p=0,bracket_right=0;
        int bracket_left[101]={0};
        int flag=0;
        for(int i=0;i<strlen(s);i++){
            p=judge_bracket(s[i]);
            if(p<4){
                bracket_left[flag++]=p;
                if(bracket_left[1]){
                    isPerfect=judge_left(bracket_left[flag-2],bracket_left[flag-1]);
                    if(!isPerfect)break;
                }
                
            }else{
                bracket_right=p;
                if(flag>0&&bracket_right-bracket_left[flag-1]==3){
                    bracket_left[flag-1]=0;
                    flag--;
                }else{
                    isPerfect=0;
                    break;
                }
            }
        }
        if(bracket_left[0])isPerfect=0;
        
        if(isPerfect)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

