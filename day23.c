#define INF 1000000000
int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
int dist[n][n];
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(i==j)
        dist[i][j]=0;
        else 
        dist[i][j]=INF;
    }
   }
for(int i = 0; i < edgesSize; i++){
    int u = edges[i][0];
    int v = edges[i][1];
    int w = edges[i][2];

    dist[u][v] = w;
    dist[v][u] = w;
}


for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dist[i][k] != INF && dist[k][j] != INF &&
               dist[i][k] + dist[k][j] < dist[i][j]){
                dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int minCount = INF;
int answer = -1;

for(int i = 0; i < n; i++){
    int count = 0;

    for(int j = 0; j < n; j++){
        if(i != j && dist[i][j] <= distanceThreshold){
            count++;
        }
    }

    // choose city with smaller count
    // if tie, choose bigger city number
    if(count < minCount || (count == minCount && i > answer)){
        minCount = count;
        answer = i;
    }
}
return answer;


}