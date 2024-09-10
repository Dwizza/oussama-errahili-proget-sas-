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
int id=1;




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
        printf("---Etudiant %d\n",count+1);
        printf("Entrez le nom d'etudiant :");
        scanf(" %[^\n]s",&eleve[count].nom);
        printf("Entrez le prenom d'etudiant :");
        scanf(" %[^\n]s",&eleve[count].prenom);
        printf("Entrez la date de naissance :");
        scanf(" %[^\n]s",&eleve[count].d_naissance);
        printf("Entrez le departement d'etudiant :");
        scanf(" %[^\n]s",&eleve[count].dep);
        printf("Entrez la note generale d'etudiant :");
        scanf("%f",&eleve[count].N_generale);
        eleve[count].ID=id++;
        count++;


}
void Modifier(){
    int Nunique,choix;

    printf("%d\n",count);
    printf("Entrez le numero unique :");
    scanf("%d",&Nunique);
    for (int i=0;i<count;i++){
        if(eleve[i].ID==Nunique){
            printf("1. Modifier le nom d'etudiant.\n");
            printf("2. Modifier le prenom d'etudiant.\n");
            printf("3. Modifier la date de naissance d'etudiant.\n");
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
            case 3:
                printf("Entrez la nouvelle date de naissance (dd/mm/aaaa) :");
                scanf(" %[^\n]s",&eleve[i].d_naissance);
                break;
            case 4:
                printf("Entrez le nouveau departement :");
                scanf(" %[^\n]s",&eleve[i].dep);
                break;
            case 5:
                printf("Entrez la nouvelle note generale :");
                scanf(" %[^\n]s",&eleve[i].prenom);
                break;
            }

        }

    }
}
void Recherche(){
    char Nnom[20];
    printf("Entrez le nom :");
    scanf(" %[^\n]s",&Nnom);
    for(int i=0;i<count;i++){
        if(strcmp(eleve[i].nom,Nnom)==0){
            printf("le numero unique : %d\n",eleve[i].ID);
            printf("le nom d'etudiant : %s\n",eleve[i].nom);
            printf("le prenom d'etudiant : %s\n",eleve[i].prenom);
            printf("la date de naissance : %s\n",eleve[i].d_naissance);
            printf("le departement d'etudiant : %s\n",eleve[i].dep);
            printf("la note generale d'etudiant : %f\n",eleve[i].N_generale);
        }

    }
}
void Supprimer (){
int sup;
    if (count==0){
        printf("------------------\n");
        printf("il n'y a aucun etudiant.\n");

    }
    else{
    printf("Entrez le numero unique que tu veux supprimer :");
    scanf("%d",&sup);
    for (int i=0;i<count;i++){
        if (eleve[i].ID-sup==0){
                for (int j=i;j<count;j++){
                    eleve[j]=eleve[j+1];
            }
            count--;
        }
      }
    printf("Votre etudiant a ete bien supprimer.\n");
  }
}
void Details(){
for (int i=0;i<count;i++){
    printf("\n");
    printf("------- etudiant--%d- \n",i+1);
    printf("\n");
    printf("le numero unique : %d\n",eleve[i].ID);
    printf("le nom d'etudiant : %s\n",eleve[i].nom);
    printf("le prenom d'etudiant : %s\n",eleve[i].prenom);
    printf("la date de naissance d'etudiant : %s\n",eleve[i].d_naissance);
    printf("le departement d'etudiant : %s\n",eleve[i].dep);
    printf("la note generale d'etudiant : %.2f\n",eleve[i].N_generale);

    }
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
            Supprimer ();
            break;
        case 4 :
            Details();
            break;
        case 7:
            Recherche();
            break;

        }

    }while(choix<100);

    return 0;
}
