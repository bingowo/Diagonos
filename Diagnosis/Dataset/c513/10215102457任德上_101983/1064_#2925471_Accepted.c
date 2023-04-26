#include<stdio.h>
#include<stdlib.h>
double cal(){
    double left,right;
    char s[10];
    scanf("%s",s);
        switch(*s){
            case '*':left=cal();right=cal();return left * right;break;
            case '+':left=cal();right=cal();return left + right;break;
            case '-':left=cal();right=cal();return left - right;break;
            case '/':left=cal();right=cal();return left / right;break;
            default:return atof(s);
    }
}
int main(){
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++){
        double end;
        end = cal();
        printf("case #%d:\n%.6lf\n",i,end);
    }
    return 0;
}