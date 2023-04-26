#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int part(const char s[][15],char*c,int n)
{
int len1=strlen(c);  
    int b[4005];
    for(int i=0;i<n;i++) b[i]=strlen(s[i]); 
    int len2=b[0];
    for(int i=1;i<n;i++)
    {
        if(b[i]>len2) len2=b[i];  
        else len2=b[i-1];
    }
    int m;
  char co[len2+1];
 for(int m=len2;m>0;m--)  
    {   int num=0;
        strncpy(co,c,m); 
co[m]=’\0’;
        if(m!=1)  
        {
            int p=0;
            while(b[p]==m&&p<n)  
         {
            if(b[p]==m && strcmp(co,s[p])==0)
            {
                num=1;
                break;
            }
            p++;
         }
        }

        else 
{
num=1;

}
        if(num==1) break;
}

for(int i=0;i<m;i++) printf("%s",c[i]);
char *pt=&c[m];
if(c+m=='/0') 
 return 0;
    else return part(s,c,n);
}

int main()
{  int n;
   scanf("%d",&n);
   char s[4005][15];
   for(int i=0;i<n;i++) scanf("%s",s[i]); 
   char c[5001];
   scanf("%s",c);
   part(s,c,n);
   printf("\n");
   return 0;
}



