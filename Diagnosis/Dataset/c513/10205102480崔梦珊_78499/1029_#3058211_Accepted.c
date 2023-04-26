#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void *a ,const void *b)
{
	return strcmp( (char *)a , (char *)b );
}

int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        int an=0;
        int al=0;
        int re=0;
        char ans[200];
        char alpha[200];
        int record[200]={0};
        for(int j=0;j<200;j++)
        {
            ans[j]='\0';
            alpha[j]='\0';
        }
        char c;
        while((c=getchar())!='\n')
        {
            if(c>='A'&&c<='Z')
            {
                alpha[al]=c;
                al++;
            }
            else
            {
                ans[an]=c;
                record[re]=1;

            }
            an++;
            re++;
        }
        /*for(int j=0;j<strlen(alpha)-1;j++)
        {
            for(int k=0;k<strlen(alpha)-1-j;k++)
            {
                if(alpha[k]>alpha[k+1])
                {
                    char temp=alpha[k];
                    alpha[k]=alpha[k+1];
                    alpha[k+1]=temp;
                }
            }
        }*/
        qsort(alpha,al,sizeof(alpha[0]),cmp);
        int w=0;
        printf("case #%d:\n",i);
        for(int j=0;j<an;j++)
        {
            if(record[j]==0)
            {
                printf("%c",alpha[w]);
                w++;
            }
            else
            {
                printf("%c",ans[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
