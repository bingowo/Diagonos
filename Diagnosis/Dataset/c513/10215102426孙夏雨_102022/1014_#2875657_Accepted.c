#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int A,B;
    scanf("%lld %lld",&A,&B);
    long long int e=1,an=0;
    if(A%B==0) an=B;
    else{
    long long int min=A<B ? A:B;
    long long int max=A>B ? A:B;
    for(;e<=(min/2);e*=3){
        if (((A/e)*e==A)&&((B/e)*e==B)) an=e;
    }}
    an=an>0 ? an:1;
    A/=an;
    B/=an;
    long long int IN,MO,DE=B;
    IN=A/B;
    MO=A%B;
    int mo[1000];
    int t=0;
    int n1=0;
    if(DE!=1){
        for(int i=0;DE>1;i++){
            int z=MO%3;
            mo[i]=z+t;
            t=0;
            if(mo[i]==2) t=1;
            else if(mo[i]==3){mo[i]=0;t=1;}
            MO/=3;
            n1++;
            DE/=3;
        }
    }
    int in[1000];
    int i=0;
    IN=IN+t;
    t=0;
    if(IN==0) printf("0");
    while(IN>0){
        int x=IN%3;
        in[i]=x+t;
        t=0;
        if(in[i]==2) t=1;
        else if(in[i]==3) {in[i]=0;t=1;}
        IN/=3;
        i++;
    }
    if(t==1) {in[i]=1;i++;}
    for(int k=0;k<i;k++) printf("%d",in[i-1-k]);
    if(B>1) printf(".");
    for (int j=0;j<n1;j++) printf("%d",mo[n1-1-j]);
    return 0;
}
