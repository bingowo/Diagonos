#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char s[21];
    int cnt;
    int num[26];
} str;

int Count(str w)
{
	char *p = w.s;
	int ret = 0;
	while(*p){
		if(w.num[*p - 'A'] == 0){
			w.num[*p - 'A'] = 1;
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
            memset(arr[i].num, 0, sizeof(int) * 26);
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