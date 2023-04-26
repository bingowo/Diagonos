#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long poww(int x,int y)
{
    int i=y;
    long long r=1;
    for(;i>0;i--)
    {
        r*=x;
    }
    return r;

}

int main()
{
    int t,k;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        int fis[128],i,j;
        for(i=0;i<128;i++)
        {
            fis[i]=-1;
        }
        char chu[65];
        int len,co=1;
        scanf("%s",chu);

        char*ch=chu;
        //printf("Test ch=%s",ch);

        len=strlen(chu);
        /*for(int k=0;k<len;k++)
        {
            int mid=*ch;
            printf("fen test =%c=mid=%d   ",*ch,mid);
            ch++;
        }*/


        int num=0;
        long long re=0;
        for(j=0;j<len;j++,ch++)
        {
            if(fis[*ch]!=-1) continue;
            else
                {
                    if(num==1) {fis[*ch]=0;num++;}
                    else
                    {
                    fis[*ch]=co;
                    co++;
                    num++;
                    }
                }

        }
        //printf("Test co=%d\n",co);
        if(num==1) num=2;
        //printf("Test num=%d\n",num);

        ch=chu;
        for(j=0;j<len;j++,ch++)
        {
            re=(fis[*ch]*poww(num,len-1-j))+re;
            //printf("Test fis[%c]=%d   j=%d\n",*ch,fis[*ch],j);
            //printf("Test re%d=%lld\n",j,re);
        }
        printf("case #%d:\n%lld\n",k,re);




    }
    return 0;
}
