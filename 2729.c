#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura de nó para a lista encadeada
typedef struct node
{
    char item[21];
    struct node *next;
} Node;

// Protótipos das funções
void filling_array(char array[20001], int size);
Node *separate_words(char array[20001]);
void insert_at_end(Node **head, char word[21]);
void printing_list(Node *list);
void verifying_list(Node **list);
void order(Node **list);

// Função principal
int main(void)
{
    // Declaração de variáveis
    int amount, i;
    char array[20001]; // Array para armazenar os dados de entrada
    Node *list = NULL; // Inicialização da lista encadeada como vazia

    // Leitura da quantidade de casos de teste
    scanf("%i", &amount);

    // Loop para processar cada caso de teste
    for (i = 0; i <= amount; i++)
    {
        // Preenchendo o array com os dados de entrada
        filling_array(array, sizeof(array));

        // Separando as palavras do array e criando a lista encadeada
        list = separate_words(array);

        // Removendo duplicatas da lista, se houver
        verifying_list(&list);

        // Ordenando a lista em ordem alfabética
        order(&list);

        // Imprimindo os elementos da lista
        printing_list(list);

        // Libera a memória alocada para os nós da lista
        Node *current = list;
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }

    // Libera a memória alocada para os nós restantes da lista
    while (list != NULL)
    {
        Node *temp = list;
        list = list->next;
        free(temp);
    }
   
    return 0;
}

// Função para preencher o array com os dados de entrada
void filling_array(char array[20001], int size)
{
    setbuf(stdin, NULL); // Limpa o buffer do stdin
    fgets(array, size, stdin); // Lê uma linha de texto do stdin
    array[strcspn(array, "\n")] = '\0'; // Remove o caractere de nova linha, se houver
}

// Função para separar as palavras do array e criar a lista encadeada
Node *separate_words(char array[20001])
{
    Node *list = NULL; // Inicializa a lista como vazia
    char *token = strtok(array, " "); // Divide a string em tokens usando o espaço como delimitador

    // Loop para iterar sobre os tokens e criar os nós da lista
    while (token != NULL)
    {
        insert_at_end(&list, token); // Insere o token no final da lista
        token = strtok(NULL, " "); // Obtém o próximo token
    }
    return list; // Retorna a lista encadeada resultante
}

// Função para inserir um novo nó no final da lista
void insert_at_end(Node **head, char word[21])
{
    Node *aux, *new_node = (Node *)malloc(sizeof(Node)); // Aloca memória para o novo nó

    if (new_node) // Verifica se a alocação de memória foi bem-sucedida
    {
        strcpy(new_node->item, word); // Copia a palavra para o novo nó
        new_node->next = NULL; // Define o próximo do novo nó como NULL

        // Verifica se a lista está vazia
        if (*head == NULL)
            *head = new_node; // Se estiver vazia, define o novo nó como o primeiro nó da lista
        else
        {
            // Se não estiver vazia, percorre a lista até encontrar o último nó
            aux = *head;
            while (aux->next)
                aux = aux->next;
            // Insere o novo nó no final da lista
            aux->next = new_node;
        }
    }
}

// Função para imprimir os elementos da lista
void printing_list(Node *list)
{
    Node *current = list; // Inicializa o ponteiro atual como o primeiro nó da lista

    // Loop para iterar sobre os nós da lista e imprimir os itens
    while (current != NULL)
    {
        printf("%s ", current->item); // Imprime o item do nó atual
        current = current->next; // Move para o próximo nó
    }

    // Quando o ponteiro atual se torna NULL, indica o final da lista
    // Imprime uma nova linha para separar os resultados de cada caso de teste
    if (current == NULL)
        printf("\n");
}

// Função para remover duplicatas da lista
void verifying_list(Node **list)
{
    Node *current = *list; // Inicializa o ponteiro atual como o primeiro nó da lista

    // Loop externo para iterar sobre todos os nós da lista
    while (current != NULL && current->next != NULL)
    {
        Node *runner = current; // Inicializa um ponteiro de corrida com o nó atual

        // Loop interno para comparar o nó atual com todos os nós seguintes
        while (runner->next != NULL)
        {
            // Se o item do próximo nó for igual ao item do nó atual, remove o próximo nó
            if (strcmp(runner->next->item, current->item) == 0)
            {
                Node *temp = runner->next; // Armazena o próximo nó em um temporário
                runner->next = runner->next->next; // Remove o próximo nó da lista
                free(temp); // Libera a memória alocada para o nó removido
            }
            else
            {
                runner = runner->next; // Move para o próximo nó
            }
        }
        current = current->next; // Move para o próximo nó na lista
    }
}

// Função para ordenar os elementos da lista em ordem alfabética
void order(Node **l)
{
    // Verifica se a lista está vazia ou tem apenas um elemento
    if (*l == NULL || (*l)->next == NULL) return;

    // Inicializa dois ponteiros auxiliares para percorrer a lista
    Node *aux = *l, *t;

    // Variável temporária para trocar os itens dos nós
    char s[100];

    // Loop externo para percorrer toda a lista
    while (aux != NULL)
    {
        t = aux->next; // Inicializa o ponteiro t para o próximo nó após aux

        // Loop interno para comparar o item do nó aux com o item dos nós seguintes
        while (t != NULL)
        {
            // Se o item do nó atual vier depois do item do próximo nó, troca os itens
            if (strcmp(aux->item, t->item) > 0)
            {
                strcpy(s, aux->item); // Copia o item do nó aux para a variável temporária
                strcpy(aux->item, t->item); // Copia o item do próximo nó para o nó aux
                strcpy(t->item, s); // Copia o item da variável temporária para o próximo nó
            }
            t = t->next; // Move para o próximo nó
        }
        aux = aux->next; // Move para o próximo nó na lista
    }
}
