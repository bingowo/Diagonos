#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int s[25];
void reverse(int*p,int n)
{
    for(int i = 0;i<n-1;i++)
    {
        for(int z =0;z<n-1-i;z++)
        {
         int a;
         a = *(p+z);
         *(p+z)=*(p+z+1);
         *(p+1+z) = a;
        }
    }
}
int main()
{
    memset(s,0,sizeof(int )*25);
    s[0] = 2;
    int point =1;
    for(int n = 3;n<30000;n++)
    {
        int judge = 1;
        for (int z =0;z<point;z++)
        {
            if(n%s[z] == 0)
            {
                judge = 0;
                break;
            }
        }
        if(judge) s[point++] = n;
            if(point == 25) break;
    }//储存素数
    /*for(int q = 0;q<25;q++)
    {
        printf("%lld ",s[q]);
    }*/
    int quiz;
    scanf("%d",&quiz);
    for(int i = 0;i<quiz;i++)
    {
        char p [90];
        int a[30];
        int b[30];
         memset(a,0,sizeof(int )*30);
         memset(b,0,sizeof(int )*30);
        int length_a =0 ;
        int length_b = 0;
        scanf("%s",p);
          int num =0;
        for(int n = 0;n<strlen(p); n++)
        {

            if(p[n]!=',')
            {
                num = num*10+p[n] - '0';
            }
             if(p[n]==','||n==strlen(p)-1)
            {

                a[length_a++] = num;
                num = 0;
            }
        }

        scanf("%s",p);
         for(int n = 0;n<strlen(p); n++)
        {

            if(p[n]!=',')
            {
                num = num*10+p[n] - '0';
            }
             if(p[n]==','||n==strlen(p)-1)
            {

                b[length_b++] = num;
                num = 0;
            }
        }//数组右边为低位，左边为高位
        //将数组a,b反转
        reverse(a,length_a);
        reverse(b,length_b);
        int length = (length_a > length_b)?length_a:length_b;
        for(int q = 0;q<length;q++)
        {
            a[q]+=b[q];
            if(!(a[q]<s[q]))
            {
                    a[q] -=s[q];
                    a[q+1]+=1;
            }

        }
        if(a[length]==1)length+=1;
        printf("case #%d:\n",i);
        for(int o = length-1;o> 0;o--)

        {
            printf("%d,",a[o]);
        }
        printf("%d\n",a[0]);
    }

    return 0;
}
