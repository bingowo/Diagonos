#include<stdio.h>
#include<string.h>

int main()
{
    char s[17],a[17]={0};
    int T,i=0,j=0,k=0,t=0,c=0,l=0,w=0,q=0;
    scanf("%d",&T);
    for(k=0;k<T;k++)
    {
        a[0]='\0';
        i=0;
        c=0;
        l=0;
        scanf("%s",s);
        c=strlen(s);
        if(c==1)
        {
         printf("case #%d:\n",k);
         printf("%s\n",s);
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
           if(j==-1) a[t]=s[i];
           t++;

        }
        l=t-1;
        printf("case #%d:\n",k);
        for(t=0;t<=l;t++)
        {
            for(w=t;w>=0;w--)
            {
                for(q=w;q<=t;q++)
                {
                    printf("%c",a[q]);
                }
                
            }
            printf("\n");
        }
        }
    }
    return 0;
}
