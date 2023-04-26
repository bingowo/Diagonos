#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*对于C、C++语言，如果你需要的话，可以用
sscanf("%x")
从char*变量中得到其所表达的十六进制数字。*/

void time_change(char a[])
{
    int time,hour,min,sec;
    sscanf(a,"%d",&time);
    hour = time / 10000 + 8;
    min = (time % 10000) / 100;
    sec = (time % 10000) % 100;
    printf("%d:%d:%d\n",hour,min,sec);
    return;
}

int main()
{
    char gps[100];
    char valid_gps[100];
    while(scanf("%s",gps))
    {
        int i,num;
        if(strcmp(gps,"END") == 0)
            break;
        char temp[100];
        char gps1[13][150];
        char*pt1,*pt2,*pt3;
        strcpy(temp,gps);
        pt1 = pt2 = temp;
        for(i = 0;i < 12;i++)
        {
            pt1 = strstr(pt1,",");
            *pt1 = '\0';
            strcpy(gps1[i],pt2);
            pt1 = pt2 = pt1 + 1;
        }
        strcpy(gps1[12],pt1);
        int flag1 = 0,flag2 = 0,flag3 = 0;
        //作为是否满足三个条件的标志

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
            time_change(gps1[1]);
    }
    return 0;
}