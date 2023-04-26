#include <stdio.h>
#include<stdlib.h>
int binary(char a){
    int m=0;
    char n = 1;
    for(int i = 8;i>0;i--,a=a>>1)m+=(a&n);
    return m;
}
int main(){
    int n,i=0;
    scanf("%d",&n);
    while(n-->0){
        int p,q=0,m=1,z;
        char s[121],*s1;
        scanf("%s",s);
        s1=s;
        while(*s1){
            p=binary(*s1);
            q+=p;
            s1++;

        }
        z=q;
        while(z%2==0)m*=2,z=z/2;
        printf("case #%d:\n%d/%d\n",i++,q/m,8*strlen(s)/m);
    }
    return 0;
}

