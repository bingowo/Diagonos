#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{ int i,j,n,m,s,k,maxl=0;
char s[5000][20],s1[10000];
scanf("%d\n",&n);
for(i=0;i<n;i++)
{ scanf("%s\n",s[i]);
    if (strlen(s[i])>maxl) maxl=strlen(s[i]);
}
scanf("%s\n",s1);
 m=strlen(s1);
 while(strlen(s1)!=0)
 {
     if(strlen(s1)==1)
     {printf("%s ",s1);
       s1="";
     }
     else
     {
         
     }
     
     
     
     
 }
 
}