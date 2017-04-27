#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct at{
    int broj;
    struct at* slijedeci;
};
typedef struct at atom;
void ispis(atom* glava, char* ime);
void ispis1(atom* glava);
/* funkcija za kopiranje liste u drugu list (zadatak 4. na MI-u) */
void copyList(atom* glava, atom** nova){
    atom** sl; /* Pointer koji pokazuje na slijedeći pointer atoma */
    atom* trenutni = malloc(sizeof(atom)); /* Inicializacija trenutnog pointera u novoj listi */
    if (!(glava->slijedeci)){ /* Ako je adresa slijedečeg elementa orginalne liste NULL(pretpostavka: kraj list će pokazivati na NULL, ukoliko ne pokazuje funkcija uzima smeće), onda... */
        trenutni->slijedeci = NULL; /* Slijedeči element, trenutnog element nove list pokazuje na NULL  */
        trenutni->broj = glava->broj; /* Broj u trenutnom elementu nove list je isti ko i u trenutnom elementu orginalne list */
        *nova = trenutni; /* glava nove liste pokazuje na trenutni element */
        ispis1(*nova); /* Nije dio orginalnog koda, no lijepo ilistrira kako program radi */
        return;
    }
    /* ako slijedeći element u orginalnoj listi nije NULL */
    trenutni->broj = glava->broj; /* ponovno se prepisuje broj iz orginalne u kopiranu lisu (redundanto, znam, no mislim da sam tako napisao na ispitu) */
    sl = malloc(sizeof(atom**)); /* inicijalizira se nova glava atoma */
    copyList(glava->slijedeci, sl); /* ponovno se poziva copyList, a ne s glavnom orginalne liste, nego s slijedečim elementom u listi, a kao nova lista se stavlja privremena varijabla sl */
    trenutni->slijedeci = *sl; /* at* slijedeći pokazuje na novo nastali atom *sl */
    *nova = trenutni;  /* na kraju se trenutni element stavlja na početak nove list, a pošto je funkcija rekurzivna ustvari će biti na istom mijestu kao i u orginalnoj listi */
    ispis1(*nova); /* Nije dio orginalnog koda, no lijepo ilistrira kako program radi */
    return;
}
/* pomočna funkcija za popunjavanje liste s random brojevima */
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
/* pomočna funkcija za ispis liste */
void ispis(atom* glava, char* ime){
    
    printf("%d ", glava->broj);
    if(!(glava->slijedeci)){
        printf("\nEnd of print of %s\n", ime);
        return;
    }
    ispis(glava->slijedeci, ime);
    return;
}
/* pomočna funkcija za ispis liste */
void ispis1(atom* glava){
    
    printf("%d ", glava->broj);
    if(!(glava->slijedeci)){
        printf("\n");
        return;
    }
    ispis1(glava->slijedeci);
    return;
}
int main(void){
    srand(time(NULL));
    atom** glava = malloc(sizeof(atom*)); /*inicijalizacija orginalne liste */
    atom** copyGlave = malloc(sizeof(atom*)); /* inicijalizacija, uskoro, kopirane liste */
    popuni(glava, 10);    /* orginalna lista se puni s random brojevima */
    ispis(*glava, "Glava");    /* ispis orginalne liste */
    copyList(*glava, copyGlave);    /* kopiranje orginalne liste u kopiranu listu */
    ispis(*copyGlave, "CopyGlave");    /* ispis kopirane liste */
    return 0;

}