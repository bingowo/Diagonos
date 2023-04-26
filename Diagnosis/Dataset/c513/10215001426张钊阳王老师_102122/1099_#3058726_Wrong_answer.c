#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct morsealpha{
    char s[6];
};
struct morsenumber{
    char s[6];
};

int main()
{
    int T;
    scanf("%d",&T);

    struct morsealpha lag0[26];//用一个结构体数组存代表字母的摩尔斯电码
    for(int i=0;i<26;i++)
    {
        memset(lag0[i].s,'\0',6);
    }
    struct morsenumber lag1[10];
    for(int i=0;i<10;i++)
    {
        memset(lag1[i].s,'\0',6);
    }
    strcpy(lag0[0].s,".-");
    strcpy(lag0[1].s,"-...");
    strcpy(lag0[2].s,"-.-.");
    strcpy(lag0[3].s,"-..");
    strcpy(lag0[4].s,".");
    strcpy(lag0[5].s,"..-.");
    strcpy(lag0[6].s,"--.");
    strcpy(lag0[7].s,"....");
    strcpy(lag0[8].s,"..");
    strcpy(lag0[9].s,".---");
    strcpy(lag0[10].s,"-.-");
    strcpy(lag0[11].s,".-..");
    strcpy(lag0[12].s,"--");
    strcpy(lag0[13].s,"-.");
    strcpy(lag0[14].s,"---");
    strcpy(lag0[15].s,".--.");
    strcpy(lag0[16].s,"--.-");
    strcpy(lag0[17].s,".-.");
    strcpy(lag0[18].s,"...");
    strcpy(lag0[19].s,"-");
    strcpy(lag0[20].s,"..-");
    strcpy(lag0[21].s,"...-");
    strcpy(lag0[22].s,".--");
    strcpy(lag0[23].s,"-..-");
    strcpy(lag0[24].s,"-.--");
    strcpy(lag0[25].s,"--..");
    strcpy(lag1[0].s,"-----");
    strcpy(lag1[1].s,".----");
    strcpy(lag1[2].s,"..---");
    strcpy(lag1[3].s,"...--");
    strcpy(lag1[4].s,"....-");
    strcpy(lag1[5].s,".....");
    strcpy(lag1[6].s,"-....");
    strcpy(lag1[7].s,"--...");
    strcpy(lag1[8].s,"---..");
    strcpy(lag1[9].s,"----.");
}