#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void multiply(char*a,char*b,char*c)
{int i,j,k,l,d,temp;
k=strlen(a);
l=2;
d=0;
for(i=0;i<k;i++)
{d=0;
for(j=0;j<l;j++)
{if(c[i+j]>='0') c[i+j]-='0';
temp=c[i+j]+(a[i]-'0')*(b[j]-'0')+d;
c[i+j]=temp%10+'0';
d=d/10;
}}
if(d) c[i+j-1]=d+'0';
int y=strlen(c);
for(y--;y>0&&c[y]=='0';y--) c[y]=0;
}
int compare(char*a,char*b,int x,int j)
{int i=0;
for(;i<x;i++){if(a[i]!='0') return 1;}
for(;i<x+j;i++){if(a[i]<b[i]) return 0;}
return 1;
}
void minus(char*a,char*b,int x,int j)
{int i=j-1,t;
for(;i>=0;i--)
{if(a[x+i]>=b[i]){a[x+i]=a[x+i]-b[i]+'0';}
else{for(t=1;a[x+i-t]=='0';t++)a[x+i-t]='9';
a[x+i-t]--;
a[x+i]=a[x+i]-b[i]+'0'+10;}
}
}
void divide(char*a,char*b,char*c)
{int i=strlen(a);
int j=strlen(b);
int x,y,k;
for(x=0;x+j<=i;x++)
{while(compare(a,b,x,j))
{minus(a,b,x,j);
c[x]++;}
c[x]+='0';
}
}
void reverse(char*a)
{int k=strlen(a);
int i;
char c;
for(i=0;i<k/2;i++)
{c=a[k-1-i];
a[k-1-i]=a[i];
a[i]=c;
}
}

int main()
{int n,i,t,m,j,k,v;
char a[40][2];
char b1[100]={0},b2[100]={0},c1[100]={0},c2[100]={0},d[100]={0};
for(i=0;i<40;i++)
{a[i][0]=(i+1)%10+'0';
a[i][1]=(i+1)/10+'0';}
scanf("%d",&t);
for(i=0;i<t;i++)
{printf("case #%d:\n",i);
scanf("%d%d",&m,&n);
b1[0]='1';
b2[0]='1';
for(j=0;j<n;j++)
{memset(c1,0,sizeof(char)*100);
multiply(b1,a[m-j-1],c1);
strcpy(b1,c1);
}
for(j=0;j<n;j++)
{memset(c2,0,sizeof(char)*100);
multiply(b2,a[j],c2);
strcpy(b2,c2);}
reverse(c1);
reverse(c2);
divide(c1,c2,d);
for(v=0;d[v]=='0';v++);
for(;v<strlen(d);v++){printf("%c",d[v]);}
printf("\n");}
}
