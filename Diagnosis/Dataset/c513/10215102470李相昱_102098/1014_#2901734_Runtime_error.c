#include <stdio.h>
int tran(int*s1,long long int m){
    int i =0;
    do{
        s1[i] = m%3;
        m = m/3;
        i++;
    }while(m);
    return i;
}
int main(){
    long long int a,b,c,d;
    int  s[60]={0};
    int  s1[30]={0};
    int s2[30] ={0};
    scanf("%lld%lld",&a,&b);
    c = a/b;
    d = a%b;
    int i = tran(s1,c);
    int j = 0,q;
    for(i = i-1;i>=0;i--,j++){
        s[j] =  s1[i];
    }
    if(d){
        int p = tran(s2,d) ;
        for(q = j,p = p-1;p>=0;p--,q++){
            s[q] = s2[p];
        }
    }
    int l = 0;
    int t = q;
    for(q = q-1;q>=0;q--){
        if(s[q]+1+l>=3){
            s[q] = s[q]+1+l-3;
            l = 1;
        }else{
            s[q] = s[q] +1+l;
            l = 0;
        }
    }

    for (q=0;q<t;q++){
        s[q] = (s[q]-1==-1?2:s[q]-1);
    }
    if(l == 1){
        printf("1");
    }
    for(int m = 0;m<t;m++){
        printf("%d",s[m]);
        if(d){
            if(m == j-1){
                printf(".");
            }
        }
    }
    return 0;
}