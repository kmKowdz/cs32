#define N 15
typedef struct graph Graph;

struct graph{
	int n;
	int C[N][N];
	int D[N][N];
	int pred[N][N];
};

//function to get the values from the buf; returns a graph
Graph GET_VALUES(char buf[], Graph G, int i){
	char *p = strtok(buf, " ");
	char x;
	int j = 1;

	while(p != NULL)
	{
		if(*p == 'x'){
			G.C[i][j] = 9999;
		}else{
			G.C[i][j] = atoi(p);
		}
		j++;
		p = strtok(NULL, " ");
	}
	G.n = j-1;
	return G;
}

//function to display the shortest path found and its cost
void DISPLAY_PATH(Graph G,int i,int j){
	int path[N];
	int len = 1;
	path[len] = j;
	int k = j;

	while(k != i){
		if (G.pred[i][k] == 0){
			printf("vertex %d to vertex %d: No Path Found\n", i, j);
			return;
		}else{
			k = G.pred[i][k];
			len = len + 1;
			path[len] = k;
		}
	}
	if(i != j){
		printf("vertex %d to vertex %d: %d ", i, j, path[len]);
		len--;
		while(len > 0){
			printf("-> %d ", path[len]);
			len--;
		}
		printf("(Cost = %d)\n", G.D[i][j]);
	}
}

//function for Floyd Algorithm; returns a Graph
Graph FLOYD(Graph G){
	int x = 9999, dijk;
	int i,j,k;

	//Initializations
	memcpy(G.D, G.C, sizeof(G.D));
	
	for(i = 1; i <= G.n; i++){
		for(j = 1; j <= G.n; j++){
			if (j == i || G.C[i][j] == x){
				G.pred[i][j] = 0;
			} else {
				G.pred[i][j] = i;
			}
		}
	}

	//Floyd's Algorithm
	for(k = 1; k <= G.n; k++){
		for(i = 1; i <= G.n; i++){
			for(j = 1; j <= G.n; j++){
				dijk = G.D[i][k] + G.D[k][j];
				if (dijk < G.D[i][j]){
					G.D[i][j] = dijk;
					G.pred[i][j] = G.pred[k][j];
				}
			}
		}
	}

	return G;
}
