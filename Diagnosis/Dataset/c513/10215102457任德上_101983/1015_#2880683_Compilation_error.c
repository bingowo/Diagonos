#include<stdio.h>
#include<stdlib.h>
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
void reverse(char *s){
    char *s1,s2;
    s1=s;
    while(*s1)s1++;
    s1--;
    while(s1>s){
        s2=*s1;
        *s1=*s;
        *s=s2;
        s1--,s++;
    }
}
int add(int n1,int n2,int carry1,int base){
    carry=0;
    int sum;
    sum=n1+n2+carry1;
    //printf("%d\n",sum);
    while(sum>=base){
        carry++;
        sum-=base;
    }
    return sum;
}
int main(){
    int T,prime[25];
    for(int i=1,j=0;j<26;i++){
        if(prime_number(i))prime[j++]=i;
    }
    scanf("%d",&T);
    while(T-->0){
        char s1[50],s2[50];
        int end[26],time=0;
        scanf("%s%s",s1,s2);
        reverse(s1);
        reverse(s2);
        int i1,i2,length1=strlen(s1),length2=strlen(s2),number1,number2,c1=1,c2=1,c3=1;
        i1=(length1+1)/2,i2=(length2+1)/2;
        while(c1<=i1||c2<=i2){
            number1=c1<=i1?(int)(s1[2*c1-2]-'0'):0;
            number2=c2<=i2?(int)(s2[2*c2-2]-'0'):0;
            if(number1!=0&&number2!=0){
                long long int base=1;
                for(int i=0;i<c3;i++)base*=prime[i];
                end[c3-1]=add(number1,number2,carry,base);
            else end[c3-1]=number1!=0?number1:number2;
            c3++,c1++,c2++;
        }
        if(carry!=0)end[c3-1]=carry;
        printf("case #%d:\n",time++);
        for(int i=0;i<c3-1;i++)printf("%d,",end[c3-1-i]);
        printf("%d\n",end[0]);
    }
}
