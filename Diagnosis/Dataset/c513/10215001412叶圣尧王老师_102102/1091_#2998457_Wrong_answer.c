#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int a[100]={0},b[100]={0},n,sign1=1,sign2=1;char s[20];
    scanf("%s",s);scanf("%d",&n);
    if(s[strlen(s)-1]!='i')
    {
        for(int i=strlen(s)-1;i>=0;i--)
            a[strlen(s)-i-1]=s[i]-'0';
    }
    else
    {
        if(s[0]=='i')b[0]=1;
        else if(s[1]=='i'&&s[0]=='-'){b[0]=1;sign2=-1;}
        else
        {
            int k=0,q;
            for(int i=0;i<strlen(s)-1;i++)if(!isdigit(s[i])){k++;q=i;}
            if(k==2)
            {
                sign1=-1;if(s[q]=='-')sign2=-1;else sign2=1;
                for(int i=1;i<q;i++)
                    a[i-1]=s[q-i]-'0';
                for(int i=q+1;i<strlen(s)-1;i++)
                    b[i-q-1]=s[strlen(s)+q-i]-'0';
                if(atoi(b)==0)b[0]=sign2;
            }
            else if(k==1)
            {
                if(s[q]=='-')sign2=-1;
                if(q==0)
                {
                    for(int i=1;i<strlen(s)-1;i++)
                        b[i-1]=s[strlen(s)-i-1]-'0';
                }
                else
                 {
                    for(int i=0;i<q;i++)a[i]=s[q-i-1]-'0';
                    for(int i=q+1;i<strlen(s)-1;i++)b[i-q-1]=s[strlen(s)+q-i]-'0';
                    if(atoi(b)==0)b[0]=sign2;
                 }
            }
            else
            {
                for(int i=0;i<strlen(s)-1;i++)b[i]=s[strlen(s)-i-2]-'0';
            }
        }
    }
    int i=99,j=99;
    while(a[i]==0)i--;while(b[i]==0)j--;
   if(sign1==-1)printf("-");
   for(;i>=0;i--)printf("%d",a[i]);
   if(sign2==-1)printf("-");
   else printf(" ");
   for(;j>=0;j--)printf("%d",b[j]);
}
