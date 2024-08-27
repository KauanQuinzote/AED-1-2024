#include <iostream>
#include <vector>
#include <algorithm>

// Estrutura para representar uma aresta com dois vértices (u, v) e um peso (weight).
struct Edge {
    int u, v, weight;
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

// Função para comparar arestas pelo seu peso, usada para ordenação.
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight; // Retorna true se o peso de a é menor que o de b
}

// Função que implementa o algoritmo de Kruskal para encontrar o custo da Árvore Geradora Mínima (MST).
int kruskalMST(std::vector<Edge>& edges, int M, int N) {
    // Ordena as arestas pelo peso em ordem crescente.
    std::sort(edges.begin(), edges.end(), compareEdges);

    // Inicializa os vetores de parent e rank
    std::vector<int> parent(M), rank(M, 0);
    for (int i = 0; i < M; i++) {
        parent[i] = i; // Cada vértice começa como seu próprio pai
    }

    int mstWeight = 0; // Inicializa o peso da MST
    int e = 0; // Contador para o número de arestas na MST
    
    // Processa cada aresta, da menor para a maior
    for (int i = 0; e < M - 1 && i < N; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        
        // Encontra os conjuntos dos dois vértices da aresta
        int setU = find(parent, u);
        int setV = find(parent, v);
        
        // Se u e v pertencem a conjuntos diferentes, a aresta é incluída na MST
        if (setU != setV) {
            mstWeight += edges[i].weight; // Adiciona o peso da aresta à MST
            unionSets(parent, rank, setU, setV); // Une os conjuntos de u e v
            e++; // Incrementa o número de arestas na MST
        }
    }

    return mstWeight; // Retorna o peso total da MST
}

int main() {
    int M, N;
    
    // Lê e processa múltiplos grafos até que M e N sejam ambos zero
    while (std::cin >> M >> N, M && N) {
        // Cria um vetor de arestas
        std::vector<Edge> edges(N);
        for (int i = 0; i < N; i++) {
            std::cin >> edges[i].u >> edges[i].v >> edges[i].weight; // Lê as arestas
        }

        // Calcula o peso da MST usando o algoritmo de Kruskal
        int result = kruskalMST(edges, M, N);
        
        // Imprime o resultado
        std::cout << result << std::endl;
    }

    return 0;
}
