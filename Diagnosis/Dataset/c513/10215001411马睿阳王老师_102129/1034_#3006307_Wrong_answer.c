#include<stdio.h>
#include<string.h>
#include<math.h>

double flag[50];

 int cmp(const void*a1,const void*b1)
{
    char a=*(char*)a1;
    char b=*(char*)b1;
    int p1,p2;//将字母改为数字更方便
    if(a>='a'&&a<='z') p1=a-'a';
    else p1=a-'A';
    if(b>='a'&&b<='z') p2=b-'a';
    else p2=b-'A';

    if(flag[p1]>flag[p2]) return -1;
    else if(flag[p1]<flag[p2]) return 1;
    else //频率相同
    {
        if(p1==p2)
        {
            if(a<b) return 1;
            else return -1;
        }
        else
        {
            if(a<b) return -1;
            else return 1;
        }
    }
}


int main()
{
    int T;
    int i=0,j=0,t=0,k=0;
    scanf("%d",&T);
    for(k=0;k<T;k++)
    {
        int c=0;
        for(i=1;i<=26;i++)
        {
          scanf("%lf",&flag[i]);
        }
        char s[105]={0};
        scanf("%s",s);
        c=strlen(s);
        qsort(s,c,sizeof(char),cmp);
        printf("case #%d:\n",k);
        printf("%s",s);
        printf("\n");
    }

    return 0;
}
