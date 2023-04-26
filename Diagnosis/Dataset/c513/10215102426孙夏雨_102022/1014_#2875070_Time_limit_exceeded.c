#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int A,B;
    scanf("%lld %lld",&A,&B);
    long long int e=3,an=0;
    if(A/B*B==A) an=B;
    else{
    for(;e<=(A<B ? A:B);e+=3){
        if (((A/e)*e==A)&&((B/e)*e==B)) an=e;
    }}
    an=an>0 ? an:1;
    A/=an;
    B/=an;
    long long int IN,MO,DE=B;
    IN=A/B;
    MO=A%B;
    long long int q=1,p=0;
    int mo[1000];
    int t=0;
    int n1=0;
    if(DE!=1){
        long long int MO1=MO;
        while(DE>1){
            n1++;
            DE/=3;
        }
        for(int i=0;i<n1;i++){
            int z=MO1%3;
            mo[i]=z;
            MO1/=3;
        }
        for(int j=0;j<n1-1;j++){
            if(mo[j]==2) mo[j+1]+=1;
            else if(mo[j]==3){mo[j+1]+=1;mo[j]=0;}
        }
        if (mo[n1-1]==2) t=1;
        else if(mo[n1-1]==3){mo[n1-1]=0;t=1;}
    }
    int in[1000];
    int i=0;
    IN=IN+t;
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
    for (int j=0;j<n1;j++) printf("%d",mo[n1-1-j]);
    return 0;
}
