#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000
int main()
{ char s[N];
  scanf("%s",s);
  int len=strlen(s);
  int m=0,a[N]={0};
  for(int i=0;i<len;)
  {  if(s[i]!='0') i++;
     else if(s[i]=='0')
     {  if(s[i+1]!='x') i++;
        else if(s[i+1]=='x')
        {  int count=0,q=0;
           while(1)
            {  if(s[i+q+2]>='0'&&s[i+q+2]<='9'&&s[i+q+2]>='a'&&s[i+q+2]<='f') q++;
               else break;
            }
            if(q!=0)
            {  for(int s=1;s=<q;s++)
               {  if(s[i+s+1]<='9') a[count]+=cow(16,q-s)*(int(s[i+s+1])-48);
                  else if(s[i+s+1]>='a') a[count]+=cow(16,q-s)*(int(s[i+s+1])-87);
                }
                count++;
            }
             i=i+q+2;
        }

     }

  }
  for(int i=0;i<=count;i++) printf("%d",a[i]);

}
