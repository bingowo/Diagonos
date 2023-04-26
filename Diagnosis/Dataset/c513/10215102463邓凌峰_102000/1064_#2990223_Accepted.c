#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 50

double solve(void){
    char s[10];
    scanf("%s",s);
    switch(s[0]){
        case '+': return solve()+solve();break;
        case '-': return solve()-solve();break;
        case '*': return solve()*solve();break;
        case '/': return solve()/solve();break;
        default: return atof(s);
    }
}

int main()
{
    int T;scanf("%d",&T);
    for(int I=0;I<T;I++){
        double ans=0;
        ans=solve();
        printf("case #%d:\n%.6f\n",I,ans);
    }
}



