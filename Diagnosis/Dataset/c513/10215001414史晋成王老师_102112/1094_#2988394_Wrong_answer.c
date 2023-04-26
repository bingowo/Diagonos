#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int cmp(const void*a,const void*b)
{ char *x,*y;
  x= (char*) a;
  y= (char*) b;
  if(x[0]!='-'&&y[0]!='-')
  {
  if(strlen(x)>strlen(y)) return 1;
  else if(strlen(x)<strlen(y)) return -1;
  else
  return strcmp(x,y);
  }
  else if(x[0]=='-'&&y[0]!='-')
  return -1;
  else if (x[0]!='-'&&y[0]=='-')
  return 1;
  else  if (x[0]=='-'&&y[0]=='-')
  { if(strlen(x)>strlen(y)) return -1;
  else if(strlen(x)<strlen(y)) return 1;
  else
  return strcmp(y,x);
      
  }
}

int main()
{ char s[60][200];
int i,j,n,m,a[200]={0},b[200]={0},t,k;
scanf("%d\n",&n);
for(i=0;i<n;i++)
{ scanf("%s",s[i]);
}
   qsort(s[0],n,sizeof(s[0]),cmp);    
   for(j=0;j<strlen(s[0]);j++)
   a[j]=s[0][strlen(s[0])-j-1]-'0';
   for(j=0;j<strlen(s[n-1]);j++)
   b[j]=s[n-1][strlen(s[n-1])-j-1]-'0';
   m=0;
   for(j=0;j<120;j++)
   { b[j] = b[j] - a[j];     
        if (b[j] < 0)          
        {
            b[j+1]-=1;         
            b[j]+=10;          
        }
   }
   for(k=130;k>=0;k--)
   if(b[k]!=0) break;
   for(j=k;j>=0;j--)
   printf("%d",b[j]);
}