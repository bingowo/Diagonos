#include<stdio.h>
#include<string.h>

int gcd(int a,int b)
{ int temp;
temp=a+b;
a=a>b?a:b;
b=temp-a;
while(b!=0)
{ temp=a%b;
a=b;b=temp;
}
return a;
}

int main()
{ char str[150]={'\0'};
int i,j,T,t,len,fuck,sum,num,temp,shit,sob;
char caonima;
scanf("%d",&T);
caonima=getchar();
for(t=0;t<T;t++)
{ i=0;j=0;shit=0;num=0;
gets(str);
len=strlen(str);
sum=8*len*sizeof(char);
for(i=0;i<len;i++)
{ fuck=(unsigned char)str[i];
while(fuck!=0)
{ if(fuck%2) shit++;
fuck=fuck/2;
}
}
sob=gcd(shit,sum);
shit=shit/sob;sum=sum/sob;
printf("%d/%d\n",shit,sum);
}
return 0;
}