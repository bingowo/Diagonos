#include <stdio.h>
#include <string.h>
char table[]="0123456789ABCDEF";
int transfer(long long a,long long b);
int main(){
    long long a,b;
    long long sum=0;
    char c[32];
    scanf("%lld",&a);
    scanf("%s",&c);
    scanf("%lld",&b);
    for (int i=0;i<strlen(c)-1;i++){
       if(c[i]>='0'&&c[i]<='9'){ sum=a*(sum+c[i]-'0');}
       else if(c[i]>='a'&&c[i]<='z'){sum=a*(sum+c[i]-'a'+10);}
       else if(c[i]>='A'&&c[i]<='Z'){sum=a*(sum+c[i]-'A'+10);}
    }
    int i=strlen(c)-1;
    if(c[i]>='0'&&c[i]<='9'){ sum=sum+c[i]-'0';}
       else if(c[i]>='a'&&c[i]<='z'){sum=sum+c[i]-'a'+10;}
       else if(c[i]>='A'&&c[i]<='Z'){sum=sum+c[i]-'A'+10;}
   
    transfer(sum,b);
    return 0;
}
int transfer(long long a,long long b){
if (a/b){
    transfer(a/b,b);
}
printf("%c",table[a%b]);
return 0;
}
