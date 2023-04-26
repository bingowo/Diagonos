#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double stk[100] = {0.0};
int top = 0;

int isOperator(char c){
    if((c=='+')||(c=='-')||(c=='*')||(c=='/')){
        return 1;
    }
    return 0;
}

int isNum(char c){
    if((isdigit(c))||(c=='.')){
        return 1;
    }
    return 0;
}

void push(double stack[], double d)
{
    stack[top] = d;
    top++;
}
double pop(double stack[])
{
    double ans = stack[top-1];
    top--;
    stack[top] = 0;
    return ans;
}
int main()
{
    int T = 0;
    scanf("%d",&T);
    getchar();
    for(int i = 0;i<T;i++){
        memset(stk,0,100*sizeof(double));top = 0;
        char s[110];memset(s,0,110*sizeof(char));
        gets(s);
        //printf("s = %s\n",s);
        char token[100][20];memset(token,0,100*20*sizeof(char));
        int slen = strlen(s),tokenCnt = 0,tokenLen = 0;
        int j = 0;
        while(j<slen){
            if(isOperator(s[j])){
                //printf("s[%d] = '%c'\n",j,s[j]);
                token[tokenCnt][0] = s[j];
                //printf("Operator: %s\n",token[tokenCnt]);
                tokenCnt++;j++;
                continue;
            }
            else if(isNum(s[j])){
                while(isNum(s[j])){
                    //printf("s[%d] = '%c'\n",j,s[j]);
                    token[tokenCnt][tokenLen] = s[j];
                    //printf("Num: %s\n",token[tokenCnt]);
                    tokenLen++;j++;
                }

                tokenCnt++;
                tokenLen = 0;
                continue;
            }
            else{
                j++;
            }
        }

        for(int j = tokenCnt-1;j>=0;j--){
            if(isNum(token[j][0])){
                //printf("token[%d] = %s\n",j,token[j]);
                push(stk,atof(token[j]));
            }
            else if(isOperator(token[j][0])){
                //printf("token[%d] = %s\n",j,token[j]);
                double tmp = 0;
                if(token[j][0] == '+'){
                    tmp = pop(stk)+pop(stk);
                }
                else if(token[j][0] == '-'){
                    tmp = pop(stk)-pop(stk);
                }
                else if(token[j][0] == '*'){
                    tmp = pop(stk)*pop(stk);
                }
                else if(token[j][0] == '/'){
                    tmp = pop(stk)/pop(stk);
                }
                //printf("tmp = %lf\n",tmp);
                push(stk,tmp);
                //for(int k = 0;k<top;k++){
                //    printf("stk[%d] = %lf\n",k,stk[k]);
                //}
            }
        }
        //for(int k = 0;k<top;k++){
        //    printf("stk[%d] = %lf\n",k,stk[k]);
        //}

        double res = stk[0];
        printf("case #%d:\n",i);
        printf("%lf\n",res);
        //for(int j = 0;j<tokenCnt;j++){
        //    printf("token = %s\n",token[j]);
        //}
    }
    return 0;
}
