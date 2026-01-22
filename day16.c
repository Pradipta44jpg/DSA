#include <stdio.h>
#include<stdlib.h>
#define INF 99999
 int main(){
     int n=4;
     int dist[4][4]={
        {0,   5,   INF, 10},
        {INF, 0,   3,  INF},
        {INF, INF, 0,  1},
        {INF, INF, INF, 0}
    };
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              for( int k=0;k<n;k++){
                  if(dist[i][j]>dist[i][k]+dist[j][k]){
                      dist[i][j]=dist[i][k]+dist[j][k];
                  }
              }
          }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}