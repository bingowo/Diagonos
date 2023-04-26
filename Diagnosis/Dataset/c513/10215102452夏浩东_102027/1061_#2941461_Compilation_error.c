#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct T{
    char s[16];
    long long int num;
};
int cmp(const void *a,const void *b)
{
    struct T *A=(struct T*)a;
    struct T *B=(struct T*)b;
    if(A->num != B->num) return (int)(A->num-B->num);
    else return strcmp(A->s,B->s);
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    struct T *L=(struct T*)malloc(cnt*sizeof(struct T*));
    for(int i=0;i<cnt;i++)
    {
        scanf("%s",L[i].s);
        int a[128];
        int digit=0,N=0;
        
        for(int i=0;s[i]!='\0';i++)
        {
        	int repeat=0;
        	for(int j=0;j<i;j++)
        	{
        		if(s[i]==s[j]){
        			repeat=1;
        			break;
				}
			}
			if(repeat==0) N++;
		}
		
		a[0]=1;
        for(int y=1;s[y]!='\0';y++)
        {
        	int repeat=0;
        	for(int j=0;j<y;j++)
        	{
        		if(s[y]==s[j]){
        			repeat=1;
					a[y]=a[j];
					break;	
				}
			}
			if(repeat==0)
			{
				a[y]=digit;
				digit = digit? digit+1:2;
			}
        }
        if(N<2) N=2;
        long long result=0;
        for(int y=0;s[y]!='\0';y++)
        {
            result=result*N+a[y];
        }
        L[i].num=result;
    }
    qsort(L,cnt,sizeof(struct T),cmp);
    for(int i=0;i<cnt;i++)
    {
        printf("%s\n",L[i].s);
    }
    return 0;

}