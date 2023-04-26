#include <stdlib.h>
#include<string.h>
void Atoi(char*a,char*b)
{int s;
for(s=0;s<strlen(a)&&a[s]!='.';s++);
for(int i=s-1,k=0;i>=0;i--,k++)
{b[k]=a[i];}}
void Atof(char*a,char*b)
{int s=0,k;
for(;s<strlen(a)&&a[s]!='.';s++);
for(int i=s+1,k=0;i<strlen(a);i++,k++)
    {b[k]=a[i];}
}
void minus(char*a0,char*b0,char*a1,char*b1,int n)
{int k,m,v,w,j;
if(strlen(a1)<strlen(b1)) {for(int i=strlen(a1);i<strlen(b1);i++)a1[i]='0';}
if(strlen(a1)>strlen(b1)) {for(int i=strlen(b1);i<strlen(a1);i++)b1[i]='0';}
for(k=strlen(a1)-1;k>=0;k--)
{if(a1[k]>=b1[k]) a1[k]=a1[k]-b1[k]+'0';
else{for(j=1;a1[k-j]=='0'&&k>=j;j++){a1[k-j]='9';}
{if(j>k){for(m=0;a0[m]=='0';m++)a0[m]='9';a0[m]--;}
else a1[k-j]--;}
a1[k]=a1[k]-b1[k]+'0'+10;
}}
if(a1[n]>='5'){a1[n-1]++;
for(int i=n-1;i>=1&&a1[i]>'9';i--)
    {a1[i]='0';a1[i-1]++;}
if(a1[0]>'9') {a1[0]='0';a0[0]++;}}
for(v=0;v<strlen(b0);v++)
{if(a0[v]>=b0[v]) {a0[v]=a0[v]-b0[v]+'0';}
else {for(j=1;a0[v+j]=='0';j++) {a0[v+j]='9';}
a0[v+j]--;a0[v]=a0[v]-b0[v]+10+'0';}}
for(w=strlen(a0)-1;a0[w]=='0'&&w>0;w--);
for(;w>=0;w--) printf("%c",a0[w]);
printf(".");
for(int i=0;i<n;i++)
{if(a1[i]!=0) printf("%c",a1[i]);
else printf("0");
}

}
int main()
{char a[501],b[501],a0[501]={0},a1[501]={0},b0[501]={0},b1[501]={0};
int n,i,k;
scanf("%s%s",a,b);
scanf("%d",&n);
b0[0]='0';
a0[0]='0';
Atoi(a,a0);
Atoi(b,b0);
a1[0]='0';
b1[0]='0';
if(strstr(a,"."))Atof(a,a1);
if(strstr(b,"."))Atof(b,b1);
int flag=0;
if(strlen(b0)>strlen(a0)) {flag=1;}
else {for(i=strlen(a0)-1;b0[i]==a0[i]&&i>=0;i--)
    if(a0[i]<b0[i]&&i!=-1) {flag=1;}
    else{if(i==-1){if(strcmp(a1,b1)<0) flag=1;}
        if(a0[i]<b0[i]&&i!=-1) {flag=1;}
    else{if(i==-1){if(strcmp(a1,b1)<0) flag=1;
    }}
if(flag){printf("-");minus(b0,a0,b1,a1,n);}
else minus(a0,b0,a1,b1,n);}

