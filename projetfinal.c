#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct date
{int annee ;
int mois;
int jour;
}d_date;
typedef struct voyage
{char nom ;
d_date date;
char desc;
}v_voy;
typedef struct Noeud Noeud;
struct Noeud
{
    v_voy val;
    struct Noeud *suiv;
};
typedef Noeud* liste;
liste supprimer(liste k,char nom){
	liste p,l;
	l=k;
	if(l->val.nom==nom)
	l=l->suiv;
	else{
		while(l->suiv->val.nom!=nom){
			l=l->suiv;
		}
		p=l->suiv;
		l->suiv=p->suiv;
		free(p);
	}

}
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void gotoxy(int x,int y){

	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void Color(int couleurDuTexte,int couleurDeFond);
int rectangle(int c){
    int i=1,j;
    while(i<3
){
            if(i==1){
            for(int j=0;j<c;j++){

            printf("*");}i++;}
             else if (i==2){printf("\n*              AGENCE DE VOYAGE             *\n*********************************************");i++;}
             else if (i==3){
                    printf("***************************************************");i++;}

    }

}
void modifier(liste k,char nom){
	liste l;
	char nvnom,desc ;
	int r;
	d_date d;
	l=k;
while(l!= NULL){

if (l->val.nom==nom){
	printf("1:changer nom,2:changer date;3:changer description");
do{

scanf("%i",&r);
}while((r<=3)&&(r>=1));
if(r==1){
	scanf("%s",&nvnom);
	l->val.nom==nvnom;
}
if(r==2){
	scanf("%i%i%i",&d.annee,&d.mois,&d.jour);
	l->val.date=d;
}
if(r==3){
	scanf("%s",&desc);
	l->val.desc==desc;
}
	break;
}

			l=l->suiv;
		}
}void modifier(liste k,char nom);



int smaller(d_date a, d_date b){
  if ( a.annee<b.annee ) return 1; // compare years
  if (a.annee ==b.annee &&  a.mois< b.mois) return 1; // compare months - but make sure years are equal
  if ( a.annee== b.annee&& a.mois == b.mois && a.jour < b.jour) return 1; // compare days but make sure years and months are equal
  return 0;}
  void recherche1(liste l){
char nom;
d_date d1,d2,d3,d4,d5;
liste aux;
char v1;
aux=l;
    scanf("%i",&d1.jour);
    scanf("%i",&d1.mois);
    scanf("%i",&d1.annee);
    scanf("%i",&d3.jour);
    scanf("%i",&d3.mois);
    scanf("%i",&d3.annee);
while(aux!=NULL){


    d2.jour=(aux->val).date.jour;
       d2.mois=aux->val.date.mois;
    d2.annee=aux->val.date.annee;

    if ((smaller(d1,d2)==1)&&(smaller(d2,d3)==1)){
       printf("%s%i%i%i%s",aux->val.nom,":",d2.jour,"/",d2.mois,"/",d2.annee,":",aux->val.desc);

        }

            aux=aux->suiv;


}}int smaller(d_date a, d_date b);
void recherche1(liste l);
void recherche2(liste l){
char nom;
d_date d4,d5;
liste aux;
aux=l;
scanf("%i",&d4.jour);
    scanf("%i",&d4.mois);
    scanf("%i",&d4.annee);

while(aux!=NULL){


    d5=(aux->val).date;
    if((d4.annee=d5.annee)&&(d4.mois=d5.mois)&&(d4.jour=d5.jour)){
       printf("%s%i%i%i%s",aux->val.nom,":",d5.jour,"/",d5.mois,"/",d5.annee,":",aux->val.desc);


            }
             aux=aux->suiv;
}




}void recherche2(liste l);


void ajout( liste l ){
    v_voy e;
    printf("saisir le nom du voyage : ");
    scanf("%s",&e.nom);
    printf("saisir la date du voyage : ");
    scanf("%i",&e.date.jour);
    scanf("%i",&e.date.mois);
    scanf("%i",&e.date.annee);
    printf("saisir la description du voyage : ");
    scanf("%s",&e.desc);
    liste p,Q;
    p = malloc(sizeof(liste));
    p->suiv=NULL;
    p->val=e;
    Q=l;
    while(Q->suiv){
        Q=Q->suiv;
    }
    Q->suiv = p;

}void ajout( liste l );
void afficherdesc( liste L){
liste q;
q=L;
char nom;
printf("saisir le nom du voyage : ");
    scanf("%s",&nom);
while (q){
  if(q->val.nom==nom){printf("%s",q->val.desc);
  break;}
q=q->suiv;
    }}void afficherdesc( liste L);



    int main(int argc, char *argv[])
{int r;
liste l;

l = malloc(sizeof(liste));
char nom,nom1,nom2;
Color(4,8);

system("cls");
	system("color 81");
rectangle(45);
 Color(0,8);
   printf("\n1:ajouter un voyage\n");
printf("2:afficher la description d'un voyage\n");
printf("3:supprimer un voyage\n");
printf("4:modifier un voyage\n");
printf("5:rechercher un voyage entre deux dates\n");
printf("6:rechercher un voyage selon une date\n");
printf("0:fermer le programme\n");
printf("taper le num de l'option : ");
    scanf("%i",&r);

while(r!=0){

    if(r==0){break;}
    else{
    switch(r){

    	case 1:	{

		ajout(l);
		break;}
		case 2:{ scanf("%s",&nom);
		afficherdesc(l);
			break;
		}
    	case 3:{scanf("%s",&nom1);
	    supprimer(l,nom1);
			break;
		}
		case 4:{scanf("%s",&nom2);
	    modifier(l,nom2);
			break;
		}
    	case 5:{recherche1(l);
			break;
		}
		case 6:{		recherche2(l);

			break;
		}}



	}    printf("taper le num de l'option : ");
    scanf("%i",&r);
}




}
