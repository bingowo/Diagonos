#include<stdio.h>
#include<stdlib.h>

int cmp(const void* x,const void* y){
    int xx=*(int*)x;
    int yy=*(int*)y;
    xx=abs(xx);
    yy=abs(yy);
    int ansx=0;
    int ansy=0;
    while (xx!=0){
        ansx++;
        xx/=10;
    }
    while (yy!=0){
        ansy++;
        yy/=10;
    }
    if (ansx==ansy) return *(int*)x-*(int*)y;
    else return ansy-ansx;
}

int main(){
    int n=0;
    int a[100010];
    while (scanf("%d",&a[n])!=EOF) n++;
    qsort(a,n,sizeof(a[0]),cmp);
    for (int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
	return 0;
}
