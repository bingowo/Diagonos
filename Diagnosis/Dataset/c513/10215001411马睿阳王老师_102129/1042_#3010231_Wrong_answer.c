#include<stdio.h>
#include<string.h>
#include<math.h>

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
    char s[17],a[17]={0},b[100][17]={0};
    int T,i=0,j=0,k=0,t=0,c=0,l=0,w=0,q=0,d=0,x=0,y=0,g=0;
    int e[1000]={0};
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
        {
            for(i=0;i<c;i++)
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
          d=strlen(a);
          for(i=1;i<pow(2,d);i++)
          {
                k=i;
                x=0;
                while(k!=0&&x<strlen(a))
                {
                    if(k&1==1)
                   {
                    b[i][j]=a[x];
                    j++;
                    x++;
                    k>>=1;
                   }
                   else
                   {k>>=1;
                    x++;
                    }
                }
          }
            l=strlen(b);
            qsort(b,l,sizeof(b[0][0]),cmp);
            printf("case #%d:\n",k);
            for(i=0;i<pow(2,c);i++)
            {
               for(j=0;b[i][j]!=0;j++)
               {
                   printf("%c",b[i][j]);
               }
               printf("\n");
            }


        }
    }\
    return 0;
}
