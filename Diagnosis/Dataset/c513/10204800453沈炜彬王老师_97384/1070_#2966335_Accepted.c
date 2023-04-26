#include <stdio.h>

int
main()
{
    int n;
    int s00[21],s01[21],s1[21];
    int res;
    
    s00[1] = 1;
    s01[1] = 0;
    s1[1] = 1;
    s00[2] = 1;
    s01[2] = 1;
    s1[2] = 2;
    for (int i=3; i<21; i++)
    {
        s00[i] = s00[i-1] + s01[i-1];
        s01[i] = s1[i-1];
        s1[i] = s00[i-1] + s1[i-1];
    }
    
    while (scanf("%d",&n),n!=-1)
    {
        res = s00[n] + s01[n] + s1[n];
        printf("%d\n",res);
    }
    
    return 0;
}