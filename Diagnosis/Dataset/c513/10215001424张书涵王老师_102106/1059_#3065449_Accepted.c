#include <stdio.h>
#include <stdlib.h>

void lowest(int *a,int *b,int *c,int n)
{
    int i,small=a[0],p=0;
    for(i=1;i<n;i++)
    {
        if(a[i]<small)
            small=a[i];
    }
    b[1]=small;
    for(i=0;i<n;i++)
    {
        if(a[i]==small)
        {
            b[0]++;
            c[p++]=i;
        }
    }
}

int both(int a,int b)
{
    int devisor,devidend,remainder,quotient;
    if(a>b)
    {
        devidend=a;
        devisor=b;
    }
    else
    {
        devidend=b;
        devisor=a;
    }
    for(;remainder!=0;)
    {
        remainder=devidend%devisor;
        quotient=devidend/devisor;
        if(remainder==0)
            return devisor;
        devidend=devisor;
        devisor=remainder;
    }
}

int main()
{
    int width,total_rain;
    scanf("%d %d",&width,&total_rain);
    int a[1001]={0},i;
    for(i=0;i<width;i++)
        scanf("%d",&a[i]);
    int b[2]={0,0};
    for(;total_rain>0;)
    {
        int c[1001];
        for(i=0;i<1001;i++)
            c[i]=-1;
        b[0]=0;//b[0]表示最低点的个数，b[1]表示最低点的高度
        lowest(a,b,c,width);
        if(total_rain<b[0])
        {
            if(b[1]==0)
            {
                printf("%d/%d",total_rain,b[0]);
                return 0;
            }
            else
            {
                int together;
                together=both(total_rain,b[0]);
                total_rain=total_rain/together;
                b[0]=b[0]/together;
                printf("%d+%d/%d",b[1],total_rain,b[0]);
                return 0;
            }
        }
        else
        {
            int p;
            for(p=0;c[p]!=-1&&p<1001;p++)
            {
                a[c[p]]++;
                total_rain--;
            }
        b[1]++;
        }
    }
    printf("%d",b[1]);
}