#include<stdio.h>
#include<string.h>

int main()
{
    char a[505];
    int T,i=0,j=0,t=0,k=0;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%s",&a);
        int l=strlen(a);
        int d=1;
        printf("case #%d:\n",i);
        if(l==1)
        {
            printf("1");
            printf("%c",a[0]);
            printf("\n");
        }
        else
        {for(j=1;j<l;j++)
        {
            if(j==l-1)
            {
                if(a[j]==a[j-1])
                {
                    d++;
                     if(d<=255)
                    {
                        printf("%d",d);
                        printf("%c",a[j-1]);
                        d=1;
                    }
                    else
                    {
                        printf("255");
                        printf("%c",a[j-1]);
                        d=d-255;
                        printf("%d",d);
                        printf("%c",a[j-1]);
                       d=1;
                    }

                }
                else
                {
                    if(d<=255)
                    {
                        printf("%d",d);
                        printf("%c",a[j-1]);
                        d=1;
                    }
                    else
                    {
                        printf("255");
                        printf("%c",a[j-1]);
                        d=d-255;
                        printf("%d",d);
                        printf("%c",a[j-1]);
                       d=1;
                    }
                    printf("1");
                    printf("%c",a[j]);
                }
            }
            else if(a[j]==a[j-1])
            {
                d++;
            }
            else
            {

                 if(d<=255)
                {
                    printf("%d",d);
                    printf("%c",a[j-1]);
                    d=1;
                }
                else
                {
                    printf("255");
                    printf("%c",a[j-1]);
                    d=d-255;
                    printf("%d",d);
                    printf("%c",a[j-1]);
                    d=1;
                }
            }


        }
        printf("\n");
        }

    }
    return 0;
}

