#include<stdio.h>
int main(){
    char tab[25]="0123456789ABCDEFGHIJK";
    int n,t,i=0,t1,k=0;
    char end[40],*p1,*p2,c;
    scanf("%d%d",&n,&t);
    while(n!=0){
        t1=n%t;
        if(t1<0)n=n/t+1;
        else n/=t;
        t1=t1>0?t1:t-t1;
        end[i++]=tab[t1];
    }
    end[i]=0;
    p1=end;
    p2=end+i-1;
    while(p1<p2){
        c=*p1;
        *p1=*p2;
        *p2=c;
        p1++,p2--;
    }
    printf("%s",end);
    return 0;
}
