#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char s[11000000];
    scanf("%s",s);
    int len=strlen(s);
    unsigned int b[11000000]={0},i=0,k=0,flag=0;
    while(i<len)
    {
        
        while(s[i]!='x'&&i<len) i++;
        if(i==len) break;
        else if(s[i-1]=='0')
        {  i++;
           if((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f')){
            while((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f')) 
           {
               flag=1;
               if(s[i]>='a'&&s[i]<='f') b[k]=b[k]*16+s[i]-'a'+10;
               else b[k]=b[k]*16+s[i]-'0';
               i++;
            }
            k++;}
            
        
        }
       else i++;
       
    }
    if(flag==0) printf("-1");
    if(flag==1)
    {
        for(int t=0;t<k;t++)
        printf("%u ",b[t]);
    }
    return 0;
}