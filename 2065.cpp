#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;  // Lê o número de clientes e o número de serviços
    vector<int> time(n);

    for (int i = 0; i < n; i++)
        cin >> time[i];  // Lê o tempo necessário para cada cliente

    // Fila de prioridade para gerenciar o tempo dos clientes (mínimo no topo)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> customer;

    for (int i = 0; i < n; i++)
        customer.push({0, i});  // Inicializa todos os clientes com tempo de 0

    int max_time = 0;
    for (int i = 0; i < m; i++)
    {
        int c;
        cin >> c;  // Lê o número de serviços para o cliente atual

        int end_time, id;
        tie(end_time, id) = customer.top();  // Obtém o cliente com o menor tempo de término

        customer.pop();

        int time = time[id] * c;  // Calcula o tempo total necessário para o cliente atual
        max_time = max(max_time, end_time + time);  // Atualiza o tempo máximo necessário

        customer.push({end_time + time, id});  // Adiciona o cliente de volta com o novo tempo de término
    }
    cout << max_time << endl;  // Imprime o tempo máximo necessário
}
