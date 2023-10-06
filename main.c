#include <stdio.h>
#include <stdlib.h>\
//Definition de nombre maximum des elements de tableau
#define Max 100


typedef struct t
{
  int Tab[Max];//declaration d'un tableau de type entier
  int NbElem;//declaration de nombre d'elements
}Matab,Tpile;

typedef struct Liste
{
    int val;//declaration entier
    //declaration d'un pointeur qui pointe sur l'element suivant
    struct Liste *svt;
    //declaration d'un pointeur qui pointe sur l'element precedant
     struct Liste *pred;
}LDC;//Liste doublement chainee

typedef struct f
{
    int Tab[Max];//declaration d'un tableau de type entier
    int id;//declaration d'un entier designant le debut
    int NbElem;//declaration d'un entier designant le nombre des elements
}Tfile;//definition d'une file par un tableau

typedef struct element
{
    int val;//declaration entier
    //declaration d'un pointeur qui pointe sur l'element suivant
    struct element *svt;
}Cellule,pt_Pile;//Definition du nom de la structure
typedef struct F
{
    //Un pointeur de type cellule indique le debut de la file
    Cellule *Debut;
    //Un pointeur de type cellule indique la fin de la file
    Cellule *Fin;
}pt_File;
///La fonction qui cree une liste sans inserer une information
LDC* CreerListe()
{
    LDC *L=(LDC*)malloc(sizeof(LDC));//allocation memoire
    if(!L)//L=NULL Tester si la memoire n'est pas allouee
    {
        printf("\nErreur de memoire");
        exit(-1);
    }
    return(LDC*)L;//on retourne l'adresse de la liste
}
///La fonction qui calcule la taile de la liste
int Taille_Liste(LDC *L)
{
    //declaration d'un pointeur de type LDC pour parcourir la liste
    LDC *courant;
    int taille=0;//declaration de variable taile et l'initialisation a 0
    //boucle for pour parcourir la liste
    for(courant=L;courant;courant=courant->svt)
        taille++;//incrementation de la taile
    return((int)taille);//0 si la liste est vide, et un entier sinon

}
///Fonction pour inserer une valeur a une position donnee
LDC* inserer_pos(LDC *L,int p,int val)
{
    int i;
    LDC *NE=CreerListe(),*courant;
    NE->val=val;
    if(!L)//tester si la liste est vide
    {
        printf("\nla liste est vide");
        exit(-1);
    }
    if((p<=0)||(Taille_Liste(L)+1<p))//tester si la position est invalide
    {
        printf("\nPosition invalide");
        exit(-1);
    }
    //insertion au debut
    if(p=1)
    {
      L->pred=NE;
      NE->svt=L;
      NE->pred=NULL;
      L=NE;
    }
    //insertion au milieu
    for(i=2,courant=L;i<=Taille_Liste(L);i++,courant=courant->svt)
        if(i==p)
        {
            courant->svt->pred=NE;
            courant->svt=NE;
        }
    //insertion a la fin
    if(p == (Taille_Liste(L)+1))
    {
        courant->suivant=NE;
        NE->pred=courant;
        NE->svt=(LDC*)NULL;
    }
   return ((LDC*)L);
}
//affichage de la liste
void afficher(LDC *L)
{
    LDC *courant;
    for(courant=L;courant;courant=courant->suivant)
        printf("(%d)->",courant->val);
    printf("\n");
}
LDC*trier_Liste(LDC *L)
{
    int Emax,aux;
    LDC *cour1,*cour2;
    for(courant=L;courant->suivant;courant=courant->suivant)
    )
}




int main()
{
    printf("Hello world!\n");
    return 0;
}
