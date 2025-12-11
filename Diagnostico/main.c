#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main() {
    int tipo_vazamento;
    char resposta;
    setlocale(LC_ALL, "");//pra colocar acento e cedilha, nao sei porque meu til nao ta funcionando

    printf("=== DIAGNÓSTICO DE VAZAMENTOS ===\n");
    printf("Para começar, qual o tipo de sinal você percebeu?\n\n");
    printf("1 - Vazamento VISÍVEL (Água jorrando, pingando, cano estourado)\n");
    printf("2 - Vazamento OCULTO (Conta alta, parede úmida, mofo)\n");
    printf("Escolha (1 ou 2): ");
    scanf("%d", &tipo_vazamento);

    // --- RAMO 1: VAZAMENTO VISÍVEL ---
    if (tipo_vazamento == 1) {
        printf("\n--- Analisando Vazamento Visível ---\n");
        printf("O vazamento está ocorrendo na rua, na calçada ou no cavalete (relogio)? (s/n): "); //primeiro para saber se o vazamento é na rua pois muitas das vezes a pressão é fraca mas isso é problema da Águas de Manaus
        scanf(" %c", &resposta);
        resposta = tolower(resposta); // tolower para detectar caso for utilizado letra maiúscula N/n - S/s


        if (resposta == 's') {
            // Se está na rua ou no hidrômetro, é problema da concessionária
            printf("\n[DIAGNÓSTICO]: Vazamento no ramal de entrada ou cavalete.\n");
            printf("[SOLUÇÃO]: Entre em contato com a AGUAS DE MANAUS para reparo de urgência.\n");
            
        } else {
            // Se não é na rua, é dentro de casa

            printf("\n--- Analisando Vazamento Interno ---\n");
            printf("O vazamento é em uma torneira, chuveiro ou caixa acoplada(caixa da privada)? (s/n): ");
            scanf(" %c", &resposta);
            resposta = tolower(resposta);
        }

            if (resposta == 's') {

                 printf("\n[DIAGNÓSTICO]: Desgaste de vedação ou reparo.\n");
                 printf("[SOLUÇÃO CASO 1]: Verifique a guarnição(borracha) da torneira, caso seja rosqueado, retire a torneira e aplique veda-rosca na área rosqueada ou chame um ENCANADOR.\n\n");
                 printf("[SOLUÇÃO CASO 2]: Verifique a guarnição(borracha) do chuveiro, caso seja rosqueado, retire o chuveiro e aplique veda-rosca na área rosqueada ou chame um ENCANADOR.\n\n");
                 printf("[SOLUÇÃO CASO 3]: Verifique o kit da caixa da privada, caso encontre a peça defeituosa, substitua a peça, caso não encontre, compre o kit completo e substitua ele ou chame um ENCANADOR.\n");

                 //A privada geralmente é o maior inimigo do consumo alto, se ele ficar enchendo infinitamente a conta fica altíssima e quase ninguém percebe.

            } else {

                 printf("\n--- Analisando Vazamento Interno ---\n");
                 printf("O vazamento é na caixa d'água, em algum registro da casa ou cano exposto? (s/n): ");
                 scanf(" %c", &resposta);
                 resposta = tolower(resposta);


            if (resposta == 's'){

                printf("\n[DIAGNÓSTICO]: Desgaste de vedação ou reparo.\n");
                printf("[SOLUÇÃO CASO 1]: Verifique se a caixa tem bóia, caso tenha verifique se não está danificada, caso esteja, troque a bóia, caso não tenha bóia, verifique se não tem um problema na parte exterior da caixa ou chame um ENCANADOR.\n\n");
                printf("[SOLUÇÃO CASO 2]: Verifique se o registro está danificado, se ele ficar pingando, substitua ele, fique de olho na polegada do registro se ele é de meia(1/2) ou três quartos(3/4), caso não esteja danificado e ele possua rosca, aplique veda-rosca ou chame um ENCANADOR.\n\n");
                printf("[SOLUÇÃO CASO 3]: Feche o registro de água e faça a medição do cano, de quantos metros irá precisar e qual a polegada do cano (1/2 ou 3/4), em caso de cano de solda(sem rosca) compre cola para cano ou chame um ENCANADOR.\n\n");

            }else{

                printf("\n[DIAGNÓSTICO]: Possível vazamento interno.\n");
                printf("[SOLUÇÃO]: Refaça o diagnóstico e escolha a opção 2, obrigado :)");

            }
        }
    }

    // --- RAMO 2: VAZAMENTO OCULTO ---
    else if (tipo_vazamento == 2) {
        printf("\n--- Analisando Vazamento Oculto ---\n");
        printf("Vamos fazer o 'Teste do Relógio'.\n");
        printf("1. Feche todas as torneiras e não use o banheiro.\n");
        printf("2. Olhe para o hidrômetro (relógio).\n");
        printf("PERGUNTA: O ponteiro ou a 'borboleta' do relógio continua girando? (s/n): ");
        scanf(" %c", &resposta);
        resposta = tolower(resposta);

        if (resposta == 's') {
            // Se gira com tudo fechado, a água está saindo em algum lugar dentro da casa
            printf("\n[DIAGNOSTICO]: Vazamento oculto na tubulação interna.\n");
            printf("[SOLUÇÃO]: Chame um BOMBEIRO HIDRAULICO que tenha aparelho de 'Caça-Vazamentos'.\n");

            //obs: bombeiro hidráulico e encanador são termos semelhantes, a unica diferença é que bombeiro hidráulico trabalha com problemas mais complexos;
            //exemplo: detectar vazamentos invisíveis, no caso da Águas de Manaus ele trabalha fazendo manobra(fechando registros) em bairros para fazer manutenção nas redes de águas.

        } else {
            // Se não gira, não há vazamento interno consumindo água agora
            printf("\n[DIAGNÓSTICO]: Não há indícios de vazamento interno contínuo.\n");
            printf("O problema pode ser erro de leitura ou vazamento 'antes' do relógio.\n");
            printf("[SOLUÇÃO]: Entre em contato com a ÁGUAS DE MANAUS para contestar a fatura ou pedir vistoria.\n");
        }
    }

    else {
        printf("\nOpção inválida. Reinicie o programa.\n");
    }

    return 0;
    }
