#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "annuaire.h"

int menu()
{
    int choix;

    printf("Veuillez selectionner une des options suivante :\n");
    printf("\t 1 - Afficher les contacts\n");
    printf("\t 2 - Ajouter un contact\n");
    printf("\t 3 - Supprimer un contact\n");
    printf("\t 4 - Modifier un contact\n");
    printf("\t 5 - Quitter l'annuaire\n");
    fscanf(stdin, "%d", &choix);
    system("cls");
    return (choix);
}

int main()
{
   int choix;
   t_pers *annuaire = NULL;

    printf("Bienvenue dans votre super annuaire :D\n");
    annuaire = recup_annuaire(annuaire);
    do
    {
        choix = menu();
        switch (choix)
        {
            case 1 :
                aff_annuaire(annuaire);
            break;
            case 2 :
                annuaire = ajouter(annuaire);
            break;
            case 3 :
                annuaire = delete_contact(annuaire);
            break;
            case 4 :
                annuaire = modif(annuaire);
            break;
            case 5 :
                printf("Merci d'avoir uiliser notre annuaire\n");
            break;
        };
    }while(choix != 5);
    sauv_annuaire(annuaire);
    return (0);
}
