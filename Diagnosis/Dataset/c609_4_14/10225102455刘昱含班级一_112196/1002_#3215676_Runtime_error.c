#include <stdio.h>

int i;

int cnt_d2b(int n)
{
    int temp,temp1,cnt=0,j;
    if (n==0 || n==1) return 1;
    for(j= 0; n!=0; j++)
    {
        temp= n%2;
        n/=2;
        if( n == 0) break;
        temp1=n%2;
        if(temp1 !=temp) cnt++;
    }
    if (cnt == 0) return 1;
    if (j == cnt) cnt+=1;
    return cnt;
}

int main()
{
    int T, n[10],maxd;
    scanf("%d",&T);
    for(i= 0; i<T; i++)
    {
        scanf("%d",&n[i]);
    }
    n[i]= 0;
    for(i=0; n[i]; i++)
    {
       maxd= cnt_d2b(n[i]);
       printf("case #%d:\n%d\n",i,maxd);
    }
    return 0;

}
