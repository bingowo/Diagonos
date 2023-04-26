#include <stdio.h>

int main() {
    int a,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    int up=2*(m-((n-1)*(n-1)-9*(n-1)+26)*a/2)/((n-1)*(n-1)-7*(n-1)+14);
    if(x==1 || x==2){
        printf("%d\n",a);
        return 0;
    } else if(x==3){
        printf("%d\n",2*a);
        return 0;
    } else if(x==4){
        printf("%d\n",2*a+up);
        return 0;
    } else{
        printf("%d\n",(x*x-9*x+26)*a/2+(x*x-7*x+14)*up/2);
    }
    printf("Hello, World!\n");
    return 0;
}
