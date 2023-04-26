#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0;i<t;i++){
        double ret=0;
        char s[53];
        double r = 1.0/8;
        scanf("%s",s);
        for(int j = 2;s[j];j++){
            ret = ret + (s[j]-'0')*r;
            r = r/8;
        }
        printf("case #%d:\n%.0lf\n",i,ret);
    }

    return 0;
}