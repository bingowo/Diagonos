#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


char s[2000][37];

int print_row(int point,int m,int num)//打印下一行并返回下一个将打印的字符串
{
    int p1 = point;
    int space =0;
    int all =strlen(s[point]);
    point++;
    while(point < num&&all+1+strlen(s[point])<= m)
    {
        all+=1+strlen(s[point]);
        point++;
    }
    space = m-all + point-p1-1;

    if(point == num)
    {
        for(int i =p1;i<point;i++)
        {
            printf("%s ",s[i]);
        }
        printf("\n");
    }
    else
    {
     int n_space = point - p1-1;
     int num_space = space/n_space;
     int q = space%n_space;
     for(int i =0;i<n_space ;i++)
     {
         if(i==n_space-q)num_space++;
         printf("%s",s[p1+i]);
         for(int j =0;j<num_space;j++)
         {
            printf(" ");
         }
     }
     printf("%s\n",s[point-1]);
    }
    return point;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        int m;
        scanf("%d",&m);
        getchar();
        char text[40];
        int point = 0;
        char c;
        int num =0;
        int space =0;
        int flag =0;
        while((c = getchar())!='\n')
        {
            if(c==' ')
            {
                space++;
                if(flag)
                {
                text[point] ='\0';
                point = 0;
                strcpy(s[num],text);
                num++;
                flag = 0;
                }
            }
            else
            {
                flag =1;
                text[point++] = c;
            }
        }
         text[point] ='\0';
        strcpy(s[num++],text);
        int p1 = 0;
        printf("case #%d:\n",i);
        while(p1!=num)
        {
            p1 = print_row(p1,m,num);
        }



    }
}

