#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct at{
    int broj;
    struct at* slijedeci;
};
typedef struct at atom;

void copyList(atom* glava, atom** nova){
    atom** sl;
    atom* trenutni = malloc(sizeof(atom));
    if (!(glava->slijedeci)){
        trenutni->slijedeci = NULL;
        trenutni->broj = glava->broj;
        *nova = trenutni;
        return;
    }
    trenutni->broj = glava->broj;
    sl = malloc(sizeof(sizeof(atom**)));
    copyList(glava->slijedeci, sl);
    trenutni->slijedeci = *sl;
    *nova = trenutni;
    return;
}
void popuni(atom** glava, int n){
    *glava = malloc(sizeof(atom));
    (*glava)->broj = rand()%10;
    if (!n){
        (*glava)->slijedeci = NULL;
        return;
    }
    popuni(&((*glava)->slijedeci), n-1);
    return;
}
void ispis(atom* glava, char* ime){
    
    printf("%d ", glava->broj);
    if(!(glava->slijedeci)){
        printf("\nEnd of print of %s\n", ime);
        return;
    }
    ispis(glava->slijedeci, ime);
    return;
}
int main(void){
    srand(time(NULL));
    atom** glava = malloc(sizeof(atom*));
    atom** copyGlave = malloc(sizeof(atom*));
    popuni(glava, 10);
    ispis(*glava, "Glava");
    copyList(*glava, copyGlave);
    ispis(*copyGlave, "CopyGlave");
    return 0;

}