//1080  双指针
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int height[1010];
int Gcd(int a, int b){
    if(a < b) return Gcd(b, a);
    if(a % b == 0) return b;
    else return Gcd(b, a%b);
}
int main(){
    int n, s, m = 0;
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; i ++){
        scanf("%d", &height[i]);
        m = (height[i] < height[m])? i: m;
    }
    int i = m-1, j = m+1; //双指针
    int top = height[m]+1, width, maxH = 0, ret1 = 0, ret2 = 0; 
    while(s > 0){
        while(i > -1 && height[i] < top) i --; //往两边找第一个高度到达top的位置
        while(j < n && height[j] < top) j ++;
        width = j-i-1;  //求宽度
        if(width <= s){
            maxH ++;
            top ++;
        }else{
            ret1 = s;
            ret2 = width;
        }
        s -= width;
    }
    if(ret1 == 0) printf("%d\n", top-1);
    else{
        int temp = Gcd(ret1, ret2);
        if(top>=1) printf("%d+%d/%d\n", top-1, ret1/temp, ret2/temp);
        else printf("%d/%d\n", ret1/temp, ret2/temp);
    }
    return 0;
}