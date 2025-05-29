// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  Nome: Maurcício Santana da Silva
//  email: mauriciosantanadasilva123@gmail.com
//  Matrícula: 20242160034
//  Semestre: 2°/  
// ----- Dados do Aluno -----

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "MauricioSilva.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>

//DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */

// int somar(int x, int y)
// {
//     int soma;
//     soma = x + y;
//     return soma;
// }

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */

//  int fatorial(int x)
// { //função utilizada para testes
//   int i, fat = 1;
    
//   for (i = x; i > 1; i--)
//     fat = fat * i;
    
//   return fat;
// }

// int teste(int a)
// {
//     int val;
//     if (a == 2)
//         val = 3;
//     else
//         val = 4;

//     return val;
// }

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */

// int q1(char data[]) {
//   int datavalida = 1;

  
//   //quebrar a string data em strings sDia, sMes, sAno


//   //printf("%s\n", data);

//   if (datavalida)
//       return 1;
//   else
//       return 0;
// }



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */


// DiasMesesAnos q2(char datainicial[], char datafinal[])
// {

//     //calcule os dados e armazene nas três variáveis a seguir
//     DiasMesesAnos dma;

//     if (q1(datainicial) == 0){
//       dma.retorno = 2;
//       return dma;
//     }else if (q1(datafinal) == 0){
//       dma.retorno = 3;
//       return dma;
//     }else{
//       //verifique se a data final não é menor que a data inicial
      
//       //calcule a distancia entre as datas


//       //se tudo der certo
//       dma.retorno = 1;
//       return dma;
      
//     }
    
// }

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não.
         Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive) {
    int qtdOcorrencias = 0;
	
    if (isCaseSensitive != 1) {
        if (c >= 'A' && c <= 'Z') {
            c = c + 32; 
        }
    }

    for (int i = 0; texto[i] != '\0'; i++) {
        char atual = texto[i];

        if (isCaseSensitive != 1) {
            if (atual >= 'A' && atual <= 'Z') {
                atual = atual + 32;
            }
        }

        if (atual == c) {
            qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
void noSpecials(char *text){
  int i, j=0;

  const char *comAcentos[] = {"Ä", "Å", "Á", "Â", "À", "Ã", "ä", "á", "â", "à", "ã",
                                "É", "Ê", "Ë", "È", "é", "ê", "ë", "è",
                                "Í", "Î", "Ï", "Ì", "í", "î", "ï", "ì",
                                "Ö", "Ó", "Ô", "Ò", "Õ", "ö", "ó", "ô", "ò", "õ",
                                "Ü", "Ú", "Û", "ü", "ú", "û", "ù",
                                "Ç", "ç"};
                                
  const char *semAcentos[] = {"A", "A", "A", "A", "A", "A", "a", "a", "a", "a", "a",
                              "E", "E", "E", "E", "e", "e", "e", "e",
                              "I", "I", "I", "I", "i", "i", "i", "i",
                              "O", "O", "O", "O", "O", "o", "o", "o", "o", "o",
                              "U", "U", "U", "u", "u", "u", "u",
                              "C", "c"};

  char buffer[256];
  buffer[0] = '\0';

  for (int i = 0; i < strlen(text);) {
    int found = 0;
    for (int j = 0; j < sizeof(comAcentos) / sizeof(comAcentos[0]); j++) {
      int len = strlen(comAcentos[j]);

      if (strncmp(&text[i], comAcentos[j], len) == 0) {
        strcat(buffer, semAcentos[j]);
        i += len;
        found = 1;
        break;
      }
    }
    if (!found) {
      strncat(buffer, &text[i], 1);
      i++;
    }
  }
  strcpy(text, buffer);
}

int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int qtdOcorrencias = 0;
    int posicao = 0;
    int len = strlen(strBusca);
    noSpecials(strTexto);
    noSpecials(strBusca);

    for(int i = 0; i<strlen(strTexto);){
      int achou = 0;
      if(strTexto[i]==strBusca[0]){
        achou=1;
        for(int j=i, k=0; k<len; j++,k++){
          if(strBusca[k]!=strTexto[j])achou=0;
        }
        if(achou){
          qtdOcorrencias++;
          posicoes[posicao] = i+1;
          posicao++;
          posicoes[posicao] = i+len;
          posicao++;

          i += len;
        }else{
          i++;
        }
      }
      if(!achou)i++;
    }

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
   int invertido = 0;

    while (num > 0) {
        invertido = invertido * 10 + (num % 10);
        num /= 10;
    }

    return invertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
    char strK[20], strN[20];
    int qtdOcorrencias = 0;
    
    sprintf(strK, "%d", numerobusca);
    sprintf(strN, "%d", numerobase);

    int lenK = strlen(strK);
    int lenN = strlen(strN);
    
    for (int i = 0; i <= lenN - lenK; i++) {
        if (strncmp(&strN[i], strK, lenK) == 0) {
            qtdOcorrencias++;
        }
    }
    
    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5]) {
    int linhas = 8;
    int colunas = 10;

    int direcoes[8][2] = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0},
        {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
    };

    int len = strlen(palavra);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            for (int d = 0; d < 8; d++) {
                int dx = direcoes[d][0];
                int dy = direcoes[d][1];
                int k;

                for (k = 0; k < len; k++) {
                    int ni = i + k * dx;
                    int nj = j + k * dy;

                    if (ni < 0 || ni >= linhas || nj < 0 || nj >= colunas)
                        break;

                    if (matriz[ni][nj] != palavra[k])
                        break;
                }

                if (k == len)
                    return 1; 
            }
        }
    }
    return 0; 
 }



// DataQuebrada quebraData(char data[]){
//   DataQuebrada dq;
//   char sDia[3];
// 	char sMes[3];
// 	char sAno[5];
// 	int i; 

// 	for (i = 0; data[i] != '/'; i++){
// 		sDia[i] = data[i];	
// 	}
// 	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
// 		sDia[i] = '\0';  // coloca o barra zero no final
// 	}else {
// 		dq.valido = 0;
//     return dq;
//   }  
	

// 	int j = i + 1; //anda 1 cada para pular a barra
// 	i = 0;

// 	for (; data[j] != '/'; j++){
// 		sMes[i] = data[j];
// 		i++;
// 	}

// 	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
// 		sMes[i] = '\0';  // coloca o barra zero no final
// 	}else {
// 		dq.valido = 0;
//     return dq;
//   }
	

// 	j = j + 1; //anda 1 cada para pular a barra
// 	i = 0;
	
// 	for(; data[j] != '\0'; j++){
// 	 	sAno[i] = data[j];
// 	 	i++;
// 	}

// 	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
// 		sAno[i] = '\0';  // coloca o barra zero no final
// 	}else {
// 		dq.valido = 0;
//     return dq;
//   }

//   dq.iDia = atoi(sDia);
//   dq.iMes = atoi(sMes);
//   dq.iAno = atoi(sAno); 

// 	dq.valido = 1;
    
//   return dq;
// }

