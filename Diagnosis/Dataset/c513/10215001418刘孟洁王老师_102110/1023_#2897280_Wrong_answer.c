#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 3100

int compare(const void*a,const void*b)
{
    char *s1=(char*)a;
    char *s2=(char*)b;
    int i=0,x=0,sum1=0,sum2=0;
   while(s1[i]!='\0')
   {
       if(isdigit(s1[i]))sum1=sum1*10+s1[i]-'0',i++;
       else i++;
   }
   while(s2[x]!='\0')
   {
       if(isdigit(s2[x]))sum2=sum2*10+s2[x]-'0',x++;
       else x++;
   }
   if(sum1==0)
   {
       if(sum2==0)
       {
           if(strcmp(s1,s2)<0)return -1;
           else return 1;
       }
       else return -1;
   }
   else
   {
       if(sum2==0)return 1;
       else if(sum1<sum2)return -1;
       else return 1;
   }
}


int main()
{
    char s[101][31],t[N];
    int length =0,i,k;
    gets(t);
    for(i=0,k=0;t[i]!='\0';i++)
    {
        s[k][length]=t[i];
        if(t[i+1]==' ')
          {
            s[k][length+1]='\0';
            length=0;k++;i++;
           }
        else if(t[i+1]=='\0')
          {
            s[k][length+1]='\0';
            length=0;
            break;
           }
           else length++;

    }
    k++;
    qsort(s,k,sizeof(s[0]),compare);
    for(i=0;i<k;i++)printf("%s ",s[i]);
    return 0;
}
