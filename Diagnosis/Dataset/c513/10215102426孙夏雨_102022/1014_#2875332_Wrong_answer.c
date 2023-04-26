#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int A,B;
    scanf("%lld %lld",&A,&B);
    long long int e=3,an=0;
    long long int ww=A%B;
    if(ww==0) an=B;
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
        int t1=0;
        for(int i=0;MO1>0;i++){
            int z=MO1%3;
            mo[i]=z+t1;
            t1=0;
            if(mo[i]==2) t1=1;
            else if(mo[i]==3){mo[i]=0;t1=1;}
            MO1/=3;
            n1++;
        }
        t=t1;
    }
    int in[1000];
    int i=0;
    IN=IN+t;
    if(IN==0) printf("0");
    int t2=0;
    while(IN>0){
        long long int w=IN;
        long long int qq=3;
        w=w%qq;
        int x=w;
        in[i]=x+t2;
        t2=0;
        if(in[i]==2) t2=1;
        else if(in[i]==3) {in[i]=0;t2=1;}
        IN/=3;
        i++;
    }
    if(t2==1) {in[i]=1;i++;}
    for(int k=0;k<i;k++) printf("%d",in[i-1-k]);
    if(B>1) printf(".");
    for (int j=0;j<n1;j++) printf("%d",mo[n1-1-j]);
    return 0;
}
