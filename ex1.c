#include <stdio.h>
#include <string.h>

void compactar(const char *entrada, char *saida) {
    int i = 0, j = 0, count;
    while (entrada[i] != '\0') {
        char atual = entrada[i];
        count = 1;
        while (entrada[i] == entrada[i + 1]) {
            count++;
            i++;
        }
        if (count > 1) {
            j += sprintf(&saida[j], "%c%d-", atual, count);
        } else {
            j += sprintf(&saida[j], "%c1-", atual);
        }
        i++;
    }
    if (j > 0) {
        saida[j - 1] = '\0'; // Remove o último '-'
    }
}

int main() {
    char entrada[100];
    char saida[100];
    
    printf("Digite a string a ser compactada: ");
    scanf("%99s", entrada);
    
    compactar(entrada, saida);
    printf("\"%s\"\n", saida);
    
    return 0;
}
