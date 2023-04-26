#include<stdio.h>

int main(){
    long long int a,b,c,d;
    int s[60]={0};
    int s1[60]={0};
    int s2[60]={0};
    scanf("%lld%lld",&a,&b);
    c=a/b;
    d=a%b;
    int i=0;
    do{
        s1[0]=c%3;
        c/=3;
        i++;
    }while(c);
    int j=0,q;
    for(i=i-1;i>0;i--,j++){
        s[j]=s1[i];
    }
    q=j;
    int n=d;
    if(d){
        int p=0;
        do{
            s2[p]=d%3;
            d/=3;
            p++;
            b/=3;
        }while(d||b!=1);
        for(p=q-1;p>=0;p--,q++){
            s[q]=s2[p];
            
        }
        
    }
    int l=0;
    int t=q;
    for(q=q-1;q>=0;q--){
        if(s[q]+1+l>=3){
            s[q]=s[q]+1+l-3;
            l=1;
        }
        else{
            s[q]=s[q]+1+l;
            l=0;
        }
    }
    for(q=0;q<t;q++){
        if(s[q]==0){
            t=t-1;
        }
        else{
            break;
        }
    }
    if(l==1){
        prinf("1");
    }
    for(int m=0;m<t;m++){
        printf("%d",s[m]);
        if(n){
            if(m==j-1);
                printf(".");
        }
    }
    return 0;
}
























