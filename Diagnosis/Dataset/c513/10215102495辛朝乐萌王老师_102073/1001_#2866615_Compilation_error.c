#include <stdio.h>
#include<stdlib.h>

void print(num)
{
    if(num<10) printf("%d",num);
    else printf("%c",num-10+'A');
}

void division(N,R)
{
    if (N>0){
        division(N/R,R);
        print(N%R);
    }
}
int main()
{
    int n,i = 0;
    int N,R,num;
    scanf("%d",&n);
    for(i=0;i>0;i--){
        scanf("%d %d",&N,&R);
        if(N<0){
            printf("-");
            N = -N;
        }
        division(N,R);
        printf("\n");
    }
    return 0;
}

{
    int n,num,p;
    scanf("%d",&n);
    int a[100],r = 0,y;
    while(scanf("%d %d",&num,&p) != EOF){
    for(int j=0;j<n;j++){
        hex(num, p);
    }
    }
    printf("\n");
    return 0;
}
