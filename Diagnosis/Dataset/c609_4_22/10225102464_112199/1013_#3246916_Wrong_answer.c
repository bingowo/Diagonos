#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[100];
int a[1111],b[1111];
void change(char s[]){
    for(int j=0;j<strlen(s);j++){
        if(s[j]<='9'&&s[j]>='0') b[j]=s[j]-48;
        else if(s[j]<='Z'&&s[j]>='A') b[j]=s[j]-'A'+10;
        for(int i=4*j+3;i>=4*j;i--){
            a[i]=b[j]%2;
            b[j]/=2;
        }
    }
}
int main()
{
    getchar();
    getchar();
    long long an_1=0;
    long long an_2=0;
    long long no_2=0;
    long long p_2=1;
    long long no_1=1;
    long long p_1=-1;
    memset(a,0,sizeof(a));
    gets(s);
    change(s);
    //for(int kk=0;kk<strlen(s)*4;kk++) printf("%d",a[kk]);
    for(int kk=strlen(s)*4-1;kk>=0;kk--) {
        if(a[kk]&1){
            an_1+=no_1;
            an_2+=no_2;
        }
        long long temp_1=no_1*p_1-no_2*p_2;
        long long temp_2=no_1*p_2+no_2*p_1;
        no_1=temp_1;
        no_2=temp_2;
    }
    if(an_1){
        if(an_2>1) printf("%lld+%lldi\n",an_1,an_2);
        if(an_2==1) printf("%lld+i\n",an_1);
        if(an_2==0) printf("%lld\n",an_1);
        if(an_2==-1) printf("%lld-i\n",an_1);
        if(an_2<-1) printf("%lld%lldi\n",an_1,an_2);
    }
    return 0;
}

