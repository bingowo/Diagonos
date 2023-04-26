#include<stdio.h>
#include<string.h>
int main(){
    int t,n,i;
    long long int a[10000];
    scanf("%d",&t);
    int m=0;
    while(m<t){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        Sort(a,n);
        printf("case #""%d",m);
        printf(":");
        printf("\n");
        for (i=0;i<n;i++) printf("%lld%c",a[i],i!=n-1?' ':'\n');
        m++;
    }
}
int count(long long int a)
{   int i,num;
	i=0;
	num=0;
	for (i=0;i<=63;i++){
		if(((((long long int)a<<63-i))>>63)==1) {num=num+1;
		}
	}
	if(a<0){
	    int k;
	    k=64-num+1;
	    num=k;
	}
	return num;
}
int cmp(const void* a,const void* b)
{  
    long long int ua=*(long long int*)a;
    long long int ub=*(long long int*)b;
    long long int a1=count(ua);
    long long int b1=count(ub);
    if(a1==b1){
        return ua<ub?-1:1;
    }else{
        return b1-a1;
    }

}
void Sort(long long int *p, int n)
{
    qsort(p,n,sizeof(long long int),cmp);
}