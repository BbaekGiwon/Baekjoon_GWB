#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int w, h;
int** map;
int** visited;
int idx = 0;
int ardx = 0;
int testresult[5000];
int dx[8] = { 0,0,1,-1,1,-1,1,-1};
int dy[8] = { 1,-1,0,0,1,-1,-1,1};


void DFS(int, int);

int main() {
   int i,j;
   
   while (1) {
      idx = 0;
      scanf("%d %d", &w,&h);
      if (w == 0 && h == 0) {
         ardx--;
         break;
      }

      map = (int**)malloc(sizeof(int*) * h);
      visited = (int**)malloc(sizeof(int*) * h);
      for (i = 0; i < h; i++) {
         map[i] = (int*)malloc(sizeof(int) * w);
         visited[i] = (int*)malloc(sizeof(int) * w);
      }

      for (i = 0; i < h; i++) {
         for (j = 0; j < w; j++) {
            scanf("%d",&map[i][j]);
            visited[i][j] = 0;
         }
      }

      for (i = 0; i < h; i++) {
         for (j = 0; j < w; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
               idx++;
               DFS(i, j);
            }
         }
      }
      testresult[ardx] = idx;
      printf("%d\n", testresult[ardx++]);

      for (i = 0; i < h; i++) {
         free(map[i]);
         free(visited[i]);
      }
      free(map);
      free(visited);

   }
   int temp = 0;
   while (temp<=ardx) {
      printf("%d\n", testresult[temp++]);
      
   }
   
   return 0;
}

void DFS(int starti,int startj) {
   int i;
   visited[starti][startj] = idx;
   
   for (i = 0; i < 8; i++) {
      if (starti + dy[i] >= 0 && starti + dy[i] < h && startj+dx[i] >=0 && startj+dx[i] <w) {
         if (map[starti + dy[i]][startj+dx[i]] == 1 && visited[starti + dy[i]][startj+dx[i]] == 0) {
            DFS(starti + dy[i], startj+dx[i]);
         }
      }
   }

}
