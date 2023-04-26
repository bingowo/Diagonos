#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pros,c,r,s;
int a[50],n;
char num[40]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void Change(){
    n=0;
    s=0;
    if(c<0){
        s=1;
        c=-c;
    }
    while(c){
        a[n]=c%r;
        c/=r;
        n++;
    }
}

void Print(){
    if(s) printf("-");
    for(int i=n-1;i>=0;i--)
        printf("%c",num[a[i]]);
    printf("\n");
}

int main(){
    scanf("%d", &pros);
    for(int cnt=0;cnt<pros;cnt++){
        scanf("%d%d",&c,&r);
        Change();
        Print();
    }

    return 0;
}
