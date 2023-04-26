#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100000
/*定义一个结构体，表示某个位置的字符c连续出现的次数cnt*/
typedef struct {char c;int cnt;}PAIR;
/*函数stat统计字串s中每个位置的字符及连续次数，结果存放于r所指的PAIR数组中。
例如:字串“aaabbb”共有两个位置，分别是a(3次)和b(3次)，“ab”也有两个位置，分别是a(1次)和b(1次)，“aabb”也有两个位置，分别是a(2次)和b(2次)。
返回值rcnt表示位置总数。*/
int stat(char*s,PAIR*r)
{
    int rcnt=0,cnt=1; char prev;
    for (prev=*s++;*s;cnt++,prev=*s++)
        if (prev!=*s) r[rcnt].c=prev,r[rcnt++].cnt=cnt,cnt=0;
    r[rcnt].c=prev,r[rcnt++].cnt=cnt;
    return rcnt;
}
/*定义函数 allSameLength_Char判断所有字符串包含的位置个数是否相同，
如果不相同，则函数返回0；如果相同，则判断在每个对应位置上所有字符串的字符是否相同，如果相同，函数返回1，否则函数返回0 。
其中:f指向每个字串的每个位置字符及次数组成的PAIR;
     n是字串数;
     fn是每个字串的位置数*/
int allSameLength_Char(PAIR (*f)[100],int n,int *fn)
{
      int i,j;
      for (i=1;i<n;i++) if (fn[i]!=fn[0]) return 0;
      for (i=0;i<fn[0];i++)
        for (j=1;j<n;j++) if (f[j][i].c!=f[0][i].c) return 0;
    return 1;
}
/*使用qsort函数对同一位置上的所有字符串的重复字符数进行排序，提取中位数，计算需要的最少变换次数。*/
int cmp(const void *a,const void *b) { return *(int*)a-*(int*)b; }
int main()
{
    int n,ans=0,fn[N],a[N],i,j; PAIR f[N][100]; char s[101];
    /*定义char PAIR f[N][100];表示每个字符串在每个位置的字符及出现次数(字串长度最长100，因此位置数最多100)
    f[0][0]存放的是第1个字符串 s1 的第1个位置的字符以及重复次数
    f[0][1]存放的是第1个字符串 s1 的第2个位置的字符以及重复次数*/
    scanf("%d",&n); for (i=0;i<n;i++) fn[i]=stat((scanf("%s",s),s),f[i]);
    if(allSameLength_Char(f,n,fn))
    {
        for (i=0;i<fn[0];i++)
        {
            for (j=0;j<n;j++) a[j]=f[j][i].cnt;
            qsort(a,n,sizeof(a[0]),cmp);
            for (j=0;j<n;j++) ans+=abs(a[j]-a[n/2]);
        }
        printf("%d\n",ans);
    }
    else printf("-1\n");
    return 0;
}