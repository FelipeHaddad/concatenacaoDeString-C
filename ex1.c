/* Integrantes
Felipe Bertacco Haddad - 10437372
Ana Julia Matilha - 10436655
Beatriz Nóbrega - 10435789
*/

#include <stdio.h>
#include <string.h>

// Função de compactação da string
void compactacao(const char *entrada, char *saida) {
    int i = 0, j = 0, count;
    
    while (entrada[i] != '\0') { // Percorre a string até o fim
        char atual = entrada[i];
        count = 1;
        
        // Conta quantas vezes o caractere atual se repete consecutivamente
        while (entrada[i] == entrada[i + 1]) {
            count++;
            i++;
        }
        
        // Adiciona o caractere e a contagem na string de saída
        if (count > 1) {
            j += sprintf(&saida[j], "%c%d-", atual, count);
        } else {
            j += sprintf(&saida[j], "%c1-", atual);
        }
        
        i++; // Avança para o próximo caractere
    }
    
    if (j > 0) {
        saida[j - 1] = '\0'; // Remove o último '-'
    }
}

int main() {
    char entrada[100]; // String de entrada
    char saida[100];   // String de saída
    
    // Solicita ao usuário que digite uma string
    printf("Digite a string a ser compactada: ");
    scanf("%99s", entrada);
    
    // Chama a função para compactar a string
    compactacao(entrada, saida);
    
    // Exibe a string compactada
    printf("\"%s\"\n", saida);
    
    return 0;
}
