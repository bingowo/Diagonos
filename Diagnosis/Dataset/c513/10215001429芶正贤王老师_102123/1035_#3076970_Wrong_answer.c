#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    long long int r;
    long long int h;
    long long int s1;
    long long int s2;
}STRUCT;

int cmp2(const void*a,const void*b)//侧面积s2排序
{
    STRUCT *x = (STRUCT*)a;
    STRUCT *y = (STRUCT*)b;
    if(x->s2 != y->s2)//s2降序
    {
        if(x->s2 > y->s2)
            return -1;
        else
            return 1;
    }
    else
    {
        if(y->s1 > x->s1)
            return 1;
        else
            return -1;
    }
    
}



int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    STRUCT CASE[1005];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&CASE[i].r);
        scanf("%lld",&CASE[i].h);
        CASE[i].s1 = CASE[i].r*CASE[i].r;
        CASE[i].s2 = 2*CASE[i].r*CASE[i].h;
    }
    //两个方案比较
    
    qsort(CASE,n,sizeof(STRUCT),cmp2);
    int mark=0,flagmax=0,flagmin=0;
    long long int sum = CASE[0].s1+CASE[0].s2;
    for(int i=0;i<n;i++)
    {
        long long int temp = CASE[i].s1+CASE[i].s2;
        if(temp>sum)
        {
            sum = temp;
            mark = i;//此圆柱在最底部
        }
    }
    
    long long int ans1=0;
    
    long long int max=CASE[0].s1+CASE[0].s2;//0-m中最大的总面积
    for(int i=0;i<m;i++)
    {
        long long int temp = CASE[i].s1+CASE[i].s2;
        if(temp>max)
        {
            max = temp;
            flagmax = i;
        }
    }
    
    long long int min=CASE[0].s1+CASE[0].s2;//0-m中最大的总面积
    for(int i=0;i<m;i++)
    {
        long long int temp = CASE[i].s1+CASE[i].s2;
        if(temp<min)
        {
            min = temp;
            flagmin = i;
        }
    }
    
    if(mark<m)
    {
        for(int i=0;i<m;i++)
    	{
        	ans1+=CASE[i].s2;
    	}
    	
    	ans1 += CASE[flagmax].s1;
    }
    else
    {
        if(CASE[mark].s1+CASE[mark].s2 > CASE[flagmax].s1+CASE[flagmax].s2)
        {
            for(int i=0;i<m;i++)
    		{
                if(i==flagmin)
                    continue;
        		ans1+=CASE[i].s2;
    		}
            ans1+=CASE[mark].s1 + CASE[mark].s2;
            
        }
        else
        {
            for(int i=0;i<m;i++)
    		{
        		ans1+=CASE[i].s2;
    		}
    		ans1 += CASE[flagmax].s1;
        }
    }
    
    printf("%lld\n",ans1);
    return 0;
    
}