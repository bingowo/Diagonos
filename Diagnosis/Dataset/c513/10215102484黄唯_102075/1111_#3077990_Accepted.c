#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 4
//存储某个点是否为函数图像上的点（1表示是）
int map[41][41];
//多项式读取函数，如果完成1041问可以跳过
void ReadPoly(int n[], char s[])
{
char *p = s;
int sgn, coe, exp;
int isConst, isMonomial;
while(*p){
sgn = 1, coe = 0, exp = 0;
isConst = 1, isMonomial = 1;
if(*p == '+' || *p == '-'){
if(*p == '-'){
sgn = -1; }else{
sgn = 1; }
p ++;
}
if(*p && isdigit(*p)){
while(*p && isdigit(*p)){
coe = coe * 10 + (*p - '0');
p ++;
}
coe *= sgn;
}
if(*p == 'x'){
if(coe == 0){
coe = 1 * sgn;
}
isConst = 0;
p ++;
}
if(*p == '^'){
isMonomial = 0;
p ++;
}
if(*p && isdigit(*p)){
while(*p && isdigit(*p)){
exp = exp * 10 + (*p - '0');
p ++;
} }
if(isConst){
n[0] = coe;

}else if(isMonomial){
n[1] = coe;
}else{
n[exp] = coe;
} } }
void f(int x, int n[])
{
int ty = 0, tx = 1;
for(int i = 0 ; i < N; i ++){
for(int j = 0 ; j < i; j ++){
tx *= x;
}
ty += tx * n[i];
tx = 1; }
if(ty >= -20 && ty <= 20){
 //将负数进行映射
tx = x < 0 ? 20 - x : x;
ty = ty < 0 ? 20 - ty : ty;
map[tx][ty] = 1; } }
int main(void) {
char s[100];
int coe[N];
while(scanf("%s", s) != EOF){
 //初始化
memset(coe, 0, sizeof(coe));
memset(map, 0, sizeof(map));
ReadPoly(coe, s + 5);
 //测试每个点在哪里
for(int x = -20; x <= 20; x ++){
f(x, coe);
}
for(int y = 20, ty; y >= -20; y --){
for(int x = -20, tx; x <= 20; x ++){
tx = x < 0 ? 20 - x : x;
ty = y < 0 ? 20 - y : y;
 //无聊的画图过程
if(x == 0 && y == 0){
if(map[tx][ty]){
printf("*");
}else{
printf("+");
} 
}else if(x == 0 && y == 20){
if(map[tx][ty]){
printf("*");
}else{

printf("^");
} }else if(x == 0 && y < 20){
if(map[tx][ty]){
printf("*");
}else{
printf("|");
} }else if(x == 20 && y == 0){
if(map[tx][ty]){
printf("*\n");
}else{
printf(">\n");
} }else if(x < 20 && y == 0){
if(map[tx][ty]){
printf("*");
}else{
printf("-");
} 
}else if(x == 20){
if(map[tx][ty]){
printf("*\n");
}else{
printf(".\n");
} 
}else{
if(map[tx][ty]){
printf("*");
}else{
printf(".");
} 
} } }
printf("\n");
}
return 0; }