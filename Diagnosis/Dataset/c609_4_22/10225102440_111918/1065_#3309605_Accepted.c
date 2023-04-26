#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double in(){
    double x,y;
    char s[101];
    scanf("%s",s);
    if(s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/'){
        x=in(),y=in();
        switch(s[0]){
            case '+': return x+y;
            case '-': return x-y;
            case '*': return x*y;
            case '/': return x/y;
        }
    }
    return atof(s);
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
        printf("case #%d:\n%lf\n",i,in());
    return 0;
}
