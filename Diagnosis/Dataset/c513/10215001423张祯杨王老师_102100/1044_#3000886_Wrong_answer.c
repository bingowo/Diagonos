#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{ char s[10000];
  scanf("%s",s);
  int len,count=0,i;
  len=strlen(s);
  int a[10000]={0};
  for(i=0;i<len;)
  {  if(s[i]!=48) i++;
     else if(s[i]==48)
     {  if(s[i+1]!=120) i++;
        else if(s[i+1]==120)
        {  int q=0;
           while(1)
            {  if(s[i+q+2]>47&&s[i+q+2]<58) q++;
               if(s[i+q+2]>96&&s[i+q+2]<103) q++;
               else break;
            }
            if(q!=0)
            {  for(int c=1;c<=q;c++)
               {  if(s[i+c+1]<58) a[count]+=pow(16,q-c)*(s[i+c+1]-48);
                  if(s[i+c+1]>96) a[count]+=pow(16,q-c)*(s[i+c+1]-87);
                }
                count++;
            }
            if(q==0)
            {  a[0]=-1;
               count=1;
            }
            i=i+q+2;
        }

     }

  }
  for(int i=0;i<count;i++) printf("%d ",a[i]);
  return 0;
}
