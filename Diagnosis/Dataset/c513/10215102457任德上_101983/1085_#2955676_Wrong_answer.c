#include<stdio.h>
#include<string.h>
typedef struct{
    int cnt,v[1005],flag;
}BigInt;
BigInt Int2Big(int a,int flag){
    BigInt r={0,{0},flag};
    do{
        r.v[r.cnt++]=a%10;
        a/=10;
    }while(a>0);
    return r;
}
BigInt sub(BigInt a,BigInt b){
    int flag=1,i=0;
    if(a.cnt>b.cnt)flag=1;
    else if(a.cnt<b.cnt)flag=-1;
    else{
        int i=a.cnt;
        while(i>=0){
            if(a.v[i]!=b.v[i]){
                flag=a.v[i]>b.v[i]?1:-1;
                break;
            }
            i--;
        }
    }
    if(flag==1){
        while(i<a.cnt||i<b.cnt){
            a.v[i]=a.v[i]>=b.v[i]?a.v[i]-b.v[i]:a.v[i]-b.v[i]+10*(a.v[i+1]-(--a.v[i+1]));
            i++;
        }
        while(a.v[a.cnt-1]==0)a.cnt--;
        a.flag=1;
        return a;
    }
    else{
        while(i<a.cnt||i<b.cnt){
            b.v[i]=b.v[i]>=a.v[i]?b.v[i]-a.v[i]:b.v[i]-a.v[i]+10*(b.v[i+1]-(--b.v[i+1]));
            i++;
        }
        while(b.v[b.cnt-1]==0)b.cnt--;
        b.flag=-1;
        return b;
    }
}
void transform(char *s1,BigInt *a){
    a->cnt=strlen(s1);
    for(int i=a->cnt-1;i>=0;i--){a->v[i]=*s1-'0';s1++;}
}
int main(){
    char s1[1000],s2[1000];
    while(scanf("%s%s",s1,s2)!=EOF){
        BigInt a={0,{0},1},b={0,{0},1},*a1,*b1;
        a1=&a;
        b1=&b;
        transform(s1,a1);
        transform(s2,b1);
        a=sub(a,b);
        if(a.flag==-1)printf("-");
        for(int i=a.cnt-1;i>=0;i--)printf("%d",a.v[i]);
        printf("\n");

    }
    return 0;
}