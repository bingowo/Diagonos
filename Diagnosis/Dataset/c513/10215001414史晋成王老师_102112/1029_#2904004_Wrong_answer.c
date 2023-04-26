#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a, const void* b)
{char *s1,*s2;
    s1=(char*)a;
    s2=(char*)b;
    return strcmp(s1,s2);
}
int main()
{ int T,i,j,n,k=0,m=0,g; char s[1000]={0},d[1000][2]={0};
scanf("%d",&T);
for(i=0;i<T;i++)
{gets(s);
 j=0;
 while(s[j])
 {if(s[j]>='A'&&s[j]<='Z') {d[k][0]=s[j];k++;}
     j++;
 }
 qsort(s,k,sizeof(s[0]),cmp);
 m=0;g=0;
 while(s[m])
 {if (s[m]>='A'&&s[m]<='Z') {s[m]=d[g][0];g++;}
 m++;
}
  printf("case #%d:\n",i);
  printf("%s\n",s);
}
}