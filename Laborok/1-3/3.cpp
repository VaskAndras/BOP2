#include <stdlib.h>
#include <stdio.h>

char* reverse(char* a){
    int length;
    for( length=0; a[length] != '\0'; length++){}
    
    char* re = (char*)malloc((length+1)*sizeof(char));
    
    int i;
    int original_length = length;

    for (i = 0; i < original_length; i++) {

        re[i] = a[original_length - 1 - i];
    }
    re[original_length] = '\0';
    return re;
}


int main() {
    char* szo = "Programozas";
    char* forditott = reverse(szo);

    if (forditott != NULL) {
        printf("Eredeti: %s\n", szo);
        printf("Megforditva: %s\n", forditott);
        
        // Fontos: a malloc-olt területet fel kell szabadítani!
        free(forditott);
    }

    return 0;
}