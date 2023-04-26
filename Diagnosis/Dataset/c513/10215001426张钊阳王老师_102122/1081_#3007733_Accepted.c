#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m;
    scanf("%d",&m);
    for(int z=0;z<m;z++)
    {
        int a,n;
        scanf("%d %d",&a,&n);

        int s[100];
        for(int z=0;z<100;z++) s[z]=-1;
        if(n==0)  {printf("case #%d:\n",z);printf("1");printf("\n");continue;}
        s[0]=a;//最后printf答案的时候倒序输出即可
        for(int j=1;j<n;j++)//j表示乘多少次a
        {
            int i=0;
            while(s[i]!=-1)
            {
                s[i]*=a;
                i++;
            }
            i=0;
            while(s[i]!=-1)
            {
                if(s[i]>=10)
                {
                    int temp;
                    temp=s[i]/10;
                    s[i]=s[i]%10;
                    if(s[i+1]==-1) s[i+1]+=temp+1;
                    else s[i+1]+=temp;
                }
                i++;
            }
        }


        printf("case #%d:\n",z);

        int cnt=0;
        int i=99;
        while(s[i]==-1) {cnt++;i--;}
        for(int z=100-cnt-1;z>=0;z--)
            printf("%d",s[z]);
        printf("\n");
    }
    return 0;
}
