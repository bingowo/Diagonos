#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define ll long long


typedef struct Cylinder
{
    ll h;
    ll r;
    ll surface;
    ll floor;
    ll lateral;

}cylinder;
void init(cylinder p)
    {
        p.floor = p.r * p.r;
        p.lateral = 2 * p.r * p.h;
        p.surface = p.floor + p.lateral;//可视化应该只有一个底面和侧面
    }


int cmp(cylinder a, cylinder b)
{
    return(a.lateral > b.lateral?1:-1);
}

int main()
{
    int n,m;
    
    scanf("%d%d",&n,&m);
    cylinder* C =(cylinder* ) malloc(sizeof(cylinder)*n);
    for(int i = 0; i < n ;i++)
    {
        
        scanf("%lld%lld",&C[i].r,&C[i].h);
        init(C[i]);
        
    }
        
    
    qsort(C,n,,sizeof(cylinder),cmp);
    

    ll m_r_max = 0;//找出来前m个数最大的半径，作为底部
    ll m_la_min = LLONG_MAX;
    for(int i = 0; i < m; i++)
    {
        if(m_r_max < C[i].r)
        {
            m_r_max = C[i].r;
        }
        if(m_la_min > C[i].lateral)
        {
            m_la_min = C[i].lateral;
        }
    }
    


    ll temp = 0;
    for(int i = m; i < n; i++)
    {
        if(C[i].surface > (m_la_min + m_r_max * m_r_max) && C[i].r >= m_r_max && C[i].surface > temp)
        {
            
            temp = C[i].surface;
        }    
    }
    


	ll all = 0;
    for(int i = 0; i < m; i++)
    {
        all += C[i].lateral;
    }
    

    if(temp)
    {
        all -= m_la_min ;
        all += temp;
    }
    else
    {
        all += (m_r_max * m_r_max);
    }
    printf("%lld\n",all);
    return 0;
}
