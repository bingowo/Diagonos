#include <stdio.h>
#include <math.h>
int main(){
    unsigned long long int sum;
    scanf("%llu",&sum);
    long long int x,y;
    long long int qm=(long long int)sqrt(sum);
    if(qm*qm>=sum)qm=qm-1;
    if(qm%2==0){
        qm=qm+1;
        x=qm/2;
        y=qm-x;
        if((qm*qm-sum)<=qm){
           y=y-(qm*qm-sum);
        }
        if((qm*qm-sum)>qm){
            y=-qm/2;
            x=x-((qm*qm-sum)-qm);
        }
    }
    if(qm%2==1){
        qm=qm+1;
        x=-qm/2;
        y=-qm/2;
        if((qm*qm-sum)<=qm){
           y=y+(qm*qm-sum);
        }
        if((qm*qm-sum)>qm){
            y=qm/2;
            x=x+((qm*qm-sum)-qm);
        }

    }
    printf("(%lld,%lld)",x,y);
    return 0;
}
