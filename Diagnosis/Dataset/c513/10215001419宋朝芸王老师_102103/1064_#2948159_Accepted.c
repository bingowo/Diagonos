#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

double expr(){
    char temp[100];
    double f1,f2;
    scanf("%s",temp);

    switch(temp[0]){
        case'+':{f1 = expr();f2 = expr(); return f1 + f2;}
        case'-':{f1 = expr();f2 = expr(); return f1 - f2;}
        case'*':{f1 = expr();f2 = expr(); return f1 * f2;}
        case'/':{f1 = expr();f2 = expr(); return f1 / f2;}
        default: return atof(temp);
    }
}

int main(){
    int T,R;
    scanf("%d",&T);
    for(R = 0; R < T; R++){

        double ans = 0;
        ans = expr();

        printf("case #%d:\n%.6lf\n",R,ans);
    }
    return 0;
}