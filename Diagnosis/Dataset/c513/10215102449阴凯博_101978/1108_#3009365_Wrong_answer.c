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
        double x=(double)n/m;
        char arr[20]={0};
        double a=x;
        for (int j=0;j<16;j++)
        {
            a=a*10.0;
            int m=(int)a%10;
            a=a-m;
            arr[t++]=m+'0';
        }
        int c,d,flag=0;
        char s[20]={0};
        for (int j=0;j<15;j++)
        {
            if (arr[14]=='0' && arr[15]=='0')
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
            for (int j=0;j<16 && arr[j]!='0';j++)
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
