#include <stdio.h>
#include <stdlib.h>
#include<math.h>
char c1[10000],c2[10000];
int q1,q2;
void reverse(char*a)
{char b;
for(int i=0;i<strlen(a)/2;i++)
{b=a[i];
a[i]=a[strlen(a)-i-1];
a[strlen(a)-i-1]=b;}
}
void multiply(char*a,char*b,char*c)
{int d=0,i,j,temp;
for(i=0;i<strlen(a);i++)
{d=0;
    for(j=0;j<strlen(b);j++)
{
if(c[i+j]>='0') c[i+j]-='0';
temp=(a[i]-'0')*(b[j]-'0')+c[i+j]+d;
c[i+j]=temp%10+'0';
d=temp/10;
}
c[i+j]+=d;}
if(c[i+j-1]) c[i+j-1]+='0';
for(i=strlen(c)-1;i>0&&c[i]=='0';i--) c[i]=0;}
int compare(char*a,char*b)
{int i;
if(strlen(a)>strlen(b)) return 1;
if(strlen(a)<strlen(b)) return 0;
for(i=strlen(a)-1;a[i]==b[i]&&i>=0;i--);
if(i==-1) return 1;
if(a[i]>b[i]) return 1;
return 0;
}
void plus(char*a,char*b,char*c)
{char k[10000]={0};
int i,temp;
for(i=0;i<strlen(a)||i<strlen(b);i++)
{if(a[i]==0) a[i]='0';
if(b[i]==0) b[i]='0';
temp=k[i]+a[i]+b[i]-'0'-'0';
k[i]=temp%10+'0';
k[i+1]+=temp/10;
}
if(k[i]) {k[i]+='0';}
for(i=strlen(k)-1;k[i]=='0'&&i>0;i--) k[i]=0;
strcpy(c,k);
}
void minus(char*a,char*b,char*c)
{
int i,x;
for(i=0;i<strlen(b);i++)
{if(a[i]>=b[i]){a[i]=a[i]-b[i]+'0';}
else{for(x=1;a[i+x]=='0';x++)a[i+x]='9';
   a[i+x]--;
   a[i]=a[i]-b[i]+'0'+10;}}
   for(i=strlen(a)-1;a[i]=='0'&&i>0;i--) a[i]=0;
   strcpy(c,a);
}
void imultiply(char*b1,char*b2,int p1,int p2)
{int k1,k2;
char d1[10000]={0},d2[10000]={0},d3[10000]={0},d4[10000]={0};
multiply(b1,c1,d1);
multiply(b2,c2,d2);
multiply(b1,c2,d3);
multiply(b2,c1,d4);
if((p1*q1)>0&&(q2*p2)<0) {plus(d1,d2,c1);k1=1;}
if((p1*q1)<0&&(q2*p2)>0) {plus(d1,d2,c1);k1=-1;}
if((p1*q1)>0&&(p2*q2)>0){if(compare(d1,d2)) {k1=1;minus(d1,d2,c1);}
                     else {k1=-1;minus(d2,d1,c1);}}
if((p1*q1)<0&&(p2*q2)<0){if(compare(d2,d1)) {k1=1;minus(d2,d1,c1);}
                     else {k1=-1;minus(d1,d2,c1);}}
if((p1*q2)>0&&(q1*p2)>0) {plus(d3,d4,c2);k2=1;}
if((p1*q2)<0&&(q1*p2)<0) {plus(d3,d4,c2);k2=-1;}
if((p1*q2)>0&&(q1*p2)<0){if(compare(d3,d4)) {k2=1;minus(d3,d4,c2);}
                     else {k2=-1;minus(d4,d3,c2);}}
if((p1*q2)<0&&(q1*p2)>0){if(compare(d4,d3)) {q2=1;minus(d4,d3,c2);}
                     else {k2=-1;minus(d3,d4,c2);}}
                     q1=k1;q2=k2;

}
int main()
{char a[20],b1[10000]={0},b2[10000]={0},b3[10000];
b1[0]='0';
b2[0]='0';
int n,p1,p2,i=0,x,k;
scanf("%s%d",a,&n);
if(n==0) {printf("1");return 0;}
if(!strcmp(a,"0")){printf("0");return 0;}
if(!strstr(a,"i")){if(a[0]=='-') {p1=-1,i++;}
else p1=1;
for(x=0;i<strlen(a);i++,x++)
{b1[x]=a[i];}
reverse(b1);
p2=1;}
else{if(a[0]=='-') {p1=-1,i++;}
else p1=1;
if(a[i]=='i'){p2=p1;p1=1;b2[0]='1';}
else{for(x=0;a[i]>='0'&&a[i]<='9';i++,x++)
{b1[x]=a[i];}
reverse(b1);
if(a[i]=='i'){strcpy(b3,b1);strcpy(b1,b2);strcpy(b2,b3);p2=p1;p1=1;}
else{if(a[i]=='-'){p2=-1;}
else p2=1;
i++;
if(a[i]=='i'){b2[0]='1';}
for(x=0;i<strlen(a)-1;i++,x++)
{b2[x]=a[i];}
reverse(b2);}}}
strcpy(c1,b1);
strcpy(c2,b2);
q1=p1;
q2=p2;
for(k=2;k<=n;k++)
{imultiply(b1,b2,p1,p2);}

if(q1==-1) printf("-");
for(i=0;i<strlen(c1)&&strcmp(c1,"0");i++)
{printf("%c",c1[strlen(c1)-i-1]);}
if(!strcmp(c2,"0")) return 0;
if(q2==-1) printf("-");
if(q2==1) printf("+");
if(!strcmp(c2,"1")) {printf("i");return 0;}
for(i=0;i<strlen(c2);i++)
{printf("%c",c2[strlen(c2)-i-1]);}
printf("i");
return 0;
}





