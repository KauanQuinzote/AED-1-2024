#include <iostream>
#include <vector>
#include <queue>
#include <climits> // Para INT_MAX

using namespace std;

const int INF = INT_MAX; // Constante para representar a infinidade

// Tamanho máximo do grafo
const int MAX_N = 1010;

// Matrizes para armazenar o grafo e os custos
int graph[MAX_N][MAX_N];
int cost[MAX_N];

// Fila para o algoritmo de Dijkstra
queue<int> q;

// Função para inicializar o grafo e o vetor de custo
void initialize() {
    for (int i = 0; i < MAX_N; i++) {
        cost[i] = INF;
        for (int j = 0; j < MAX_N; j++) {
            graph[i][j] = INF; // Inicializa todos os pesos com infinito
        }
    }
}

// Algoritmo de Dijkstra para encontrar o menor caminho
int dijkstra(int source, int destination, int n) {
    cost[source] = 0; // O custo para a origem é zero
    q.push(source); // Adiciona a origem na fila

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Atualiza os custos dos vizinhos
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INF && cost[v] > cost[u] + graph[u][v]) {
                cost[v] = cost[u] + graph[u][v];
                q.push(v);
            }
        }
    }
    return cost[destination]; // Retorna o custo mínimo para o destino
}

int main() {
    int n, m, c, k;

    // Lê a entrada até que todos os valores sejam zero
    while (cin >> n >> m >> c >> k, (n || m || c || k)) {
        initialize(); // Inicializa o grafo e os custos

        // Lê as arestas e seus custos
        for (int i = 0; i < m; i++) {
            int u, v, p;
            cin >> u >> v >> p;

            // Adiciona a aresta com base nas condições
            if (u >= c && v >= c) {
                graph[u][v] = p;
                graph[v][u] = p;
            }
            if (u >= c && v < c) {
                graph[u][v] = p;
            }
            if (u < c && v >= c) {
                graph[v][u] = p;
            }
            if (u < c && v < c && abs(u - v) == 1) {
                graph[u][v] = p;
                graph[v][u] = p;
            }
        }

        // Executa o algoritmo de Dijkstra e imprime o custo mínimo
        cout << dijkstra(k, c - 1, n) << endl;
    }

    return 0;
}
