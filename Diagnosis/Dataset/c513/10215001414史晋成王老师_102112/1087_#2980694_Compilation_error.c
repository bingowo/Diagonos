#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int add1(char s[],int k)
{ int i=k;
while(i>=0)
{ s[i]+=1;
 if(s[i]<='9' ) return i;
 s[i]='0';
 i--;
}
return i;
}

int main()
{ int t,i,j,n,len,k;
char s[110]={'0'};
    scanf("%d\n",&t);
    for(i=0;i<t;i++)
    { scanf("%s\n",s+1);
     len=strlen(s);
     add1(s,len-1);
     for(j=1;j<len;j++)
     { if(s[j==s[j-1]) break;
     }
     if(j!=len)
     { j=add1(s,j);
       while(j>0)
       { if(s[j]!=s[j-1]) break;
           j=add1(s,j);
       }
         for(k=j+1;k<len;k++)
         s[k]=(k-j+1)%2+'0';
     }
     printf("case #%d:\n",i);
     if(s[0]!='0') printf("%c",s[0]);
     printf("%s\n",s+1);
      
    }
    
    
}