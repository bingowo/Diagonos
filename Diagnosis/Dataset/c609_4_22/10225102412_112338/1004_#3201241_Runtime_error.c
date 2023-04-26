#include<stdio.h>
int main()
{
    int a,b,A,B;char s[100];
    scanf("%d %s %d",&a,s,&b);
    A = AtoDec(a,s[100]);
    DectoB(A,b);
}

int AtoDec(int a,char s[100])
{
    int n=0;
    int len=strlen(s);
    int i;
    for (i=0;i<len-1;i++){
       if (s[i]>='a'){
           n += (s[i]-'a')*pow(a,len-i-2);
       }
       if (s[i]<='Z' && s[i]>='A'){
           n += (s[i]-'A')*pow(a,len-i-2);
       }
       else{
           n += (s[i]-'0')*pow(a,len-i-2);
       }
    }
    return n;
}

DectoB(int A,int b)
{
    char s[100];
    int i=0;
    int j;
    while (A>0){
        if (A%b>=10){
            s[i] = A%b-10+'A';
        }
        else{
            s[i] = A%b+'0';
        }
        i++;
    }
    for (j=i-1;j>=0;j--){
        printf("%c",s[j]);
    }
}