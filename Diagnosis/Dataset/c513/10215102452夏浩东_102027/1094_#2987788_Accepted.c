#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int* add(int* L1,int* L2)
{
	int *L=(int*)malloc(121*sizeof(int));
    int left=0;
    for(int i=120;i>=1;i--)
    {
    	int temp = L1[i]+L2[i]+left;
    	L[i]=temp%10;
    	left=temp/10; 
	}
	L[0]=left;
	return L;
}
int* cut(int* L1,int* L2)
{
    int *L=(int*)malloc(121*sizeof(int));
    for(int i=120;i>=1;i--)
    {
    	if(L1[i]>=L2[i]) L[i]=L1[i]-L2[i];
    	else {
    		L[i]=L1[i]+10-L2[i];
    		L1[i-1]-=1;
		}
	}
	L[0]=0;
    return L;
}
int cmp(const void *a,const void *b)
{
    int* A = (int*) a;
    int* B = (int*) b;
    if(A[0]==1 && B[0]==0) return 1;
    else if(A[0]==0 && B[0]==1) return -1;
    else if(A[0]==0 && B[1]==0){
        for(int i=1;i<121;i++){
        	if(A[i]!=B[i]){
				return (B[i]-A[i]);
			}
		}
        return -1;
    }else{
        for(int i=1;i<121;i++){
            if(A[i]!=B[i]) return (A[i]-B[i]);
        }
        return -1;
    }
}
int main()
{
	int L[50][121];
	for(int i=0;i<50;i++)
	{
		for(int j=0;j<121;j++)
		{
			L[i][j]=0;
		}
	}
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        char s[122];
        scanf("%s",s);
        int k=120;
        for(int j=(int)strlen(s)-1;j>=0;j--)
        {
            if(s[j]=='-') L[i][0]=1;
            else L[i][k--]=s[j]-'0';
        } 
    }
    qsort(L,cnt,sizeof(L[0]),cmp);
    int *p=(int*)malloc(121*sizeof(int));
    if(L[0][0]==0 && L[cnt-1][0]==0) p=cut(L[0],L[cnt-1]);
    else if(L[0][0]==0 && L[cnt-1][0]==1) p=add(L[0],L[cnt-1]);
    else if(L[0][0]==1 && L[cnt-1][0]==1) p=cut(L[cnt-1],L[0]); 
    int zero=0;
    for(zero=0;p[zero]==0;zero++) continue;
    for(int i=zero;i<121;i++) printf("%d",p[i]);
    free(p);
    return 0;
}