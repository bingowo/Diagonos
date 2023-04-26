#include <stdio.h>//用了我3h，因为我自以为是的认为，int s[26],就默认把数组里面全放置0了
#include <stdlib.h>//学到了如何计算字符串中不同的个数
#include <string.h>
typedef struct{
    char s[21];
    int cnt;
} str;

int Count(str w)
{
    int num[26];
	char *p = w.s;//用p更方便
	int ret = 0;
    memset(num, 0, sizeof(int) * 26);
	while(*p)
    {
		if(num[*p - 'A'] == 0)
        {
			num[*p - 'A'] = 1;//标志，表明已经记过了
			ret += 1;
		}
		p ++;
	}
	return ret;
}

int cmp(const void *a,const void *b)
{
    str pa=*(str*)a;
    str pb=*(str*)b;
    
    if(pa.cnt==pb.cnt)
    {
       return  strcmp(pa.s,pb.s);
    }
    else if (pa.cnt > pb.cnt) 
   {return -1;}
    else 
   { return 1;}
}

int main()
{
    int t;
    scanf("%d",&t);//次数
    
    str arr[100];
    for (int j=0; j<t; j++)
    {
        int n;
        scanf("%d",&n);//一次字符串的数量

        for(int i=0; i<n; i++)
        {
            scanf("%s",arr[i].s);
           
            arr[i].cnt=Count(arr[i]);//将各个字符串输入到对应的空间
        }
        qsort(arr,n,sizeof(str),cmp);
        
        printf("case #%d:\n",j);
        for(int i=0; i<n; i++)
        {
            printf("%s\n",arr[i].s);
        }
    }
    return 0;
}