#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long cToThree(char c){
    if(c == '0'){return 0;}
    if(c == '1'){return 1;}
    if(c == '2'){return -1;}
    return 0;
}
long long threeToi1(char *s){
    int slen = strlen(s);
    long long res = 0;
    for(int i = 0;i<slen;i++){
        res = res*3+cToThree(s[i]);
    }
    return res;
}
void threeToi2(char *s, long long *n2){
    int slen = strlen(s);
    long long n21 = 0,n22 = 1;
    for(int k = 0;k<slen;k++){
        n22*=3;
        n21 = n21*3+cToThree(s[k]);
    }
    n2[0] = n21;n2[1] = n22;
    return;
}
long long GCD(long long a, long long b)
{
    long long r = 0;
    while(b!=0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
void myPrint(long long n1,long long*n2){
    if((n1 == 0)&&(n2[0]==0)){
        printf("0");
        return;
    }
    if(n1 == 0){
        printf("%lld %lld",n2[0],n2[1]);
        return;
    }
    if(n2[0] == 0){
        printf("%lld",n1);
        return;
    }
    printf("%lld %lld %lld",n1,n2[0],n2[1]);
    return;
}
int main()
{
    char s[50];memset(s,0,50*sizeof(char));
    scanf("%s",s);
    char s1[50];memset(s1,0,50*sizeof(char));
    char s2[50];memset(s2,0,50*sizeof(char));
    sscanf(s,"%[^.].%[^.]",s1,s2);
    long long n1 = threeToi1(s1);
    long long *n2 = (long long*)malloc(2*sizeof(long long));memset(n2,0,2*sizeof(long long));
    threeToi2(s2,n2);

    if((n1<0)&&(n2[0]>0)){
        n1+=1;
        n2[0] = n2[1] - n2[0];
    }
    else if((n1>0)&&(n2[0]<0)){
        n1-=1;
        n2[0] = n2[1] + n2[0];
    }
    else if((n1<0)&&(n2[0]<0)){
        n2[0] = -1*n2[0];
    }
    long long gcd = GCD(n2[0],n2[1]);
    gcd = gcd>0?gcd:-1*gcd;
    n2[0]/=gcd;n2[1]/=gcd;
    //printf("gcd = %lld\n",gcd);
    //printf("s1 = %s\ns2 = %s\n",s1,s2);
    //printf("n1 = %d, n21 = %lld, n22 = %lld\n",n1,n2[0],n2[1]);


    myPrint(n1,n2);
    return 0;
}
