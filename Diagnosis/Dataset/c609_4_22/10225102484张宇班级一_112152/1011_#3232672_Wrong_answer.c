#include <stdio.h>
#include <string.h>
int main(){
char a[30];
int s=46;
scanf("%s",a);
long long int m=0;
long long int x=0;
long long int q=1;
if(strstr (a,".")==NULL){
    for(int i=0;a[i]!=0;i++)
     {if(a[i]!='2')
    m=m*3+a[i]-'0';
    else
        m=m*3-1;}
        printf("%d",m);
}
else {char*p=strchr(a,s);
int k=p-a+1;
int y=k;
for(int i=0;i<k-1;i++)
    {if(a[i]!='2')
    m=m*3+a[i]-'0';
    else
        m=m*3-1;}
for(k=k+1;a[k]!=0;k++)
    {if(a[k]!='2')
    x=x*3+a[k]-'0';
    else
        x=x*3-1;}
int l=k-1-y;
for(int i=0;i<l;i++)
    q=q*3;
if(x<0)
{
    m=m-1;
    x=x+q;
}
printf("%ld %ld %ld",m,x,q);
}


}