#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef long long int lli;
int prime[1000];
int isprime(int i){
    if(i==1)return 0;
    if(i==2)return 1;
    if(i%2==0)return 0;
    for(int j=3;j<i;j++){
        if(i%j==0)return 0;
    }
    return 1;
}
void create(int* prime){
    int idx=0;
    *(prime+idx++)=1;
    for(int i=1;i<1000;i++){
        if(isprime(i))*(prime+idx++)=i;
    }
}
int cal(int *ret,int num,int idx);
int main(){
    create(prime);
    int idx=0;
    int in[1000]={0};
    while(scanf("%d",&in[idx++])){
        char ch=getchar();
        if(ch==',')continue;
        if(ch=='\n')break;
    }
    int inlen=idx;
    int ret[1000]={0};
    int retlen;
    idx=1;
    for(int i=inlen-1;i>=0;i--){
        retlen=cal(ret,in[i],idx);
        idx++;
    }
    ret[retlen]=-1;int i=0;
    for(int i=retlen-1;i>=0;i--){
        printf("%d",ret[i]);
    }
}
void myitoa(char*a,int num){
    int i=0;
    do{
        *(a+i)=num%10;
        num/=10;
        i++;
    }while(num);
}
int mylen(char *a){
    int i=99;
    while(*(a+i)==0)i--;
    return i+1;
}
int cal(int *ret,int num,int idx)
{
    char *quan=(char*)malloc(sizeof(char)*100);memset(quan,0,100);
    int quanlen;
    char *s=(char*)malloc(sizeof(char)*100);memset(s,0,100);*s=1;
    for(int i=0;i<idx;i++){
        char *t=(char*)malloc(sizeof(char)*100);memset(t,0,100);
        myitoa(t,prime[i]);
        int si=mylen(s),ti=mylen(t);
        for(int i=0;i<si;i++){
            int begin=i;int carry=0;int temp=0;
            for(int j=0;j<ti;j++){
                temp=s[i]*t[j];
                int one=carry+quan[begin]+temp;
                carry=one/10;quan[begin]=one%10;begin++;
            }
        while(carry){quan[begin]=carry%10;carry/=10;begin++;}
        quanlen=mylen(quan);
        for(int i=0;i<quanlen;i++)*(s+i)=*(quan+i);
        memset(quan,0,100);
        }
    }
    quan=s;
    int carry=0;int i,j;
    for(j=0;j<num;j++){
        for(i=0;i<quanlen;i++){
            int temp=carry+ret[i]+quan[i];
            ret[i]=temp%10;
            carry=temp/10;}
        while(carry){
            int temp=ret[i]+carry;
            ret[i]=temp%10;
            carry=temp/10;
            i++;
        }
    }
    return i;
}