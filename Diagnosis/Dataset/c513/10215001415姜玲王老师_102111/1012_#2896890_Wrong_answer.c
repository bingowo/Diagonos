#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{char s[1000];
long long n=0,p=0,a,b;
int k=0,digit=1,l=1,j=0,num[1000];
scanf("%s",s);
if(s[strlen(s)-1]=='i')
{if(s[0]=='i'){p=1;}
else{if(s[0]=='-'&&s[1]=='i') p=-1;
else{if(s[0]=='-') {digit=-1;k++;}
while(s[k]!='+'&&s[k]!='-'&&s[k]!='i'){n=n*10+(s[k]-'0');k++;}
         n*=digit;
if(s[k]=='i'){p=n;n=0;}
else{if(s[k]=='-'){l=-1;}
if(s[k+1]=='i') {p=1*l;}

else {k++;while(k<strlen(s)-1){p=p*10+(s[k]-'0');k++;}
         p*=digit;}}
}}}
    else{if((s[0])=='-'){digit=-1;k++;}
         while(k<strlen(s)){n=n*10+(s[k]-'0');k++;}
         n*=digit;}
if(p==0&&n==0) printf("0");
for(;p!=0||n!=0;j++)
{if((n+p)%2) {n--;a=n;b=p;n=(b-a)/2;p=(a+b)/(-2);num[j]=1;}
else{a=n;b=p;n=(b-a)/2;p=(a+b)/(-2);num[j]=0;}
}
for(j--;j>=0;j--){printf("%d",num[j]);}}
