#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{ int t,n,i,j,z,b,c,count1,count2,flag,flag2,x,a; char s[100],s1[100],s2[100];
scanf("%d\n",&n);
for(i=0;i<n;i++)
{ gets(s1); a=strlen(s1);
  gets(s2); b=strlen(s2);
  gets(s); c=strlen(s);
  j=0;flag=0;flag2=0;
  while(s[j])
  { for(t=j;t<j+a;t++)
    {if(s[t]==s1[t-j]) flag++;}
    if (flag==a) {count1=j+a-1;break;}
    flag=0; j++;
  }
  x=b-1;
  while(s[c-1])
  { for(t=c-1;t>=c-b;t--)
  {if(s[t]==s2[x+t+1-c]) flag2++;}
  if (flag2==b) {count2=c-b-1;break;}
      flag2=0;c--;
  }
  printf("case #%d:\n",i);
  if(count2==count1) printf("%d\n",0);
  else
  printf("%d\n",abs(count2-count1));
}
    
}