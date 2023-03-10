#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 110, maxc = 1e2+10, maxv = 1e2+10;

int volume[maxn], peso[maxn], preco[maxn] , n, C, V;
long long dp[maxn][maxc][maxv];
bool vis[maxn][maxc][maxv];

long long programacao_dinamica(int i, int V, int C) {
	// Verifica se é o último item (caso base, não há mais itens para se considerar)
	if(i == n+1) return 0;
	
	
	// matriz de visitação (vis) é utilizado para saber se a posição já foi visitada anteriormente
	if(vis[i][C][V]) return dp[i][C][V];
	
	// Caso não tenha sido visitado ainda,a visita é feita:
	vis[i][C][V] = 1;
	
	// (Primeira possibilidade) Não adicionar o elemento
	dp[i][C][V] = programacao_dinamica(i+1, C, V);
	
	// (Segunda possibilidade) Adicionar o elemento caso não ultrapasse o limite de peso e volume
	// Devemos retirar o volume e o peso do item selecionado da capacidade
	if(C >= peso[i] && V >= volume[i]) 
		dp[i][C][V] = max(dp[i][C][V], programacao_dinamica(i+1, C - peso[i], V - volume[i]) + preco[i]);
	
	return dp[i][C][V];
	
}

int main() {
	// Entrando com o número de itens e a capacidade 
	scanf("%d %d %d", &n, &V, &C);
	
	// Entrando com os pesos, volumes e os valores de cada um dos itens
	for(int i = 1; i <= n; i++)
		scanf("%d %d %d", &volume[i], &peso[i], &preco[i]);
	
	// Exibindo a solução por programação dinâmica
	printf("%lld\n", programacao_dinamica(1, C, V));
	
}