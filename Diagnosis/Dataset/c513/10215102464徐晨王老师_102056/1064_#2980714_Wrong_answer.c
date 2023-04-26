#include <stdio.h>
#include <string.h>
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
   }
}
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n%lf\n",t,expr());
    }
    return 0;
}