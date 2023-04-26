#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define L 100
typedef struct {
    char xnum[100];
    char ynum[100];
    char xminus[100];
    char yminus[100];
    char maxnum[100];
}Chebyshev;


void minus1(int a[],int b[])
{   int i;
    for(i=L;i>0;i--)
    {
        a[i] -= b[i];
        if(a[i]<0){
            a[i-1]-=1;
            a[i]+=10;
        }
    }
}


int cmp(int a[], int b[])
{	
	int ret = 0;
	int i;
	for(i = 0 ; i < L+1; i ++){
		if(a[i] > b[i]){
			ret = 1;
			break;
		}else if(a[i] < b[i]){
			ret = -1;
			break;
		}
	}
	
	return ret;
}
int cmp2(const void *a, const void *b){
    Chebyshev * pa = (Chebyshev *)a;
	Chebyshev * pb = (Chebyshev *)b;
	if(pa->maxnum != pb->maxnum){
		return pb->maxnum - pa->maxnum;
	}else{
		return strcmp(pa->xnum, pb->xnum);
	}
}

int main(){
    char x1[L+1];
    char y1[L+1];
    int j,k; 
    int A[L+1]={0};
    int C[L+1]={0};
    Chebyshev a[100];
    scanf("%s %s",a[0].xnum,a[0].ynum);
    for(j=strlen(a[0].xnum)-1,k=L;j>=0;j--,k--){
        A[k] = a[0].xnum[j]-'0';
    }
    for(j=strlen(a[0].ynum)-1,k=L;j>=0;j--,k--){
        C[k] = a[0].ynum[j]-'0';
    }    
    int n;
    scanf("%d",&n);
    for(int i=1;i<n+1;i++){
        scanf("%s %s",a[i].xnum,a[i].ynum);
        int B[L+1]={0};
        for(j=strlen(a[i].xnum)-1,k=L;j>=0;j--,k--){
            B[k] = a[i].xnum[j]-'0';
        }
        int m=cmp(A,B);
        if(m==1){
        	minus1(A,B);
        	int t=0;
            while(t<=L && A[t]==0) t++;  //跳过前置0
            if(t>L) a[i].xminus[0]='0';   //整数部分为0
            else
            {
                int num=0;
                while(t<=L){
                    a[i].xminus[num]=A[t++]; //整数部分
                    num++;
                }
                a[i].xminus[num]='\0';
            }
    	}else if(m==-1){
        	minus1(B,A);
        	int t=0;
            while(t<=L && B[t]==0) t++;  //跳过前置0
            if(t>L) a[i].xminus[0]='0';   //整数部分为0
            else
            {
                int num=0;
                while(t<=L){
                    a[i].xminus[num]=B[t++]; //整数部分
                    num++;
                }
                a[i].xminus[num]='\0';
            }
        }else{
            a[i].xminus[0]='0';
            a[i].xminus[1]='\0';
        }
        int D[L+1]={0};
        for(j=strlen(a[i].ynum)-1,k=L;j>=0;j--,k--){
            D[k] = a[i].ynum[j]-'0';
        }
        m=cmp(C,D);
        if(m==1){
        	minus1(C,D);
        	int t=0;
            while(t<=L && C[t]==0) t++;  //跳过前置0
            if(t>L) a[i].yminus[0]='0';   //整数部分为0
            else
            {
                int num=0;
                while(t<=L){
                    a[i].yminus[num]=C[t++]; //整数部分
                    num++;
                }
                a[i].yminus[num]='\0';
            }
    	}else if(m==-1){
        	minus1(D,C);
        	int t=0;
            while(t<=L && D[t]==0) t++;  //跳过前置0
            if(t>L) a[i].yminus[0]='0';   //整数部分为0
            else
            {
                int num=0;
                while(t<=L){
                    a[i].yminus[num]=D[t++]; //整数部分
                    num++;
                }
                a[i].yminus[num]='\0';
            }
        }
        else{
            a[i].yminus[0]='0';
            a[i].yminus[1]='\0';
        }
        m=cmp(a[i].xminus,a[i].yminus);
        if(m==1){
        	minus1(a[i].xminus,a[i].yminus);
        	int t=0;
            while(t<=L && a[i].xminus[t]==0) t++;  //跳过前置0
            if(t>L) a[i].maxnum[0]='0';   //整数部分为0
            else
            {
                int num=0;
                while(t<=L){
                    a[i].maxnum[num]=a[i].xminus[t++]; //整数部分
                    num++;
                }
                a[i].maxnum[num]='\0';
            }
    	}else if(m==-1){
        	minus1(a[i].yminus,a[i].xminus);
        	int t=0;
            while(t<=L && a[i].yminus[t]==0) t++;  //跳过前置0
            if(t>L) a[i].maxnum[0]='0';   //整数部分为0
            else
            {
                int num=0;
                while(t<=L){
                    a[i].maxnum[num]=a[i].yminus[t++]; //整数部分
                    num++;
                }
                a[i].maxnum[num]='\0';
            }
        }else{
            a[i].maxnum[0]='0';
            a[i].maxnum[1]='\0';
        }
    }
    qsort(a,n,sizeof(a[0]),cmp2);
    printf("%s",a[0].maxnum);
    printf("%s %s",a[0].xnum,a[0].ynum);
}