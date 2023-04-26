//还是和dp没啥关系啊，dp专题dp了一个寂寞
//只要你知道组合数分子分母的前n为一定除得开，就可以大胆的在里面除啦，不用算好分子分母再一起除
//从而引发llu越界
#include <stdio.h>
typedef unsigned long long int llu;
llu C(m,n){
    llu ret = 1;
    if(n>m/2) n=m-n;
    
    for(int i=1;i<=n;i++){
        ret*=(m+1-i);
        ret/=i;
    }

    return ret;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int m,n;
        scanf("%d%d",&m,&n);
        printf("case #%d:\n",t);
        printf("%llu\n",C(m,n));
    }
}