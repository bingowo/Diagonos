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
        char s1[53],s2[53],*m1,*m2,*n1,*n2;
        int c=1;
        scanf("%s%s",s1+1,s2+1);
        *s1=',',*s2=',';
        m1=s1+strlen(s1);
        m2=s2+strlen(s2);
        *m1=',',*m2=',';
        *(m1+1)=0,*(m2+1)=0;
        m1=s1+strlen(s1)-1,m2=s2+strlen(s2)-1;
        *m1=0,*m2=0;
        e1=strrchr(s1,','),e2=strrchr(s2,',');
        while(e1>=s1||e2>=s2){
            int k1=atoi(e1),k2=atoi(e2);
            end[c-1]=add(k1,k2,carry,prime[c-1]);
            c++;
        }
        if(carry!=0){end[c-1]=carry;c++;}
        c--;
        printf("case #%d:\n",i);
        for(int i=0;i<c-1;i++)printf("%d,",end[c3-1-i]);
        printf("%d\n",end[0])
        
        
        
        
        
        
        
        
        
    }
}
