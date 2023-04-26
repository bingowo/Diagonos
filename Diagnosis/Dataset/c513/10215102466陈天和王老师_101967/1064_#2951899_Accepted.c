#include <stdio.h>
#include <stdlib.h>

double f_bolan(){
    char s[11]={'\0'};
    scanf("%s",s);
    switch (s[0]) {
        case'+': return f_bolan()+f_bolan();
        case'-': return f_bolan()-f_bolan();
        case'/': return f_bolan()/f_bolan();
        case'*': return f_bolan()*f_bolan();
        default:return atof(s);
    }
}

int main(){
    int T;
    scanf("%d\n",&T);
    for(int t=0;t<T;t++){
        double ans=f_bolan();
        printf("case #%d:\n",t);
        printf("%f\n",ans);
    }
    return 0;
}