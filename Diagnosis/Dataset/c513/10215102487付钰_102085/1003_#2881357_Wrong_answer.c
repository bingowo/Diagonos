#include<stdio.h>
#include<string.h>
int count(long long int u)
{
	int r=0;
    int i;
    long long int d=1,m;
	for (i=0;i<63;i++){
	    m=u&d;
		if (m!=0)
		{
		    r++;
		}
		d=d<<1;	
	}
    return r;
}


int cmp(long long int * a,long long int* b)
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
        qsort(a,n,sizeof(long long int),cmp);
        printf("case #""%d",m);
        printf(":");
        printf("\n");
        for (i=0;i<n;i++) printf("%lld%c",a[i],i!=n-1?' ':'\n');
        m++;
    }
}


