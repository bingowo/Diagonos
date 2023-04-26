#include<stdio.h>
#include<string.h>
#include<math.h>
int GCD(int m,int n){
    int a,b,c;
    if(m>n)a=n;
    else
        a=m;
    for(b=2;b<=a;b++){
        if(m%b==0&&n%b==0)return b*GCD(m/b,n/b);
    }
    return 1;
}
int main(){
    char s[30],s1[30],s2[30],*c1,*c2;
    int i=0,p=0,gcd,C,B=0;
    long long int A=0;
    scanf("%s",s);
    c1=s,c2=s;
    while(*c1!='.')c1++;
    if(c1<s){
    while(*c2)c2++;
    while(c1>s){
        s1[i]=s[i];
        i++,c1--;
    }
    s1[i]=0;
    while(c2>c1){
        i++;
        s2[p++]=s[i];
        c2--;
    }
    s2[i]=0;
    c1=s1,c2=s2;
    while(*c1){
        if(*c1=='2')A=-1+A*3;
        else if(*c1=='1')A=1+A*3;
        else A=A*3;
        c1++;
    }
    C=(int)pow(3,strlen(c2));
    while(*c2){
        if(*c2=='2')B=-1+B*3;
        else if(*c2=='1')B=1+B*3;
        else B=B*3;
        c2++;
    }
    if(B<0){A--,B+=C;}
    gcd=GCD(B,C);
    printf("%d %d %d",A,B,C);
    }
    else{
        c1=s;
        while(*c1){
        if(*c1=='2')A=-1+A*3;
        else if(*c1=='1')A=1+A*3;
        else A=A*3;
        c1++;
        }

    }
    printf("%lld",A);
    return 0;


}