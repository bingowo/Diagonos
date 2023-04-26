#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int a,b,n;
        scanf("%d%d%d",&a,&b,&n);
        int s[n+1];
        for(int k=0;k<n;k++)
            s[k]=0;
        s[0]=1;
        int l=1,w=0;
        for(int k=0;k<b;k++)
        {
            int jin=0;
            for(int p=0;p<n;p++)
            {
                int c=s[p];
                s[p]=(s[p]*a+jin)%10;
                jin=(c*a+jin)/10;
            }
        }
        printf("case #%d:\n",i);
        for(int d=n-1;d>=0;d--)
        printf("%d\n",s[d]);


    }
    return 0;
}
