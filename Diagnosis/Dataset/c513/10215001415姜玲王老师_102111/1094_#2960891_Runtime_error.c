#include <stdio.h>
#include <stdlib.h>
#include<math.h>
typedef struct {char a[200];int sign;} distance;
int compare(char*c,char*b)
{int x,y;
x=strlen(c);
y=strlen(b);
if(x>y) return -1;
if(x<y)  return 1;
for(x--;x>=0&&c[x]==b[x];x--);
if(x<0) return -1;
if(c[x]>b[x]) return -1;
if(c[x]<b[x]) return 1;

}
int cmp(const void*a,const void*b)
{distance p1=*(distance*)a;
distance p2=*(distance*)b;
if(p1.sign>p2.sign) return -1;
if(p1.sign<p2.sign) return 1;
if(p1.sign>0&&p2.sign>0) return compare(p1.a,p2.a);
return compare(p2.a,p1.a);
}
void reverse(char*b)
{int k=strlen(b),i;
char c;
for(i=0;i<k/2;i++)
{c=b[i];
b[i]=b[k-1-i];
b[k-1-i]=c;}}
void minus(char*x,char*y,char*z)
{int i,k=strlen(y),j;
    for(i=0;i<y;i++)
{if(x[i]>=y[i]) x[i]=x[i]-y[i]+'0';
else{for(j=1;x[i+j]=='0';j++)x[i+j]='9';
x[i+j]--;
x[i]=x[i]-y[i]+'0'+10;}}
strcpy(z,x);
}
void plus(char*x,char*y,char*z)
{int i,temp,d=0;
for(i=0;i<strlen(x)||i<strlen(y);i++)
{if(x[i]==0) x[i]='0';
if(y[i]==0)  y[i]='0';
temp=x[i]-'0'+y[i]-'0'+d;
z[i]=temp%10+'0';
d=temp/10;
}
if(d) z[i]=d+'0';
}
int main()
{int n,i,j,k;
char answer[200]={0};
distance p[50];
scanf("%d",&n);
for(i=0;i<n;i++)
{scanf("%s",p[i].a);
if(p[i].a[0]=='-'){p[i].sign=-1;reverse(p[i].a);j=strlen(p[i].a);p[i].a[j-1]=0;}
else{p[i].sign=1;reverse(p[i].a);}}
qsort(p,i,sizeof(p[0]),cmp);
if(p[0].sign==1&&p[i-1].sign==1){minus(p[0].a,p[i-1].a,answer);}
if(p[0].sign==1&&p[i-1].sign==1){minus(p[0].a,p[i-1].a,answer);}
if(p[0].sign==1&&p[i-1].sign==-1){plus(p[0].a,p[i-1].a,answer);}
k=strlen(answer);
for(k--;answer[k]=='0'&&k>0;k--);
for(;k>=0;k--)
printf("%c",answer[k]);
}
