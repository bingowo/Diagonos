#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct file
{ char time[20];
  int size;
  char  name[100];
    
};
int cmpname(const void*a,const void*b)
{char* d1,*d2;  char x[100],y[100]; int i;
 d1=(char*)a;
 d2=(char*)b;
  for(i=33;d1[i];i++) 
  {x[i-33]=d1[i];}
  for(i=33;d2[i];i++) 
  {y[i-33]=d2[i];}
  return strcmp(x,y);
}
int cmpsize(const void*a,const void*b)
{char* d1,*d2;  int x=0,y=0; int i;
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
   return x-y;
}
int cmptime(const void*a,const void*b)
{ char* d1,*d2;  char x[30],y[30]; int i;
 d1=(char*)a;
 d2=(char*)b;
 for(i=0;i<16;i++)
 { x[i]=d1[i]; y[i]=d2[i];
 }
 for(i=0;i<16;i++)
 {if(x[i]!=y[i]) return x[i]-y[i];
 }
}

int main()
{ int n,i; char s[102][100000],order[20]; struct file a[10000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {gets(s[i]);
    }
    scanf("%s\n",order);
    if (order[6]=='N')
    qsort(s,n,sizeof(s[0]),cmpname);
    else if(order[6]=='S')
    qsort(s,n,sizeof(s[0]),cmpsize);
    else if(order[6]=='T')
    qsort(s,n,sizeof(s[0]),cmptime);
    for(i=0;i<n;i++)
    printf("%s\n",s[i]);
     memset(s,0,sizeof(s[0]));
    while(scanf("%d",&n))
    { if (n==0) break;
      for(i=0;i<n;i++)
    {gets(s[i]);
    }
    scanf("%s",order);
    if (order[6]=='N')
    qsort(s,n,sizeof(s[0]),cmpname);
    else if(order[6]=='S')
    qsort(s,n,sizeof(s[0]),cmpsize);
    else if(order[6]=='T')
    qsort(s,n,sizeof(s[0]),cmptime);
    printf("\n");
    for(i=0;i<n;i++)
    printf("%s\n",s[i]);
        memset(s,0,sizeof(s[0]));
    }
        
        
}