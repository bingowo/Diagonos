#include <stdio.h>
double expr(){
char a[10];
double f1,f2;
scanf("%s",a);
switch (a[0]){
    case '+':{f1=expr();f2=expr();return f1+f2; }
    case '-':{f1=expr();f2=expr();return f1-f2; }
    case '*':{f1=expr();f2=expr();return f1*f2; }
    case '/':{f1=expr();f2=expr();return f1/f2; }
    default: return atof(a);
}
}
int main(){
    int n,i;
    double answer;
    scanf("%d",&n);
    for (i=0;i<n;i++){
    printf("case#%d:\n",i);
    expr();
    answer=expr();
    printf("%lf\n",answer);
    return 0;}
}