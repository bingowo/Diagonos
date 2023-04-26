#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int alpha[26]={0};
void getsecret(char *a);            //不要什么都想着哈希表，十万大小的哈希表，太离谱了
int main()
{
    int i,x,T;
    char s[101];
    scanf("%d", &T);

    for(x=0;x<T;x++)
    {
        scanf("%s",s);
        printf("case #%d:\n",x);
        getsecret(s);
        printf("\n");
    }

    return 0;
}
void getsecret(char *a)
{
    int i,len,res[10]={0};
    len=strlen(a);
    for(i=0;i<len;i++)
    {
        alpha[a[i]-'A']++;
    }
    while(alpha[25]!=0) //0-Z
    {
        res[0]++;
        alpha[25]--;alpha[4]--;alpha[17]--;alpha[14]--;
    }
    while(alpha[22]!=0) //2
    {
        res[2]++;
        alpha[22]--;alpha[19]--;alpha[14]--;        
        //这个数字把我看恶心到了，眼睛都疼了，下次开大一点，别舍不得，直接用ASCII码表对应
    }
    while(alpha[20]!=0) //4
    {
        res[4]++;
        alpha[20]--;alpha[5]--;alpha[14]--;alpha[17]--;
    }
    while(alpha[23]!=0) //6
    {
        res[6]++;
        alpha[23]--;alpha[18]--;alpha[8]--;
    }
    while(alpha[6]!=0)  //8
    {
        res[8]++;
        alpha[6]--;alpha[4]--;alpha[7]--;alpha[8]--;alpha[19]--;
    }
    while(alpha[17]!=0) //3
    {
        res[3]++;
        alpha[19]--;alpha[7]--;alpha[17]--;alpha[4]-=2;
    }
    while(alpha[18]!=0) //7
    {
        res[7]++;
        alpha[18]--;alpha[4]-=2;alpha[21]--;alpha[13]--;
    }
    while(alpha[21]!=0) //5
    {
        res[5]++;
        alpha[5]-=2;alpha[8]--;alpha[21]--;
    }
    while(alpha[8]!=0)  //9
    {
        res[9]++;
        alpha[13]-=2;alpha[8]--;alpha[4]--;
    }
    while(alpha[14]!=0) //1
    {
        res[1]++;
        alpha[14]--;
    }
    for(i=0;i<10;i++)
    {
        while(res[i]!=0)
        {
            printf("%d",i);
            res[i]--;
        }
    }
}
