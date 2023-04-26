#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 10007

char s1[N],s2[N],ss1[N],ss2[N],sumx[N],sumz[N];
int mf,mi,tmp,x;

void read1(char s[])
{
    int len = strlen(s);
    int i,j,k,l;
    for(i = 0;i < len; i++)
       {
           if(s[i] == '.'){k = i;break;}
       }
       if(k == 0)
        {
            for(j = 1; j < len; j++){s2[j-1] = s[j];s1[0] = '0';s1[1] = '\0';}
            s2[len-1] = '\0';
       }
       else if(i == len){strcpy(s1,s);s1[len] = '\0';s2[0] = '0';s2[1] = '\0';}
       else if(k == len-1){for(j = 0; j < len-1; j++)s1[j] = '\0';s2[0] = '0';s2[1] = '\0';}
       else
       {
           for(j = 0;j < k; j++)s1[j] = s[j];
           s1[j] = '\0';
           for(j += 1,l = 0; j < len; j++,l++)s2[l] = s[j];
           s2[l] = '\0';
       }
}

void read2(char s[])
{
    int len = strlen(s);
    int i,j,k,l;
    for(i = 0;i < len; i++)
       {
           if(s[i] == '.'){k = i;break;}
       }
       if(k == 0)
        {
            for(j = 1; j < len; j++)
               {ss2[j-1] = s[j];ss2[len-1] = '\0';ss1[0] = '0';ss1[1] = '\0';}
        }
       else if(i == len){strcpy(ss1,s);ss1[len] = '\0';ss2[0] = '0';ss2[1] = '\0';}
       else if(k == len-1){for(j = 0; j < len-1; j++)ss1[j] = '\0';ss2[0] = '0';ss2[1] = '\0';}
       else
       {
           for(j = 0;j < k; j++)ss1[j] = s[j];
           ss1[j] = '\0';
           for(j += 1,l = 0; j < len; j++,l++)ss2[l] = s[j];
           ss2[l] = '\0';
       }
}

void reverse(char s[])
{
    int i,len;
    len = strlen(s)-1;
    for(i = 0;i <= len/2; i++)
    {
        char p = s[i];
        s[i] = s[len-i];
        s[len-i] = p;
    }
    s[len+1] = '\0';
}



void addfloat(char t1[],char t2[])
{
    int len1,len2,len,i;
    len1 = strlen(t1);
    len2 = strlen(t2);
    len = len1 > len2?len1:len2;
    int cha = abs(len1-len2);
    if(len1 > len2)
    {
        for(i = 0; i < len2; i++){t2[i+cha] = t2[i];}
        for(i = 0; i < cha; i++)t2[i] = '0';
        t2[len] = '\0';
    }
    else if(len1 < len2)
    {
        for(i = 0; i < len1; i++){t1[i+cha] = t1[i];}
        for(i = 0; i < cha; i++)t1[i] = '0';
        t1[len] = '\0';
    }
    mf = 0;
    for(i = 0; i < len; i++)
    {
        tmp = t1[i]-'0' + t2[i]-'0'+ mf;
        sumx[i] = (tmp%10) + '0';
        mf = tmp/10;
    }

}

void addint(char t1[],char t2[])
{
    int len1,len2,len,i;
    len1 = strlen(t1);
    len2 = strlen(t2);
    len = len1 > len2?len1:len2;
    mi = mf;
    if(len1 > len2)
        {
            for(i = len2; i < len1; i++)t2[i] = '0';
            t2[len1] = '\0';
        }
    else if(len1 < len2)
        {
            for(i = len1; i < len2; i++)t2[i] = '0';
            t1[len2] = '\0';
        }
    for(i = 0; i < len; i++)
    {
        tmp = t1[i]-'0' + t2[i]-'0'+ mi;
        sumz[i] = (tmp%10) + '0';
        mi = tmp/10;
    }
    while(mi)
    {
       sumz[len] = (mi%10) + '0';
       mi /= 10;
       len++;
    }
    sumz[len] = '\0';
}

void deal(int n)
{
    int i;
    int len1 = strlen(sumx);
    int len2 = strlen(sumz);
    x = len1-n-1;
    if((sumx[x]-'0')>=5)sumx[x+1]++;
    if((sumx[x+1] -'0') >= 10)
    mf = 0;
    {for(i = x+1; i < len1; i++)
    {
        tmp = sumx[i] - '0' + mf;
        sumx[i] = tmp%10 + '0';
        mf = tmp/10;
    }
    if((sumz[0] + mf) >= 10)
    {
       mi = mf;
       for(i = 0; i < len2; i++)
       {
         tmp = sumz[i] - '0' + mi;
         sumz[i] = tmp%10 + '0';
         mi = tmp/10;
       }
       if(mi)
       {
           sumz[len2] = mi%10;
           len2++;
           mi /= 10;
       }
    }
    }
}

int main()
{
    int num;
    char fl1[N],fl2[N];
        memset(s1,'0',sizeof(s1));memset(s2,'0',sizeof(s2));memset(ss1,'0',sizeof(ss1));memset(ss2,'0',sizeof(ss2));
        scanf("%s%s%d",fl1,fl2,&num);
        read1(fl1);read2(fl2);
        reverse(s1);reverse(s2);reverse(ss1);reverse(ss2);
        addfloat(s2,ss2);addint(s1,ss1);
        deal(num);
        reverse(sumz);reverse(sumx);
        sumx[num] = '\0';
        //printf("%s %s %s %s\n",s1,s2,ss1,ss2);
        printf("%s.%s\n",sumz,sumx);
        //printf("%d",x);
    return 0;
}
