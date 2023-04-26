#include <stdio.h>
int main(void)
{
int t;
scanf("%d", &t);
for(int i = 0 ; i < t; i ++){
int n, isEqual = 1, a, b;
int visit[101][101] = {{0, 0}}, inmap[101] = {0}, outmap[101] = {0};
scanf("%d", &n);
for(int j = 0 ; j < n ; j ++){
scanf("%d %d", &a, &b);
if(!visit[a][b]){
inmap[a] ++, outmap[b] ++;
// 这是要排除重复的指令，将已经读到的指令存储到visit中
visit[a][b] = 1;
}
}
for(int i = 0 ; i < 101 ; i ++){
if(inmap[i] > 1){
isEqual = 0;
}else if(inmap[i] && outmap[i]){
isEqual = 0;
}
}
if(isEqual){
printf("Lucky dxw!\n");
}else{
printf("Poor dxw!\n");
}
}
return 0;
}