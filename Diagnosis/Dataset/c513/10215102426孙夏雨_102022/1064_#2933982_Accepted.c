#include <stdio.h>
#include <stdlib.h>

double expr()
{
    char s[11];
    double f1=0.0,f2=0.0;
    scanf("%s",s);
    switch(s[0]){
        case '+':{f1=expr();f2=expr();return f1+f2;}
        case '-':{f1=expr();f2=expr();return f1-f2;}
        case '*':{f1=expr();f2=expr();return f1*f2;}
        case '/':{f1=expr();f2=expr();return f1/f2;}
        default: return atof(s);
    }
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        double ans;
        ans=expr();
        printf("case #%d:\n%.6f\n",t,ans);
    }
    return 0;
}
