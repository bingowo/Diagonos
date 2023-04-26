#include<stdio.h>
#include<stdlib.h>
int main()
{int b=0,c,d,i,j,k,olp,f; int a[500],m[10],n[10],o[4],p[7]; char t[500];
gets(t); while(t[b){a[b]=t[b]-'0';b++;}
b-=1;
printf("0001");
c=b/3; d=b%3;
for(i=0;i<10;i++)
{m[9-i]=b%2;
 b=b/2;
}
for(i=0;i<10;i++)
{
    printf("%d",m[i]);
}

for(f=0;f<c;f++)
{  j=a[3*f]*100+a[3*f+1]*10+a[3*f+2];
  k=9;
  while(j)
  { n[k]=j%2;
    j=j/2;
    k--;
  }
  for(k=0;k<10;k++)
  printf("%d",a[k]);
}
if (d==1)
{ olp=a[3*c];
  for(i=0;i<4;i++)
{   o[3-i]=olp%2;
  olp/=2;
}
for(i=0;i<4;i++)
{   printf("%d",o[i]);
}
}
    
if(d==2)
{ olp=a[3*c]*10+a[3*c+1];
    for(i=0;i<7;i++)
{ p[6-i]=olp%2;
 olp=olp/2;
}
for(i=0;i<7;i++)
{ printf("%d",p[i]);
    
}
}
return 0;
}