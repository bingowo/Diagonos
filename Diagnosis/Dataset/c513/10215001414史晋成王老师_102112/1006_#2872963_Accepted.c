#include<stdio.h>
#include<stdlib.h>
int main()
{ int T,i,k,ans; char s[100];
  scanf("%d",&T);
  for (i=0;i<T;i++)
    { scanf("%s",s);
      k=0; ans=0;
      while(s[k])
      { if(s[k]=='1') 
        ans=ans*3+1;
        if(s[k]=='0')
        ans=ans*3+0;
        if (s[k]=='-')
        ans=ans*3-1;
        k++;
      }
      printf("case #%d:\n",i);
      printf("%d\n",ans);
    }
return 0;
}