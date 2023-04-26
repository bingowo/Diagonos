#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 10007

char s1[N],s2[N],ss1[N],ss2[N],sumx[N],sumz[N];
int mf = 0,mi = 0,tmp = 0,x = 0;
int num;

void read1(char s[])
{
    int len = strlen(s);
    int i,j,k = -1,l;
    for(i = 0;i < len; i++)
       {
           if(s[i] == '.')break;
       }
    if(i == 0)
        {
            for(j = 1; j < len; j++){s2[j-1] = s[j];s1[0] = '0';s1[1] = '\0';}
            s2[len-1] = '\0';
       }
       else if(i == len)
       {
           int f = 1;
           for(k = 0,l = 0;k < len; k++)
           {
               if(f && s[k] == '0')continue;
               f = 0;
               s1[l] = s[k];
               l++;
           }
           s1[l] = '\0';s2[0] = '0';s2[1] = '\0';}
       else if(i == len-1)
       {
           int f = 1;
           for(k = 0,l = 0;k < len; k++)
           {
               if(f && s[k] == '0')continue;
               f = 0;
               s1[l] = s[k];
               l++;
           }
           s1[l] = '\0';s2[0] = '0';s2[1] = '\0';
       }
       else
       {
           for(j = 0;j < i; j++)s1[j] = s[j];
           s1[j] = '\0';
           for(j += 1,l = 0; j < len; j++,l++)s2[l] = s[j];
           s2[l] = '\0';
       }
}

void read2(char s[])
{
    int len = strlen(s);
    int i,j,k = -1,l;
    for(i = 0;i < len; i++)
       {
           if(s[i] == '.')break;
       }
       if(i == 0)
        {
            for(j = 1; j < len; j++)
               {ss2[j-1] = s[j];ss2[len-1] = '\0';ss1[0] = '0';ss1[1] = '\0';}
        }
       else if(i == len)
       {
           int f = 1;
           for(k = 0,l = 0;k < len; k++)
           {
               if(f && s[k] == '0')continue;
               f = 0;
               ss1[l] = s[k];
               l++;
           }
           ss1[l] = '\0';ss2[0] = '0';ss2[1] = '\0';
       }
       else if(i == len-1)
       {
            int f = 1;
           for(k = 0,l = 0;k < len; k++)
           {
               if(f && s1[k] == '0')continue;
               f = 0;
               s1[l] = s[k];
               l++;
           }
           ss1[l] = '\0';ss2[0] = '0';ss2[1] = '\0';
       }
       else
       {
          int f = 1;
           for(k = 0,l = 0;k < len; k++)
           {
               if(f && s1[k] == '0')continue;
               f = 0;
               s1[l] = s[k];
               l++;
           }
           ss1[l] = '\0';
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
    if(len < num)
    {
        for(i = len1-1; i >= 0; i--)t1[i+num-len1] = t1[i];
        for(i = 0; i < num-len1; i++)t1[i] = '0';
        t1[num] = '\0';
        for(i = len2-1; i >= 0; i--)t2[i+num-len2] = t2[i];
        for(i = 0; i < num-len2; i++)t2[i] = '0';
        t2[num] = '\0';
        len = num;
        //memset(sumx,'0',sizeof(sumx));memset(sumz,'0',sizeof(sumz));
    }//如果两者的小数部分都没有需要保留的数长的话，将后面的数字初始化为0；
    else if(len1 > len2)
    {
        for(i = len2-1; i >= 0; i--){t2[i+cha] = t2[i];}
        for(i = 0; i < cha; i++)t2[i] = '0';
        t2[len] = '\0';
    }
    else if(len1 < len2)
    {
        for(i = len1-1; i >= 0; i--){t1[i+cha] = t1[i];}
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
    sumx[len] = '\0';
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
            for(i = len1; i < len2; i++)t1[i] = '0';
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
   {
      mf = 0;
      for(i = x+1; i < len1; i++)
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
           sumz[len2] = mi%10 + '0';
           len2++;
           mi /= 10;
       }
    }
  }
}

int main()
{
    int i;
    char fl1[N],fl2[N];
        for(i = 0; i < 10007; i++){s1[i] = '0';s2[i] = '0';ss1[i] = '0';ss2[i] = '0';sumx[i] = '0';sumz[i] = '0';}
        //for(i = 0; i < (int)strlen(sumx); i++)sumx[i] = '0';
        //for(i = 0; i < (int)strlen(sumz); i++)sumz[i] = '0';
        scanf("%s%s%d",fl1,fl2,&num);
        //memset(sumx,'0',sizeof(sumx));memset(sumz,'0',sizeof(sumz));
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