#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct {
    int number;
    int total;
} ABC;
int cmp(const void *a, const void *b){
    ABC * pa = (ABC *)a;
	ABC * pb = (ABC *)b;
	return pa->total - pb->total;
}
void Sort(ABC *ps, int n)
{ 
    qsort(ps,n,sizeof(ps[0]),cmp);
}
int main(){
    int m,n,i,j;
    int num=0;
    int res=0;
    int num2=0;
    char a[1000];
    char b[1000];
    char c[1000];
    char d[1000];
    char e[1000];
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&n);
    for(j=0;j<n;j++){
        scanf("%d",&b[j]);
    }
    for(i=0;i<n;i++){
        res=0;
        for(j=0;j<m;j++){
            if(b[i]==a[j]){
                c[num]=b[i];
                d[num]=j;
                num++;
                res=1;
            }
        }
        if(res==0){
            e[num2]=b[i];
            num2++;
        }
    }
    for(i=0;i<num2;i++){
        for(j=i+1;j<num2;j++){
            if(e[i]>e[j]){
                int temp=e[i];
                e[i]=e[j];
                e[j]=temp;
            }
        }
    }
    ABC s[n];
    for(i=0;i<num;i++){
        s[i].number=c[i];
        s[i].total=d[i];
    }
    Sort(s,num);
    for (i=0;i<num;i++) printf("%u%c",s[i],i!=num-1?' ':'\n');
    for(i=0;i<num2;i++) printf("%u%c",e[i],i!=num2-1?' ':'\n');
}