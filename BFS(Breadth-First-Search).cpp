#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define MAX 100
int i, j, k, l=0, n, qu[MAX], ribs_arr[MAX][MAX], p[MAX], father=0;

int front=0, rare=0, v=0, visit[MAX], visited[MAX];

int G[MAX][2], ribs;
vector <int> M[MAX];
vector <int> Level[MAX];
vector <int> path_arr;

 
void spisuk_na_rebra() {
	cout << "Enter the number of ribs: ";
	cin >> ribs;

	for (int i = 0; i < ribs; i++) {
		cout << "\tEnter rib " << i + 1 << ": " << endl;
		for (int j = 0; j < 2; j++)
			cin >> G[i][j];
	}
}


void Spisuk_ot_Susedi() {

	for (i = 1; i <= n; i++) {
		M[i].push_back(0);
	}

	for (i = 0; i < ribs; i++) {
		M[G[i][0]].push_back(G[i][1]);
		M[G[i][0]].at(0) += 1;
		M[G[i][1]].push_back(G[i][0]);
		M[G[i][1]].at(0) += 1;
	}
}



void path(int r) {
	if (r != v) {
		path_arr.push_back(r);
		path(p[r]);
	}
}



int main() {
	cout << "Number of V: ";
	cin >> n;

	spisuk_na_rebra();
	Spisuk_ot_Susedi();

	cout << "Enter initial vertex: ";
	cin >> v;
	cout << "Visited vertices \n";
	cout << v << " ";
	visited[v] = 1;
  p[v] = 0;
	k = 1;
	father = v;

	M[father][0] = 1;
	Level[1].push_back(v);
	l = 1;

	while (k < n) {
		for (auto it = M[v].begin() + 1; it != M[v].end(); it++) {
			if (visited[*it] != 1 && visit[*it] != 1) {
				p[*it] = father;
				visit[*it] = 1;
				M[*it][0] = M[father][0] + 1;
				Level[M[*it][0]].push_back(*it);
				l = M[*it][0];
				qu[rare++] = *it;
			}
		}
		v = qu[front++];
		father = v;
		cout << v << " ";
		k++;
		visit[v] = 0; visited[v] = 1; 
	}
	cout << endl;
  

	for (i = 1; i <= l; i++) {
  cout << "Level " << i << " verticles: " << endl; 
		for (auto it = Level[i].begin(); it != Level[i].end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
  
  
  for(i = 1; i <= n; i++) {
     cout << i << " : " << p[i] << endl;
  }
	

	return 0;
}

