#include <stdio.h>
#include <queue>
#include <math.h>
#include <iostream>
#include <limits.h>

using namespace std;

struct state{
	int digit[4];
	int depth;
};

state target;

int moves [8][4]= {  {-1, 0, 0, 0 },
					 { 1, 0, 0, 0 },
					 { 0,-1, 0, 0 },
					 { 0, 1, 0, 0 },
					 { 0, 0,-1, 0 }, 
					 { 0, 0, 1, 0 },
					 { 0, 0, 0,-1 },
					 { 0, 0, 0, 1 } };


void next_states(state s, state next[8]){
	int i,j;

	for(i=0; i<8; i++){
		next[i] = s;
		next[i].depth = s.depth+1;
		for(j=0; j<4; j++){
			next[i].digit[j] += moves[i][j];
			if (next[i].digit[j]<0)
				next[i].digit[j] = 9;
			if (next[i].digit[j]>9)
				next[i].digit[j] = 0;
		}
	}

}


int equal(state s, state e){
	int i;
	for (i=0; i<4; i++)
		if (s.digit[i] != e.digit[i])
			return 0;

	return 1;
}

int min_dist(int x, int y){
	int dist = INT_MAX;
	dist = min(dist, abs(x-y));
	dist = min(dist, abs(10+x-y));
	dist = min(dist, abs(x-y-10));

	return dist;
}

int h(state x, state y){
	return min_dist(x.digit[0], y.digit[0]) + min_dist(x.digit[1], y.digit[1]) + min_dist(x.digit[2], y.digit[2]) + min_dist(x.digit[3], y.digit[3]);
}

struct cmpState {
    bool operator()(state const& x, state const& y){
        return x.depth + h(x, target) > y.depth + h(y, target);
    }
};

int bfs(state current, state final, int visited[10][10][10][10]){
	state next[8];
	int i;
	// queue<state> q;
	priority_queue <state, vector<state>, cmpState > pq;

	// o estado inicial pode ser invalido !!!!
	if (!visited[current.digit[0]][current.digit[1]][current.digit[2]][current.digit[3]]){
		visited[current.digit[0]][current.digit[1]][current.digit[2]][current.digit[3]] = 1;
		// q.push(current);
		pq.push(current);

		while(!pq.empty()) {
			current = pq.top();
			pq.pop();
			// current = q.front();
			// q.pop();
			// chegou no estado final.. basta terminar (este é o nivel minino!!!) e mostrar o nivel que saiu da árvore...!
			if (equal(current, final))
				return current.depth;
			// nao é igual.. entao, calcula todos os proximos estados e continua a busca em largura.....
			next_states(current, next);
			for (i=0; i<8; i++){
				if (!visited[next[i].digit[0]][next[i].digit[1]][next[i].digit[2]][next[i].digit[3]]){
					visited[next[i].digit[0]][next[i].digit[1]][next[i].digit[2]][next[i].digit[3]] = 1;
					pq.push(next[i]);
				}
			}
		}
	}
	return -1;
}


int main (){
	int nr_testes, test, forbidden, i,j,k,l,d;
	int visited[10][10][10][10];
	state initial, final, aux;

	scanf("%d", &nr_testes);
	for (test=0; test<nr_testes; test++){
		scanf("%d %d %d %d", &initial.digit[0], &initial.digit[1], &initial.digit[2], &initial.digit[3]);
		scanf("%d %d %d %d", &final.digit[0], &final.digit[1], &final.digit[2], &final.digit[3]);
		scanf("%d", &forbidden);

		for(i=0; i<10; i++)
			for(j=0; j<10; j++)
				for(k=0; k<10; k++)
					for(l=0; l<10; l++)
						visited[i][j][k][l] = 0;

		for(i=0; i<forbidden; i++) {
			scanf("%d %d %d %d", &aux.digit[0], &aux.digit[1], &aux.digit[2], &aux.digit[3]);
			visited[aux.digit[0]][aux.digit[1]][aux.digit[2]][aux.digit[3]] = 1;
		}
		initial.depth=0;
		target = final;
		printf("%d\n", bfs(initial, final, visited));
	}

	// priority_queue <state, vector<state>, cmpState > pq;
	// target.digit[0] = 9;
	// target.digit[1] = 9;
	// target.digit[2] = 9;
	// target.digit[3] = 9;
	// target.depth = 0;
	
	// state a;
	// a.digit[0] = 9;
	// a.digit[1] = 9;
	// a.digit[2] = 9;
	// a.digit[3] = 8;
	// a.depth = 1;
	// state ab;
	// ab.digit[0] = 9;
	// ab.digit[1] = 9;
	// ab.digit[2] = 9;
	// ab.digit[3] = 9;
	// ab.depth = 3;
	// state ca;
	// ca.digit[0] = 9;
	// ca.digit[1] = 7;
	// ca.digit[2] = 9;
	// ca.digit[3] = 9;
	// ca.depth = 0;

	// pq.push(a);
	// pq.push(ab);
	// pq.push(ca);

	// while(!pq.empty()) {
	// 	state current = pq.top();
	// 	cout << current.digit[0] << current.digit[1] << current.digit[2] << current.digit[3] << " " << current.depth << endl;

	// 	pq.pop();
	// }


	return 0;


}