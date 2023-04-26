#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int carry=0;
int prime_number(int a){
    if(a==1)return 0;
    if(a==2)return 1;
    if(a%2==0)return 0;
    for(int i=3;i<a;i=i+2){
        if(a%i==0)return 0;
    }
    return 1;
}
int add(int n1,int n2,int carry1,int base){
    carry=0;
    int sum;
    sum=n1+n2+carry1;
    while(sum>=base){
        carry++;
        sum-=base;
    }
    return sum;
}
int main(){
    int T,prime[25],time=0;
    for(int i=1,j=0;j<26;i++){
        if(prime_number(i))prime[j++]=i;
    }
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        static char s1[53],s2[53],*m1,*m2,*n1,*n2;
        static int end[26];
        int c=1;
        scanf("%s%s",s1+1,s2+1);
        *s1=',',*s2=',';
        n1=strrchr(s1,','),n2=strrchr(s2,',');
        while(n1!=NULL||n2!=NULL){
            int k1,k2;
            if(n1!=NULL){k1=atoi(n1+1);*n1=0;n1=strrchr(s1,',');}
            else k1=0;
            if(n2!=NULL){k2=atoi(n2+1);*n2=0;n2=strrchr(s2,',');}
            else k2=0;
            end[c-1]=add(k1,k2,carry,prime[c-1]);
            c++;
        }
        if(carry!=0){end[c-1]=carry;c++;}
        c--;
        carry=0;
        printf("case #%d:\n",i);
        for(int i=0;i<c-1;i++)printf("%d,",end[c-1-i]);
        printf("%d\n",end[0]);
    }
    return 0;
}