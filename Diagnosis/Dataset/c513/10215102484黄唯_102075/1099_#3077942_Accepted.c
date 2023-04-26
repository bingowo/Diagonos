#include <stdio.h>
#include <string.h>
//读取字母和数字
char ReadMorese(char s[])
{
char ret;
if(strcmp(s, ".-") == 0){
ret = 'A'; }else if(strcmp(s, "-...") == 0){
ret = 'B'; }else if(strcmp(s, "-.-.") == 0){
ret = 'C'; }else if(strcmp(s, "-..") == 0){
ret = 'D'; }else if(strcmp(s, ".") == 0){
ret = 'E'; }else if(strcmp(s, "..-.") == 0){
ret = 'F'; }else if(strcmp(s, "--.") == 0){
ret = 'G'; }else if(strcmp(s, "....") == 0){
ret = 'H'; }else if(strcmp(s, "..") == 0){
ret = 'I'; }else if(strcmp(s, ".---") == 0){
ret = 'J'; }else if(strcmp(s, "-.-") == 0){
ret = 'K'; }else if(strcmp(s, ".-..") == 0){
ret = 'L'; }else if(strcmp(s, "--") == 0){
ret = 'M'; }else if(strcmp(s, "-.") == 0){
ret = 'N'; }else if(strcmp(s, "---") == 0){
ret = 'O'; }else if(strcmp(s, ".--.") == 0){
ret = 'P'; }else if(strcmp(s, "--.-") == 0){
ret = 'Q'; }else if(strcmp(s, ".-.") == 0){
ret = 'R'; }else if(strcmp(s, "...") == 0){
ret = 'S'; }else if(strcmp(s, "-") == 0){
ret = 'T'; }else if(strcmp(s, "..-") == 0){
ret = 'U'; }else if(strcmp(s, "...-") == 0){
ret = 'V';

}else if(strcmp(s, ".--") == 0){
ret = 'W'; }else if(strcmp(s, "-..-") == 0){
ret = 'X'; }else if(strcmp(s, "-.--") == 0){
ret = 'Y'; }else if(strcmp(s, "--..") == 0){
ret = 'Z'; }else if(strcmp(s, "-----") == 0){
ret = '0'; }else if(strcmp(s, ".----") == 0){
ret = '1'; }else if(strcmp(s, "..---") == 0){
ret = '2'; }else if(strcmp(s, "...--") == 0){
ret = '3'; }else if(strcmp(s, "....-") == 0){
ret = '4'; }else if(strcmp(s, ".....") == 0){
ret = '5'; }else if(strcmp(s, "-....") == 0){
ret = '6'; }else if(strcmp(s, "--...") == 0){
ret = '7'; }else if(strcmp(s, "---..") == 0){
ret = '8'; }else if(strcmp(s, "----.") == 0){
ret = '9'; }else if(strcmp(s, "/") == 0){
ret = ' '; }else if(strcmp(s, "///") == 0){
ret = '.'; }
return ret;
}
int main(void) {
int t;
scanf("%d", &t);
for(int i = 0 ; i < t; i ++){
char s[1100];
scanf("%s", s);
char *p1 = s, *p2 = s;
char temp[1000];
printf("case #%d:\n", i);
while(*p2){
if(*p2 == '/'){
memmove(temp, p1, p2 - p1);
temp[p2 - p1] = '\0';
printf("%c", ReadMorese(temp));
p2 ++;
p1 = p2;

if(*p2 == '/'){
while(*p2 == '/'){p2 ++;} //以便于读取多个'/'
p2 --;
} }else{
p2 ++;
} }
//一般while后都需要做一些尾部处理，这个地方如果'/'结尾
if(*(p2 - 1) != '/'){
memmove(temp, p1, p2 - p1);
temp[p2 - p1] = '\0';
printf("%c\n", ReadMorese(temp));
}else{
printf("\n");
} }
return 0; }