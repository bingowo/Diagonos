#include <stdio.h>
#include <string.h>
#define LEN 1100
#define MOD 1000000007LL
typedef long long int lli;
void CountChoice(int c[], char w[], int n)
{
for(int i = 0 ; i < n ; i ++){
if(i == 0){
if(w[i] != w[i + 1]){
c[i] = 2; }else{
c[i] = 1; } }else if(i == n - 1){
if(w[i - 1] != w[i]){
c[i] = 2; }else{
c[i] = 1; } }else{
if(w[i - 1] != w[i] && w[i] != w[i + 1] && w[i - 1] != w[i + 1]){
c[i] = 3; }else if(w[i - 1] != w[i] || w[i] != w[i + 1]){
c[i] = 2; }else{
c[i] = 1; } } } }
int main(void) {
char w[LEN];
scanf("%s", w);
int len = strlen(w);
int choice[len];
if(len == 1){
choice[0] = 1; }else{
CountChoice(choice, w, len);
}
lli a = 1;
for(int i = 0 ; i < len ; i ++){
a *= choice[i];
a %= MOD;
}
printf("%lld", a);
/*编程思维与实践-06.md 2022/3/28
60 / 67*/
return 0; }