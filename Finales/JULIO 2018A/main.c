#include <stdio.h>
#include <stdlib.h>

struct s_indices{
    int indice_inicial;
    int indice_final;
};
typedef struct s_indices t_indice;

t_indice buscarSub(char* str, char* sub){
    t_indice indices;

    indices.indice_inicial = -1;
    indices.indice_final = -1;

    int existeSub = 0;
    int indStr = 0;
    int indSub = 0;

    while(str[indStr] != '\0' && !existeSub){

        if(str[indStr] == sub[indSub]){
            indices.indice_inicial = indStr;
            indices.indice_final = indStr;
        
            while(str[indStr] == sub[indSub] && str[indStr] != '\0' && sub[indSub] != '\0'){
                indices.indice_final = indStr;
                indStr++;
                indSub++;
            }

            if(sub[indSub] == '\0'){
                existeSub = 1;
            }

            indSub = 0;
        }

        indStr++;

    }

    return indices;

}

int main(){
    char str[] = "La verdad absoluta no existe, y esto es absolutamente cierto.";
    char subCad[] = "d ab";
    t_indice indices = buscarSub(str, subCad);
    printf("(%d , %d)",indices.indice_inicial, indices.indice_final);
    return 0;
}