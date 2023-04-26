#include<stdio.h>
#include<string.h>
#include<math.h>
int binary(char *s,int *n){
    char *s1,c;
    s1=s;
    int m=0;
    while(*s1){
        c=*s1;
        for(int k=7;k>=0;k--){
            if(c>=pow(2,k)){n[m++]=1;c-=pow(2,k);}
            else n[m++]=0;
        }
        s1++;
    }
    int q=(strlen(s)*8)%6;
    while((6-q)!=0&&q!=0){n[m++]=0;q++;}
    return m;
}
void trans(int num,int *n,char *c,char *tab){
    if(num==0)*c=0;
    else{
        int sum=0;
        for(int i=0;i<6;i++){
            sum=sum*2+n[i];
        }
        *c=tab[sum];
        trans(num-6,n+6,c+1,tab);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    char tab[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    for(int i=0;i<t;i++){
        char s[101],c[200],*c1;
        scanf("%s",s);
        int n[810],num;
        num=binary(s,n);
        trans(num,n,c,tab);
        c1=c+strlen(c);
        while((strlen(c)%4)!=0){*c1='=';c1++;*c1=0;}
        printf("case #%d:\n%s\n",i,c);
    }
    return 0;
}