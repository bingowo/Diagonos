#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int n;
    char a[120];
    int b[100];
    int sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        gets(a);
        int length=strlen(a);
        for(int j=0;j<length;j++)
        {
            unsigned char c=a[i];
            while(c>0)
            {
                if(c&1)
                    cnt++;
                c>>=1;
            }
        }
        int m=8*length;
        for(int q=cnt;q>1&&m>0&&cnt>0;q--)
        {
            if(m%q==0&&cnt%q==0)
                {
                    m=m/q;
                    cnt=cnt/q;
                }
        }
        printf("%d/%d\n",cnt,m);
    }
    return 0;
}
