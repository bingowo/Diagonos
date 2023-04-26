#include <stdio.h>
#include <stdlib.h>
#define N 10000
int p[26];
int compare(const void*a,const void*b)
{
      char *s1=(char*)a;
      char *s2=(char*)b;
       char ch1,ch2;
       while(*s1&&*s2)
       {
           ch1=*s1<'a'?*s1:*s1+32;
           ch2=*s2<'a'?*s2:*s2+32;
           if(p[ch1-'A']!=p[ch2-'A'])
            return p[ch1-'A']-p[ch2-'A'];
           s1++;s2++;
       }
       if(*s1==0)return -1;
}
void sort(char (*s)[],int n)
{qsort(s,n,sizeof(char),compare);}

int main()
{
    int i,j,k;
    while(1)
    {
        char s[27];
        while(1)
        {
            char t[N],str[101][21];
           scanf("%s",s);
           for(i=0;i<26;i++)p[s[i]-'A']=i;
           gets(t);
           int num=0,length=0;
           for(j=0;t[j]!='\0';j++)
           {
               str[num][length]=t[j];
               length++;
               if(s[j+1]==' ')
                {str[num][length++]='\0';j++;num++;length=0;}
            }

      sort(str,num);
      for(k=0;k<num;k++)
          for(length=0;str[k][length]!='\0';length++)
              printf("%c",str[k][length]);
        }
    }
    return 0;
}