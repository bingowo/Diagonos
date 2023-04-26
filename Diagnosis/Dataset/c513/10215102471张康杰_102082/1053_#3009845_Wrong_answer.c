#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*对于C、C++语言，如果你需要的话，可以用
sscanf("%x")
从char*变量中得到其所表达的十六进制数字。*/

void time_change(char a[],char b[])
{
    int time,hour,min,sec;
    int cnt = 0,base = 100000,cnt1 = 0;
    sscanf(a,"%d",&time);
    time += 80000;
    if(time < 100000)
    {
        b[cnt++] = '0';
        base /= 10;
        cnt1++;
    }
    else if(time > 240000)
    while(base != 0)
    {
        b[cnt++] = time / base + '0';
        cnt1++;
        time %= base;
        base /= 10;
        if(cnt1 == 2)
        {
            b[cnt++] = ':';
            cnt1 = 0;
        }
    }
    b[cnt - 1] = '\0';
    if(b[0] == '2' && b[1] == '4')
    {
        b[0] = b[1] = '0';
    };
}

int main()
{
    char gps[200];
    char valid_gps[100];
    char time[10];
    while(scanf("%s",gps) == 1)
    {
        int i,num;
        int flag1 = 0,flag2 = 0,flag3 = 0,flag4 = 0;
        //作为是否满足三个条件的标志
        if(strcmp(gps,"END") == 0)
            break;
        char temp[200];
        char gps1[13][15];
        char*pt1,*pt2,*pt3;
        strcpy(temp,gps);
        pt1 = pt2 = temp;
        for(i = 0;i < 12;i++)
        {
            pt1 = strstr(pt1,",");
            *pt1 = '\0';
            strcpy(gps1[i],pt2);
            pt1 = pt2 = pt1 + 1;
            if(strcmp(gps1[0],"$GPRMC") == 0)
                flag1 = 1;
            else
            {
                flag4 = 1;
                break;
            }
        }
        if(flag4)
        {
            flag4 = 0;
            continue;
        }
        strcpy(gps1[12],pt1);
        if(strcmp(gps1[0],"$GPRMC") == 0)
            flag1 = 1;
        else
            continue;
        if(strcmp(gps1[2],"A") == 0)
            flag2 = 1;
        else
            continue;
        num = gps[2] ^ gps[1];
        for(i = 3;i < strlen(gps);i++)
        {
            if(gps[i] == '*')
                break;
            else
            {
                num ^= gps[i];
            }
        }
        num %= 65536;
        int num1;
        pt3 = strchr(gps1[12],'*') + 1;
        sscanf(pt3,"%x",&num1);
        if(num == num1)
            flag3 = 1;
        if(flag1 && flag2 && flag3)
            time_change(gps1[1],time);
    }
    printf("%s\n",time);
    return 0;
}