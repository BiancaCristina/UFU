/////////////////////////REDE IPE/////////////////////////
///////// BIANCA CRISTINA DA SILVA - 11711BCC023 /////////
///////// THAYNARA SILVA PINTO     - 11711BCC    /////////
///////// GUSTAVO                  - 11711BCC    /////////
//////////////////////////////////////////////////////////

#include "grafo.h"

/// ARQUIVO
int le_vertice (vertice* v, char* url,int qtd_vertices); // LE ARQUIVO TXT DE VERTICES
int le_aresta (aresta* a, char* url, int quantidade); // LE ARQUIVO TXT DE ARESTAS
int tamanho_arquivo (char* url); // CONTA TAMANHO DE LINHAS DO ARQUIVO
char* le_cidade (); // LE CIDADE E FORMATA PARA QUE SEJA ENCONTRADA NO BANCO DE DADOS
char* formata_cidade (char* cidade); // FORMATA O NOME DA CIDADE PARA O USUARIO
