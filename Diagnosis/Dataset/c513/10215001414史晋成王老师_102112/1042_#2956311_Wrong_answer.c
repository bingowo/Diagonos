#include<stdio.h>
#include<stdlib.h>
#include<string.h>
cmp(const void*a,const void*b)
{ char *x,*y;
x=(char*)a; y=(char*)b;
return strcmp(x,y);
}
int main()
{int t,i,j,n,r,flag,f,m,x,y,l,z,p; char s[100][100]={0},k[100]={0},c[100]={0};
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
c[f]=0;l=0;p=0;
for(x=0;x<f;x++)
{ for(y=0;y<f-x;y++)
   {  for(z=x;z<=x+y;z++)
        {s[l][p]=c[z];p++;}
        s[l][p]=0;l++;p=0;
   }
}
qsort(s,l,sizeof(s[0]),cmp);
for(x=0;x<l;x++)
printf("%s\n",s[x]);
}
    
}