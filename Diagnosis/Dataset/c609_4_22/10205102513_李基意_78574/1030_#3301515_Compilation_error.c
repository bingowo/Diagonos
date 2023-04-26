#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int T;
char line[110];
double f[26];
int cmp(const char* aa,const char* bb)
{
    if(tolower(*aa)==tolower(*bb)) 
        return aa>bb; //同一个字母，小写asc码大，排前面
    if(f[tolower(aa)-'a']==f[tolower(bb)-'a']) 
        return tolower(aa)f[tolower(bb)-'a'];//频率不同，频率大的排在前面
}
void solve()
{
    for(int i=0;i<26;i++) cin>>f[i];
        scanf("%s",line);
    int ll=strlen(line);
    qsort(line,ll,sizeof(s[0]),cmp);
    printf("%s",line);
    return;
}
int main()
{
    scanf("%d",&T);
    for(int step=0;step<T;step++)
    {
        printf("case #%d:\n",step);
        solve();
    }
    return 0;
}