#include<stdio.h>
#include<string.h>

int cmp(const void*a1,const void*b1)
{
    char a=*(char*)a1;
    char b=*(char*)b1;
    if(a-b-'0'==32) return -1;
    else if(b-a-'0'==32) return 1;
    else if(a>b) return 1;
    else return -1;
}

int main()
{
    char s[17],a[17]={0},b[17]={0};
    int T,i=0,j=0,k=0,t=0,c=0,l=0,w=0,q=0,d=0,x=0,y=0,e=0,g=0;
    scanf("%d",&T);
    for(k=0;k<T;k++)
    {
        memset(a,0,strlen(a));
        i=0;
        c=0;
        l=0;
        d=0;
        t=0;
        x=0;
        y=0;
        e=0;
        g=0;
        scanf("%s",s);
        c=strlen(s);
        qsort(s,c,sizeof(s[0]),cmp);
        if(c==1)
        { printf("case #%d:\n",k);
          printf("%s\n",s);
        }
        else if(c==2)
        {
            printf("case #%d:\n",k);
            printf("%c\n",s[0]);
            printf("%s\n",s);
            printf("%c\n",s[1]);
        }
        else
        {for(i=0;i<c;i++)
        {
           j=i;
           while(j>=0)
           {
               if(s[i]!=s[j-1]) j--;
               else break;
           }
           if(j==-1)
           {a[t]=s[i];
            t++;
           }

        }
        l=strlen(a)-1;
        d=0;
        printf("case #%d:\n",k);
        for(t=0;t<=l;t++)
        {
            printf("%c\n",a[t]);
            for(w=t+1;w<=l;w++)
            {
                for(d=0;w+d<=l;d++)
                {
                    printf("%c",a[t]);
                    for(q=w;q<=w+d;q++)
                   {printf("%c",a[q]);}
                    printf("\n");
                }
            }
            //从后往前去掉元素
         for(x=l-1;x>0;x--)
         {strncpy(b,a,x);
          e=strlen(b);
          for(y=e;y<=l;y++)
          {b[y]=a[y+1];}
          g=strlen(b);
          for(t=e;t<g;t++)
          {
              printf("%c",b[t]);
              for(w=t+1;w<g;w++)
              {
                  for(d=0;w+d<g;d++)
                  {
                      printf("%c",b[t]);
                      for(q=w;q<=w+d;q++)
                      printf("%c",a[q]);
                      printf("\n");
                  }
              }
          }



         }
        }
        }
    }
    return 0;
}
