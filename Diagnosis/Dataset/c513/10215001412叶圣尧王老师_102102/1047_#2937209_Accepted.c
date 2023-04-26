#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int T,t;scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        char s[501],a[250];int d[250],k=0;
        scanf("%s",s);a[k]=s[0];d[k]=1;
        for(int i=1;i<strlen(s);i++)
        {
            if(s[i]==s[i-1])
            {
                d[k]++;
                if(d[k]>=255){k++;i++;a[k]=s[i];d[k]=1;}
            }
            else
            {
                k++;
                a[k]=s[i];d[k]=1;
            }
        }a[k+1]='\0';
        printf("case #%d:\n",t);
        for(int i=0;i<strlen(a);i++)
            printf("%d%c",d[i],a[i]);
        printf("\n");
    }
}
