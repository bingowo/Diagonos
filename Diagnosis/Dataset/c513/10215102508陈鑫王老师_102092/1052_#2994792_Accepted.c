#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char res[11]="GUWXZFHSIO";
int res1[10]={8,4,2,6,0,5,3,7,9,1};
int cmp1(const void*a,const void*b)
{
    char x=*(char*)a;
    char y=*(char*)b;
    return x<y?-1:1;
}
int cmp2(const void*a,const void*b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    return x<y?-1:1;

}
int ch(char s[],char s1)
{
    int ret=0,len=strlen(s);
    int j=0;
    for(;s[j]=='*'&&j<len;j++);
    if(j==len)
    {
        return -1;
    }
    else
    {for(int i=0;i<len;i++)
    {
        if(s1==s[i])
        {
            ret++;
            s[i]='*';
        }

    }
    return ret;
    }
}
void others(char s[],int n,char s1)
{
    int len=strlen(s);
    int time=0;
    if(s1=='W')
    {
       for(int i=0;i<len;i++)
       {
           if(s[i]=='O')
           {
               for(int j=0;j<n;j++)
                s[i+j]='*';
               time=1;
               i=i+n;
               for(;s[i]=='O';i++);
               i--;
           }
           if(s[i]=='T')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=2;
               i=i+n;
               for(;s[i]=='T';i++);
               i--;
           }
           if(time==2)
           {
              break;
           }
       }
    }
       else if(s1=='Z')

       {for(int i=0;i<len;i++)
       {
           if(s[i]=='E')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=1;
               i=i+n;
               for(;s[i]=='E';i++);
               i--;

           }
           if(s[i]=='O')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=2;
               i=i+n;
               for(;s[i]=='O';i++);
               i--;
           }
           if(s[i]=='R')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=3;
               i=i+n;
               for(;s[i]=='R';i++);
               i--;
           }
           if(time==3)
           {
              break;
           }
       }
    }
    else if(s1=='U')

       {for(int i=0;i<len;i++)
       {
           if(s[i]=='F')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=1;
               i=i+n;
               for(;s[i]=='F';i++);
               i--;
           }
           if(s[i]=='O')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=2;
               i=i+n;
               for(;s[i]=='O';i++);
               i--;
           }
           if(s[i]=='R')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=3;
               i=i+n;
               for(;s[i]=='R';i++);
                i--;
           }
           if(time==3)
           {
              break;
           }
       }
    }
    else if(s1=='X')

       {for(int i=0;i<len;i++)
       {
           if(s[i]=='I')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=1;
               i=i+n;
               for(;s[i]=='I';i++);
               i--;
           }
           if(s[i]=='S')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=2;
               i=i+n;
               for(;s[i]=='S';i++);
               i--;
           }
           if(time==2)
           {
              break;
           }
       }
    }
    else if(s1=='G')

       {for(int i=0;i<len;i++)
       {
           if(s[i]=='E')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=1;
               i=i+n;
               for(;s[i]=='E';i++);
               i--;
           }
           if(s[i]=='H')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=2;
               i=i+n;
               for(;s[i]=='H';i++);
               i--;
           }
           if(s[i]=='I')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=3;
               i=i+n;
               for(;s[i]=='I';i++);
               i--;
           }
           if(s[i]=='T')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=4;
               i=i+n;
               for(;s[i]=='T';i++);
               i--;
           }
           if(time==4)
           {
              break;
           }
       }
    }
    else if(s1=='H')

       {for(int i=0;i<len;i++)
       {
           if(s[i]=='E')
           {
               for(int j=0;j<2*n;j++)
               {
                   s[i+j]='*';
               }
               time=1;
               i=i+2*n;
               for(;s[i]=='E';i++);
               i--;
           }
           if(s[i]=='R')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=2;
               i=i+n;
               for(;s[i]=='R';i++);
               i--;
           }
           if(s[i]=='T')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=3;
               i=i+n;
               for(;s[i]=='T';i++);
               i--;
           }
           if(time==3)
           {
              break;
           }
       }
    }
    else if(s1=='S')

       {for(int i=0;i<len;i++)
       {
           if(s[i]=='E')
           {
               for(int j=0;j<2*n;j++)
               {
                   s[i+j]='*';
               }
               time=1;
               i=i+2*n;
               for(;s[i]=='E';i++);
               i--;
           }
           if(s[i]=='N')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=2;
               i=i+n;
               for(;s[i]=='N';i++);
               i--;
           }
           if(s[i]=='V')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=3;
               i=i+n;
               for(;s[i]=='V';i++);
               i--;
           }
           if(time==3)
           {
              break;
           }
       }
    }
    else if(s1=='F')

       {for(int i=0;i<len;i++)
       {
           if(s[i]=='E')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=1;
               i=i+n;
               for(;s[i]=='E';i++);
               i--;
           }
           if(s[i]=='I')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=2;
               i=i+n;
               for(;s[i]=='I';i++);
               i--;
           }
           if(s[i]=='V')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=3;
               i=i+n;
               for(;s[i]=='V';i++);
               i--;
           }
           if(time==3)
           {
              break;
           }
       }
    }
    else if(s1=='I')

       {for(int i=0;i<len;i++)
       {
           if(s[i]=='E')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=1;
               i=i+n;
               for(;s[i]=='E';i++);
               i--;
           }
           if(s[i]=='N')
           {
               for(int j=0;j<2*n;j++)
               {
                   s[i+j]='*';
               }
               time=2;
               i=i+2*n;
               for(;s[i]=='N';i++);
               i--;
           }

           if(time==2)
           {
              break;
           }
       }
    }
    else if(s1=='O')

       {for(int i=0;i<len;i++)
       {
           if(s[i]=='E')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=1;
               i=i+n;
               for(;s[i]=='E';i++);
               i--;
           }
           if(s[i]=='N')
           {
               for(int j=0;j<n;j++)
               {
                   s[i+j]='*';
               }
               time=2;
               i=i+n;
               for(;s[i]=='N';i++);
               i--;
           }

           if(time==2)
           {
              break;
           }
       }
    }

}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[21];
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(char),cmp1);
        int a[20]={0},index=0;
        for(int j=0;j<10;j++)
        {
            int m=ch(s,res[j]);
            if(m==-1)break;
            if(m>0)
            {
                others(s,m,res[j]);
                while(m)
                {
                    a[index++]=res1[j];
                    m--;
                }
            }
        }
        qsort(a,index,sizeof(int),cmp2);
        printf("case #%d:\n",i);
        for(int j=0;j<index;j++)
        {
            printf("%d",a[j]);
        }
        printf("\n");

    }
    return 0;
}
