//
//  pile_depile.h
//  console10_pile
//
//  Created by asap on 16/04/2024.
//

#ifndef pile_depile_h
#define pile_depile_h

typedef struct ElementPile ElementPile;
struct ElementPile {
    int nombre;
    ElementPile *suivant;
};
typedef struct Pile Pile;
struct Pile{
    ElementPile *premier;
};

Pile *initialisationPile(){
    Pile *pile = malloc(sizeof(*pile));
    ElementPile *element = malloc(sizeof(*element));
    
    if (pile == NULL || element == NULL){
        exit(EXIT_FAILURE);
    }
    element->nombre=0;
    element->suivant=NULL;
    pile->premier=element;
    
    return pile;
}

void empiler(Pile *pile, int nvNombre){
    ElementPile *nouveau = malloc(sizeof(*nouveau));
    if (nouveau == NULL || pile == NULL){
        exit(EXIT_FAILURE);
    }
    
    nouveau->nombre=nvNombre;
    nouveau->suivant= pile->premier;
    pile->premier = nouveau;
}

int depiler(Pile *pile){
    if(pile == NULL){
        exit(EXIT_FAILURE);
    }
    int nombreDepile=0;
    ElementPile *elementDepile=pile->premier;
    
    if(pile != NULL && pile->premier != NULL){
        nombreDepile=elementDepile->nombre;
        pile->premier=elementDepile->suivant;
        free(elementDepile);
    }
    return nombreDepile;
}

void afficherPile(Pile *pile){
    if(pile == NULL){
        exit(EXIT_FAILURE);
    }
    ElementPile *actuel=pile->premier;
    
    while(actuel != NULL){
        printf("%d ", actuel->nombre);
        actuel=actuel->suivant;
    }
    printf("\n");
    
}
#endif /* pile_depile_h */
