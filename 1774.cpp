#include <iostream>
#include <vector>
#include <algorithm>

// Estrutura para representar uma aresta com dois vértices (u, v) e um custo (cost).
struct Edge {
    int u, v, cost;
};

// Função para encontrar a raiz de um conjunto com compressão de caminho.
int find(std::vector<int>& parent, int i) {
    // Se o próprio elemento é o pai, ele é a raiz
    if (parent[i] == i)
        return i;
    // Caso contrário, seguimos recursivamente até a raiz e aplicamos compressão de caminho
    return parent[i] = find(parent, parent[i]);
}

// Função para unir dois conjuntos baseando-se na sua "rank".
void unionSets(std::vector<int>& parent, std::vector<int>& rank, int u, int v) {
    // Encontramos as raízes dos conjuntos de u e v
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    
    // Unimos os conjuntos com base na rank (altura)
    if (rank[rootU] < rank[rootV])
        parent[rootU] = rootV;
    else if (rank[rootU] > rank[rootV])
        parent[rootV] = rootU;
    else {
        // Se as ranks são iguais, fazemos um ser raiz do outro e incrementamos sua rank
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

// Função para comparar arestas pelo seu custo, usada para ordenação.
bool compareEdges(const Edge& a, const Edge& b) {
    return a.cost < b.cost; // Retorna true se o custo de a é menor que o de b
}

// Função que implementa o algoritmo de Kruskal para encontrar o custo da Árvore Geradora Mínima (MST).
int kruskalMST(std::vector<Edge>& edges, int R, int C) {
    // Ordena as arestas pelo custo em ordem crescente.
    std::sort(edges.begin(), edges.end(), compareEdges);

    // Inicializa os vetores de parent e rank
    std::vector<int> parent(R + 1), rank(R + 1, 0);
    for (int i = 1; i <= R; i++) {
        parent[i] = i; // Cada vértice começa como seu próprio pai
    }

    int mstCost = 0; // Inicializa o custo da MST
    int e = 0; // Contador para o número de arestas na MST
    
    // Processa cada aresta, da menor para a maior
    for (int i = 0; e < R - 1 && i < C; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        
        // Encontra os conjuntos dos dois vértices da aresta
        int setU = find(parent, u);
        int setV = find(parent, v);
        
        // Se u e v pertencem a conjuntos diferentes, a aresta é incluída na MST
        if (setU != setV) {
            mstCost += edges[i].cost; // Adiciona o custo da aresta à MST
            unionSets(parent, rank, setU, setV); // Une os conjuntos de u e v
            e++; // Incrementa o número de arestas na MST
        }
    }

    return mstCost; // Retorna o custo total da MST
}

int main() {
    int R, C;
    std::cin >> R >> C; // Lê o número de vértices (R) e arestas (C)
    
    // Cria um vetor de arestas
    std::vector<Edge> edges(C);
    for (int i = 0; i < C; i++) {
        std::cin >> edges[i].u >> edges[i].v >> edges[i].cost; // Lê as arestas
    }

    // Calcula o custo da MST usando o algoritmo de Kruskal
    int result = kruskalMST(edges, R, C);
    
    // Imprime o resultado
    std::cout << result << std::endl;

    return 0;
}
