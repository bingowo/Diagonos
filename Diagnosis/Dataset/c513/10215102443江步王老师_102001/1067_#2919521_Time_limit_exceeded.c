#include<stdio.h>


long long T(int n);
int main()
{
    int t;
    int n;
    int i;
    scanf("%d",&t);
    for (i=0;i<t;i++){
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%lld\n",T(n));
    }
    return 0;
}

long long T(int n)
{
    if (n==0){
        return 0;
    }
    else if (n==1 || n==2){
        return 1;
    }
    else if (n ==3){
        return 2;
    }
    else if (n==4){
        return 4;
    }
    else if(n==5){
        return 7;
    }
    else if(n==6){
        return 13;
    }
    else if (n==7){
        return 24;
    }
    else{
        return (T(n-3)+T(n-2)+T(n-1));
    }
}