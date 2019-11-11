#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define TTURMA 4
#define TALUNO 5
#define TDESAFIOS 5

//HABILIDADE VAI DE 0 A 5
typedef struct bruxo {
    char nomeBruxo[50];
    int inteligencia, destreza, carisma;
}BRUXO;

typedef struct Turma{
    char nomeTurma[50];
    float pontos;
    BRUXO alunos[TALUNO];
    int compara;
}TURMA;
//
//
//
//
//FUNÇÕES DESAFIOS

//Função Quadrilol
void QuadriLOL(TURMA turmas[], int* contDesafio){
    int i,j,somacarisma[4]={},pontos,maiorcarisma=0,maiordestreza=0,somadestreza[4]={};

    system("CLS");
    printf("\n ---------------------------- \n");
    printf("|");
    printf("    DESAFIO QUADRILOL:      ");
    printf("| \n");
    printf(" ---------------------------- \n");
    //pegando as informações
    for(i=0;i<TTURMA;i++){
        for (j=0;j<TALUNO;j++){
            somacarisma[i] += turmas[i].alunos[j].carisma;
            somadestreza[i] += turmas[i].alunos[j].destreza;
        }//pegando os alunos
    }//todas as turmas
    //comparando turma com maior carisma
    for (i=0;i<TTURMA;i++){
        if (somacarisma[i]>maiorcarisma){
            maiorcarisma = somacarisma[i];
            j=i;
        }
    }

    printf("Turma %s Ganhou o desafio de maior carisma. \n",turmas[j].nomeTurma);
    turmas[j].pontos += 5;// turma com maior carisma ganhou
    //comparando maior carisma (fim)

    //comparando maior destreza
    for (i=0;i<TTURMA;i++){
        if (somadestreza[i]>maiordestreza){
            maiordestreza = somadestreza[i];
            j=i;
        }
    }
    printf("Turma %s Ganhou o desafio de maior destreza.\n",turmas[j].nomeTurma);
    turmas[j].pontos += 10;//maior destreza ganhou
    //comparando maior destreza (fim)
    system("PAUSE");
    system("CLS");
    *contDesafio = *contDesafio + 1;
}

// Função Do Artes Arcanistas
void ArtesArcanistasArcanas(TURMA turmas[], int* contDesafio) {
    int i, turmasSelecionadas[2], alunosSelecionados[2];
    system("CLS");
    printf("\n ---------------------------- \n");
    printf("|");
    printf("  Artes Arcanistas Arcanas:   ");
    printf("| \n");
    printf(" ---------------------------- \n");
    srand(time(NULL));


    //Sorteando Turmas
    do{
    for(i=0; i<2; i++) {
        turmasSelecionadas[i] = rand()%4;
    }
    }while(turmasSelecionadas[0] == turmasSelecionadas[1]);

    //Sorteando Alunos
    for(i=0; i<2; i++) {
    alunosSelecionados[i] = rand()%5;
    }


    //Printando os alunos e turmas sorteados
    printf("\nA batalha sera entre %s da turma %s e %s da turma %s\n", turmas[turmasSelecionadas[0]].alunos[alunosSelecionados[0]].nomeBruxo,
    turmas[turmasSelecionadas[0]].nomeTurma, turmas[turmasSelecionadas[1]].alunos[alunosSelecionados[1]].nomeBruxo,
    turmas[turmasSelecionadas[1]].nomeTurma);

    //Comparando alunos para ver quem ganha.
    if(turmas[turmasSelecionadas[0]].alunos[alunosSelecionados[0]].inteligencia > turmas[turmasSelecionadas[1]].alunos[alunosSelecionados[1]].inteligencia) {
        printf("O aluno %s da turma %s ganhou!!!\n", turmas[turmasSelecionadas[0]].alunos[alunosSelecionados[0]].nomeBruxo, turmas[turmasSelecionadas[0]].nomeTurma);
        turmas[turmasSelecionadas[0]].pontos += 10;
    } else if (turmas[turmasSelecionadas[0]].alunos[alunosSelecionados[0]].inteligencia > turmas[turmasSelecionadas[1]].alunos[alunosSelecionados[1]].inteligencia) {
        printf("Deu empate!!!\n");
    } else {
       printf("O aluno %s da turma %s ganhou!!!\n", turmas[turmasSelecionadas[1]].alunos[alunosSelecionados[1]].nomeBruxo, turmas[turmasSelecionadas[1]].nomeTurma);
       turmas[turmasSelecionadas[1]].pontos += 10;
    }

    system("PAUSE");
    system("CLS");
    *contDesafio = *contDesafio + 1;
}

void BuscandoPedra(TURMA turmas[], int *contDesafio){
int i, j, k, aux,times[TTURMA][TALUNO-2],dex[TTURMA]={},
menor=666, imenor, float_zal, lugar[10]={}, procura[10]={}, encontrou[TTURMA]={}, count=0, rodada = 1, fim=0;
    system("cls");
    //Sorteando a localizacao da pedra de float zal
    srand(time(NULL));
    float_zal= rand()%10;
    system("CLS");
    printf("\n ------------------------------ \n");
    printf("|");
    printf("BUSCANDO A PEDRA 'FLOAT ZAL':");
    printf("| \n");
    printf(" ------------------------------ \n");
    printf ("\n\npedra ta aqui %d\n\n", (float_zal+1));
    lugar[float_zal]=1;
    printf ("\nO resultado do sorteio dos participantes desta prova sao os seguintes:\n");
    //Sorteando 3 alunos de cada turma
    for(i=0;i<TTURMA;i++){
        printf("\n----------------------------\n");
        printf ("Turma %s\n\n", turmas[i].nomeTurma);
        for(j=0;j<TALUNO-2;j++){
            aux=rand()%5;
            times[i][j]=aux;
                while((aux==times[i][j-1]) || (aux==times[i][j-2])){
                    aux=rand()%5;
                    times[i][j]=aux;
                }
            dex[i]=dex[i]+turmas[i].alunos[aux].destreza;
        printf ("Aluno %d: %s", aux, turmas[i].alunos[aux].nomeBruxo);
        printf("\nInteligencia: %d\n", turmas[i].alunos[aux].inteligencia);
        printf("Destreza: %d\n", turmas[i].alunos[aux].destreza);
        printf("Carisma: %d\n", turmas[i].alunos[aux].carisma);
        printf ("\n");

        }
            //Verificando menor destreza
            if(dex[i]<menor){
            menor=dex[i];
            imenor=i;
            }
    }

    //Atribuindo 0 a turma com menor destreza
    printf("\n----------------------------\n");
    printf ("\nOh nao!!! A turma %s foi pega pelo valdechar!!!", turmas[imenor].nomeTurma);
    for(i=0;i<TALUNO-2;i++){
    turmas[imenor].alunos[times[imenor][i]].carisma=0;
    turmas[imenor].alunos[times[imenor][i]].destreza=0;
    turmas[imenor].alunos[times[imenor][i]].inteligencia=0;
    }
    printf ("\nTodos os seus status foram reduzidos a 0!!!\n");
    //Procurando a pedra de float zal

        for(i=0;i<TTURMA;i++){
            if(i!=imenor){
                printf("\n----------------------------");
                printf ("\nTurma %s, escolha entre 1 e 10, um lugar para procurar a pedra de float zal\n", turmas[i].nomeTurma);
                procura[i]= rand()%10;
                //scanf("%d", &procura[i]);
                printf("Turma %s escolhe %d\n", turmas[i].nomeTurma, (procura[i]+1));
            }
            //procura[i]= (procura[i]-1);
            if(lugar[procura[i]]==1){
                fim=1;
                encontrou[i]=1;
            }
        }
    //Anuncio dos vencedores
    for (i=0;i<TTURMA;i++){
        if(encontrou[i]==1){
            printf("\n----------------------------");
            printf ("\nTurma %s achou a pedra de float zal!!!\n", turmas[i].nomeTurma);
            turmas[i].pontos += 20;
        }else{
            printf("\n----------------------------\n");
            printf ("\nNinguem encontrou a pedra de 'float zal'");
            break;
        }
    }
    printf("\n----------------------------\n");
    system("PAUSE");
    system("CLS");
    *contDesafio = *contDesafio + 1;
}
//FIM FUNÇÕES DESAFIOS
//
//
//
//FUNCIONALIDADES DO PROGRAMA
void Salvar(TURMA turmas[], int *contDesafio, int *validarCadastroTurma, int *validarCadastroBruxos){
    int i, j;
    FILE *arquivo = fopen("save.txt","w");

    for(i=0;i<TTURMA;i++) {
            fprintf(arquivo, "%s\n", turmas[i].nomeTurma);
            //fputs(turmas[i].nomeTurma, arquivo);
            fprintf(arquivo, "%f\n", turmas[i].pontos);
        for(j=0;j<TALUNO;j++){
            fprintf(arquivo, "%s\n", turmas[i].alunos[j].nomeBruxo);
            //fputs(turmas[i].alunos[j].nomeBruxo, arquivo);
            fprintf(arquivo, "%d\n", turmas[i].alunos[j].inteligencia);
            fprintf(arquivo, "%d\n", turmas[i].alunos[j].destreza);
            fprintf(arquivo, "%d\n", turmas[i].alunos[j].carisma);
        }
    }
    fprintf(arquivo, "%d\n", *contDesafio);
    fprintf(arquivo, "%d\n", *validarCadastroTurma);
    fprintf(arquivo, "%d\n", *validarCadastroBruxos);
    fclose(arquivo);
}

void Carregar(TURMA turmas[], int *contDesafio,  int *validarCadastroTurma, int *validarCadastroBruxos) {
int i, j;

    FILE *arquivo = fopen("save.txt","r");
        for(i=0;i<TTURMA;i++) {
                fflush(stdin);
                //fgets(turmas[i].nomeTurma, 50, arquivo);
                fscanf(arquivo, "\n%[^\n]", &turmas[i].nomeTurma);
                fflush(stdin);
                fscanf(arquivo, "%f", &turmas[i].pontos);
            for(j=0;j<TALUNO;j++){
                fflush(stdin);
                //fgets(turmas[i].alunos[j].nomeBruxo, 50, arquivo);
                fscanf(arquivo, "\n%[^\n] ", &turmas[i].alunos[j].nomeBruxo);
                fflush(stdin);
                fscanf(arquivo, "%d", &turmas[i].alunos[j].inteligencia);
                fscanf(arquivo, "%d", &turmas[i].alunos[j].destreza);
                fscanf(arquivo, "%d",  &turmas[i].alunos[j].carisma);
            }
        }
        fscanf(arquivo, "%d", contDesafio);
        fscanf(arquivo, "%d", validarCadastroTurma);
        fscanf(arquivo, "%d", validarCadastroBruxos);
        fclose(arquivo);
}

int Confere(char nome[]){ //Confere se eles os nomes estão sendo preenchidos corretamente
    int i, c=0;
    if(strlen(nome)== 0){
      return 1;
    } else{
        for(i=0;i<strlen(nome);i++) {
            if(nome[i] == 32) {
                c++;
            }
        }
        if(c==strlen(nome)){
            return 1;
        }
    }
return 0;
}

int Grifinoria(TURMA turmas[]) {
    int i;
    char Equipe[]= "grifinoria";
    for(i=0;i<TTURMA;i++) {
        if(strcmp(Equipe, strlwr(turmas[i].nomeTurma))) {
            turmas[i].pontos += 20;
        }
    }

}

int CadastrarTurma(TURMA turmas[]){ //
    int i, j, compara;
    srand(time(NULL));
    system("CLS");
    for (i=0;i<TTURMA;i++){
        turmas[i].pontos=0;
        printf ("\nDigite o nome da Turma %d.", (i+1));
        do{
            fflush(stdin);
            gets (turmas[i].nomeTurma);
            fflush(stdin);
            if(Confere(turmas[i].nomeTurma) == 1) {
                printf("\nErro!!! Nome invalido.\n");
                printf("\nDigite o nome novamente.\n");
            }
                if(i>0){
                    for(j=1;j<=i;j++){
                    compara = strcmp(turmas[i].nomeTurma, turmas[j-1].nomeTurma);
                        if (compara==0){
                            printf("\nErro!!! Nome invalido.\n");
                            printf("\nDigite o nome novamente.\n");
                            break;
                        }
                    }
                }
        }while((Confere(turmas[i].nomeTurma) == 1) || (compara==0));
    }
    system("CLS");
    return 1;
}

void Atribuir0 (TURMA turmas[]) {
    int i;
    for(i=0;i<TTURMA;i++) {
        turmas[i].compara = 0;
    }
}

int MenuEscTurma(TURMA turmas[]) {
    int escTurma, retornoindice;
    do{
    printf("Escolha a turma:\n");
    printf (" 1. %s \n",turmas[0].nomeTurma);
    printf (" 2. %s \n",turmas[1].nomeTurma);
    printf (" 3. %s \n",turmas[2].nomeTurma);
    printf (" 4. %s \n",turmas[3].nomeTurma);
    scanf ("%d", &escTurma);
        if((escTurma<1) || (escTurma>TTURMA)) {
            printf("\nOpcao invalida, digite novamente.\n");
            system("PAUSE");
            system("CLS");
        }
    }while((escTurma<1) || (escTurma>TTURMA));
    retornoindice = escTurma-1;

    //determinando a cor
            switch(retornoindice) {
            case 0:
                system("color 4f");
                break;
            case 1:
                system("color 2f");
                break;
            case 2:
                system("color 3f");
                break;
            case 3:
                system("color e0");
                break;
            }
    return retornoindice;
}

int CadastrarBruxo(TURMA turmas[]){
    int i=0,j,k, comparar=1, z;
    srand(time(NULL));
    Atribuir0(turmas);//atrui 0 para todos os flags
        for(z=0;z<TTURMA;z++) { //repetir o intervalo
            do{//começo da comparação dos flags
                system("CLS");
                i = MenuEscTurma(turmas);
                if(turmas[i].compara == 1) {
                    printf("\nEquipe ja preenchida, tente outra equipe.\n");
                    system("PAUSE");
                }
            }while(turmas[i].compara==1);//fim da comparação flags
            system("CLS");
            //cadasdrando cada aluno da turma


            printf("TURMA %s\n", turmas[i].nomeTurma);
            for (j=0;j<TALUNO;j++){
                printf("Aluno %d: ",j+1);
                do{
                    fflush(stdin);

                    gets(turmas[i].alunos[j].nomeBruxo);//pega nome do aluno
                    fflush(stdin);
                    turmas[i].alunos[j].inteligencia = rand()%6;//preenche inteligencia
                    turmas[i].alunos[j].destreza = rand()%6;//preenche destreza
                    turmas[i].alunos[j].carisma = rand()%6;//preenche carisma
                    //preenchendo  cada aluno
                    if(Confere(turmas[i].alunos[j].nomeBruxo) == 1) {
                        printf("\nErro!!! Nome invalido.\n");
                        printf("\nDigite o nome novamente.\n");
                    }
                }while(Confere(turmas[i].alunos[j].nomeBruxo) == 1);
            }
            //cadasdrando cada aluno da turma (fim)

        turmas[i].compara = 1;
        }
        system("CLS");
return 1;
}//Fim Cadastrar Aluno

void ImprimirDadosTurmas(TURMA turmas[]) { //Imprime os dados de todas as turmas
       int i, j;
       system("CLS");
       for (i=0;i<TTURMA;i++){
        printf("\n----------------------------\n");
        printf("            TURMA %s:         \n",turmas[i].nomeTurma);
        printf("PONTOS: %.2f", turmas[i].pontos);
        printf("\n----------------------------\n");
        printf("\nOs alunos sao:\n");
        for (j=0;j<TALUNO;j++){
            printf("%s\n", turmas[i].alunos[j].nomeBruxo);
        }// imprimir os alunos
    }//cada turma
    system("PAUSE");
}// Fim imprime

void ImprimirDadosAlunos(TURMA turmas[]) {
int i, j;
    i = MenuEscTurma(turmas);
    system("CLS");
    printf("\nOs alunos sao:\n");
    for(j=0;j<TALUNO;j++){
        printf("%s\n", turmas[i].alunos[j].nomeBruxo);
        printf("Inteligencia: %d\n", turmas[i].alunos[j].inteligencia);
        printf("Destreza: %d\n", turmas[i].alunos[j].destreza);
        printf("Carisma: %d\n", turmas[i].alunos[j].carisma);
    }
    system("PAUSE");
}
//FIM FUNCIONALIDADES DO PRGRAMA
//
//
//
//MENUS
void MenuDesafios(TURMA turmas[], int *contDesafio){
    int resposta;
    system("color 0f");
    do {
        system("CLS");
        printf("Escolha um dos desafios:\n");
        printf("1-QUADRILOL\n");
        printf("2-ARTES ARCANISTAS\n");
        printf("3-BUSCANDO A PEDRA 'FLOAT ZAL'\n");
        scanf("%d",&resposta);
    }while(resposta<1 || resposta>3);


    switch(resposta){
        case 1:
            QuadriLOL(turmas,contDesafio);
        break;
        case 2:
            ArtesArcanistasArcanas(turmas,contDesafio);
        break;
        case 3:
            BuscandoPedra(turmas,contDesafio);
        break;
    }
}

void MenuPrincipal(TURMA turmas[], int *contDesafio, int *validarCadastroTurma, int *validarCadastroBruxos){
    int escolha=0, i, iMaior = 0;
    float maior[2] = {-1,-1};
    do{
        system("cls");
        system("color 0f");
        printf("\n----------------------------------------------------------\n");
        printf("\n- GERENCIADOR ULTRA MEGA BLASTER DA ESCOLA DE BRUXOS 2.0 -\n");
        printf("\n----------------------------------------------------------\n");
        printf("Escolha uma das funcoes:\n");
        printf("1-CADASTRAR TURMA\n");
        printf("2-CADASTRAR BRUXO\n");
        printf("3-EXECUTAR DESAFIOS (%d/5)\n", *contDesafio);
        printf("4-IMPRIMIR DADOS DAS TURMAS\n");
        printf("5-IMPRIMIR DADOS DOS ALUNOS DA TURMA ESCOLHIDA\n");
        printf("6-SALVAR\n");
        printf("7-CARREGAR DADOS\n");
        printf("8-SAIR DO PROGRAMA\n");
        printf("\n----------------------------------------------------------\n");
            do{
                scanf("%d", &escolha);
            }while ((escolha<1) || (escolha>8));
        printf("\n----------------------------------------------------------\n");

        switch (escolha){
            case 1:
                if (*validarCadastroTurma == 1){
                    printf("\n As turmas ja foram preenchidas !!! \n");
                    printf(" \n Escolha outra opcao \n");
                    system("PAUSE");
                    system("CLS");
                }else {
                *validarCadastroTurma = CadastrarTurma(turmas);
                }

            break;

            case 2:
                if(*validarCadastroTurma == 1 && *validarCadastroBruxos == 0) {
                    *validarCadastroBruxos = CadastrarBruxo(turmas);
                } else if (*validarCadastroBruxos == 1 && *validarCadastroTurma == 1){
                   printf("\nAlunos ja foram preenchidos \n");
                   system("PAUSE");
                   system("CLS");
                }else{
                    printf("\nNao pode preencher os alunos sem cadastrar as turmas\n");
                    system("PAUSE");
                    system("CLS");
                }
            break;

            case 3:
                if (*contDesafio < 5 && *validarCadastroBruxos == 1 && *validarCadastroTurma == 1){
                    MenuDesafios(turmas, contDesafio);
                    for(i=0; i<TTURMA;i++) {
                        printf("\nA turma %s esta com: %.2f pontos\n", turmas[i].nomeTurma, turmas[i].pontos);
                        printf("\n --------------------------------------------------- \n");
                    }
                    system("PAUSE");
                } else if (contDesafio>=5 && *validarCadastroBruxos == 1 && *validarCadastroTurma == 1) {
                    printf("\nJa foi executado o numero maximo de desafios\n");
                    system("PAUSE");
                    system("CLS");
                } else {
                    printf("\nNao pode iniciar os desafios sem preencher os alunos e as turmas\n");
                    system("PAUSE");
                    system("CLS");
                }
            break;

            case 4:
                if(*validarCadastroBruxos == 1 && *validarCadastroTurma == 1) {
                    ImprimirDadosTurmas(turmas);
                } else {
                    printf("\nNao e possivel imprimir os dados da turma sem preencher a turma/alunos\n");
                    system("PAUSE");
                    system("CLS");
                }
            break;

            case 5:
                if(*validarCadastroBruxos == 1 && *validarCadastroTurma == 1) {
                    ImprimirDadosAlunos(turmas);
                } else {
                    printf("\nNao e possivel imprimir os dados dos alunos sem preencher a turma/alunos\n");
                    system("PAUSE");
                    system("CLS");
                }
            break;

            case 6:
                Salvar(turmas, contDesafio, validarCadastroTurma, validarCadastroBruxos);
            break;

            case 7:
                Carregar(turmas, contDesafio, validarCadastroTurma, validarCadastroBruxos);
            break;
        }
    }while(escolha!=8);
    system("cls");
    for(i=0; i<TTURMA;i++) {
        printf("\nA turma %s esta com: %.2f pontos\n", turmas[i].nomeTurma, turmas[i].pontos);
    }
    system("PAUSE");
    Grifinoria(turmas);
    for(i=0; i<TTURMA;i++) {
        if (turmas[i].pontos>=maior[0]){
            maior[1] = maior[0];
            maior[0] = turmas[i].pontos;
            iMaior = i;
        }
    }
    if (*contDesafio == 5 && (maior[0]!=maior[1])){
        printf("\n\nPARABENS! A TURMA %s GANHOU!\n", strupr(turmas[iMaior].nomeTurma));
        system("PAUSE");
    }else if (maior[0]==maior[1]){
        printf(" \n HOUVE EMPATE ENTRE AS TURMAS...NEHUMA TUMRMA FOI A GANHADORA \n");
        system("PAUSE");
    }
}
//FIM MENUS
//
//
//

int main (){
    TURMA turmas[TTURMA];
    int contDesafio = 0, validarCadastroTurma = 0, validarCadastroBruxos = 0;

    MenuPrincipal(turmas, &contDesafio, &validarCadastroTurma, &validarCadastroBruxos);
return 0;
}
