#include<stdio.h>
#include<ctype.h>
#define N 201


void selection_sort(char* alpha,int cnt);
void swap(char* a, char* b);
int main()
{
    int t;
    int i;
    scanf("%d\n",&t);

    for (i=0;i<t;++i)
    {
        char s[N];//s数组用于存放当前行字符串
        char alpha[N]={0};
        gets(s);
        char* p=s;
        int cnt=0;

        while(*p)
        {
            if (isalpha(*p))
            {
                alpha[cnt++]=*p;
            }
            p++;
        }
        selection_sort(alpha,cnt);
        cnt=0;
        p=s;

        while (*p)
        {
            if (isalpha(*p))
            {
                *p=alpha[cnt++];
            }
            p++;
        }

        printf("case #%d:\n",i);
        printf("%s\n",s);        
    }

    return 0;
}

void selection_sort(char* alpha,int cnt)
{
    int i,j,k;
    for (i=0;i<cnt;++i)
    {
        k=i;
        for (j=i+1;j<cnt;++j)
        {
            if (alpha[j]<alpha[k])
            {
                k=j;
            }
        }
        if (k!=i)
        {
            swap(alpha+i,alpha+k);
        }
    }
    return;
}

void swap(char* a, char* b)
{
    char t=*a;
    *a=*b;
    *b=t;
    return;
}