#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{char s[1100000]; int i,j,k,l,left,right,re,max,l1,r1;
scanf("%s",s); l=strlen(s);
if (l==1) printf("%c",s[0]);
else{
   for (i=0;i<l;i++)
    {  re=0;
        if (left<=right)
       { 
        for(j=left;j<right;j++)
        { if (s[j]==s[right])
          { re=1;
            break;
          }
         
        }
        if (re==1) 
        left=j+1;
      
       }
      if(max<(right-left+1))
      {max=(right-left+1);l1=left;r1=right;}
      right++;
      
    }
    for(k=l1;k<=r1;k++)
    printf("%c",s[k]);
}
}