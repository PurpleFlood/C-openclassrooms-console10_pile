//
//  main.c
//  console10_pile
//
//  Created by asap on 16/04/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "pile_depile.h"
#include "file_defile.h"
Pile *initialisationPile();
File *initialisationFile();
void empiler(Pile *pile, int nvNombre);
void enfiler(File *file, int nvNombre);
int depiler(Pile *pile);
int defiler(File *file);
void afficherPile(Pile *pile);
void afficherFile(File *file);

int main(int argc, const char * argv[]) {
    
    /*
    Pile *mapile=initialisation();
    
    empiler(mapile, 9);
    empiler(mapile, 88);
    empiler(mapile, 33);
    afficherPile(mapile);
    depiler(mapile);
    afficherPile(mapile);
    */
    
    File *mafile=initialisationFile();
    
    enfiler(mafile, 8);
    enfiler(mafile, 19);
    enfiler(mafile, 11);
    printf("Etat de la file :\n");
    afficherFile(mafile);
    printf("Je defile %d\n", defiler(mafile));
    printf("Je defile %d\n", defiler(mafile));
    afficherFile(mafile);
    return 0;
}
