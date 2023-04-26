#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    return x<y?-1:1;
}
int main()
{
    int m;
    scanf("%d",&m);
    int a[500];
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    int n;
    scanf("%d",&n);
    int b[500];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    int temp,cnt=0;
    for(temp=0;temp<m;temp++)
    {
        for(int i=cnt;i<n;i++)
        {
            if(a[temp]==b[i])
            {
                int c=b[cnt];
                b[cnt]=b[i];
                b[i]=c;
                cnt++;
            }
        }
    }
    qsort(b+cnt,n-cnt,sizeof(int),cmp);
    printf("%d",b[0]);
    for(int i=1;i<n;i++)
    {
        printf(" %d",b[i]);
    }
    return 0;


}
