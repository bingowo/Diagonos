#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void *a, const void *b    )
{
    char *s1,*s2;
    char ch1,ch2;
    s1=(char *)a;
    s2=(char *)b;
    while(*s1&&*s2)
    {
        ch1=(*s1)>=‘a’?*s1-32:*s1;    //转换为大写字母
        ch2=(*s2)>='a'?*s2-32:*s2;     //转换为大写字母
        if(p[ch1-‘A’]!=p[ch2-‘A’])     //按字母顺序表比较字母
            return p[ch1-'A']-p[ch2-'A'];
        else
        {
            s1++;
            s2++;
        }
    }
    if(*s1==0) return -1;
    else return 1;

}

int main()
{
    int T;
    scanf("%d",&T);
    int cas=0;
    for(cas=0; cas<T; cas++)
    {
        printf("case #%d:\n",cas);
        //输入字母顺序表
        int p[26];
        char s[26];
        scanf("%s",s);
        for(int i=0; i<26; i++)
            p[s[i]-'A']=i;

        //获取待排列字符串并存入二维数组
        char tmp[2000];
        gets(tmp);
        char a[100][20];
        int j=0;
        while(1)
        {
            int k=0;
            if(tmp[j]!=' '&&tmp[j])
                a[cnt][k++]=tmp[j++];
            cnt++;
            if(!tmp[j])
                break;
            else
                j++;
        }
        qsort(a,cnt,sizeof(a[0]),cmp);
        for(int i=0; i<cnt; i++)
            printf("%s",a[i]);
        printf("\n");
    }
}




