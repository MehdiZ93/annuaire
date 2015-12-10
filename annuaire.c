#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "annuaire.h"

t_pers *modif(t_pers *annuaire)
{
    char nom[40], prenom[40];
    t_pers *tmp = annuaire;
    int choix;

    printf("Saisissez le nom de la personne a modifier\n");
    scanf("%s", nom);
    printf("Saisissez le prenom de la personne a modifier\n");
    scanf("%s", prenom);
    while (tmp != NULL && (strcmp(tmp->nom, strcapitalize(nom)) != 0 && strcmp(tmp->prenom, strcapitalize(prenom)) != 0))
        tmp = tmp->nxt;
    if(tmp != NULL)
    {
        do
        {
            printf("Que voulez vous modifier ?\n");
            printf("1 - Nom\n2 - Prenom\n3 - Telephone\n4 - Retour au menu principal\n");
            scanf("%d", &choix);
            switch (choix)
            {
                case 1 :
                    do
                    {
                        printf("Saissisez le nouveau nom\n");
                        scanf("%s", nom);
                    }while(check_str(nom) != 0);
                    tmp->nom = strdup(strcapitalize(nom));
                    printf("Le nom a bien ete modifie\n");
                break;
                case 2 :
                    printf("Saissisez le nouveau prenom\n");
                    scanf("%s", nom);
                    tmp->prenom = strdup(strcapitalize(nom));
                    printf("Le prenom a bien ete modifie\n");
                break;
                case 3 :
                    printf("Saissisez le nouveau numero de telephone\n");
                    scanf("%s", nom);
                    tmp->tel = strdup(strcapitalize(nom));
                    printf("Le numero de telephone a bien ete modifie a bien ete modifie\n");
                break;
            };
        }while (choix != 4);
    }
    else
        printf("La personne n'a pas ete trouvee\n");
    system("pause");
    system("cls");
    return annuaire;
}

int check_str(char * str)
{
    int i = 0;

    if (strlen(nom) < 2)
        return 1;
    while (str[i] != 0)
    {
        if ((str[i] < 'A' && str[i] > 'Z') || (str[i] < 'a' && str[i] > 'z'))
            return 1;
        i++;
    }
    return 0;
}

int check_arg(char *nom, char *prenom, char *tel)
{
    if (check_str(nom) != 0)
    {
        printf("Le nom saisie n'est pas au bon format\n");
        return 1;
    }
    if(tel[0] != '0' && strlen(tel) < 10)
    {
        printf("Le numero de telephone rentre n'est pas au bon format\n");
        return 1;
    }
    return 0;
}

t_pers *ajouter(t_pers *annuaire)
{
    char nom[40] = "Vide", prenom[40] = "Vide", tel[11] = "0000000000";

    system("cls");
    do
    {
        printf("Entrez le nom\n");
        fscanf(stdin, "%s",nom);
        printf("Entrez le prenom\n");
        fscanf(stdin, "%s",prenom);
        printf("Entrez le numero de telephone\n");
        scanf("%s",tel);
    }while(check_arg(nom, prenom, tel) != 0);
    annuaire = ajout_element(annuaire, strcapitalize(nom), strcapitalize(prenom), tel);
    printf("%s %s a bien ete ajoute\n",nom, prenom);
    system("pause");
    system("cls");
    return (annuaire);
}

void aff_annuaire(t_pers *annuaire)
{
    t_pers *tmp = annuaire;
    while (tmp != NULL)
    {
        printf("%s\n%s\n%s\n\n", tmp->nom, tmp->prenom, tmp->tel);
        tmp = tmp->nxt;
    }
        system("pause");
        system("cls");
}

t_pers* delete_contact(t_pers* annuaire)
{
    char nom[40], prenom[40];
    t_pers *tmp = annuaire, *tmp2 = annuaire;
    int i = 0;

    printf("Saisissez le nom de la personne a supprimer\n");
    scanf("%s", nom);
    printf("Saisissez le prenom de la personne a supprimer\n");
    scanf("%s", prenom);
    while (tmp != NULL && strcmp(tmp->nom, strcapitalize(nom)) != 0)
    {
        if (i > 0)
            tmp2 = tmp2->nxt;
        tmp = tmp->nxt;
        i++;
    }
    while (tmp != NULL && strcmp(tmp->prenom, strcapitalize(prenom)) != 0)
    {
        tmp = tmp->nxt;
        tmp2 = tmp2->nxt;
    }
    if (tmp != NULL && strcmp(tmp->nom, strcapitalize(nom)) == 0 && strcmp(tmp->prenom, strcapitalize(prenom)) == 0)
    {
        tmp2->nxt = tmp->nxt;
        free(tmp);
        printf("%s %s a bien ete supprimer\n", nom, prenom);
    }
    else
        printf("La personne %s %s n'est pas dans l'annuaire\n", nom, prenom);
    system("pause");
    system("cls");
    return annuaire;
}
