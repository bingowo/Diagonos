#include <stdio.h>

int main(){
    int T;
    scanf("%d",&T);
    while(T-->0){
        char s[100],*s1;
        int m=0,p,i=0;
        scanf("%s",s);
        s1=s;
        while(*s1){
            if(*s1=='-')p=-1;
            else if(*s1=='1')p=1;
            else p=0;
            m=m*3+p;
            s1++;
            
        }
        printf("case #%d:\n%d\n",i++,m);
    }
    return 0;
}

