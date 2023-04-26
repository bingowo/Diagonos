#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return (*(int*)a)-(*(int*)b);
}

int G(int x,int y)
{
    int b = x > y ? x : y;
    int s = x > y ? y : x;
    while(b%s)
    {
        int res = b%s;
        b = s;
        s = res;
    }
    return s;
}

int main()
{
    int n,r;
    scanf("%d %d",&n,&r);
    int *land = (int*)malloc(sizeof(int)*n);

    for(int i = 0;i < n;i++)
        scanf("%d",&land[i]);

    qsort(land,n,sizeof(int),cmp);
    int max = land[n-1];
    int cnt = 0;
    int fz = 0,fm = 0,num = 0;
    while(r > 0)
    {
        int min = land[0];
        int h = 0;
        if(cnt < n)
        {
            cnt = 0;
            for(int i = 0;i < n;i++)
            {
                if(land[i] == min) cnt++;
                else
                {
                    h = (land[i]-min)*cnt;
                    int res = land[i];
                    for(int j = 0;j < i;j++) land[j]  = res;
                    break;
                }
            }
        }
        if(h == 0) //雨水已经高出所有地面
        {
            fz = r/G(r,n);
            fm = n/G(r,n);
            if(fz >= fm)
            {
                int k = fz/fm;
                fz = fz-(k*fm);
                max += k;
            }
            num = max;
            break;
        }
        else if(h > 0 && r <= h)   //雨水没有高出但是也已经不足
        {
            int rate = r/cnt;
            min += rate;
            r -= cnt*rate;
            if(r != 0)
            {
                fz = r/G(r,cnt);
                fm = cnt/G(r,cnt);
            }
            if(fz >= fm && fm != 0)
            {
                int k = fz/fm;
                fz = fz-(k*fm);
                min += k;
            }
            num = min;
            break;
        }
        else              //雨水充沛且地面还能装水
        {
            r -= h;
        }
    }
    printf("%d",num);
    if(fz != 0)
    {
        printf("+%d/%d",fz,fm);
    }
    free(land);

    return 0;
}