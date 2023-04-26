#include <stdio.h>
#include<string.h>
int main()
{
    int T;
    int n;
    scanf("%d",&T);
    int s[200];
    for(int i =0 ;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        int point = 0;
        do
        {
            s[point++] = n%2;
            n = n/2;
        }
        while(n!=0);
        int pre = 1,res=1;
        while(--point >0)
        {
            if(s[point] != s[point-1])
            {
                pre ++;
            }
            else
            {
                res = pre>res?pre:res;
                pre = 1;
            }
        }
        res = pre>res?pre:res;
        printf("case #%d:\n%d\n",i,res);
    }
    return 0;

}
