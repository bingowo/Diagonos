#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Rto10(char a[], int r)
{
	int len, i, num;
	int sum = 0;
	len = strlen(a);
	for (i = 0; i < len; i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
			num = a[i] - '0';
		else if (a[i] >= 'A' && a[i] <= 'F')
			num = a[i] - 'A' + 10;
		sum = sum * r + num;
	}
	return sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char a[100];
        int b[128]={0};
        char c[100]={0};
        scanf("%s",a);
        int len;
        len=strlen(a);
        int ans=0,temp=1,flag=0;
        int R=0;
        for(int i=0;i<128;i++)
            b[i]=-1;
        b[a[0]]=1;
        c[0]='1';
        for(int i=1;i<len;i++)
        {
            if( b[a[i]]==-1)
            {
                if(flag==0)
                {
                    b[a[i]]=0;
                    flag=1;
                }
                else
                {
                    temp++;
                    b[a[i]]=temp;
                }
            }
            if(temp<10)
                c[i]=b[a[i]]+'0';
            else
                c[i]=b[a[i]]-10+'A';
        }
        R=temp==1?2:temp+1;
        ans=Rto10(c,R);
        printf("case #%d:\n%d\n",i,ans);
    }
    return 0;
}
