#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#define TAILLE_MAX 1000

void fuseau_horaire(int index_heure,int index_minutes){
    system("cls");
    printf("\n\n\t\t Fuseau horaire:");
    printf("\n\n\tLos Angles: %dh%d",(index_heure-9)%24,index_minutes);
    printf("\n\n\tNew York: %dh%d",(index_heure-6)%24,index_minutes);
    printf("\n\n\tLondres: %dh%d",(index_heure-1)%24,index_minutes);
    printf("\n\n\tParis: %dh%d",(index_heure)%24,index_minutes);
    printf("\n\n\tMoscou: %dh%d",(index_heure+2)%24,index_minutes);
    printf("\n\n\tTokyo: %dh%d",(index_heure+7)%24,index_minutes);
    printf("\n\n\t r= retour");
}
void page_entrer(){
    int i;int j;
    for(i=0;i<200;i++){
        //system("cls");
        for(j=0;j<i;j++)
            printf(" ");                 // cette fonction represente l'animation de du début du code
            printf("_-_-_-_-_-");
            printf("\n");

        Sleep(10);


    }
    system("cls");
    printf("\n\n\n\n\n\n\t\t    bonjour et bienvenue sur l'agenda\n\n\n\tfait par:\n\n\t\t\tSaif\n\n\t\t\tMax\n\n\t\t\tMaxime\n\n\t\t\tWilliam");
    Sleep(2000);
}

int compare(const char* chaine1, const char* chaine2){      // compare deux chaines de caractères, tres utile pour les mois etc...
    int vrai = 0;
    while(*chaine1 != '\0' || *chaine2 != '\0'){
        if(*chaine1 != *chaine2){
            vrai = 1;
            }
      chaine1++;
      chaine2++;
    }
    return vrai;
}

int lire(char *chaine, int longueur){            // lire permet de demander à l'utilisateur une chaine de caractère avec des espaces. le Scanf ne permet pas
    char *positionEntree = NULL;                             // positionentree est le pointeur qui va stocker la chaine de caractere
    if (fgets(chaine, longueur, stdin) != NULL){           // tant que la phrase demander nest pas finis
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

int compare(const char* chaine1, const char* chaine2);


void calendar(int jour,int index_mois,int index_annee){
    int k=0;
    int a;
    int bis=0;

    char *day[2];
    char semaine[15][2]={"L","M","M","J","V","S","D","L","M","M","J","V","S","D"};
    int code[]={6,2,2,5,0,3,5,1,4,6,2,4};
    int codebis[]={5,1,2,5,0,3,5,1,4,6,2,4};
    printf("\t\t\t\n\t _______________________________________________________");
    char chaine[TAILLE_MAX]="";
    for(k=1;k<36;k++){
        FILE* fichier = NULL;
        fichier = fopen("stock.txt", "w");
        if (fichier != NULL){
            fprintf(fichier,"%d%d%d.txt",k,index_mois+1,index_annee);
            fclose(fichier);
        }
        fichier = fopen("stock.txt", "r");
        fgets(chaine,TAILLE_MAX,fichier);
        fclose(fichier);
        fichier = fopen(chaine, "r");
        if (fichier != NULL){
            *day="e";
            }
        else
            *day=" ";
        fclose(fichier);
        int i;
        for(i=2001;i<index_annee+1;i++){
            if (i%4==0)
                bis+=1;
            }
        if (index_annee%4==0)
            a=(7+((index_annee%2000)+bis)%7+codebis[index_mois])%7;
        else
            a=(7+((index_annee%2000)+bis)%7+code[index_mois])%7;
        bis=0;

        if (k==1){
            printf("\t\t\t|___%s___|___%s___|___%s___|___%s___|___%s___|___%s___|___%s___|",semaine[0],semaine[1],semaine[2],semaine[3],semaine[4],semaine[5],semaine[6]);
            printf("\n\t|       |       |       |       |       |       |       |");
            printf("\n\t|");}

        if((k+a-1)%7==0&&k!=1&&k<jour+1){
            printf("\t\t\t|_______|_______|_______|_______|_______|_______|_______|\n\t|");
            for(i=0;i<7;i++)
                printf("       |");


            printf("\n\t|");}
        if(k==1){
            for(i=0;i<a;i++)
                printf("       |");
            }

        if(k<10)
            printf("  %d  %s |",k,*day);
        if(k>9&& k<jour+1)
            printf(" %d  %s |",k,*day);

        if(k==jour){
            if(a+jour<=35){
                for(k=jour+a;k<35;k++)
                    printf("       |");
            }
            if(a+jour>=36){
                for(k=jour+a;k<42;k++)
                    printf("       |");
            }
        }

    }
    printf("\t\t\t|_______|_______|_______|_______|_______|_______|_______|");

}


int trouver_le_mois(char *mois,int index_annee){      // fonction qui permet au programme d'identifier le mois demandé par l"utilisateur et lui affilie le bon nombre jour dans le mois
    int finalday;
    char Mois_tableau[][12]={"janvier","fevrier","mars","avril","mai","juin","juillet","aout","septembre","octobre","novembre","decembre"};
    int jour_tableau [12]={31,28,31,30,31,30,31,31,30,31,30,31};         // les deux tableaux sont liés. a chaque mois dans la Mois_tableau, un nombre de jour est attribué dans jour_tableau
    int i;
    for(i=0;i<11;i++){
        if(mois==Mois_tableau[i]){
            if(mois==Mois_tableau[1]&& index_annee%4==0 && index_annee!=2000)    // sil'année est bisextile et que le mois est février, donner 29 jours au lieu de 28
            finalday=29;
            }
        else
            finalday= jour_tableau[i];
    }
    return finalday;         // retourne le nombre de jour
}

int main(int argc, char *argv[])
{

    system("mode con LINES=35 COLS=73");          // determine la taille de l'écran
    //page_entrer();                                // fait appel a la fonction pour faire la petite animation
    system("cls");                              // l'écran est effacé pour le ré actualise
    time_t now = time (NULL);                             // on prend le temps donné par le PC
    struct tm tm_now = *localtime (&now);                 // l'information est stockée dans une structure
    char s_now[sizeof "JJ/MM/AAAA HH:MM:SS"];
    //strftime (s_now, sizeof s_now, "%d/%m/%Y %H:%M:%S", &tm_now);
    strftime(s_now, sizeof s_now,"%Y",&tm_now);                // Y => on veut recupére l'annee, qui sera attribué à l'index_année
    int index_annee = atoi(s_now);
    strftime(s_now, sizeof s_now,"%m",&tm_now);            // m => on veut recupéré le mois, qui sera attribué à l'index_mois
    int index_mois = atoi(s_now);
    strftime(s_now, sizeof s_now,"%H",&tm_now);            // H => on veut recupéré le mois, qui sera attribué à l'index_mois
    int index_heure = atoi(s_now);
    strftime(s_now, sizeof s_now,"%M",&tm_now);            // M => on veut recupéré le mois, qui sera attribué à l'index_mois
    int index_minutes = atoi(s_now);
    int index_jour;
    int bisextile;           // variable pour le cas pour l'annee est bisextile
    char evenement[TAILLE_MAX]="";
    char numero[TAILLE_MAX]="";
    char Heure[TAILLE_MAX]="";
    char adresse[TAILLE_MAX]="";
    char *chaine = calloc(100, sizeof(char));           //permettra de stocker le nom des futurs fichier, a savoir leur date
    system("cls");

    system("COLOR 1E");  //F1   0A    1E                        changer la couleur de la console
    printf("\n\t\t\t  Calendrier %d\n",index_annee);             //affichier le calendrier
    char next[2];
    int jour_tableau [12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int i;
    char nombre_de_jour[][32]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"}; // pour afficher le calendrier avec les bons jours
    char Mois_tableau[][12]={"janvier","fevrier","mars","avril","mai","juin","juillet","aout","septembre","octobre","novembre","decembre"};

    index_mois-=1;
    printf("\n\n\n\t\t\t\t\%s\n",Mois_tableau[index_mois]);           // afficher le mois sur le calendrier
    calendar(jour_tableau[index_mois],index_mois,index_annee);        // afficher le calendrier

    printf("\n\n\n\tp = mois d'avant\n\tn = mois d'apres\n\tf = fuseau horaire\n\ttaper un jour pour y acceder");


    while(1){
        FILE* fichier = NULL;
        scanf("%s",next);
        //if(next)
        if(compare(next,"p") == 0){      // fonction pour afficher le mois precedent
            system("cls");
            if(index_mois==0){            // si le mois est janvier, aller sur decembre et changer une année en arrière
                index_mois=12;
                index_annee-=1;
            }
            index_mois-=1;
            if(index_annee!=2000&&index_annee%4==0&&index_mois==1)             // verifier si l'annnee est bisexttile et mettre le bon nombre de jour pour fevrier
                bisextile=1;
            else bisextile=0;
            printf("\n\t\t\t\tCalendrier %d\n\n",index_annee);
            printf("\n\n\n\t\t\t\t\%s\n",Mois_tableau[index_mois]);
            calendar(jour_tableau[index_mois]+bisextile,index_mois,index_annee); //affichier le calendrier + bisextile si besoin
            printf("\n\n\n\tp = mois d'avant\n\tn = mois d'apres\n\tf = fuseau horaire\n\ttaper un jour pour y acceder");    // message pour l'utilisateur
        }




        if(compare(next,"n") == 0){         // si l'utilisateur veux changer de mois, il appuie sur n => mois d'apres
            system("cls");
            if(index_mois==11){
                index_mois=-1;               // on change l'index du mois et de l'annee pour afficher le bon mois a la bonne annee
                index_annee+=1;
            }
            index_mois+=1;
            if(index_annee!=2000&&index_annee%4==0&&index_mois==1)       // si l'annee est bisextile, rajouter un jour au mois de fevrier
                bisextile=1;
            else bisextile=0;
            printf("\n\t\t\tCalendrier %d\n\n",index_annee);
            printf("\n\n\n\t\t\t\t\%s\n",Mois_tableau[index_mois]);
            calendar(jour_tableau[index_mois]+bisextile,index_mois,index_annee);
            printf("\n\n\n\tp = mois d'avant\n\tn = mois d'apres\n\tf = fuseau horaire\n\ttaper un jour pour y acceder");

            }


        if(compare(next,"r") == 0){       // fonction qui permet de quitter un jour précis et revenir sur le calendrier du mois
            system("cls");
            //index_mois+=1;
            printf("\n\t\t\t\tCalendrier %d\n\n",index_annee);
            printf("\n\n\n\t\t\t\t\%s\n",Mois_tableau[index_mois]);
            calendar(jour_tableau[index_mois],index_mois,index_annee);
            printf("\n\n\n\tp = mois d'avant\n\tn = mois d'apres\n\tf = fuseau horaire\n\ttaper un jour pour y acceder");
        }


        for(i=0;i<31;i++){                             // fonction qui affiche un jour précis du mois si l'utilisateur tape ce jour précis
            if(compare(next,nombre_de_jour[i])==0){
                index_jour=i;
                system("cls");
                printf("\n\t\t\tagenda du %d %s %d\n\n\n\n",i+1,Mois_tableau[index_mois],index_annee);
                fichier = fopen("stock.txt", "w");                              // ouvrir le fichier de stockage
                if (fichier != NULL){
                    fprintf(fichier,"%d%d%d.txt",index_jour+1,index_mois+1,index_annee); // stocker la date de l'évéement
                    fclose(fichier);
                }
                fichier = fopen("stock.txt", "r");
                fgets(chaine,TAILLE_MAX,fichier); // recuperer la date de l'évenement pour créer un fichier avec la date
                fclose(fichier);
                fichier = fopen(chaine, "r");       // ouvrir le fichier evenement de cette date
                if (fichier != NULL){
                        fgets(chaine,TAILLE_MAX,fichier);
                        printf("Evenement:            %s",chaine);
                        fgets(chaine,TAILLE_MAX,fichier);
                        printf("Numero de telephone:  %s",chaine);
                        fgets(chaine,TAILLE_MAX,fichier);
                        printf("Adresse:              %s",chaine);
                        fgets(chaine,TAILLE_MAX,fichier);
                        printf("Heure:                %s",chaine);
                        printf("\n\n \td= supprimer l' evenement");
                    }
                printf("\n\tr = retour \n\te =creer un evenement\n\tm = modifier l'evenement");  // retourner sur le calendrier
            }
            fclose(fichier);
        }

        if(compare(next,"f")==0)
            fuseau_horaire(index_heure,index_minutes);

        if(compare(next,"d")==0){
            fichier=fopen("stock.txt","w");
            if (fichier != NULL){
                    fprintf(fichier,"%d%d%d.txt",index_jour+1,index_mois+1,index_annee);
                    fclose(fichier);
                    fichier=fopen("stock.txt","r");
                    fgets(chaine,TAILLE_MAX,fichier);
                    fclose(fichier);
            remove(chaine);
            printf("L'evenement a ete supprimer!\n\t r pour retour");

            }
        }
        if(compare(next,"m")==0){
            fichier=fopen("stock.txt","w");
            if (fichier != NULL){
                    fprintf(fichier,"%d%d%d.txt",index_jour+1,index_mois+1,index_annee);
                    fclose(fichier);
                    fichier=fopen("stock.txt","r");
                    fgets(chaine,TAILLE_MAX,fichier);
                    fclose(fichier);
                    fichier=fopen(chaine,"w+");

                    lire(evenement,TAILLE_MAX);
                    printf("\nNouvel evenement:\t");
                    lire(evenement,TAILLE_MAX);
                    fprintf(fichier,"%s\n",evenement);

                    lire(numero,TAILLE_MAX);
                    printf("\nNouveau numero:\t");
                    lire(numero,TAILLE_MAX);
                    fprintf(fichier,"%s\n",numero);

                    lire(adresse,TAILLE_MAX);
                    printf("\nNouvelle adresse:\t");
                    lire(adresse,TAILLE_MAX);
                    fprintf(fichier,"%s\n",adresse);

                    lire(Heure,TAILLE_MAX);
                    printf("\nNouvelle heure:\t");
                    lire(Heure,TAILLE_MAX);
                    fprintf(fichier,"%s\n",Heure);

                    fclose(fichier);
            printf("\n\tL'evenement a ete modifie!\n\t r pour retour\n\tm pour modifier");

            }
        }
        if (compare(next,"janvier")==0||compare(next,"fevrier")==0||compare(next,"mars")==0||compare(next,"avril")==0||compare(next,"mai")==0||compare(next,"juin")==0||compare(next,"juillet")==0||compare(next,"aout")==0||compare(next,"septembre")==0||compare(next,"octobre")==0||compare(next,"novembre")==0||compare(next,"decembre")==0){
            for(i=0;i<12;i++){                    // si l'utilisateur veux voir un mois précis
                if(compare(next,Mois_tableau[i]) == 0){
                    system("cls");
                    index_mois=i;
                    if(index_annee!=2000&&index_annee%4==0&&index_mois==1)
                        bisextile=1;
                    else bisextile=0;
                    printf("\n\t\t\t\tCalendrier %d\n\n",index_annee);
                    printf("\n\n\n\t\t\t\t\%s\n",Mois_tableau[index_mois]);
                    calendar(jour_tableau[i]+bisextile,index_mois,index_annee);
                }
            }
        }


        if(compare(next,"e")==0){        // permet d'aller dans evenement. s'il n'est pas créé, un fichier est crée
            FILE* fichier = NULL;
            fichier = fopen("stock.txt", "w");
            if (fichier != NULL){
                fprintf(fichier,"%d%d%d.txt",index_jour+1,index_mois+1,index_annee);
                fclose(fichier);
                fichier = fopen("stock.txt", "r");
                fgets(chaine,TAILLE_MAX,fichier);
                fclose(fichier);
                fichier = fopen(chaine, "w");

                lire(evenement,TAILLE_MAX);
                printf("\tQuel est l'evenement\t?");
                lire(evenement,TAILLE_MAX);
                fprintf(fichier,"%s\n",evenement);

                lire(numero,TAILLE_MAX);
                printf("Numero de telephone:\t");
                lire(numero,TAILLE_MAX);
                fprintf(fichier,"%s\n",numero);

                lire(adresse,TAILLE_MAX);
                printf("adresse:\t");
                lire(adresse,TAILLE_MAX);
                fprintf(fichier,"%s\n",adresse);

                lire(Heure,TAILLE_MAX);
                printf("Heure:\t");
                lire(Heure,TAILLE_MAX);
                fprintf(fichier,"%s\n",Heure);


                printf("\n evenement cree!");
                fclose(fichier);
            }
            }
        }


return 0;
}


