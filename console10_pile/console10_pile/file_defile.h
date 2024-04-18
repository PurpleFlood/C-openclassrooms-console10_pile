//
//  file_defile.h
//  console10_pile
//
//  Created by asap on 16/04/2024.
//

#ifndef file_defile_h
#define file_defile_h

typedef struct ElementFile ElementFile;
struct ElementFile {
    int nombre;
    ElementFile *suivant;
};
typedef struct File File;
struct File{
    ElementFile *premier;
};

File *initialisationFile(){
    File *file = malloc(sizeof(*file));
    ElementFile *element = malloc(sizeof(*element));
    
    if (file == NULL || element == NULL){
        exit(EXIT_FAILURE);
    }
    element->suivant=NULL;
    file->premier=element;
    
    return file;
}

void enfiler(File *file, int nvNombre){
    ElementFile *nouveau = malloc(sizeof(*nouveau));
    if (nouveau == NULL || file == NULL){
        exit(EXIT_FAILURE);
    }
    
    nouveau->nombre=nvNombre;
    nouveau->suivant=NULL;
    
    if(file->premier!=NULL){
        ElementFile *elementactuel=file->premier;
        while(elementactuel->suivant !=NULL){
            elementactuel=elementactuel->suivant;
        }
        elementactuel->suivant=nouveau;
        
    }else {
        file->premier=nouveau;
    }
}

int defiler(File *file){
    if(file == NULL){
        exit(EXIT_FAILURE);
    }
    
    int nombreDefile=0;
   
    
    if(file != NULL && file->premier != NULL){
        ElementFile *elementDefile=file->premier;
        nombreDefile=elementDefile->nombre;
        file->premier=elementDefile->suivant;
        free(elementDefile);
    }
    return nombreDefile;
}

void afficherFile(File *file){
    if(file == NULL){
        exit(EXIT_FAILURE);
    }
    ElementFile *actuel=file->premier;
    
    while(actuel != NULL){
        printf("%d ", actuel->nombre);
        actuel=actuel->suivant;
    }
    printf("\n");
    
}

#endif /* file_defile_h */
