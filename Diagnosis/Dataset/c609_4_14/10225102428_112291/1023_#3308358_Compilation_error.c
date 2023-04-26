#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct {
int val; //表示日期“大小”的值
int y; //年
int d; //日
char m[7]; //玛雅历的月份
}RECORD;

int cmp(const void* a,const void* b){ 
	return((RECORD*)a)->val - ((RECORD*)b)->val; 
}

int month2idx(char* m){ 
	int i;
	static char* month[] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
	for (i=0;;i++) if (!strcmp(m,month[i])) return i; 
}

RECORD* Input(int n)
{
    RECORD *a = (RECORD*)malloc(sizeof(RECORD)*n);
    int i, j = 0;
    for (i=0;i<n;i++) {//printf("1\n");
		scanf("%d.%s %d", &a[i].d, &a[i].m, &a[i].y);
		a[i].val = a[i].y*1000+month2idx(a[i].m)*20+a[i].d;
	}
	return a; 
}

int main(){
	
	int t, i, j, n, k = 0;
	scanf("%d", &t);
	for(j = 0; j < t; j++){
		RECORD *A = NULL;
		scanf("%d", &n);
		A = Input(n);
		qsort(A, n, sizeof(RECORD), cmp);
		printf("case #%d:\n", j);
		for (i=0;i<n;i++)
			printf("%d. %s %d\n",A[i].d,A[i].m,A[i].y);
		free(A);
	}
	
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
char *month[] =
{
    "pop","no","zip", "zotz", "tzec", "xul",
    "yoxkin", "mol", "chen", "yax", "zac",
    "ceh", "mac", "kankin", "muan", "pax",
    "koyab", "cumhu","uayet"
};
typedef struct
{
    int y;//年
    char m;//月
    int d;//日
    int m_num;
}date;

int cmp(const void* e1, const void* e2)
{
    struct date* a=(struct date*)e1;
    struct date* b=(struct date*)e2;
    if((*a).y == (*b).y)
    {
        if((*a).m_num == (*b).m_num)
        {return ((*a).d < (*b).d);}
        return((*a).m_num < (*b).m_num);
    }
    return ((*a).y < (*b).y);
}
int main()
{
    int t;//问题数
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;//每个问题
        scanf("%d",&n);
        for(int k=0;k<n;k++){
            data *a = (data*)malloc(sizeof(data)*n);
            //struct D[k].d;
            getchar();
            //struct D[k].m;
            //struct D[k].y;
            scanf("%d",&a[k].d);
            getchar();//读取‘.’符号
            scanf("%s",a[k].m);
            getchar();//读取‘ ’符号
            scanf("%d",&a[k].y);
            data *A=NULL;
            A=a[n];
            for(int i = 0; i < 19; i++)
            {
                if(a[i].m == *month[i])
                    a[i].m_num = i;
            }
        }
        qsort(A,n,sizeof(data),cmp);
        printf("case #%d:\n",i);
        for(int j = 0; j < n; j++)
        {
            printf("%d.%s %d\n",A[j].d,A[j].m,A[j].y);
        }
        free(A);

    }
    return 0;
}