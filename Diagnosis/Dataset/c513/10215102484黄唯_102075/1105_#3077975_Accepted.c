#include <stdio.h>
int main(void) {
int w, h;
scanf("%d %d", &w, &h);
int graph[h][w];
for(int i = 0 ; i < h ; i ++){
for(int j = 0 ; j < w; j ++){
scanf("%d", &graph[i][j]);
} }
int cmp[8], min = 255, t = 0, lbp[h - 2][w - 2];
for(int i = 1; i < h - 1; i ++){
for(int j = 1; j < w - 1 ; j++){
min = 255, t = 0;
cmp[0] = graph[i - 1][j - 1] >= graph[i][j] ? 1 : 0;
cmp[1] = graph[i - 1][j] >= graph[i][j] ? 1 : 0;
cmp[2] = graph[i - 1][j + 1] >= graph[i][j] ? 1 : 0;
cmp[3] = graph[i][j + 1] >= graph[i][j] ? 1 : 0;
cmp[4] = graph[i + 1][j + 1] >= graph[i][j] ? 1 : 0;
cmp[5] = graph[i + 1][j] >= graph[i][j] ? 1 : 0;
cmp[6] = graph[i + 1][j - 1] >= graph[i][j] ? 1 : 0;
cmp[7] = graph[i][j - 1] >= graph[i][j] ? 1 : 0;
for(int i = 0 ; i < 8; i ++){
for(int j = 0; j < 8; j ++){
t = t * 2 + cmp[(j + i) % 8];
}
min = t < min ? t : min ;
t = 0; }
lbp[i - 1][j - 1] = min; } }
for(int i = 0 ; i < h - 2; i ++){
for(int j = 0 ; j < w - 2; j ++){
printf("%d%c", lbp[i][j], j == w - 3 ? '\n' : ' ');
} }
return 0; }