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
  {  if(s[i]!='0') i++;
     else if(s[i]=='0')
     {  if(s[i+1]!='x') i++;
        else if(s[i+1]=='x')
        {  int q=0;
           while(1)
            {  if(s[i+q+2]>='0'&&s[i+q+2]<='9') q++;
               else if(s[i+q+2]>='a'&&s[i+q+2]<='f') q++;
               else break;
            }
            if(q!=0)
            {  for(int c=1;c<=q;c++)
               {  if(s[i+c+1]<='9') a[count]+=pow(16,q-c)*(s[i+c+1]-48);
                  if(s[i+c+1]>='a') a[count]+=pow(16,q-c)*(s[i+c+1]-87);
                }
                count++;
            }
            i=i+q+2;
        }

     }

  }
  if(count!=0)
  { for(int i=0;i<count;i++) 
    printf("%d ",a[i]);
  }
  if(count==0) printf("-1");
  return 0;
}