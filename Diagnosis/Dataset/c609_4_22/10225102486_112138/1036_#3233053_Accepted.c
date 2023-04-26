#include<stdio.h>

int F(){
    char c1,c2;
    int s=0;
    if((c1=getchar())=='('){
        if((c2=getchar())=='('){
            ungetc(c2,stdin);
            s=2*F();
        }
        else s=1;
        if((c1!='\n'))
            s+=F();
    }
    return s;
 }

 int main(){
    printf("%d",F());
    return 0;
 }
