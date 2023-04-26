#include<stdio.h>
#define LONG_LONG_MAX 9223372036854775807

struct Cylinder
{
    int r;
    int h;
    long long s;
    long long sd;
    long long sc;
}cy[1000];

int cmp(const void *q1,const void *q2)
{
    struct Cylinder *p1=(struct Cylinder*)q1;
    struct Cylinder *p2=(struct Cylinder*)q2;
    if(p1->sc<p2->sc) return 1;
    else return -1;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&cy[i].r,&cy[i].h);
        cy[i].sd=cy[i].r*cy[i].r;
        cy[i].sc=cy[i].r*cy[i].h*2;
        cy[i].s=cy[i].sd+cy[i].sc;
    }
    qsort(cy,n,sizeof(struct Cylinder),cmp);
    long long m_r_max=0;
    long long m_sc_min=LONG_LONG_MAX;
    for(int i=0;i<m;i++)
    {
        if(m_r_max<cy[i].r) m_r_max=cy[i].r;
        if(m_sc_min>cy[i].sc) m_sc_min=cy[i].sc;
    }
    long long temp=0;
    for(int i=m;i<n;i++)
    {
        if(cy[i].s>(m_sc_min+m_r_max*m_r_max) && cy[i].r>=m_r_max && cy[i].s>temp)
        {
            temp=cy[i].s;
        }
    }
    long long sum=0;
    for(int i=0;i<m;i++)
    {
        sum+=cy[i].sc;
    }
    if(temp)
    {
        sum-=m_sc_min;
        sum+-temp;
    }
    else sum+=(m_r_max*m_r_max);
    printf("%lld",sum);
    return 0;
}
