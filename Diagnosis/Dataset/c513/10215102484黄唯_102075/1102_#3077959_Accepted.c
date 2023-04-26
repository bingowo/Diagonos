#include <stdio.h>
#include <math.h>
typedef long long int lli;
int main(void) {
lli n;
scanf("%lld", &n);
if(n == 0){
printf("(0,0)");
}else{
lli round = sqrt(n);
lli ox, oy; //开始点
lli bx; //这个是边界值
lli delta = n - round * round;
//因为会出现round算大了的情况（浮点数嘛……）所以要休整一下
while(delta < 0){
round --;
delta = n - round * round;
}
//分奇偶讨论
if(round % 2 == 0){
round /= 2;
ox = -1 * round;
oy = -1 * round;
bx = 1 * round;
//如果边界x与ox的差距很大很大，那么可以把ox跑满，然后算oy
if(delta > bx - ox){
delta -= (bx - ox);
ox = bx;
oy += delta;
}else{
ox += delta;
} }else{
round = (round + 1) / 2;
ox = 1 * (round - 1);
oy = 1 * (round - 1) + 1;
bx = -1 * (round - 1) - 1;
//同上
if(delta > ox - bx){
delta -= (ox - bx);
ox = bx;
oy -= delta;
}else{
ox -= delta;
} }
printf("(%lld,%lld)", ox, oy);
}
return 0; }