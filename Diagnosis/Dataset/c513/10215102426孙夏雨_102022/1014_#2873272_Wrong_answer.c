#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int A,B;
    scanf("%lld %lld",&A,&B);
    long long int IN,MO,DE=B;
    IN=A/B;
    MO=A%B;
    if((MO-1)/3*3!=MO){
        IN++;
        MO=(-1)*(DE-MO);
    }
    int in[1000];
    int i=0;
    if(IN==0) printf("0");
    while(IN>0){
        long long int w=IN;
        while(w>=3) w-=3;
        int x=w;
        in[i]=x;
        IN/=3;
        i++;
    }
    for(int j=0;j<i;j++){
        if(in[j]==2){
            if(j==i-1) {in[j+1]=1;i++;}
            else {in[j+1]+=1;}
        }
        else if(in[j]==3){
            if(j==i-1){in[j+1]=1;i++;in[j]=0;}
            else {in[j+1]+=1;in[j]=0;}
        }
    }
    for(int k=0;k<i;k++) printf("%d",in[i-1-k]);
    if(B>1) printf(".");
    int mo[1000];
    if(DE!=1){
        long long int MO1=llabs(MO);
        int n1=0;
        while(DE>1){
            n1++;
            DE/=3;
        }
        for(int i=0;i<n1;i++){
            int z=MO1%3;
            mo[i]=z;
            MO1/=3;
        }
        for(int j=0;j<n1;j++){
            if(MO<0) printf("%d",mo[n1-j-1]==1 ? 2 : 0);
            else printf("%d",mo[n1-1-j]);
        }
    }
    return 0;
}

