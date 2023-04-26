#include <stdio.h>
#include <stdlib.h>

struct data{long long int num; int sign;};

int cmp(const long long *c,const long long *d){
    struct data m,n;
    long long int m1,n1,m2,n2;
    m=*(struct data*)c;
    n=*(struct data*)d;
    m1=m.num;
    n1=n.num;
    if(m.sign==0) m2=-m1;
    if(m.sign==1) m2=m1;
    if(n.sign==0) n2=-n1;
    if(n.sign==1) n2=n1;
    while(m2>9) m2/=10;
    while(n2>9) n2/=10;
    if(m2!=n2) {
        if(n2>=m2) return 1;
        else return -1;
    }
    else if(m2==n2){
        if(m1>=n1) return 1;
        else return -1;
    };
}

int main(){
    int Num,Now=0,num,i;
    struct data{long long int num; int sign;} a[10001];
    scanf("%d",&Num);
    while(Now<Num){
        scanf("%d",&num);
        for(i=0;i<num;i++){
            scanf("%lld",&a[i].num);
            if(a[i].num>=0) a[i].sign=1;
            else a[i].sign=0; 
        }
        qsort(a, num, sizeof(a[0]), cmp);
        printf("case #");
        printf("%d:\n",Now);
        for(i=0;i<num-1;i++){
            printf("%lld ",a[i].num);
        }
        printf("%lld\n",a[i].num);
        Now++;
    }
    return 0;
}