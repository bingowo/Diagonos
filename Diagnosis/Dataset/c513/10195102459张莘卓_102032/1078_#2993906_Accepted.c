#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int v;
    int fz;  //分子
    int fm;  //分母
}Number;

#define N 1002
#define INF 1000009
int min(int a, int b) {return a<b?a:b;}
int gcd(int a, int b) {
    while(b){int t=b; b=a%b; a=t;}
    return a;
}
int cmp(const void*a, const void*b)
{return *(int*)a - *(int*)b;}

void full_final(Number s, Number *a, int l_pos, int r_pos, int dir){
    int arr[N];
    int t = 0;
    for (int i = l_pos; i != r_pos + dir; i += dir) {
        arr[t] = a[i].v;
        t++;
    }
    qsort(arr, t, sizeof(int), cmp);
    int cnt;
    for (int i = 1; i < t; i++) {
        int c = (arr[i] - arr[i - 1]) * i;
        if (s.v < c) {
            cnt = i;
            break;
        }
        else {
            s.v -= c;
        }
    }
       int fz = s.v * s.fm + s.fz;
        int fm = s.fm * cnt;
        int high_zs = arr[cnt - 1] + fz / fm;
        fz %= fm;
        int g = gcd(fz, fm);
        fz /= g;
        fm /= g;
        for (int i = l_pos; i != r_pos + dir; i += dir)
        {
            if (a[i].v <= high_zs) {
                a[i].v = high_zs;
                a[i].fz = fz;
                a[i].fm = fm;
            }
        }
    }


Number full_sub(Number s, Number *a, int l_pos, int r_pos, int dir) {
    int t_pos = l_pos;
    while (t_pos != r_pos && a[t_pos + dir].v <= a[t_pos].v) t_pos += dir;
    while (t_pos != r_pos && a[t_pos + dir].v >= a[t_pos].v) t_pos += dir;  //找坑

    int high = min(a[l_pos].v, a[t_pos].v);
    int v = 0;
    for (int i = l_pos; i != t_pos + dir; i += dir) {  // 填坑需要的水量
        if (a[i].v < high) v += high - a[i].v;
    }
    if (s.v >= v) {  //能填满坑
        for (int i = l_pos; i != t_pos + dir; i += dir) {
            if (a[i].v < high) a[i].v = high;
        }
        s.v -= v;
        return s;
    }
    full_final(s, a, l_pos, t_pos, dir);
    Number ret;
    ret.v = 0;
    ret.fz = 0;
    ret.fm = 1;
    return ret;
}


void full(Number s, Number *a, int l_pos, int r_pos, int dir)
{
   while (s.v > 0 || s.fz > 0)
       s = full_sub(s, a, l_pos, r_pos, dir);
}




int water_lowest(Number *a,int s,int base,int lpos,int rpos)
{
    int width = rpos - lpos - 1;
    int high = min(a[lpos].v, a[rpos].v) - base;
    int v = width * high;
    if (s >= v){
        for (int i = lpos + 1; i <= rpos - 1; i++)
               a[i].v = base + high;
        return s - v;
    }
    else //水量s 不能放满当前凹槽，则计算能放到的高度
    {
        int w_high = base + s / width;
        int r = s % width;
        int fz = r, fm = width;
        int g = gcd(fz, fm);
        fz /= g;  fm /= g;
        for (int i = lpos + 1; i <= rpos - 1; i++)  {
            a[i].v = w_high; a[i].fz = fz; a[i].fm = fm;
        }
        return 0;
    }
}


int water_sub(Number *a, int s, int n, int pos)
 {
    int base = a[pos].v;
    int l_pos, r_pos;
    int l_v = 0, r_v = 0;
    for (int i = pos - 1; i >= 0; i--) {
        l_pos = i;
        if (a[i].v > base) break;
        l_v += base - a[i].v;
    }
    for (int i = pos + 1; i <= n + 1; i++) {
        r_pos = i;
        if (a[i].v > base) break;
        r_v += base - a[i].v;
    }
    int v=l_v+r_v;
    
    if(v==0) return water_lowest(a,s,base,l_pos,r_pos);
    else if (v <= s)
    {
            for (int i = l_pos + 1; i <= r_pos - 1; i++)
            {
                a[i].v = base;
            }
            return s - v;
    }else {
        Number half;
        half.v = s / 2;
        half.fz = s % 2;
        half.fm = 2;
        if (half.v >= l_v) //一半水量填满左边坑,剩余水量填右边部分坑
        {
                for (int i = l_pos + 1; i <= pos - 1; i++) {
                    a[i].v = base;
                }
                half.v = s - l_v;   half.fz = 0;  half.fm = 1;
                full(half, a, pos, r_pos, 1);    //剩余水量填右边部分坑
                return 0;
        }
        if (half.v >= r_v) //一半水量填满右边,剩余水量填左边部分坑
        {
                for (int i = pos + 1; i <= r_pos - 1; i++) {
                    a[i].v = base;
                }
                half.v = s - r_v;    half.fz = 0;    half.fm = 1;
                full(half, a, pos, l_pos, -1);   //剩余水量填左边部分坑
                return 0;
         }
        full(half, a, pos, l_pos, -1);   //一半水量填左边部分坑
        full(half, a, pos, r_pos, 1);    //一半水量填右边部分坑
        return 0;
    }
}

void pour_water(Number *a,int s, int n, int p)
{
      while (s > 0)
            s = water_sub(a,s,n, p);
}




int main()
{
    int n, s, pos;
    Number a[N];
    scanf("%d%d%d", &n, &s, &pos);
    a[0].v = INF;a[n + 1].v = INF;
    a[0].fz=a[n+1].fz=0;
    a[0].fm=a[n+1].fm=1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].v);
        a[i].fz = 0;a[i].fm = 1;
    }

    pour_water(a, s, n, pos);

    for (int i = 1; i <= n; i++)
    {
        if (a[i].v == 0 && a[i].fz > 0) {
            printf("%d/%d", a[i].fz, a[i].fm);
        }
        else
        {
            printf("%d", a[i].v);
            if (a[i].fz > 0)
                printf("+%d/%d", a[i].fz, a[i].fm);
        }
        printf("%c",(i==n) ? '\n':' ');
    }
    return 0;
}
