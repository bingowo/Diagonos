#include<stdio.h>
int main(){
    int t,n,r,flag,i,j;
    char s[40],num[40];
    for(i=0;i<36;++i){
        if(i<10) s[i]=i+'0';
        else s[i]=i-10+'A';
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&r);
        j=flag=0;
        if(n<0) n=-n,flag=1;
        while(n){
            num[j++]=s[n%r];
			n/=r;
        }
        if(flag) printf("-");
        for(i=j-1;~i;--i) printf("%c",num[i]);
        printf("\n");
    }
    return 0;
}