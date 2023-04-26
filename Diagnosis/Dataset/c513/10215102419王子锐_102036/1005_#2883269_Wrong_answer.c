#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int cas=0; cas<T; cas++){
        char s[51];
        scanf("%s",s);
        double a=0; 
        for(int i=2; i<strlen(s); i++)
        a+= (double)(s[i]-'0') * pow(0.125,i-1);
        
        printf("case #%d:\n%lld\n",cas,a);
        
    }
    return 0;
    
}
