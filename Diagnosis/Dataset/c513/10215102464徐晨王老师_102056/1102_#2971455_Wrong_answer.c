#include <stdio.h>
#include <math.h>
int main(){
    unsigned long long int sum;
    scanf("%llu",&sum);
    long long int x,y;
    if(sum<=990423840){
    x=0;y=0;
    long long int sym=1,ans=1;
    unsigned long long int i=0;
    int k=1,flag=1;
    if(sum==0)k=0;
    while(k){
        if(flag==1){
            for(int j=0;j<ans;j++){
            y=y+sym;
            i++;
            if(i==sum){
                k=0;
                break;
            }
            }
            flag=-1;
            sym=-sym;
            continue;
        }
        if(flag==-1){
            for(int j=0;j<ans;j++){
            x=x+sym;
            i++;
            if(i==sum){
                k=0;
                break;
            }
            }
            flag=1;
            ans++;
            continue;
        }
    }
    }
    else{
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
    }
    printf("(%lld,%lld)",x,y);
    return 0;
}
