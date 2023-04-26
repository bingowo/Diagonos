#include <stdio.h>
int main(void) {
int a[9], t;
scanf("%d", &t);
for(int i = 0 ; i < t; i ++){
int isZero = 1, isInit = 1;
for(int j = 0 ; j < 9; j ++){
scanf("%d", &a[j]);
if(a[j] != 0){
isZero = 0; } }
printf("case #%d:\n", i);
if(isZero){
printf("0");
}else{
for(int j = 0 ; j < 9 ; j ++){
if(a[j] != 0){
 //if和else中的语句几乎相同，除了符号处理不一样（'+'可以强制显示符号
if(isInit/*是否是首项*/){
if(j < 7){
if(a[j] == -1){
printf("-x^%d", 8 - j);
}else if(a[j] == 1){
printf("x^%d", 8 - j);
}else{
printf("%dx^%d", a[j], 8 - j);
} 
}else if(j == 7){
if(a[j] == -1){
printf("-x", 8 - j);
}else if(a[j] == 1){
printf("x", 8 - j);
}else{
printf("%dx", a[j], 8 - j);
} 
}else{
printf("%d", a[j]);
}
isInit = 0; }else{
if(j < 7){
if(a[j] == -1){
printf("-x^%d", 8 - j);
}else if(a[j] == 1){
printf("+x^%d", 8 - j);
}else{
printf("%+dx^%d", a[j], 8 - j);
/*编程思维与实践-07.md 2022/4/3
4 / 30*/
} 
}else if(j == 7){
if(a[j] == -1){
printf("-x", 8 - j);
}else if(a[j] == 1){
printf("+x", 8 - j);
}else{
printf("%+dx", a[j], 8 - j);
} 
}else{
printf("%+d", a[j]);
} } } } }
printf("\n");
}
return 0; }