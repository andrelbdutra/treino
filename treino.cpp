#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void imprimeInteiroArq(FILE *arqInt){ //função para imprimir na tela os valores do arquivo de inteiros
    arqInt = fopen("arquivoInteiro.txt", "r"); // apenas impressão de arquivo "read"
    int num;

    cout<<"==IMPRIMINDO ARQUIVO DE INTEIROS== \n";
    if (arqInt != NULL)
    {
        fscanf(arqInt, "%d", &num);
        while (!feof(arqInt))
        {
            printf("%d\n",num);
            fscanf(arqInt, "%d", &num);
        }
        fclose(arqInt);
    }
    else
        printf("Erro ao abrir o arquivo!");

}

void imprimeCharArq(FILE *arqChar){ //função para imprimir na tela os valores do arquivo de chars
    arqChar = fopen("arquivoChar.txt", "r"); // apenas leitura de arquivo "read"
    char c;

    cout<<"==IMPRIMINDO ARQUIVO DE CHARACTERES== \n";
    if(arqChar != NULL){
        fscanf(arqChar, "%c", &c);
        while (!feof(arqChar))
        {
            printf("%c", c);
            fscanf(arqChar, "%c", &c);
        }
        fclose(arqChar);
    }
    else
        cout<<"Erro ao abrir o arquivo!";
}

void escreveArq(FILE *arqEsc){ // função para escrever em um arquivo
    arqEsc = fopen("arquivoEscrita.txt", "w"); //escreve em arquivo "write"
    int count = 0;
    cout<<"Escreva quantos numeros tera 'arquivoEscrita.txt': \n";
    cin>>count;

    if (arqEsc != NULL)
    {
        for (int i = 0; i < count; i++)
        {
            fprintf(arqEsc, "%d\n", i);
        }
        fclose(arqEsc);
    }
}

void escreveBin (FILE *dbin, int *valor){
    dbin = fopen("dadosBin.txt", "wb"); //escreve em binário "write binary"
    int aux;
    cout<<"Digite a quantidade de dados binarios: ";
    cin>>*valor;
    int dados[*valor];

    if(dbin != NULL){
        for (int i = 0; i < *valor; i++)
        {
            dados[i] = i;
        }
        
        fwrite(dados, sizeof(int), aux = *valor, dbin);
        fclose(dbin);
    }
    else
        cout<<"Erro ao abrir arquivo\n";
}

void leBin(FILE *lebin, int *valor){
    cout<<"==DADOS BINARIOS==\n";
    lebin = fopen("dadosBin.txt", "rb"); // apenas leitura em binário "read binary"
    int dados[*valor];

    if (lebin != NULL)
    {
        fread(dados, sizeof(int), *valor, lebin);
        for (int i = 0; i < *valor; i++)
        {
            cout<<dados[i]<<endl;
        }
        fclose(lebin);
    }
    else
        cout<<"Erro ao abrir o arquivo\n";
    
}

void menu(){
    cout<<"\nESCOLHA UMA OPCAO------------------------------------------------\n\n";

    cout<<"Opcao 1 - imprimir arquivo 'arquivoInteiro.txt'\n";
    cout<<"Opcao 2 - imprimir arquivo 'arquivoChar.txt'\n";
    cout<<"Opcao 3 - escreve no arquivo 'arquivoEscrita.txt'\n";
    cout<<"Opcao 4 - escreve no arquivo binario 'dadosBin.txt'\n";
    cout<<"Opcao 5 - le e imprime os dados do arquivo binario 'dadosBin.txt'\n";
    cout<<"Opcao 6 - sair\n";
    cout<<"- ";
}

int main(int argc, char const *argv[])
{
    int val = 0, indc = 0;
    int *valor;
    valor = &val;
    FILE *arqInt;
    FILE *arqChar;
    FILE *arqEsc;
    FILE *dbin;
    FILE *lebin;        

    while (indc != 6)
    {
        menu();
        cin>>indc;
        
        switch (indc)
        {
        case 1:
            imprimeInteiroArq(arqInt);
            break;
        case 2:
            imprimeCharArq(arqChar);
            break;
        case 3:
            escreveArq(arqEsc);
            break;
        case 4:
            escreveBin(dbin, valor);
            break;
        case 5:
            leBin(lebin, valor);
            break;
        default:
            break;
        }
    }
    return 0;
}


