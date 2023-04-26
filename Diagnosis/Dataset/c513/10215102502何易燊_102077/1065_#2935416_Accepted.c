#include <stdio.h>

int main()
{
    int a,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    int p[21] = {1,0,1,1};
    int q[21] = {0,1,1,2};
    int ans_a = 1, ans_x = 0;
    int loc_a, loc_x;
    for (int i=3;i<=n-1;i++)
    {
        ans_a += p[i-3];
        ans_x += q[i-3];
        if (i==x) loc_a = ans_a, loc_x = ans_x;
        p[i+1] = p[i]+p[i-1];
        q[i+1] = q[i]+q[i-1];
    }
    int hytrodren = (m-a*ans_a)/ans_x;
    printf("%d\n",(x>2)?(a*loc_a+hytrodren*loc_x):a);
    return 0;
}