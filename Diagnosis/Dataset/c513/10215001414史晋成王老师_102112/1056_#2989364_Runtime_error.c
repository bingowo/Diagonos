#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{ int i,j,n,m,k,maxl=0,l,f,p;
char s[5000][20]={0},s1[10000]={0},s2[10000]={0};
scanf("%d\n",&n);
for(i=0;i<n;i++)
{ gets(s[i]);
    if (strlen(s[i])>maxl) maxl=strlen(s[i]);
}
scanf("%s\n",s1);
 while(strlen(s1)!=0)
 {
     if(strlen(s1)==1)
     {printf("%s ",s1);
       memset(s1,0,sizeof(s1));
     }
     else
     { int flag=0,flag1=0;
     l=maxl;
     while(l>=1)
     {
      for(i=0;i<l;i++) 
         s2[i]=s1[i];
         s2[i]=0;
        for(f=0;f<n;f++)
  {  flag1=1;
      if(l==strlen(s[f])) 
    {for(j=0;j<l;j++)
      {if(s2[j]!=s[f][j]) {flag1=0;break;}}
     if(flag1==1) {break;}
    }
  }
        if(flag1==1)
        { flag=1;
         printf("%s ",s2);
         for(k=0;k<strlen(s1)-l;k++)
         s1[k]=s1[k+l];
         s1[k]=0;
         memset(s2,0,sizeof(s2)); 
         break;
        }
        else
        l--;
     }
     if(flag==0)
     {
         printf("%s ",s2);
         for(k=0;k<strlen(s1)-1;k++)
         s1[k]=s1[k+1];
         s1[k]=0;
     }
     }
     
     
     
 }
 
}