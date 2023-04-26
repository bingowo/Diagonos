#include <stdio.h>
#include <math.h>
typedef struct{
int x, y;
}Point;
int reach(int axy/*目标点*/, int mapxy/*第一次路径上的点*/, int offsetxy/*偏移量*/) {
int ret;
if(offsetxy > 0 && axy >= mapxy && (axy - mapxy) % offsetxy == 0){
ret = (axy - mapxy) / offsetxy + 1; //表示循环多少次可以到达
}else if(offsetxy < 0 && axy <= mapxy && (axy - mapxy) % offsetxy == 0){
ret = (axy - mapxy) / offsetxy + 1; //表示循环多少次可以到达
}else if(offsetxy == 0 && axy == mapxy){
ret = 0; //表示总是可以到达
}else{
ret = -1; //没戏
}
return ret;
}
int main(void) {
char order[110];
scanf("%s", order);
char *p = order;
Point o = {0, 0}, offset = {0, 0};
int t, mapx[101], mapy[101];
while(*p){
//记录第一次轨迹经过的点
mapx[(p - order)] = o.x, mapy[(p - order)] = o.y;
switch(*p){
case 'U': o.y++; break;
case 'D': o.y--; break;
case 'L': o.x--; break;
case 'R': o.x++; break; }
p ++;
}
mapx[(p - order)] = o.x, mapy[(p - order)] = o.y;
//记录偏移量，也就是最后点的位置
offset = o;
scanf("%d", &t);
int x, y, isReachx = -1, isReachy = -1, len = p - order;
for(int i = 0 ; i < t; i ++){
scanf("%d %d", &x, &y);
for(int j = 0 ; j < len ; j ++){
isReachx = -1, isReachy = -1;
/*编程思维与实践-06.md 2022/3/28
24 / 67*/
isReachx = reach(x, mapx[j], offset.x);
isReachy = reach(y, mapy[j], offset.y);
/*if((均不设不可到达)且((有一个坐标（x或y）可以总是到达)或(经过同样次
数平移可以到达)))*/
if((isReachx != -1 && isReachy != -1) && (isReachx * isReachy == 0 ||
isReachx == isReachy)){
break; } }
//同上
if((isReachx != -1 && isReachy != -1) && (isReachx * isReachy == 0 ||
isReachx == isReachy)){
printf("Yes\n");
}else{
printf("No\n");
} }
return 0; }