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
        char arr[200]={0};
        int a=0;
        for (int j=0;j<200;j++)
        {
            a=n*10/m;
            n=n*10%m;
            arr[t++]=a+'0';
        }
        int c,d,flag=0;
        char s[200]={0};
        for (int j=0;j<200;j++)
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
                    int k,flag1=0;
                    for (k=j-1;k>=0;k--)
                        if (arr[k]==arr[j])
                        {
                            int x,y,cnt=0;
                            for (x=k,y=j;x<=j;x++,y++)
                            {
                                if (arr[x]!=arr[y])
                                    break;
                                else
                                    cnt++;
                            }
                            if (cnt==j-k+1)
                            {
                                flag1=1;
                                break;
                            }
                        }
                    if(flag1==1)
                    {
                        c=k+1;
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
//        printf("%s\n",arr);
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
