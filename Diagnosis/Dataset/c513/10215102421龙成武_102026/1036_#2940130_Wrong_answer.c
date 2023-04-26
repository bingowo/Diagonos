#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
unsigned long long hash[64];
typedef struct
{
    long long x, y;
    unsigned long long d;
}POINT;
unsigned long long pow2(int j);
void gethash();
unsigned long long myullabs(long long a, long long b);
int compar(const void* p1, const void* p2);
int main()
{
    int i, j, n;
    unsigned long long ans1, ans2, eachd;
    scanf("%d", &n);
    POINT* point = (POINT*)malloc(n * sizeof(POINT));
    for (i = 0;i < n;i++)
    {
        scanf("%lld %lld", &point[i].x, &point[i].y);
        point[i].d = (unsigned long long)llabs(point[i].x) + (unsigned long long)llabs(point[i].y);
        //printf("%llu",point[i].d);
    }
    qsort(point, n, sizeof(POINT), compar);
    ans2 = 0;
    ans1 = myullabs(point[0].x, point[1].x) + myullabs(point[0].y, point[1].y);     //考虑到在都为负数的情况下，得到的结果会超过unsigned long long的范围，
    //但是对后面那个循环的结果，没有影响，因为这种情况必然是两个坐标的曼哈顿距离为偶数，所以……
    //等等，真的没有影响吗，还是有的吧，实在是oj在极端数据之后就没给别的坐标了，但凡给了，那个0和偶数的条件是不一样的
    //所以不仅仅是在打印ans1时要判断，在for循环里也要判断才是
    gethash();
    for (i = 0;i < n - 1;i++)
    {
        eachd = myullabs(point[i].x, point[i + 1].x) + myullabs(point[i].y, point[i + 1].y);
        if (eachd == 0 && myullabs(point[i].x, point[i + 1].x) != pow2(62))     //确保他不是因为溢出而变成0的
            continue;
        else if (eachd % 2 == 0)      //如果是偶数的话，铁定到不了
        {
            //ans2=0;，只有在第一次才是，但既然只有第一次才需要，那何必写在循环体里
            break;
        }
        else
        {
            for (j = 0;j < 64;j++)
            {
                if (eachd <= hash[j])
                    break;
            }
            ans2 += j + 1;
        }
    }
    if (myullabs(point[0].x, point[1].x) == pow2(62) && ans1 == 0)
        printf("18446744073709551616\n%11u", ans2);                     //直接以字符串的形式打印结果
    else
        printf("%llu\n%llu", ans1, ans2);             //格式控制符要是写了%d，就会按int去读取了
    return 0;
}
int compar(const void* p1, const void* p2)
{
    int flag = 0;
    POINT* a = (POINT*)p1, * b = (POINT*)p2;
    if (a->d > b->d)
        flag = -1;
    else if (a->d < b->d)
        flag = 1;
    else
    {
        if (a->x < b->x)
            flag = -1;
        else if (a->x > b->x)
            flag = 1;
        else
        {
            if (a->y < b->y)
                flag = -1;
            else
                flag = 1;
        }
    }
    return flag;
}
unsigned long long pow2(int j)
{
    unsigned long long res = 2;
    while (j--)
        res = res * 2;
    return res;
}
void gethash()
{
    int i;
    for (i = 0;i < 64;i++)
    {
        hash[i] = pow2(i) - 1;
    }
}
unsigned long long myullabs(long long a, long long b)
{
    unsigned long long res;
    long long temp;
    //res = (unsigned long long)a - (unsigned long long)b;              把一个负数赋值给unsigned不是一个好习惯，同样，把一个负数当作unsigned来计算也不是好习惯
    //还是加if语句来规避掉会比较好
    if (a > b)
    {
        res = a - b;
    }
    else if (a <= b)
    {
        res = b - a;
    }
    return res;
}