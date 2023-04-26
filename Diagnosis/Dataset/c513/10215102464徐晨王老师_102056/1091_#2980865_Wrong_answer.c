#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    unsigned long long int a,b,c,d;
    int n;
    scanf("%llu+%llui%d",&a,&b,&n);
    c=a;
    d=b;
    for(int i=0;i++;i<n){
        c=a*c+b*d;
        d=a*d+b*c;
    }
    printf("%llu+%llui",c,d);
    return 0;
}