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
int id=0;




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
        printf("---Etudiant %d\n",count+1);
        printf("Entrez le nom d'etudiant :");
        scanf(" %[^\n]s",&eleve[count].nom);
        printf("Entrez le prenom d'etudiant :");
        scanf(" %[^\n]s",&eleve[count].prenom);
        printf("Entrez la date de naissance (dd/mm/yy) :");
        scanf(" %[^\n]s",&eleve[count].d_naissance);
        printf("Entrez le departement d'etudiant :");
        scanf(" %[^\n]s",&eleve[count].dep);
        printf("Entrez la note generale d'etudiant :");
        scanf("%f",&eleve[count].N_generale);
        eleve[count].ID=++id;
        count++;
}
void Modifier(){
    int Nunique,choix;
    printf("Entrez le numero unique :");
    scanf("%d",&Nunique);
    for (int i=0;i<count;i++){
        if(eleve[i].ID==Nunique){
            printf("1. Modifier le nom d'etudiant : %s\n",eleve[i].nom);
            printf("2. Modifier le prenom d'etudiant : %s\n",eleve[i].prenom);
            printf("3. Modifier la date de naissance d'etudiant : %s\n",eleve[i].d_naissance);
            printf("4. Modifier le departement d'etudiant : %s\n",eleve[i].dep);
            printf("5. Modifier la note generale d'etudiant : %.2f\n",eleve[i].N_generale);
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
    char depR[20];
    int choix,N=0;
    printf("1. Chercher par nom.\n");
    printf("2. Chercher par departement.\n");
    printf("Entrez votre choix :");
    scanf("%d",&choix);
    switch(choix){
    case 1:
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

    break;
    case 2:
            printf("Entrez le departement :");
            scanf(" %[^\n]s",&depR);
            for (int i=0;i<count;i++){
            if (strcmp(eleve[i].dep,depR)==0){
                printf("\t\t--Etudiant-- %d :\n",N);
                printf("Le numero unique d'etudiant :%d\n",eleve[i].ID);
                printf("Le nom d'etudiant :%s\n",eleve[i].nom);
                printf("Le prenom d'etudiant :%s\n",eleve[i].prenom);
                printf("La date de naissance d'etudiant :%s\n",eleve[i].d_naissance);
                printf("Le departement d'etudiant :%s\n",eleve[i].dep);
                printf("La note generale d'etudiant :%.2f\n",eleve[i].N_generale);
                N++;
        }
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
    printf("--------------\n");
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
void calcul(){
     char T[20][50];
     int countDep=0;
     int stocker = 0;
     float somme = 0;
     int lengthDep = 0;
        for (int i = 0; i < count; i++){
            for (int j = 0; j < i; j++){
                if (strcmp(eleve[i].dep, eleve[j].dep) == 0){
                stocker = 1;
                break;
                }
            }
                if (!stocker){
                      strcpy(T[countDep], eleve[i].dep);
                      countDep++;
                }
        }

        for (int i = 0; i < countDep; i++){
            for (int j = 0; j < count; j++){
                if (strcmp(T[i], eleve[j].dep) == 0){
                    somme += eleve[j].N_generale;
                    lengthDep++;
                }
            }
        printf("Le departement %s = %.2f \n",eleve[i].dep,somme / lengthDep);
        }
    }
void Statistique(){
    int choix;
    char depS[20];
    char depR[20];
    int N=1,C=1,X=1;
    float S=0,temp=0;
    char T[20][50];
    int countDep=0;
    int stocker = 0;
    float somme = 0;
    int lengthDep = 0;

    printf("1. Afficher le nombre total d'etudiants inscrits.\n");
    printf("2. Afficher le nombre d'etudiants dans chaque departement.\n");
    printf("3. Afficher les etudiants ayant une moyenne generale superieure a un certain seuil.\n");
    printf("4. Afficher les 3 etudiants ayant les meilleures notes.\n");
    printf("5. Afficher le nombre d'etudiants ayant reussi dans chaque departement.\n");
    printf("Entrez votre choix :");
    scanf("%d",&choix);
    switch(choix){
    case 1:
        printf("Le nombre total d'etudiant inscrits : %d.\n",count);
        break;
    case 2:

        for (int i = 0; i < count; i++){
            for (int j = 0; j < i; j++){
                if (strcmp(eleve[i].dep, eleve[j].dep) == 0){
                stocker = 1;
                break;
                }
            }
        if (!stocker){
              printf("%s\n", eleve[i].dep);
              strcpy(T[countDep], eleve[i].dep);
              countDep++;
            }
        }

        for (int i = 0; i < countDep; i++){
            for (int j = 0; j < count; j++){
                    if (strcmp(T[i], eleve[j].dep) == 0){
                        somme += eleve[j].N_generale;
                        lengthDep++;
                    }
            }

        }
        for (int i=0;i<countDep;i++)
        printf("Le departement %s = %.2f \n: ", eleve[i].dep, somme / lengthDep);
    break;
    case 3:
        printf("Entrez le seuil :");
        scanf("%f",&S);
        for (int i=0;i<count;i++){
            if(eleve[i].N_generale>=S){
                printf("\t\t--Etudiant-- %d :\n",C);
                printf("Le numero unique d'etudiant :%d\n",eleve[i].ID);
                printf("Le nom d'etudiant :%s\n",eleve[i].nom);
                printf("Le prenom d'etudiant :%s\n",eleve[i].prenom);
                printf("La date de naissance d'etudiant :%s\n",eleve[i].d_naissance);
                printf("Le departement d'etudiant :%s\n",eleve[i].dep);
                printf("La note generale d'etudiant :%.2f\n",eleve[i].N_generale);
                C++;
            }
        }
        break;
    case 4:
        for(int i =0;i<count;i++){
            for(int j=0;j<count;j++){
                if(eleve[j].N_generale<eleve[j+1].N_generale){
                    temp=eleve[j].N_generale;
                    eleve[j].N_generale=eleve[j+1].N_generale;
                    eleve[j+1].N_generale=temp;
                }
            }
        }
        for(int i=0;i<3;i++){
            printf("\n");
            printf("\t\t--Etudiant-- %d :\n",i+1);
            printf("\n");
            printf("Le nom d'etudiant :%s\n",eleve[i].nom);
            printf("Le prenom d'etudiant :%s\n",eleve[i].prenom);
            printf("La date de naissance d'etudiant :%s\n",eleve[i].d_naissance);
            printf("Le departement d'etudiant :%s\n",eleve[i].dep);
            printf("La note generale d'etudiant :%.2f\n",eleve[i].N_generale);
        }
        break;
    case 5:
        for (int i =0;i<count;i++){
            if(eleve[i].N_generale>=10){
                printf("Le nom d'etudiant : %s",eleve[i].nom);
                printf("La note generale : %.2f",eleve[i].N_generale);
            }
        }
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
        case 5 :
            calcul();
            break;
        case 6:
            Statistique();
            break;
        case 7:
            Recherche();
            break;
        case 9:
            exit(0);
        }

    }while(choix<100);

    return 0;
}
