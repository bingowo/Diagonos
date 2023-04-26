#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
char s[100];
scanf("%s",s);
//printf("%s\n",s);
int t[400]={0};
int cnt=0;
int l=strlen(s);
int p=0;
for(int i=2;i<l;i++)
{
    if(s[i]>='0'&&s[i]<='9')p=s[i]-'0';
    else p=s[i]-'A'+10;
    int flag=8;
    while(flag!=0){
        if((flag&p)!=0)
        t[cnt++]=1;
        else t[cnt++]=0;
        flag>>=1;
    }
}
/*for(int i=0;i<cnt;i++)
{
    printf("%d",a[i]);

}*/
long long int a,b;
long long int qr=0,qi=0;
for(int i=0;i<cnt;i++)
{
    a=-qr-qi+t[i];//r
    b=qr-qi;
    qr=a;qi=b;
}

//printf("%lld %lld",a,b);
if(b==0)printf("%lld",a);
else{
    if(a!=0)
    {
        printf("%lld",a);
        if(b>0)printf("+");
        if(b==1)printf("i");
        else if(b==-1)printf("-i");
        else printf("%lldi",b);


    }
}

}
