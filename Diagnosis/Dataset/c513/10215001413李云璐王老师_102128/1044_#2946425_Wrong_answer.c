#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char s[100001];
    scanf("%s",s);
    int len=strlen(s);
    int b[3334]={0},i=0,k=0;
    while(s[i])
    {
        int flag=0;
        while(s[i]!='x'&&s[i]!='\n') i++;
        if(i>=len) break;
        else if(s[i-1]==0)
        {  i++;
           k++;
           while((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f')) 
           {
               b[k]=0;
               flag=1;
               if(s[i]>='a'&&s[i]<='f') b[k]=b[k]*16+s[i]-'a'+10;
               else b[k]=b[k]*16+s[i]-'0';
               i++;
            }
         if(flag==0) printf("-1");
         if(flag==1) printf("%d ",b[k]);   
        
       }
    
    
       else i++;
       
    }
    
    return 0;
}