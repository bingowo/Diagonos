#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define N 25

int GCD(int m,int n){
    return m%n == 0?n:GCD(n,m%n);
}

int CanbeRoot (int n)
{
    for(int i = 1; n > 0; i += 2) n -= i;
    return n == 0;
}

int findX(char s[])
{
    for(int i =0;i<strlen(s);++i){
        if(s[i]=='x')return 1;
    }
    return 0;
}

int getXISHU (char s[])
{
    if(!findX(s))return atoi(s);
    int idx = 0, sign = 1;
    if(s[idx] == '+' || s[idx] == '-'){
        sign = s[idx] == '-'? -1:1;
        idx++;
    }
    if(s[idx]=='x'){
        return sign;
    }
    int ret = 0;
    while(isdigit(s[idx]) && idx < strlen(s)){
        ret = ret * 10 + s[idx++] - '0';
    }
    return ret * sign;
}

int getZHISHU (char s[])
{
    if(!findX(s))return 0;
    if(s[strlen(s)-1]=='x')return 1;
    return s[strlen(s)-1] - '0';
}

void getCoef (char poly[], int* coe)
{
    int temp = 0;
    char s[3][10];
    for(int i=0;i<3;++i){
        for(int j=0;j<10;++j)s[i][j]=0;
    }
    int si = 0, sj = 0;
    for(int i=0;i<strlen(poly);++i){
        if(poly[i] == '-' || poly[i] == '+'){
            sj = 0;
            s[++si][sj++] = poly[i];
        }else{
            s[si][sj++] = poly[i];
        }
    }
    for(int i = 0; i <= si;++i){
        //printf("%s\n",s[i]);
        coe[getZHISHU(s[i])] = getXISHU(s[i]);
    }

}

int canDivide (int a[])
{
    int delta = a[1]*a[1] -4*a[0]*a[2];
    if(delta<0 || !CanbeRoot(delta))return -1;
    return delta;
}

void simplify(int* a)
{
    int m=abs(a[0]),n=abs(a[1]);int g;
    if(m==0&&n==0)return;
    else if(m==0&&n!=0)a[1]=1;
    else if(n==0&&m!=0)a[0]=1;
    else{
    if(n>m)g=GCD(n,m);
    else g=GCD(m,n);

    a[0]/=g;a[1]/=g;}
}

int main()
{
    char s[N]={0};
    int coef[3] = {0,0,0};
    scanf("%s",s);
    getCoef(s,coef);
    if(canDivide(coef)==-1){
        printf("No Answer!");
        return 0;
    }
    //for(int i=0;i<3;++i)printf("%d ",coef[i]);
    int d = canDivide(coef);
    int ret1[2],ret2[2];
    ret1[0]=2*coef[2];ret1[1]=coef[1]-sqrt(d);
    ret2[0]=2*coef[2];ret2[1]=coef[1]+sqrt(d);
    simplify(ret1);simplify(ret2);

    if(ret1[0]<ret2[0])printf("%d %d %d %d",ret1[0],ret1[1],ret2[0],ret2[1]);
    else if(ret1[0]>ret2[0])printf("%d %d %d %d",ret2[0],ret2[1],ret1[0],ret1[1]);
    else{
        if(ret1[1]<=ret2[1])printf("%d %d %d %d",ret1[0],ret1[1],ret2[0],ret2[1]);
        else printf("%d %d %d %d",ret2[0],ret2[1],ret1[0],ret1[1]);
    }
    return 0;
}