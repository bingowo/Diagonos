#include <stdio.h>
#include <math.h>
struct Val
{
    int dig; // 数位长度
    int val; // 数字
};
Val a[1000006];
// 获得数位长度
int getDig (int val)
{
    val = abs(val);
    int ans = 0;
    while (val)
    {
        ans ++;
        val /= 10;
    }
    return ans;
}
int cmp (const Val &a , const Val &b){
    if (a.dig != b.dig)
        return a.dig > b.dig;
    return a.val < b.val;
}
int main() {
    int x,n = 0;
    while (scanf("%d",&x)!=EOF) 
    {
        a[++n].val = x;
        a[n].dig = getDig(a[n].val);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for (int i = 1 ; i <= n ; i++)
    {
        printf("%d",a[i].val);
        if (i == n) 
            printf("\n");
        else 
            printf(" ");
    }
	return 0;
}

