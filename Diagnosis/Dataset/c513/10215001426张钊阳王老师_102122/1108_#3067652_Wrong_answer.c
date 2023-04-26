#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int z=0;z<T;z++)
    {
        int a,b;
        scanf("%d %d",&b,&a);

        int left[100];//left数组用来储存余数 每次新的余数都遍历之前的余数 对比直到有相同的

        int s[150]={0};//s是作为数组来储存商的值

        s[0]=b*10/a;
        left[0]=b*10-s[0]*a;

        //printf("%d",left[0]);

        int i=0;
        int cnt=0,flag=0,start,over;

        while(left[i]!=0)
        {
            i++;
            cnt++;
            s[i]=left[i-1]*10/a;
            int atemp=10*left[i-1];
            left[i]=atemp-s[i]*a;

            printf("%d %d\n",i,cnt);
            for(int i=0;i<=cnt;i++) printf("%d\n",left[i]);

            for(int j=0;j<cnt;j++)
            {
                if(left[i]==left[j])
                {
                    flag=1;//说明是循环小数
                    start=j;
                    over=i;
                    break;
                }
            }
            if(flag==1) break;
        }

        printf("case #%d:\n",z);

        printf("0.");
        if(flag==1)
        {
            for(int i=0;i<=cnt;i++)
            {
                printf("%d",s[i]);
            }
            printf("\n");
            printf("%d-%d\n",start+2,over+1);
        }


        else if(flag==0)
        {
            for(int i=0;i<=cnt;i++)
            {
                printf("%d",s[i]);
            }
            printf("\n");
        }


    }
    return 0;
}
