#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int cmp(const void*a,const void*b)
{ char *x,*y;
  x= (char*) a;
  y= (char*) b;
  return strcmp(x,y);
    
}

int main()
{ char s[60][200];
int i,j,n,m,s;
scanf("%d\n",&n);
for(i=0;i<n;i++)
{ scanf("%s",s[i]);
}
   qsort(s[0],n,sizeof(s[0]),cmp);    
 for(i=0;i<n;i++)
{ printf("%s\n",s[i]);
}
}