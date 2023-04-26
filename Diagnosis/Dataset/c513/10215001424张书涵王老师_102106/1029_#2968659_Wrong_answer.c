#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d ",&T);
    int i;
    for(i=0;i<T;i++)
    {
        int l;
        char a[200]={0};
        char b[201]={0};
        char c;
        int lenth[100]={0};
        int k,j=0,p,q;
        gets(b);
        for(p=0,q=0;b[j]!='\n'&&b[j]!='\0';q++)
        {
            for(k=0;b[j]!=' '&&b[j]!=0;j++,p++,k++)
                a[p]=b[j];
            lenth[q]=k;
            if(b[j]==' ')
                j++;
        }
        l=strlen(a);
        for(j=0;a[j];j++)
        {
            for(p=j+1;a[p];p++)
            {
                if(a[p]>90||a[p]<65);
                {
                    if(a[j]>90||a[j]<65);
                    else
                    {
                        if(a[j]>a[p])
                        {
                            c=a[p];
                            a[p]=a[j];
                            a[j]=c;
                        }
                    }
                }
            }
        }
        printf("case #%d:\n",i);
        for(j=0,p=0;lenth[j]!=0;j++)
        {
            for(q=0;q<lenth[j];p++,q++)
                printf("%c",a[p]);
            printf(" ");
        }
        printf("\n");
    }
}