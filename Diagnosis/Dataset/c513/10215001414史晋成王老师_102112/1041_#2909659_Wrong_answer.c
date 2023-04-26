#include<string.h>
#include<stdlib.h>
#include<stdlib.h>

int main()
{char s[100]; int i,j,k,max;
gets(s);
k=0; while(s[k]) k++;
i=0;j=0;max=0;
for(i=0;i<k-1;i++)
{ if(s[i]!=s[i+1]) j++;
  if(j>max) max=j;
  if(s[i]==s[i+1]) j=0;
}
printf("%d",max);
    
}