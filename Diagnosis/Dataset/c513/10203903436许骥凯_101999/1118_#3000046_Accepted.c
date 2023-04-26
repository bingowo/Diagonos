#include<stdio.h>

void rotate(int (*graph)[200], int *w, int *h){
    int temp[200][200];
    for (int i = 0; i != *h; i++)
        for (int j = 0; j != *w; j++)
            temp[i][j] = graph[i][j];
    for (int i = 0; i != *w; i++)
        for (int j = 0; j != *h; j++)
            graph[i][j] = temp[*h - 1 - j][i];
    int t = *w;
    *w = *h;
    *h = t;
}


int main(){
    int w, h, d; char c; scanf("%d%d%d %c", &w, &h, &d, &c);
    d = (d % 360) / 90;
    if (c == 'L') d = (360 - d) % 360; 
    int graph[200][200];
    for (int i = 0; i != h; i++)
        for (int j = 0; j != w; j++)
            scanf("%d", &graph[i][j]);
    for (int i = 0; i != d; i++)
        rotate(graph, &w, &h);
    printf("%d %d\n", w, h);
    for (int i = 0; i != h; i++)
        for (int j = 0; j != w; j++)
            printf("%d%c", graph[i][j], j == w - 1? '\n': ' ');
    return 0;
}