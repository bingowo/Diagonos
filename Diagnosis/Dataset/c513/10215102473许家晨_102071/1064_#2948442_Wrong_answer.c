#include<stdio.h>
#include<ctype.h>
double expr(){
    char a[10];
    double f1,f2;
    scanf("%s",a);
    switch (a[0])
    {
    case '+':{f1=expr();f2=expr();return f1+f2;break;}
    case '-':{f1=expr();f2=expr();return f1-f2;break;}
    case '*':{f1=expr();f2=expr();return f1*f2;break;}
    case '/':{f1=expr();f2=expr();return f1/f2;break;}
    default:
        return atof(a);
    }
}
int main(){
    int T,cnt=0;
    scanf("%d",&T);
    while(T){
        printf("case #%d: \n",cnt++);
        double res=expr();
        printf("%f\n",res);
        return 0;
}}
