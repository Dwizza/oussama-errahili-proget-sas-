#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct eleves{
int ID;
char nom[20];
char prenom[20];
char d_naissance[12];
char dep[10];
float N_generale;
};
struct eleves eleve[100];
int count=0;


void Menu(){
    printf("---------------------Menu----------------------\n");
printf("1- Ajouter un etudiant.\n");
printf("2- Modifier un etudiant.\n");
printf("3- Supprimer un etudiant.\n");
printf("4- Afficher les details d'un etudiant.\n");
printf("5- Calculer la moyenne generale.\n");
printf("6- Afficher les statistiques.\n");
printf("7- Rechercher un etudiant.\n");
printf("8- Trier les etudiants.\n");
printf("9- Quitter.\n");
}
void Add(){
    int N;
    printf("Enrtrez le nombre d'etudiant que tu veux ajouter :");
    scanf("%d",&N);
    eleve[0].ID=1;
    for(int i=0;i<N;i++){
        printf("---Etudiant %d\n",i+1);
        printf("Entrez le nom d'etudiant :");
        scanf(" %[^\n]s",&eleve[i].nom);
        printf("Entrez le prenom d'etudiant :");
        scanf(" %[^\n]s",&eleve[i].prenom);
        printf("Entrez la date de naissance :");
        scanf(" %[^\n]s",&eleve[i].d_naissance);
        printf("Entrez le departement d'etudiant :");
        scanf(" %[^\n]s",&eleve[i].dep);
        printf("Entrez la note generale d'etudiant :");
        scanf("%f",&eleve[i].N_generale);
        count++;
        eleve[i].ID++;
       }
}
void Modifier(){
    int Nunique,choix;
    printf("%d",eleve[0].ID);
    printf("Entrez le numero unique :");
    scanf("%d",&Nunique);
    for (int i=0;i<=count;i++){
        if(eleve[i].ID==Nunique){
            printf("1. Modifier le nom d'etudiant.\n");
            printf("2. Modifier le prenom d'etudiant.\n");
            printf("3. Modifier la date de naissance d'etudiant.(dd/mm/aaaa)\n");
            printf("4. Modifier le departement d'etudiant.\n");
            printf("5. Modifier la note generale d'etudiant.\n");
            printf("Entrez votre choix :");
            scanf("%d",&choix);
            switch(choix){
            case 1:
                printf("Entrez le nouveau nom :");
                scanf(" %[^\n]s",&eleve[i].nom);
                break;
            case 2:
                printf("Entrez le nouveau prenom :");
                scanf(" %[^\n]s",&eleve[i].prenom);
                break;

            }

        }

    }
}
void Recherche(){

}

int main()
{
    int choix;
    do{
        Menu();
        printf("Entrez votre choix :");
        scanf("%d",&choix);
        switch(choix){
        case 1:
            Add();
            break;
        case 2:
            Modifier();
            break;
        case 3:
            Recherche();
            break;

        }

    }while(choix<100);

    return 0;
}
