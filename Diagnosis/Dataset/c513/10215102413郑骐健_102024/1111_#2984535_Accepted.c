#define _CRT_SECURE_NO_WARNINGS 1
/* strchr example */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
//计算点的y坐标
 int cal(int a[4], int x)
{
	 int y = 0;
	 for (int i = 0;i < 4;i++)
	 {
		 y += (int)pow(x, i) * a[i];
	 }
	 if (y > 20 || y < -20)return 21;
	 else return y;
}
int main()
{
    int flag = 0;
    int flag2 =0;
    char a;
    while((a=getchar())!=EOF)
        {
            if(flag)
            {
                int coe1[4] = {0,0,0,0};//次数从小到大,
                char mid[20]={0};
                scanf("%s",mid);
                char *p=mid;
                while(*p)
                {
                    int sign=1,coe=0,dim=0;
                    if(*p=='-')
                    {
                        sign = -1;
                        p++;
                    }
                    else if(*p=='+')p++;
                    while(isdigit(*p))
                    {
                        coe=coe*10+*p-'0';
                        p++;
                    }
                    if(*p=='x')
                    {
                        coe=(coe>0)?coe:1;
                        p++;
                        if(*p=='^')
                        {
                            p++;
                            dim=*p-'0';
                            p++;
                        }
                        else dim=1;
                    }
                    coe1[dim]=sign*coe;
                }
                //画图
                int res[41];
                for(int i =-20;i<=20;i++)
                {
                    res[i+20] = cal(coe1,i);
                }
                char res2[41][41]={0};
                for(int row=0;row<41;row++)
                {
                    for(int col=0;col<41;col++)
                    {
                        res2[row][col] = '.';
                    }
                }
                for(int col=0;col<40;col++)res2[20][col]='-';res2[20][40]='>';
                for(int row=40;row>=0;row--)res2[row][20]='|';res2[0][20] = '^';
                res2[20][20]='+';
                for(int z=0;z<41;z++)
                {
                    if(res[z]==21)continue;
                    else res2[res[z]*(-1)+20][z] = '*';
                }
                for(int f=0;f<41;f++)
                {
                    for(int h=0;h<41;h++)
                    {
                        printf("%c",res2[f][h]);
                    }
                    printf("\n");
                }
                flag = 0;
            }
            else if(a==')')
            {
                flag = 1;
                if(flag2)printf("\n");
                else flag2 = 1;
            }
        }

	return 0;
}
