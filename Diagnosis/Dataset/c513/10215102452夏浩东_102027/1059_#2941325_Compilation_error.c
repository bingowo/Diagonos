#include <stdio.h>
#include <stdlib.h>
typedef struct R{
    int high;
    int num;
};
int cmp(const void *a,const void *b)
{
    int *A=(int*)a;
    int *B=(int*)b;
    return *A-*B;
}
int GCD(int a,int b)
{
	return b == 0 ? a:GCD(b,a%b);
}
int main()
{
    int width=0,rain=0;
    scanf("%d %d",&width,&rain);
    int *L=(int*)malloc(width*sizeof(int));
    struct R *NL=(struct R*)malloc(width*sizeof(struct R));
    for(int i=0;i<width;i++){NL[i].num=0;}
    for(int i=0;i<width;i++){scanf("%d",&L[i]);}
    qsort(L,width,sizeof(int),cmp);
    int k=0,cnt=0;
    for(int i=1;i<width;i++)
    {
        if(L[i]==L[i-1]) cnt+=1;
        else {cnt+=1;NL[k].num=cnt;NL[k++].high=L[i-1];cnt=0;}
    }
    if(L[width-1]==L[width-2]) {NL[k].high=L[width-1];NL[k].num=cnt+1;}
    else {NL[k].high=L[width-1];NL[k].num=1;}
    int num1=0,num2=0,res=L[0];
    for(int i=0;i<=k-1;i++)
    {
        rain-=(NL[i+1].high-NL[i].high)*NL[i].num;
        if(rain < 0)
        {
            num1=rain+(NL[i+1].high-NL[i].high)*NL[i].num;
            num2=NL[i].num;
            break;
        }
        res=NL[i+1].high;
        NL[i+1].num+=NL[i].num;
        if (rain==0) {break;}
    }
	if(res+num1/num2==0 && num1%num2==0) printf("0");
	else if(res+num1/num2==0) printf("%d+%d",(num%num2)/GCD(num1%num2,num2),num2/GCD(num1%num2,num2));
	else if(num1%num2==0)printf("%d",res+num1/num2);
	else printf("%d+%d/%d",res+num1/num2,(num%num2)/GCD(num1%num2,num2),num2/GCD(num1%num2,num2));
    free(L);
    free(NL);
    return 0;
}