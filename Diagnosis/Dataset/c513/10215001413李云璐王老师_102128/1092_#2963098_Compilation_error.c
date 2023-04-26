#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>




int main()
{
    char s[1100];
    scanf("%s",s);
    int a[100000]={0};
    a[0]=1;
    int wei=1,yu;
    int n=strlen(s);
    if(n==0) printf("0");
    if(n==1) printf("1");
    if(n==2) {if(s[0]==s[1]) printf("1");else printf("4");}
    if(n>2){
    for(int i=0;i<n-1;i++)
    {
        if(i==0&&s[i]!=s[i+1])
         {yu=0;
        for(int i=0;i<wei;i++)
    {
        int c=a[i];
        a[i]=(a[i]*2+yu)%10;
        yu=(c*2+yu)/10;
    }
        while(yu>0) {a[wei]=yu;wei++;yu/=10;}}
        else if(i==n-1&&s[i]!=s[i-1]) 
        {yu=0;
    for(int i=0;i<wei;i++)
    {
        int c=a[i];
        a[i]=(a[i]*2+yu)%10;
        yu=(c*2+yu)/10;
    }
    while(yu>0) {a[wei]=yu;wei++;yu/=10;}}
        else{
        if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1]) 
        {
            yu=0;
            for(int i=0;i<wei;i++)
           {
             int c=a[i];
             a[i]=(a[i]*3+yu)%10;
             yu=(c*3+yu)/10;
            }
            while(yu>0) {a[wei]=yu;wei++;yu/=10;}
        }
        if(s[i]==s[i-1]&&s[i]!=s[i+1]) 
        {
            yu=0;
            for(int i=0;i<wei;i++)
         {
             int c=a[i];
             a[i]=(a[i]*2+yu)%10;
             yu=(c*2+yu)/10;
          }
            while(yu>0) {a[wei]=yu;wei++;yu/=10;}
            
        }
        if(s[i]==s[i+1]&&s[i]!=s[i-1]) 
        {
            yu=0;
            for(int i=0;i<wei;i++)
             {
                int c=a[i];
                a[i]=(a[i]*2+yu)%10;
                yu=(c*2+yu)/10;
              }
            while(yu>0) {a[wei]=yu;wei++;yu/=10;}
            
        }
        if(s[i-1]==s[i+1]&&s[i]!=s[i-1]) 
            {
                yu=0;
                for(int i=0;i<wei;i++)
                {
                   int c=a[i];
                   a[i]=(a[i]*2+yu)%10;
                   yu=(c*2+yu)/10;
                }
                while(yu>0) {a[wei]=yu;wei++;yu/=10;}
                
            }
        }
    }
    printf("%d\n",wei);
    for(int i=wei-1;i>=0;i--)
    printf("%d",a[i]);
    return 0;




}
