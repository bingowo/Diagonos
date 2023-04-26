#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct{int xi,ci;}multi;

int cmp(const void*a,const void*b)
{
    multi c = *(multi*)a;
    multi d = *(multi*)b;
    if(c.ci > d.ci)return -1;
    else return 1;
}

int main()
{
    char s1[103],s2[103];
    multi t1[53],t2[53];
    multi sum[103],sum1[103];
    int i,j,k,l,h,g,x;
        while(scanf("%s%s",s1,s2)!=EOF)
       {
           k = 0;
        for(i = 0; i < strlen(s1); i++)
        {
            if(isdigit(s1[i])&&s1[i+1] == 'x')//nx或nx^m的情况
            {
                if(s1[i-1] == '-')t1[k].xi = -1*(s1[i]-'0');
                else t1[k].xi = s1[i]-'0';
                if(s1[i+2] == '^')
                {
                    t1[k].ci = s1[i+3]-'0';
                    if(isdigit(s1[i+4]))t1[k].ci = t1[k].ci*10 + s1[i+4]-'0';
                    }
                else t1[k].ci = 1;
                k++;
            }
            else if(isdigit(s1[i])&&isdigit(s1[i+1])&&s1[i+2] == 'x')//nmx或nmx^y的情况
            {
                t1[k].xi = (s1[i]-'0')*10 + s1[i+1]-'0',i++;
                if(s1[i-2] == '-')t1[k].xi = -1*t1[k].xi;
                if(s1[i+2] == '^')
                {
                    t1[k].ci = s1[i+3]-'0';
                    if(isdigit(s1[i+4]))t1[k].ci = t1[k].ci*10 + s1[i+4]-'0';
                    }
                else t1[k].ci = 1;
                k++;
            }
            else if(s1[i] == 'x'&&!isdigit(s1[i-1]))//x或-x的情况
            {
                if(s1[i-1] == '-')t1[k].xi = -1;
                else t1[k].xi = 1;
                if(s1[i+1] == '^')
                {
                    t1[k].ci = s1[i+2]-'0';
                    if(isdigit(s1[i+3]))t1[k].ci = t1[k].ci*10 + s1[i+3]-'0';
                    }
                else t1[k].ci = 1;
                k++;
            }
            else if(isdigit(s1[i])&&s1[i+1] == '\0'&&s1[i-1] != '^')//常数情况
            {
                if(s1[i-1] == '-')t1[k].xi = -1*(s1[i]-'0');
                else t1[k].xi = s1[i]-'0';
                t1[k].ci = 0;
                k++;
            }
        }
        l = 0;
        for(i = 0; i < strlen(s2); i++)
        {
            if(isdigit(s2[i])&&s2[i+1] == 'x')
            {
                if(s2[i-1] == '-')t2[l].xi = -1*(s2[i]-'0');
                else t2[l].xi = s2[i]-'0';
                 if(s2[i+2] == '^')
                {
                    t2[l].ci = s2[i+3]-'0';
                    if(isdigit(s2[i+4]))t2[l].ci = t2[l].ci*10 + s2[i+4]-'0';
                    }
                else t2[l].ci = 1;
                l++;
            }
            else if(isdigit(s2[i])&&isdigit(s2[i+1])&&s2[i+2] == 'x')
            {
                t2[l].xi = (s2[i]-'0')*10 + s2[i+1]-'0',i++;
                if(s2[i-2] == '-')t2[l].xi = -1*t2[l].xi;
                if(s2[i+2] == '^')
                {
                    t2[l].ci = s2[i+3]-'0';
                    if(isdigit(s2[i+4]))t2[l].ci = t2[l].ci*10 + s2[i+4]-'0';
                    }
                else t2[l].ci = 1;
                l++;
            }
            else if(s2[i] == 'x'&&!isdigit(s2[i-1]))
            {
                if(s2[i-1] == '-')t2[l].xi = -1;
                else t2[l].xi = 1;
                 if(s2[i+1] == '^')
                {
                    t2[l].ci = s2[i+2]-'0';
                    if(isdigit(s2[i+3]))t2[l].ci = t2[l].ci*10 + s2[i+3]-'0';
                    }
                else t2[l].ci = 1;
                l++;
            }
            else if(isdigit(s2[i])&&s2[i+1] == '\0'&&s2[i-1] != '^')
            {
                if(s2[i-1] == '-')t2[l].xi = -1*(s2[i]-'0');
                else t2[l].xi = s2[i]-'0';
                t2[l].ci = 0;
                l++;
            }
        }
        h = 0;
        for(i = 0; i < k; i++)
           {
               for(j = 0; j < l; j++)
              {
                sum[h].xi = t1[i].xi * t2[j].xi;
                sum[h].ci = t1[i].ci + t2[j].ci;
                h++;
              }
           }
            g = -1;
            for(i = 0,x = 0; i < h; i++)
             {
                 for(j = i+1; j < h; j++)
                {
                  if(sum[i].ci == sum[j].ci)
                  {
                      sum[i].xi = sum[i].xi+sum[j].xi;
                      sum[j].ci = g;//记录已经算过的x的次数
                      g--;
                    }//次数相同的合并，
               }
                if(sum[i].ci >= 0&&sum[i].xi != 0)sum1[x] = sum[i],x++;//去掉系数为0的；
             }
             qsort(sum1,x,sizeof(sum1[0]),cmp);
             for(i = 0; i < x; i++)printf("%d%c",sum1[i].xi,i==x-1?'\n':' ');
        }
    return 0;
}