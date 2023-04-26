#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data
{
    long long int a;    //整数
    int number;  //位数
};
int cmp(const void *a,const void *b){
    struct data d1,d2;
     d1=*((struct data *)a);
     d2=*((struct data *)b);
     if(d2.number!=d1.number){
        return d2.number-d1.number;
     }
     else{
        if(d1.a>d2.a){
            return 1;
        }
        else return -1;
     }

}
int main()
{
    struct data p[10001];
    int i=0;
    while((scanf("%lld ",&p[i].a))!=EOF){
        p[i].a=abs(p[i].a);
        p[i].number=0;
        while(p[i].a){
            p[i].a=p[i].a/10;
            p[i].number++;
        }
        i++;
    }
    qsort(p,i,sizeof(p[0]),cmp);
    for(int j=0;j<i;j++){
        printf("%lld",p[j].a);
    }



    return 0;
}
