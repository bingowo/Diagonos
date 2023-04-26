#include <stdio.h>
#include <math.h>

double expr(){
    char a[10];
    double f1, f2;
    scanf("%s", a);
    switch(a[0]){
        case'+': {f1= expr( ); f2 = expr( ); return f1 + f2;}
        case'-': {f1= expr( ); f2 = expr( ); return f1 - f2;}
        case'*': {f1= expr( ); f2 = expr( ); return f1 * f2;}
        case'/': {f1= expr( ); f2 = expr( ); return f1 / f2;}
        default: return atof(a);
    } }

int main(){
    int num,now=0;
    scanf("%d",&num);
    while(now<num){
        printf("case #");
        printf("%d:\n",now);
        printf("%.6f\n",expr());
        now++;
    }
    return 0;
}