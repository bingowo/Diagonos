#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char ss[16];
}STR;

int combination(int n)
{
    int i,j; int cnt=0,a=1;
    for (i=1;i<=n;i++)
    {
        for (j=0;j<i;j++)
        {
            a=a*(n-j);
            a=a/(j+1);
        }
        cnt+=a;
        a=1;
    }
    return cnt;
}

char* print_subset(int n , int s, char* str)
{
int j=0;
char* s1=(char*)calloc((n+1),sizeof(char));
for(int i = 0 ; i < n ; ++i)
 {
 if( s&(1<<i) )     // 判断s的二进制中哪些位为1，即代表取某一位
  s1[j++]=str[i]; //或者a[i]
 }

 return s1;
}

STR* subset(int n ,char* s)
{
    char* ss=NULL;
     STR* arr=(STR*)calloc(combination(n)+1,sizeof(STR));

 for(int i= 0 ; i < (1<<n) ; ++i)
 {
 ss=print_subset(n,i,s);
 strcpy(arr[i].ss,ss);
 free(ss);
 }
    return arr;
}



int cmp(const void* a,const void* b)
{
    char* pa=(char*)a;  char* pb=(char*)b;
    return (*pa>*pb)?1:-1;
}

int cmp1(const void* a,const void* b)
{
    STR* pa=(STR*)a;  STR* pb=(STR*)b;
    int i,j;
    for (i=0,j=0;i<strlen(pa->ss) && j<strlen(pb->ss);i++,j++)
    {
        if (pa->ss[i]>pb->ss[j]) return 1;
        if (pa->ss[i]<pb->ss[j]) return -1;
    }
    return (strlen(pa->ss)-strlen(pb->ss));
}

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[18]={0};
        scanf("%s",s);
        int cnt=1,j,k=0,h,x,m;
        qsort(s,strlen(s),sizeof(char),cmp);
        for (j=1;j<strlen(s);j++)
        {
            if (s[j]!=s[j-1])
                cnt++;
        }
        char* s2=(char*)malloc((cnt+1)*sizeof(char));
        char* s3=(char*)malloc((cnt+1)*sizeof(char));
        for (j=1;j<strlen(s);j++)
        {
            if (s[j]!=s[j-1])
                s2[k++]=s[j-1];
        }
        s2[k++]=s[j-1];
        s2[k]='\0';
        qsort(s2,cnt,sizeof(char),cmp);
        int n=combination(cnt)+1;
        STR* arr=NULL;
        arr=subset(cnt ,s2);
        qsort(arr,n,sizeof(STR),cmp1);
        for (j=0;j<n;j++)
        {
            if (strlen(arr[j].ss))
                printf("%s\n",arr[j].ss);
        }
        free(s2); free(arr);

    }
    return 0;
}
