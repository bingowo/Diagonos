#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int cmp(char*s2,char**s,int n)
{ int i,j,m,flag=1;;
for(i=0;i<n;i++)
  {  flag=1;
      if(strlen(s2)!=strlen(s)) continue;
    for(j=0;j<strlen(s2);j++)
      {if(s2[j]!=(s+i)[j]) flag=0;}
     if(flag==1) return 1;
  }
    return 0;
}
int main()
{ int i,j,n,m,k,maxl=0,l;
char s[5000][20]={0},s1[10000]={0},s2[10000]={0};
scanf("%d\n",&n);
for(i=0;i<n;i++)
{ scanf("%s\n",s[i]);
    if (strlen(s[i])>maxl) maxl=strlen(s[i]);
}
scanf("%s\n",s1);
 while(strlen(s1)!=0)
 {
     if(strlen(s1)==1)
     {printf("%s ",s1);
       s1[0]=0;
     }
     else
     { int flag=0;
     l=maxl;
     while(l>=1)
     {
      for(i=0;i<l;i++) 
         s2[i]=s1[i];
         s2[i]=0;
        if(cmp(s2,s,n))
        { flag=1;
         printf("%s ",s2);
         for(k=0;k<strlen(s1)-l;k++)
         s1[k]=s1[k+l];
         s1[k]=0;
         s2[0]=0; 
         break;
        }
        else
        l--;
     }
     if(flag==0)
     {
         printf("%s",s2);
         for(k=0;k<strlen(s1)-1;k++)
         s1[k]=s1[k+1];
         s1[k]=0;
     }
     }
     
     
     
 }
 
}