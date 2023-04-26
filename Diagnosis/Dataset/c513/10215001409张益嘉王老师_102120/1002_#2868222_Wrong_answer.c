#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int fis[128],i,j;
    for(i=0;i<128;i++)
    {
        fis[i]=-1;
    }
    int t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
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


        int num=0,re=0;
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

        //printf("Test num=%d\n",num);
        ch=chu;
        for(j=0;j<len;j++,ch++)
        {
            re=(fis[*ch]*pow(num,len-1-j))+re;
            //printf("Test fis[%c]=%d   j=%d\n",*ch,fis[*ch],j);
            //printf("Test re%d=%d\n",j,re);
        }
        printf("case #%d:\n%d\n",i,re);
      



    }
    return 0;
}
