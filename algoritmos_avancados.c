// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Este código inicial serve como base para o desenvolvimento das estruturas de navegação, pistas e suspeitos.
// Use as instruções de cada região para desenvolver o sistema completo com árvore binária, árvore de busca e tabela hash.
    // 🌱 Nível Novato: Mapa da Mansão com Árvore Binária
    //
    // - Crie uma struct Sala com nome, e dois ponteiros: esquerda e direita.
    // - Use funções como criarSala(), conectarSalas() e explorarSalas().
    // - A árvore pode ser fixa: Hall de Entrada, Biblioteca, Cozinha, Sótão etc.
    // - O jogador deve poder explorar indo à esquerda (e) ou à direita (d).
    // - Finalize a exploração com uma opção de saída (s).
    // - Exiba o nome da sala a cada movimento.
    // - Use recursão ou laços para caminhar pela árvore.
    // - Nenhuma inserção dinâmica é necessária neste nível.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sala
{
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// Reserva memória para uma Sala e devolve seu endereço.
Sala *criarSala(char nome[])
{
    Sala *novaSala = (Sala *)malloc(sizeof(Sala));

    if (novaSala == NULL)
    {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }

    strcpy(novaSala->nome, nome);

    // Os ponteiros começam sem apontar para nenhuma sala.
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;

    return novaSala;
}

// Armazena nos ponteiros da sala pai os endereços
// das salas filha recebidas como parâmetro.
void conectarSalas(Sala *pai, Sala *esquerda, Sala *direita)
{
    pai->esquerda = esquerda;
    pai->direita = direita;
}

// Percorre a árvore de acordo com as escolhas do jogador.
void explorarSalas(Sala *atual)
{
    char opcao;

    while (atual != NULL)
    {
        printf("\nVoce esta em: %s\n", atual->nome);

        if (atual->esquerda == NULL && atual->direita == NULL)
        {
            printf("Esta sala nao possui mais caminhos.\n");
            break;
        }

        printf("\nEscolha uma opcao:\n");

        if (atual->esquerda != NULL)
            printf("e - Ir para %s\n", atual->esquerda->nome);

        if (atual->direita != NULL)
            printf("d - Ir para %s\n", atual->direita->nome);

        printf("s - Sair\n");

        scanf(" %c", &opcao);

        if (opcao == 'e' && atual->esquerda != NULL)
        {
            // Copia para 'atual' o endereço armazenado
            // no ponteiro esquerda da sala atual.
            atual = atual->esquerda;
        }
        else if (opcao == 'd' && atual->direita != NULL)
        {
            // Copia para 'atual' o endereço armazenado
            // no ponteiro direita da sala atual.
            atual = atual->direita;
        }
        else if (opcao == 's')
        {
            printf("Exploracao encerrada.\n");
            break;
        }
        else
        {
            printf("Opcao invalida!\n");
        }
    }
}

// Libera as salas da árvore começando pelas folhas.
void liberarSalas(Sala *raiz)
{
    if (raiz == NULL)
        return;

    liberarSalas(raiz->esquerda);
    liberarSalas(raiz->direita);

    free(raiz);
}

int main()
{
    Sala *hall = criarSala("Hall de Entrada");
    Sala *salaEstar = criarSala("Sala de Estar");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *cozinha = criarSala("Cozinha");
    Sala *jardim = criarSala("Jardim");
    Sala *escritorio = criarSala("Escritorio");
    Sala *sotao = criarSala("Sotao");

    conectarSalas(hall, salaEstar, biblioteca);
    conectarSalas(salaEstar, cozinha, jardim);
    conectarSalas(biblioteca, escritorio, sotao);

    printf("=== DETECTIVE QUEST ===\n");

    explorarSalas(hall);

    liberarSalas(hall);

    return 0;
}


    // 🔍 Nível Aventureiro: Armazenamento de Pistas com Árvore de Busca
    //
    // - Crie uma struct Pista com campo texto (string).
    // - Crie uma árvore binária de busca (BST) para inserir as pistas coletadas.
    // - Ao visitar salas específicas, adicione pistas automaticamente com inserirBST().
    // - Implemente uma função para exibir as pistas em ordem alfabética (emOrdem()).
    // - Utilize alocação dinâmica e comparação de strings (strcmp) para organizar.
    // - Não precisa remover ou balancear a árvore.
    // - Use funções para modularizar: inserirPista(), listarPistas().
    // - A árvore de pistas deve ser exibida quando o jogador quiser revisar evidências.

    // 🧠 Nível Mestre: Relacionamento de Pistas com Suspeitos via Hash
    //
    // - Crie uma struct Suspeito contendo nome e lista de pistas associadas.
    // - Crie uma tabela hash (ex: array de ponteiros para listas encadeadas).
    // - A chave pode ser o nome do suspeito ou derivada das pistas.
    // - Implemente uma função inserirHash(pista, suspeito) para registrar relações.
    // - Crie uma função para mostrar todos os suspeitos e suas respectivas pistas.
    // - Adicione um contador para saber qual suspeito foi mais citado.
    // - Exiba ao final o “suspeito mais provável” baseado nas pistas coletadas.
    // - Para hashing simples, pode usar soma dos valores ASCII do nome ou primeira letra.
    // - Em caso de colisão, use lista encadeada para tratar.
    // - Modularize com funções como inicializarHash(), buscarSuspeito(), listarAssociacoes().

    return 0;
}

