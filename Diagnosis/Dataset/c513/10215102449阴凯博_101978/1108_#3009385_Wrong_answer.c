#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int n,m,t=0;
        scanf("%d %d",&n,&m);
        char arr[120]={0};
        int a=0;
        for (int j=0;j<100;j++)
        {
            a=n*10/m;
            n=n*10%m;
            arr[t++]=a+'0';
        }
        int c,d,flag=0;
        char s[120]={0};
        for (int j=0;j<100;j++)
        {
            if (arr[97]=='0' && arr[98]=='0')
            {
                flag=1;
                break;
            }
            else
            {
                if (strchr(s,arr[j])==0)
                {
                    s[j]=arr[j];
                }
                else
                {
                    if (*(strchr(arr,arr[j])+1)==arr[j+1])
                    {
                        c=j+1-(&arr[j]-strchr(arr,arr[j]));
                        d=j;
                        break;
                    }
                    else
                    {
                        s[j]=arr[j];
                    }
                }
            }
        }
        if (flag==1)
        {
            printf("0.");
            int k;
            for (k=98;k>=0 && arr[k]=='0';k--);
            for (int j=0;j<=k;j++)
                printf("%c",arr[j]);
            printf("\n");
        }
        else
        {
            printf("0.");
            for (int j=0;j<d;j++)
                printf("%c",arr[j]);
            printf("\n");
            printf("%d-%d",c,d);
            printf("\n");
        }



    }
    return 0;
}
