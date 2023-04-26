#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int a[100];
    int number;
    char s[1000];
}hang;
int cmp(const void*a,const void*b)
{
    hang*p1,*p2;
    p1=(hang*)a;
    p2=(hang*)b;
    int i=0,k1,k2;
    k1=p1->number;k2=p2->number;
    if(k1>=k2)
    {
        for(i=0;i<k2+1;i++)
        {
            if(p1->a[i]>p2->a[i])return -1;
            else if(p1->a[i]<p2->a[i])return 1;
            else i=i;
        }
        if(i==k2+1) return 1;
    }
    if(k1<k2)
    {
        for(i=0;i<k1+1;i++)
        {
            if(p1->a[i]>p2->a[i])return -1;
            else if(p1->a[i]<p2->a[i])return 1;
            else i=i;
        }
        if(i==k1+1) return 1;
    }
}
void paixu(int h)
{
    int n,i;
    int k=0,j=0,f=1;
    hang p[1100];
    scanf("%d",&n);
getchar();
    for(i=0;i<n;i++)
    {


        gets(p[i].s);
        p[i].number=0;
        k=0;j=0;
        while(p[i].s[k])
        {

            f=1;p[i].a[j]=0;
            while(p[i].s[k]!=' ' && p[i].s[k])
                {
                    if(p[i].s[k]=='-'){k++;f=-1;}
                    p[i].a[j]=p[i].a[j]*10+(p[i].s[k]-'0');
                    k++;
                }
                p[i].a[j]=p[i].a[j]*f;
            if(p[i].s[k]==' '){p[i].number++;k++;j++;}
        }
    }

    qsort(p,n,sizeof(p[0]),cmp);
    for(i=0;i<n;i++)
    {
        for(k=0;k<p[i].number;k++)printf("%d ",p[i].a[k]);
        printf("\n");
    }


}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)
        paixu(h);

}

