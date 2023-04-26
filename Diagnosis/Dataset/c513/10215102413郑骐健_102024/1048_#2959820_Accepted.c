#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define  num 10007





int main()
{
//提取各项系数，从低到高存入数组
    char c;
     int k1[100] = {0};
        int k2[100] = {0};
        int flag = 1;
        int sqr =0;
        int co = 0;
        char last =0;
    int *p = k1;
    int max =0;
    int flag_s = 0;
    while((c = getchar())!=EOF)
    {
       if(c=='\n')//计算并输出
       {
           p[sqr] = co*flag;
           int res[200] ={0};
           for(int i=0;i<60;i++)
           {
               for(int z =0;z<60;z++ )
               {
                   res[i+z] += k1[i]*k2[z];
               }
           }
           for(int point = 120;point >=0;point--)
           {
               if(res[point]==0)continue;
               else printf("%d ",res[point]);
           }
           printf("\n");


           p=k1;
           memset(k1,0,sizeof(k1));
           memset(k2,0,sizeof(k2));
           flag = 1;
           sqr = 0;
           co = 0;
           flag_s =0;
           continue;
       }





            switch (c)
            {
            case '+':
                p[sqr] = flag*co;
                flag = 1;
                sqr = 0;
                co = 0;
                flag_s = 0;
                break;
            case '-':
                if(last !=0)p[sqr] = flag*co;
                flag = -1;
                sqr = 0;
                co=0;
                flag_s =0;
                break;
            case 'x':
                sqr = 1;
                if(co == 0)co = 1;
                break;
            case ' ':
                p[sqr] = flag*co;
                p = k2;
                co =0;
                sqr =0;
                flag =1;
                flag_s = 0;
                break;
            case '^':
            sqr =0;
            flag_s = 1;
            break;
            default://常数的情况
            if(flag_s)sqr =sqr*10 + c-'0';
            else if(last ==0||last =='+' ||last == '-'||last ==' ')co = c-'0';
            else if(last >='0'&&last<='9')co = co*10+c-'0';
            }
            last = c;
        }

    return 0;
}
