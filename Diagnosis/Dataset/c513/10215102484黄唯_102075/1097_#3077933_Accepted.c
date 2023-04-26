#include <stdio.h>
#include <stdlib.h>
typedef struct{
char c;
int space; //存储空格数
int line; //存储第几行
}Chr;
int cmp(const void *a, const void *b)
{
Chr *pa = (Chr *)a;
Chr *pb = (Chr *)b;
if(pa->line != pb->line){
return pb->line - pa->line; }else{
return pa->space - pb->space;
} }
void PrintSpace(int n){ for(int i = 0 ; i < n ; i ++){ printf(" ");}}
int main(void) {
char s[100];
while(scanf("%s", s) != EOF){
char *p = s;
int num = 0, l = 0;
while(*p){p ++, num ++;}
Chr in[num];
p = s, num = 0;
while(*p){
in[num].c = *p;
in[num].space = num;
if(p == s || *p > *(p - 1)){
l ++;
in[num].line = l;
}else if (*p < *(p - 1)){
l --;
in[num].line = l;
}else{
in[num].line = l ;
}
p ++, num ++;
}
qsort(in, num, sizeof(Chr), cmp);
for(int i = 0, isInit = 1, offset = 0; i < num; i ++){
if(isInit){
PrintSpace(in[i].space);
printf("%c", in[i].c);
if(i != num - 1 && in[i].line != in[i + 1].line){

isInit = 1;
printf("\n");
}else{
offset = in[i].space + 1, isInit = 0; } }else{
PrintSpace(in[i].space - offset);
printf("%c", in[i].c);
offset = in[i].space + 1;
if(i != num - 1 && in[i].line != in[i + 1].line){
isInit = 1;
printf("\n");
} } }
printf("\n");
}
return 0; }