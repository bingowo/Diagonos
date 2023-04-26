#include <stdio.h>
#include <ctype.h>
#include <math.h>
int main(void) {
char s[100];
scanf("%s", s);
char *p = s, c;
int isLeft = 1;
int num = 0, coe = 0;
int t = 0, sgn = 1;
while(*p){
if(isdigit(*p)){
while(*p && isdigit(*p)){
t = t * 10 + (*p - '0');
p ++;
} }else if(*p == '+'){
if(t != 0 ){
num += isLeft * sgn * t;
t = 0, sgn = 1; }else{
 /*如果符号下一个是字母，说明系数为1，下面‘-’相同*/
if(isalpha(*(p + 1))){
coe += 1;
c = *(p + 1);
p += 2; }else{
sgn = 1;
p ++;
} 
} }else if(*p == '-'){
if(t != 0 ){
num += isLeft * sgn * t;
t = 0, sgn = 1; }else{
if(isalpha(*(p + 1))){
coe -= 1;
c = *(p + 1);
p += 2; }else{
sgn = -1;
p ++;
} 
} }else if(isalpha(*p)){
if(t == 0){
 //读无符号首字母的时候需要这样做

coe += isLeft * sgn * 1; }else{
coe += isLeft * sgn * t;
}
t = 0, c = *p, sgn = 1;
p ++;
}else if(*p == '='){
if(t != 0 ){
num += isLeft * sgn * t;
t = 0, sgn = 1; }
isLeft = -1;
p ++;
} }
if(t != 0){
num += isLeft * sgn * t;
}
 //由于会出现-0.000的弱智情况，所以单独判断一下。要注意浮点数不能直接判断等于
if(fabs((double)num / (double)coe) < 1e-6){
printf("%c=0.000", c);
}else{
printf("%c=%.3lf", c, -1 * (double)num / (double)coe);
}
return 0; }