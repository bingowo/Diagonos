#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void print(char*s,int len,int l,int r)
{ char k[1000];
    if(l==r)  return;
 for(;l!=r;l++)
 { k[len]=s[l];
   k[len+1]=0;
   printf("%s\n",k);
   print(s,len+1,l+1,r);
     
 }
    
}
cmp(const void*a,const void*b)
{ char *x,*y;
x=(char*)a; y=(char*)b;
return strcmp(x,y);
}
int main()
{int t,i,j,n,r,flag,f,m,x,y,l,z,p,o; char s[100][100]={0},k[100]={0},c[100]={0};
scanf("%d",&t);
for(i=0;i<t;i++)
{ scanf("%s",k);
printf("case #%d:\n",i);
n=strlen(k);f=0;
for(j=0;j<n;j++)
{ flag=1;
  for(r=j+1;r<n;r++)
  if(k[r]==k[j])  {flag=0;break;}
  if(flag==1) {c[f]=k[j];f++;}
}
c[f]=0;
qsort(c,f,sizeof(c[0]),cmp);
print(c,0,0,f);

memset(s,0,sizeof(s));
memset(k,0,sizeof(k));
memset(c,0,sizeof(c));
}
    
}