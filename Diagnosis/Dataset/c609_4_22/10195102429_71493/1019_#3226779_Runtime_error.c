#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data
{
    int a;    //整数
    int number;  //位数
};
int getDig (int val){
    val = abs(val);
    int ans = 0;
    while (val){
        ans ++;
        val /= 10;
    }
    return ans;
}
int cmp(const void *a,const void *b){
    struct data d1,d2;
     d1=*((struct data *)a);
     d2=*((struct data *)b);
     if(d2.number!=d1.number){
        return d2.number-d1.number;
     }
     else{
        if(d1.a>d2.a){
            return 1;
        }
        else return -1;
     }

}
int main()
{
    struct data p[10001];
    long long int i=0;
    while((scanf("%d",&p[i].a))!=EOF){
            p[i].number=getDig(p[i].a);

            i++;}
    qsort(p,i,sizeof(p[0]),cmp);
    for(int j=0;j<i;j++){
        printf("%d ",p[j].a);
    }



    return 0;
}
