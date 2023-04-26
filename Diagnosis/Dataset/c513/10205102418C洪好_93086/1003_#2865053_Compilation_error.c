//#include <iostream>
//#include <algorithm>
//using namespace std;
#include<stdio.h>

typedef struct number
{
    long long num;
    int no1;
    number()
    {
        num = no1 = 0;
    }
};

int cnt1(long long n)//计算1的位数算法
{
    int cnt = 0;
    while (n)
    {
        n = n & (n - 1);
        cnt++;
    }
    return cnt;
}

bool cmp(number a, number b)
{
    if (a.no1 == b.no1) return a.num < b.num;
    return a.no1 > b.no1;
}

int main()
{
    //cout << cnt1(100);
    int t; 
    //cin >> t;
    scanf("%d",&t);
    for (int i = 0; i < t; i++)
    {
        int n; 
        //cin >> n;
        scanf("%d",&n);
        number a[10000];
        for (int j = 0; j < n; j++)
        {
            //cin >> a[j].num;
            scanf("%d",&a[j].num);
            a[j].no1 = cnt1(a[j].num);
        }
        sort(a, a + n, cmp);
        //cout << "case #" << i << ":" << endl;
        printf("case #%d:\n",i);
        for (int j = 0; j < n; j++)
        {
            //cout << a[j].num << " ";
            printf("%d",a[j].num);
        }
        //cout << endl;
        printf("\n");
    }
}