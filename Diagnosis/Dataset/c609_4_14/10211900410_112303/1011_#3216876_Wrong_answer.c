#include <stdio.h>
#include <math.h>
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    char s[1000];
    char s1[1000],s2[1000];
    scanf("%s",&s);
    int i=0,j=0,l=strlen(s);
    while(s[i]!='.' && i<l){
        s1[i++]=s[i];//取整数部分
    }
    i++;//跳过小数点
    while(i<l){
        s2[j++]=s[i];
        i++;
    }
    int l1,l2;
    l1=l-j;l2=j;
    int A=0,B=0,C;
    int x,y;
    for(int k=0;k<l-j;k++){
        if(s1[k]=='2') x=-1;
        else x=s1[k]-'0';
        A+=x*pow(3,--l1);
    }//求整数部分
    if(l2==0){
        printf("%d",A);
    }
    else{
        for(int k=0;k<l2;k++){
            if(s2[k]=='2') y=-1;
            else y=s2[k]-'0';
            B=B*3+y;
        }
        C=pow(3,l2+1);
        int b=B/gcd(B,C);
        int c=C/gcd(B,C);
        if(A==0) printf("%d %d",b,c);
        else printf("%d %d %d",A,b,c);
    }
    return 0;
}
