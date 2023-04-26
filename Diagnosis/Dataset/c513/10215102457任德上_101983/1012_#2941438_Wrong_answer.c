#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
int R(long long int a,long long int b){
    if((a-b)%2!=0)return 1;
    return 0;
}
int main(){
    long long int sign,a=0LL,b=0LL,m,a1,b1;
    int flag1=0,flag2=0,flag3=0;
    char c;
    int n[1000];
    sign=1LL;
    while((c=getchar())!='\n'){
        if(c=='-')sign=-1LL;
        else if(c=='+')sign=1LL;
        else if(c=='i'){
            flag1=1;
        }
        else{
            flag2++;
            int i=0;
            char num[20]={0};
            num[i++]=c;
             while(isdigit(c=getchar()))num[i++]=c;
             if(c=='i')flag2--;
            ungetc(c,stdin);
            m=sign*atoll(num);
            if(a==0LL){a=m;m=0LL;}
            else b=m;
            sign=1LL;
        }
    }
    if(flag1==1&&flag2==0&&a!=0LL){b=a;a=0LL;}
    if((flag1==1&&flag2>=1&&b==0LL)||(flag1==1&&flag2==0&&a==0LL))b=sign;
    int i=0;
    do{
        int r=R(a,b);
        n[i++]=r;
        a1=a;
        b1=b;
        a=(r-a1+b1)/2,b=(r-a1-b1)/2;
    }while(a!=0||b!=0);
    for(int k=i-1;k>=0;k--)printf("%d",n[k]);
    return 0;
}