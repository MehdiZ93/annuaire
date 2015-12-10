#ifndef ANNUAIRE_H
#define ANNUAIRE_H

typedef struct s_pers
{
    char* nom;
    char* prenom;
    char* tel;
    struct s_pers *nxt;
}t_pers;

t_pers *ajouterEnFin(t_pers *liste, char *nom, char *prenom, char* tel);
t_pers * ajout_element(t_pers *liste, char *nom, char *prenom, char* tel);
t_pers *recup_annuaire(t_pers *annuaire);
void sauv_annuaire(t_pers *annuaire);
t_pers *ajouter(t_pers *annuaire);
void aff_annuaire(t_pers *annuaire);
t_pers* delete_contact(t_pers* annuaire);
char* strcapitalize(char *str);
t_pers *modif(t_pers *annuaire);

#endif /* ANNUAIRE_H */
