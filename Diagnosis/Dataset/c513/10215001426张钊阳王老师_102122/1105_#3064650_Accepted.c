#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w,h;//w是如图像宽度 h是图像高度
    scanf("%d %d",&w,&h);
    int trans(int *s,int  l);
    int s[100][100];//做一个二维数组保存数字表

    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
    {
        scanf("%d",&s[i][j]);
    }
    int ans[100][100];

    for(int i=1;i<h-1;i++)//h是行数  w是列数
    {
        for(int j=1;j<w-1;j++)
        {
            int x=s[i][j];
            int square[8]={0};//用于保存围绕在这个数周围的八个数
            square[0]=s[i-1][j-1];square[1]=s[i-1][j];square[2]=s[i-1][j+1];square[3]=s[i][j+1];
            square[4]=s[i+1][j+1];square[5]=s[i+1][j];square[6]=s[i+1][j-1];square[7]=s[i][j-1];

            //if(i==1&&j==1) {for(int k=0;k<8;k++) printf("%d",square[k]);printf("\n");}

            int stao[8]={0};

            for(int t=0;t<8;t++)
            {
                if(square[t]>=x) stao[t]=1;
                else if(square[t]<x) stao[t]=0;
            }

           //if(i==1&&j==1) {for(int k=0;k<8;k++) printf("%d",stao[k]);printf("\n");}

            int temp;//用temp来储存临时的八个结果 最后取最小值
            int min=100000;


            for(int m=0;m<8;m++) //遍历8个数作为起点
            {
                int ss[8]={0};
                int cnt=0;
                int z=0;
                for(z=0;z+m<8;z++)
                {
                    ss[z]=stao[z+m];
                    cnt++;
                }
                for(int t=0;t<8-cnt;t++)
                {
                    ss[z]=stao[t];
                    z++;
                }
                /*if(i==1&&j==1)
                    {
                    printf("%d ",cnt);
                    for(int kk=0;kk<8;kk++)
                    printf("%d",ss[kk]);
                    printf("\n");
                    }*/

                temp=trans(ss,8);
                if(temp<min) min=temp;
                else ;
            }//于是得到一个代表二进制的数组
            //这个循环结束后能够得到min
            ans[i][j]=min;
        }
    }
    for(int i=1;i<h-1;i++)
        for(int j=1;j<w-1;j++)
    {
        if(j==w-2)
        {
            printf("%d\n",ans[i][j]);
        }
        else
        {
            printf("%d ",ans[i][j]);
        }

    }
    return 0;
}

int trans(int *s,int  l)
{
    int ans=0;
    for(int i=0;i<l;i++)
    {
        ans=ans*2+s[i];
    }
    return ans;
}
