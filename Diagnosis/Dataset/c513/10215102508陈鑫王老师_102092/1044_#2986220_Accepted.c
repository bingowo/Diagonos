#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[6]={10,11,12,13,14,15};
int main()
{
    char s[100001];
    scanf("%s",s);
    int temp=0;
    unsigned int ans=0;
    char *p=s,*q;
    while(*p!='\0')
    {
       if(*p=='0'&&*(p+1)=='x')
       {
           ans=0;
           q=p+2;
           while(*q<'g'&&*q!='\0')
           {
               if(*q>='a')
               ans=ans*16+a[*q-'a'];
               else ans=ans*16+(*q-'0');
               q++;
           }
           if(q!=p+2) 
           {temp++;
           if(temp==1)
               printf("%u",ans);
            else if(temp>1)
                printf(" %u",ans);
           }
           p=q;
       }
       p++;
    }
    if(temp==0)
        printf("-1");
    return 0;

}
