#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char ss[16];
}STR;

int combination(int n)
{
    int i,j; int cnt=0,a=1;
    for (i=1;i<=n;i++)
    {
        for (j=0;j<i;j++)
        {
            a=a*(n-j);
            a=a/(j+1);
        }
        cnt+=a;
        a=1;
    }
    return cnt;
}

int cmp(const void* a,const void* b)
{
    char* pa=(char*)a;  char* pb=(char*)b;
    return (*pa>*pb)?1:-1;
}

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[18]={0};
        scanf("%s",s);
        int cnt=1,j,k=0,h,x,m;
        qsort(s,strlen(s),sizeof(char),cmp);
        for (j=1;j<strlen(s);j++)
        {
            if (s[j]!=s[j-1])
                cnt++;
        }
        char* s2=(char*)malloc((cnt+1)*sizeof(char));
        for (j=1;j<strlen(s);j++)
        {
            if (s[j]!=s[j-1])
                s2[k++]=s[j-1];
        }
        s2[k++]=s[j-1];
        s2[k]='\0';
        qsort(s2,cnt,sizeof(char),cmp);
        int n=combination(cnt);
//        printf("%d\n",n);
        j=0,k=0,h=0,m=1;
        for (j=0;j<n;j++)
        {
            k++;
            for (x=0;x<k;x+=m)
                printf("%c",s2[h+x]);
            printf("\n");
            if (k==cnt-h)
            {
                if (h+m<cnt-1)
                {
                    m++;
                    k--;
                }
                else
                {
                    h++;
                    m=1;
                    k=0;
                }

            }

        }
        free(s2);

    }
    return 0;
}
