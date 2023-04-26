#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char number[1500];
    long long int total;
} WORD;
int comp(long long int *a, long long int *b)
{
	WORD * pa = (long long int)(WORD *)a;
	WORD * pb = (long long int)(WORD *)b;
	if(pa->total != pb->total){
		return pa->total - pb->total;
	}else{
		return strcmp(pa->number, pb->number);
	}
}
void Sort(WORD *ps, long long int n)
{ 
    qsort(ps,n,sizeof(ps[0]),comp);
}
int main(){
    int i;
    long long int n;
    scanf("%lld",&n);
    WORD s[n];
    for(i=0;i<n;i++){
        scanf("%s",s[i].number);
        int a[128];
        for(int t=0;t<128;t++){
            a[t]=-1;
        }
        int R=0;
        char *p=s[i].number;
        a[*p]=1;
        while(*++p){
            if(a[*p]==-1){
                a[*p]=R;
                R=R?R+1:2;
            }
        }
        if(R<2){
            R=2;
        }
        long long int N=0;
        p=s[i].number;
        while(*p)
            N=N*R+a[*p++];
        s[i].total=N;
        
    }
    Sort(s,n);
    for(i=0;i<n;i++){
        printf("%s\n",s[i].number);
    }
    
}