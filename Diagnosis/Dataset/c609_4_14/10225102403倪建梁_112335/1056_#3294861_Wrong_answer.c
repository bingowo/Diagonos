#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b,c,d,e;
        d=1;e=1;
        scanf("%d %d",&a,&b);
        if(b==0) c=1;
        else{
            for (int i=0;i<b;i++) d *= a-i;
            for (int i=0;i<b;i++) e *= b-i;
        }
        c=d/e;
        printf("case #%d:\n",i);
        printf("%d\n",c);
    }
    return 0;
}