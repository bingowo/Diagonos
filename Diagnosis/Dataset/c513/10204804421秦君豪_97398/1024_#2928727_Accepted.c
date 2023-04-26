#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char stdnum[12];
    int grade;
}student;
int cmp(const void*a,const void *b)
{
    student *a1=(student*)a;
    student *b1=(student*)b;
    if((a1->grade)!=(b1->grade)) return ((a1->grade)>(b1->grade)?-1:1);
    else return strcmp(a1->stdnum,b1->stdnum);
}

int main()
{
    int T;
    int N,M,G;
    int cnt,n;
    int i,j,k;
    scanf("%d",&T);
    for (i=0;i<T;i++)
    {
        scanf("%d%d%d",&N,&M,&G);
        int question[M+1];
        student s[N+1];;
        for(j=1;j<=M;j++)
        {
            scanf("%d",&question[j]);
        }
        for(j=0;j<N;j++)
        {
            
            scanf("%s",&s[j].stdnum);
            scanf("%d",&cnt);
            s[j].grade=0;
            for(k=0;k<cnt;k++)
            {
                scanf("%d",&n);
                s[j].grade+=question[n];
            }
        }
        qsort(s,N,sizeof(student),cmp);
        printf("case #%d:\n",i);
        cnt = 0; 
        
        for(k=0;k<N;k++)
        {
        	if(s[k].grade<G) 
        	{
        		cnt=k-1;
        		break;
			}
		}
        printf("%d\n",cnt+1);
        for(k=0;k<=cnt;k++)
        {
            printf("%s %d\n",s[k].stdnum,s[k].grade);
        }
    }

    return 0;
}














/*while(min<=max)
        {
            int mid=(min+max)/2;
            if(s[mid].grade>=G&&s[mid+1].grade<G)
            {
                cnt=mid+1;
                printf("%d\n",cnt);
                break;
            }
            else if (s[mid].grade>=G&&s[mid+1].grade>=G)
            {
                min=mid+1;
            }
            else max=mid-1;
        }*/