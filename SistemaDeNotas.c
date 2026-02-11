#include <stdio.h>
#include <string.h>

#define N 40
#define M 4

int main()
{
    char nomes[N][60];
    int id[N];
    int notas[N][M];
    int faltas[N];
    float media[N];

    int totalAlunos = 0;
    int opcao = 0;
    int i, j;

    for (i = 0; i < N; i++)
    {
        id[i] = -1;
        faltas[i] = 0;
        media[i] = 0;
        for (j = 0; j < M; j++)
        {
            notas[i][j] = -1;
        }
    }
            //MENU - LETHICIA 
    do
    {
        printf("\n===== SISTEMA DE GERENCIAMENTO DE TURMA =====\n");
        printf("\n===== MENU PRINCIPAL =====\n");

        printf("1. Cadastrar alunos\n");
        printf("2. Lancar notas\n");
        printf("3. Lancar faltas\n");
        printf("4. Listar alunos\n");
        printf("5. Boletim completo\n");
        printf("6. Estatisticas da turma\n");
        printf("7. Ranking Top 5\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            int q, k;
            int idValido;
            int repetido;

            printf("\nQuantos alunos deseja cadastrar? ");
            scanf("%d", &q);

            if (q < 1 || q > N - totalAlunos)
            {
                printf("\nQuantidade invalida ou limite da turma excedido!\n");
            }
            else
            {
                for (k = 0; k < q; k++)
                {
                    printf("\nCadastro do aluno %d\n", totalAlunos + 1);

                    idValido = 0;
                    while (idValido == 0)
                    {
                        printf("Digite o ID (maior que 0): ");
                        scanf("%d", &id[totalAlunos]);

                        if (id[totalAlunos] <= 0)
                        {
                            printf("ID invalido! Deve ser positivo.\n");
                        }
                        else
                        {
                            repetido = 0;
                            for (i = 0; i < totalAlunos; i++)
                            {
                                if (id[i] == id[totalAlunos])
                                {
                                    repetido = 1;
                                }
                            }

                            if (repetido == 1)
                            {
                                printf("ID ja existe! Tente outro.\n");
                            }
                            else
                            {
                                idValido = 1; 
                            }
                        }
                    }

                    printf("Digite o nome: ");
                    scanf(" %[^\n]", nomes[totalAlunos]);

                    faltas[totalAlunos] = 0;
                    media[totalAlunos] = 0;

                    for (j = 0; j < M; j++)
                    {
                        notas[totalAlunos][j] = -1;
                    }

                    totalAlunos++;
                    printf("Aluno cadastrado com sucesso!\n");
                }
            }
            break;
        }
        case 8:
            printf("Saindo...\n");
            break;
        default:
            if (opcao != 8)
                printf("Opcao invalida!\n");
            break;
        }

    } while (opcao != 8);

    return 0;
}