#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct file
{ char time[20];
  int size;
  char  name[100];
    
};
int cmpname(const void*a,const void*b)
{char* d1,*d2;  char x[100],y[100]; int i,j,k;
 d1=(char*)a;
 d2=(char*)b;
  for(i=33;d1[i];i++) 
  {x[i-33]=d1[i];}
  for(j=33;d2[i];j++) 
  {y[j-33]=d2[j];}
  for(k=0;d1[k]&&d2[k];k++)
  { if(d1[k]!=d2[k]) return d1[k]-d2[k];
  }
  if(j>i) return 1;
  else return -1;
}
int cmpsize(const void*a,const void*b)
{char* d1,*d2;  int x=0,y=0; int i; char m[100],n[100];
 d1=(char*)a;
 d2=(char*)b;
 for(i=16;i<32;i++)
 {if(d1[i]!=' ')
 { x*=10;
   x+=d1[i]-'0';}
    }
  for(i=16;i<32;i++)
 {if(d2[i]!=' ')
 { y*=10;
   y+=d2[i]-'0';}
    }
    for(i=33;d1[i];i++) 
  {m[i-33]=d1[i];}
  for(i=33;d2[i];i++) 
  {n[i-33]=d2[i];}
   if(x!=y) return x-y;
   else return strcmp(m,n);
}
int cmptime(const void*a,const void*b)
{ char* d1,*d2;  char x[30],y[30]; int i; char m[100],n[100];
 d1=(char*)a;
 d2=(char*)b;
 for(i=0;i<16;i++)
 { x[i]=d1[i]; y[i]=d2[i];
 }
 for(i=33;d1[i];i++) 
  {m[i-33]=d1[i];}
  for(i=33;d2[i];i++) 
  {n[i-33]=d2[i];}
 for(i=0;i<16;i++)
 {if(x[i]!=y[i]) return x[i]-y[i];
 }
 return strcmp(m,n);
}

int main()
{ int n,i; char s[102][100000],order[20]; struct file a[10000];
    while(scanf("%d\n",&n))
    { if (n==0) break;
      for(i=0;i<n;i++)
    {gets(s[i]);
    }
    gets(order);
    if (order[6]=='N')
    qsort(s,n,sizeof(s[0]),cmpname);
    else if(order[6]=='S')
    qsort(s,n,sizeof(s[0]),cmpsize);
    else if(order[6]=='T')
    qsort(s,n,sizeof(s[0]),cmptime);
    
    for(i=0;i<n;i++)
    printf("%s\n",s[i]);
    printf("\n");
    }
        
        
}