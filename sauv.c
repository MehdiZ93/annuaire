#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "annuaire.h"

t_pers *recup_annuaire(t_pers *annuaire)
{
    FILE *fp;
    char nom[40] = "", prenom[40] = "",tel[11] = "";
    t_pers *tmp;

    if ((fp = fopen("./contact/repertoire.txt","r")) == NULL)
    {
        fprintf(stderr, "Erreur lors de l'ouverture du ficher\n");
        exit(1);
    }
    while (!feof(fp) != 0)
    {
        fscanf(fp,"%s", nom);
        fscanf(fp,"%s", prenom);
        fscanf(fp,"%s", tel);
        annuaire = ajouterEnFin(annuaire, nom, prenom, tel);
    }
    fclose(fp);
    tmp = annuaire;
    while (tmp->nxt->nxt != NULL)
        tmp = tmp->nxt;
    tmp->nxt = NULL;
    return annuaire;
}

void sauv_annuaire(t_pers *annuaire)
{
    FILE *fp;

    if ((fp = fopen("./contact/repertoire.txt","w+")) == NULL)
    {
        fprintf(stderr, "Erreur lors de l'ouverture du ficher\n");
        exit(1);
    }
    while(annuaire != NULL)
    {
        fprintf(fp, "%s\n%s\n%s\n", annuaire->nom, annuaire->prenom, annuaire->tel);
        annuaire = annuaire->nxt;
    }
    fclose(fp);
    printf("L'annuaire a ete sauvegarder avec succes\n");
}

