#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct
{
    char s;
    float f;
}str;
int cmp(const void* a,const void*b);
int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        float Freq[26];
        for (int j=0;j<26;j++)
            scanf("%f",&Freq[j]);
        str S[110];int l=0;
        getchar();
        while((S[l].s=getchar())!='\n')
            l++;
        for (int j=0;j<l;j++)
        {
            if (S[j].s>='a'&&S[j].s<='z') S[j].f=Freq[S[j].s-'a'];
            else if (S[j].s>='A'&&S[j].s<='Z') S[j].f=Freq[S[j].s-'A'];
        }
        str temp;
        for (int j=0;j<l-1;j++)
        {
            for (int k=l-1;k>j;k--)
            {
                if (S[k].f>S[k-1].f)
                {
                    temp=S[k];
                    S[k]=S[k-1];
                    S[k-1]=temp;
                }
                else if (fabs(S[k].f-S[k-1].f)<0.001)
                {
                    if (S[k].s>S[k-1].s)
                    {
                        temp=S[k];
                        S[k]=S[k-1];
                        S[k-1]=temp;
                    }
                }
            }
        }
        printf("case #%d:\n",i);
        for (int j=0;j<l;j++)
        {
            if (j!=l-1) printf("%c",S[j].s);
            else printf("%c\n",S[j].s);
        }    
        
    }
}

int cmp(const void* a,const void* b)
{
    str *x;str *y;
    x=(str*)&a;y=(str*)&b;
    if (x->f<y->f) return 1;
    else if (fabs((x->f-y->f))<0.001)
    {
        if (x->s<y->s) return 1;
    }
    return -1;
}