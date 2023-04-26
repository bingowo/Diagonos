#include<stdio.h>
char s[15]={0};
int i=0;
void transform(long long x,long long y){
    if(y%2LL==0LL){
        long long x1,x2;
        x1=x-1LL;
        x2=x+1LL;
        y/=2LL;
        x1/=2LL;
        x2/=2LL;
        if(x1==0LL&&y==0LL){
            s[i++]='E';
            return;
        }
        if(x2==0LL&&y==0LL){
            s[i++]='W';
            return;
        }
        if((x1+y)%2LL!=0LL){
            s[i++]='E';
            transform(x1,y);
        }
        else{
            s[i++]='W';
            transform(x2,y);
        }
    }
    else{
        long long y1,y2;
        y1=y-1LL;
        y2=y+1LL;
        x/=2LL;
        y1/=2LL;
        y2/=2LL;
        if(y1==0LL&&x==0LL){
            s[i++]='N';
            return;
        }
        if(x==0LL&&y2==0LL){
            s[i++]='S';
            return;
        }
        if((x+y1)%2LL!=0LL){
            s[i++]='N';
            transform(x,y1);
        }
        else{
            s[i++]='S';
            transform(x,y2);
        }
    }
}
int main(){
    long long int x1,y1;
    scanf("%lld%lld",&x1,&y1);
    if((x1+y1)%2LL==0LL&&(x1!=0LL||y1!=0LL))printf("-1");
    else if(x1==0LL&&y1==0LL)printf("0");
    else{
        transform(x1,y1);
        printf("%d\n",i);
    }
    return 0;
}