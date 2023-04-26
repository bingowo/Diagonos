#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0;i<t;i++){
        double ret=0;
        char s[52];
        double r = 1.0/8;
        scanf("%s",s);
        for(int j = 2;j<52;j++){
            ret = ret + s[j]*r;
            r = r/8;
        }
        printf("case #%d:\n%g\n",i,ret);
    }
    
    return 0;
}