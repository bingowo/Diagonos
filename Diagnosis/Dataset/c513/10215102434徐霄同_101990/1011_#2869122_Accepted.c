#include <stdio.h>
#include <string.h>
long long a,b;
void fs(int x)
{
    long long aa;
    if(x==0){
        a=1;
        b=0;
    }
    else{
        fs(x-1);
        aa=a;
        a=-a-b;
        b=aa-b;
    }
}
int main()
{
    long long a0,b0;
    char s[100];
    int n[400];
    int i,j,l,x;
    scanf("%s",s);
    l=strlen(s);
    for(i=2;i<l;i++){
        if(s[i]>='0' && s[i]<='9')
            x=s[i]-'0';
        else
            x=s[i]-'A'+10;
        j=4*i-5;
        while(x>0){
            n[j]=x%2;
            x=x/2;
            j--;
        }
    }
    a0=0;
    b0=0;
    j=4*l-9;
    for(i=j;i>=0;i--)
        if(n[i]==1){
            fs(j-i);
            a0=a0+a;
            b0=b0+b;
        }
    if(b0==0)
        printf("%lld\n",a0);
    else if(a0==0){
        if(b0==1)
            printf("i\n");
        else if(b0==-1)
            printf("-i\n");
        else
            printf("%lldi\n",b0);
    }
    else  if(b0==1)
        printf("%lld+i\n",a0);
    else if(b0==-1)
        printf("%lld-i\n",a0);
    else if(b0>1)
        printf("%lld+%lldi\n",a0,b0);
    else
        printf("%lld%lldi\n",a0,b0);
    return 0;
}