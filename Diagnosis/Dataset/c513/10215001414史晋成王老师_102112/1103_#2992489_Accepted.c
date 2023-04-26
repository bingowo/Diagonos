#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{ int i,j,n,m,a[1000]={0};
  char s1[10],s2[1000];
  while(scanf("%s %s\n",s1,s2)!=EOF)
  { 
     if(s1[0]=='I'&&s1[1]=='N')
    { if(s2[0]=='A'&&s2[1]=='X')
       {  a['A']=0;
           if(s2[3]!='-')
           {for(i=3;i<strlen(s2);i++)
         { a['A']*=10;
           a['A']+=(s2[i]-'0');
         }
               
           }
         else if(s2[3]=='-')
         {  for(i=4;i<strlen(s2);i++)
         { a['A']*=10;
           a['A']+=(s2[i]-'0');
         }
          a['A']*=-1;     
         }
           
       }
       if(s2[0]=='B'&&s2[1]=='X')
       { a['B']=0;
          if(s2[3]!='-')
          { for(i=3;i<strlen(s2);i++)
         { a['B']*=10;
           a['B']+=s2[i]-'0';
         }
          }
           else if(s2[3]=='-')
         {  for(i=4;i<strlen(s2);i++)
         { a['B']*=10;
           a['B']+=(s2[i]-'0');
         }
          a['B']*=-1;     
         }
       }
       if(s2[0]=='C'&&s2[1]=='X')
       { a['C']=0;
       if(s2[3]!='-')
          { for(i=3;i<strlen(s2);i++)
         { a['C']*=10;
           a['C']+=s2[i]-'0';
         }
          }
          else if(s2[3]=='-')
         {  for(i=4;i<strlen(s2);i++)
         { a['C']*=10;
           a['C']+=(s2[i]-'0');
         }
          a['C']*=-1;     
         }
       }
       if(s2[0]=='D'&&s2[1]=='X')
       { a['D']=0;
       if(s2[3]!='-')
          { for(i=3;i<strlen(s2);i++)
         { a['D']*=10;
           a['D']+=s2[i]-'0';
         }
          }
          else if(s2[3]=='-')
         {  for(i=4;i<strlen(s2);i++)
         { a['D']*=10;
           a['D']+=(s2[i]-'0');
         }
          a['D']*=-1;     
         }
           
       }
    } // IN
    
    if(s1[0]=='M'&&s1[1]=='O'&&s1[2]=='V')
    { a[s2[0]]=a[s2[3]];} //MOV
    
    if(s1[0]=='A'&&s1[1]=='D'&&s1[2]=='D')
    { a[s2[0]]=a[s2[0]]+a[s2[3]];}
    
    if(s1[0]=='S'&&s1[1]=='U')
    {a[s2[0]]=a[s2[0]]-a[s2[3]];}
    
    if(s1[0]=='M'&&s1[1]=='U'&&s1[2]=='L')
    {a[s2[0]]=a[s2[0]]*a[s2[3]];}
    
    if(s1[0]=='D'&&s1[1]=='I'&&s1[2]=='V')
    {a[s2[0]]=a[s2[0]]/a[s2[3]];}
    
    if(s1[0]=='O'&&s1[1]=='U'&&s1[2]=='T')
    {printf("%d\n",a[s2[0]]);}
    
  }
    
}