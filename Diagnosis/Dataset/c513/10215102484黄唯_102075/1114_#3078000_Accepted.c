#include <stdio.h>
#include <ctype.h>
//读取多项式，老轮子了
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
int main(void) {
char s[100];
int coe[3] = {0}, isValid = 0;
int a[2] = {0}, b[2] = {0}, temp;
scanf("%s", s);
ReadPoly(coe, s);
//枚举各种可能性
for(int i1 = 1; i1 <= 200; i1 ++){
if(i1 == 1 || coe[2] % i1 == 0){
for(int i0 = -200; i0 <= 200; i0 ++){
if(i0 != 0 && (i0 == -1 || i0 == 1 || coe[0] % i0 == 0)){
a[1] = i1, a[0] = i0;
b[1] = coe[2] / i1, b[0] = coe[0] / i0;
if(a[1] * b[0] + a[0] * b[1] == coe[1]){
isValid = 1;
goto out;
} } } } }
out:
//保证输出的顺序
if(a[1] > b[1]){
temp = a[1]; a[1] = b[1]; b[1] = temp;
temp = a[0]; a[0] = b[0]; b[0] = temp;
}else if(a[1] == b[1] && a[0] > b[0]){
temp = a[1]; a[1] = b[1]; b[1] = temp;
temp = a[0]; a[0] = b[0]; b[0] = temp; 
}
if(isValid){
printf("%d %d %d %d", a[1], a[0], b[1], b[0]);
}else{
printf("No Answer!");
}
return 0; }