#include<stdio.h>

int main(){
    char st[123456];
    scanf("%s",st);
    int i=0;
    int a[10010];
    int pos=2;
    int strl=strlen(st);
    while (pos<strl){
        int n=0;
        if (st[pos]>='0' && st[pos]<='9'){
            n=st[pos]-'0';
        }
        else {
            n=st[pos]-'A'+10;
        }
        if (n>=8){
            a[i]=1;
            i++;
            n-=8;
        }
        else {
            a[i]=0;
            i++;
        }
        if (n>=4){
            a[i]=1;
            i++;
            n-=4;
        }
        else {
            a[i]=0;
            i++;
        }
        if (n>=2){
            a[i]=1;
            i++;
            n-=2;
        }
        else {
            a[i]=0;
            i++;
        }
        if (n>=1){
            a[i]=1;
            i++;
            n-=1;
        }
        else {
            a[i]=0;
            i++;
        }
        pos++;
    }
    long long ansa=0,ansb=0;
    for (int j=0;j<i;j++){
        long long x=-ansa-ansb;
        long long y=ansa-ansb;
        ansa=x;
        ansb=y;
        if (a[j]==1){
            ansa+=1;
        }
    }
    if (ansa==0&&ansb==0){
        printf("0\n");
    }
    else if (ansa==0){
        if (ansb==1) printf("i\n");
        else if (ansb==-1) printf("-i\n");
        else printf("%lldi\n",ansb);
    }
    else if (ansb==0){
        printf("%lld\n",ansa);
    }
    else if (ansb<0){
        if (ansb==-1) printf("%lld-i\n",ansa);
        else printf("%lld%lldi\n",ansa,ansb);
    }
    else if (ansb==1){
        printf("%lld+i\n",ansa);
    }
    else printf("%lld+%lldi\n",ansa,ansb);
    return 0;
}
