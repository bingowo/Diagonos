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
        gets(a);
        int length=strlen(a);
        for(int j=0;j<length;j++)
        {
            sum=sum+a[j];
        }
        int q;
        int cnt=0;
        for(q=0;sum!=0;q++)
        {
            b[q]=sum%2;
            sum=sum/2;
            if(b[q]==1)
                cnt++;
        }
        q=q+1;
        for(int c=cnt;c>1&&q>0&&cnt>0;c--)
        {
            if(q%c==0&&cnt%c==0)
                {
                    q=q/c;
                    cnt=cnt/c;
                }
        }
        printf("%d/%d\n",cnt,q);
    }
    return 0;
}
