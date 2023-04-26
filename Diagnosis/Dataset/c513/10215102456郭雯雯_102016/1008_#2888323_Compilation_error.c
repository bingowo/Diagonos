#include<stdio.h>
int main(){
    int t,m=0;
    long long int x,y,z;
    scanf("%d",&t);
    while(m<t){
        int n;
        scanf("%d %d",&x,&y);
        z=x^y;
        n=num(z);
        printf("%d\n",n);
        m++;
    }
}