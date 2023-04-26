#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long int x;
    long long int y;
    char dir;
}ZB;

void f(long long int x,long long int y,long long int max,ZB* p,long long int num)
{
    long long int juex=llabs(x),juey=llabs(y);
    if(juex>juey) {
        if(x<0) {
            x+=max;
            max/=2;
            (p+num)->dir='W';
            num++;
            (p+num)->x=x;
            (p+num)->y=y;
        }
        else {
            x-=max;
            max/=2;
            (p+num)->dir='E';
            num++;
            (p+num)->x=x;
            (p+num)->y=y;
        }
    }
    else {
        if(y<0){
            y+=max;
            max/=2;
            (p+num)->dir='S';
            num++;
            (p+num)->x=x;
            (p+num)->y=y;
        }
        else{
            y-=max;
            max/=2;
            (p+num)->dir='N';
            num++;
            (p+num)->x=x;
            (p+num)->y=y;
        }
    }
    if(max>0) f(x,y,max,p,num);
    else return;
}

int main()
{
    long long int x=0,y=0,allM=0,allbu=0,max=1,num=0;
    scanf("%lld %lld",&x,&y);
    allM=llabs(x)+llabs(y);
    if(allM==0) printf("0\n");
    else if(allM%2==0)printf("-1\n");
    else{
        while(allM>0){
            allbu++;
            allM/=2;
            max*=2;
        }
        max/=2;
        printf("%lld\n",allbu);
        ZB* p=(ZB* )malloc((allbu+1)*sizeof(ZB));
        p->x=x;
        p->y=y;
        f(x,y,max,p,num);
        for(int i=allbu-1;i>=0;i--){
            printf("%c",(p+i)->dir);
        }
        printf("\n");
        free(p);
    }
    return 0;
}
