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
        a+=s[i]*1.0*pow(8,1-i);
        
        printf("case #%d:\n%lld\n",cas,a);
        
    }
    return 0;
    
}