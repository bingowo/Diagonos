#include<stdio.h>
#include<stdlib.h>
int n=0;
int cmp(const void* _a,const void* _b)
{
    int* a = (int*)_a ; int* b = (int*)_b ;
    int* p = a;
    while(*(p--));
    p++;
    if(*(p+*a+n)!=*(p+*b+n)) {
        return *(p+*b+n) - *(p+*a+n) > 0 ? 1 : -1 ;}
    if(*(p+*a+2*n)!=*(p+*b+2*n)) {
        return *(p+*b+2*n) - *(p+*a+2*n) > 0 ? 1 : -1 ;}
    if(*(p+*a+3*n)!=*(p+*b+3*n)) {
        return *(p+*a+3*n) - *(p+*b+3*n) > 0 ? 1 : -1 ;}
    return *a - *b > 0 ? 1 : -1 ;
}
int main()
{
    int m;
    while(scanf("%d %d",&n,&m) && n!=0){
		int s[4*n];int a,b,c;
        for(int h=0;h!=4*n;h++)
        	s[h]=0;
        for(int j=0;j!=n;j++) 
			s[j]=j+1;
        for(int i=0;i!=m;i++){
            scanf("%d %d %d",&a,&b,&c);
            if(c==1) {
                s[2*n-1+a]+=1;s[3*n-1+b]+=1;
                s[n-1+a]+=3;s[n-1+b]-=1;}
            else if(c==-1) {
                s[2*n-1+b]+=1;s[3*n-1+a]+=1;
                s[n-1+a]-=1;s[n-1+b]+=3;}
            else {
                s[n-1+a]+=1;s[n-1+b]+=1;}   
        }
        qsort(s,n,sizeof(s[0]),cmp);
        for(int k=0;k!=n;k++) printf("%d ",s[k]);
    }
}