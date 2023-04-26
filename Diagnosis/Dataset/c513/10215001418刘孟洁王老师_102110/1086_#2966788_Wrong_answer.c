#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{char si[10007],sf[10007];}flo;

int po,num;
char ans1[1007],ans2[1007];
void read(char s[],char si[],char sf[])
{
    int len = strlen(s);
    int flag,k,i;
    flag = 1;
    for(i = 0,k = 0; i < len && s[i] != '.'; i++)
    {
        if(flag && s[i] == '0')continue;
        flag = 0;
        si[k] = s[i];
        k++;
    }
    si[k] = '\0';
    for(i += 1,k = 0; i < len; k++,i++)sf[k] = s[i];
    sf[k] = '\0';
    if(!strlen(si)){si[0] = '0';si[1] = '\0';}
    if(!strlen(sf)){sf[0] = '0';sf[1] = '\0';}
    //printf("%d %d ",len,flag);
    //printf("%s %s\n",si,sf);
}

void reverse(char s[])
{
    int len = strlen(s)-1,i;
    for(i = 0; i <= len/2; i++)
    {
       char p = s[i];
       s[i] = s[len-i];
       s[len-i] = p;
    }
}

void minus_float(char s1[],char s2[])
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i,m;
    int len = len1 > len2?len1 : len2;
    if(len1 < num&&len2 < num)//若小数不够长；
    {
        for(i = len1-1; i >= 0; i--)s1[i + num-len1] = s1[i];
        for(i = len2-1; i >= 0; i--)s2[i + num-len2] = s2[i];
        for(i = 0; i < num-len1; i++)s1[i] = '0';
        for(i = 0; i < num-len2; i++)s2[i] = '0';
        s1[num] = '\0';s2[num] = '\0';
    }
    for(i = len1-1; i >= 0; i--)s1[i + len-len1] = s1[i];
    for(i = len2-1; i >= 0; i--)s2[i + len-len2] = s2[i];
    for(i = 0; i < len-len1; i++)s1[i] = '0';
    for(i = 0; i < len-len2; i++)s2[i] = '0';
    s1[len] = '\0';s2[len] = '\0';
    for(i = 0; i < len; i++)ans2[i] = s1[i]-s2[i] + '0';
    for(i = 0; i < len-1; i++)
    {
        if(ans2[i] < '0')
        {
            ans2[i] += 10;
            ans2[i+1] -= 1;
        }
    }
    if (ans2[len-num-1] >= '5')//判断四舍五入；
    {
        m = 1;
        for(i = len-num; i < len; i++)
        {
            int tmp = ans2[i]-'0' + m;
            ans2[i] = tmp%10 + '0';
            //printf("%d ",ans2[len-num]);
            m = tmp/10;
        }
    }
    if(ans2[len-1] < '0'){ans2[len-1] += 10;po = 1;}
    ans2[len] = '\0';
    //printf("%s %s\n",s1,s2);
   //printf("%d\n",ans2[len-num]);
    //printf("%s\n",ans2);
}
 void minus_int(char s1[],char s2[])
 {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i;
    int len = len1> len2?len1: len2;
    for(i = len1; i < len; i++)s1[i] = '0';
    for(i = len2; i < len; i++)s2[i] = '0';
    s1[len] = '\0';s2[len] = '\0';
    for(i = 0; i < len; i++)ans1[i] = s1[i]-s2[i] + '0';
    if(po == 1)ans1[0] -= 1;
    for(i = 0; i < len; i++)
    {
        if(ans1[i] < '0')
        {
            ans1[i] += 10;
            ans1[i+1] -= 1;
        }
    }
    ans1[len] = '\0';
    //printf("%s %s\n",s1,s2);
    //printf("%s\n",ans1);
 }

int main()
{
    char s1[1007],s2[1007],tmp[1007];
    char si1[1007],sf1[1007],si2[1007],sf2[1007];
    int len1,len2,k = 0;
    scanf("%s%s%d",s1,s2,&num);
    memset(ans1,'0',sizeof(ans1));memset(ans1,'0',sizeof(ans2));
    read(s1,si1,sf1);read(s2,si2,sf2);
    len1 = strlen(si1);len2 = strlen(si2);
    if((len1 < len2)||(len1 == len2 && strcmp(si1,si2)<0)||(strcmp(si1,si2) == 0 && strcmp(sf1,sf2)<0))
    {
        strcpy(tmp,si1);
        strcpy(si1,si2);
        strcpy(si2,tmp);
        strcpy(tmp,sf1);
        strcpy(sf1,sf2);
        strcpy(sf2,tmp);
        k = 1;
    }
    reverse(si1);reverse(sf1);reverse(si2);reverse(sf2);
    minus_float(sf1,sf2);minus_int(si1,si2);
    reverse(ans1);reverse(ans2);
    ans2[num] = '\0';
    if(k == 1)printf("-%s.%s\n",ans1,ans2);
    else if(k == 0)printf("%s.%s\n",ans1,ans2);
    return 0;
}