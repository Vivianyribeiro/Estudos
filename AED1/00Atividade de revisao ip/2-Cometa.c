#include <stdio.h>

int main() {
    int ano_atual, ano_passagem, anos_desde_passagem, anos_para_passagem;
    int periodo_cometa = 76; // período do cometa Halley em anos
    int anos_bissextos = 0; // quantidade de anos bissextos desde 1986
    int i;

    // Ler ano atual do usuário
    printf("Digite o ano atual: ");
    scanf("%d", &ano_atual);

    // Calcular ano da próxima passagem do cometa Halley
    ano_passagem = 1986; // ano da última passagem do cometa Halley
    anos_desde_passagem = ano_atual - ano_passagem;
    anos_para_passagem = periodo_cometa - anos_desde_passagem % periodo_cometa;
    if (anos_para_passagem == periodo_cometa) { // se já passou este ano, pular para a próxima passagem
        anos_para_passagem = 0;
    }
    ano_passagem += anos_desde_passagem + anos_para_passagem;

    // Contar anos bissextos desde 1986 até a próxima passagem do cometa Halley
    for (i = 1988; i <= ano_passagem; i += 4) {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
            anos_bissextos++;
        }
    }

    // Adicionar dias extras dos anos bissextos ao cálculo do ano da próxima passagem do cometa Halley
    ano_passagem += anos_bissextos;

    // Imprimir resultado
    printf("O próximo ano de passagem do cometa Halley será: %d\n", ano_passagem);

    return 0;
}




/*#include <stdio.h>
#include <time.h>

int main () {
    int base = 1986, ano, antes_ou_depois;
    int tm_year;
    time_t tempo = time(NULL);
    puts("\nData atual\n");
    printf(ctime(&tempo));
    printf("%i", tm_year + 1900);
    printf("\nDigite o ano que deseja calcular: ");
    scanf("%d", &ano);

    

    
    
    return 0;
}
*/