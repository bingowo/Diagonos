#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
char s1[51],s2[51],s[55];
int read1(char s1[],char s[])
{   int l=strlen(s1);int i=0;int j=0;
    while(s[i])
    {
        while(s[i+j]==s1[j])
        {
            j++;
        }
            if(j==l)
                return i+l;
            else
            {
                j=0;
            }
            i++;
    }
    return -1;
}
int read2(char s1[],char s[])
{
    int l=strlen(s1);int i=0,max=-1,j=0;
    while(s[i])
    {
        while(s[i+j]==s1[j])
        {
            j++;
        }
            if(j==l)
                if(max<i)
                {max=i;j=0;}
            else
            {
                j=0;
            }
            i++;
    }
    return max;
}
int main()
{
    int n,t1,t2,end;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        memset(s,0,55);
        scanf("%s%s%s",s1,s2,s);
          s[strlen(s)]='!';s[strlen(s)]='\0';
          t1=read1(s1,s);
          t2=read2(s2,s);
          if(t2==0)
            t1=read2(s1,s);
          if(t2<t1)
          {
              end=t1-(t2+strlen(s2));
          }
          else
          end=t2-t1;
        printf("case #%d:\n",i);

          if(t1==-1||t2==-1||t1==t2+strlen(s1))
            printf("0\n");
          else
          {
              printf("%d\n",abs(end));
          }
    }
    return 0;
}
