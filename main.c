#include <stdio.h>
#include <stdlib.h>\
//Definition de nombre maximum des elements de tableau
#define Max 100


typedef struct t
{
  int Tab[Max];//declaration d'un tableau de type entier
  int NbElem;//declaration de nombre d'elements
}Tliste,Tpile;

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
    int taille;
}pt_file;
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
LDC* inserer_pos(LDC *L,int p,int elem)
{
    int i;
    LDC *NE=CreerListe(),*courant;
    NE->val=elem;//Remplire le champs val
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
    if(p==1)
    {
      L->pred=NE;
      NE->svt=L;
      NE->pred=NULL;
      L=NE;
      return ((LDC*)L);
    }
    //insertion au milieu
     //determination de la position et l'insertion
    for(i=2,courant=L;i<=Taille_Liste(L);i++,courant=courant->svt)
        if(i==p)
        {
            //courant sera a la position (p-1) donc on insere apres courant
            courant->svt->pred=NE;
            courant->svt=NE;
        }//courant pointe sur le dernier si on a pas encore atteindre la position

    //insertion a la fin
     if(p == (Taille_Liste(L)+1))//la position est apres le dernier element
     {
        courant->svt=NE;
        NE->pred=courant;
        NE->svt=(LDC*)NULL;
     }
      return ((LDC*)L);
}
///affichage de la liste
void afficherListe(LDC *L)
{
    LDC *courant;
    for(courant=L;courant;courant=courant->svt)
        printf("(%d)->",courant->val);
    printf("\n");
}
///suppression d'un element dans la liste
LDC* supprimer(LDC *L,int esup)
{
    LDC *courant=L,*tmp;
    while(courant)
    {
        if(courant->val!=esup)
            courant=courant->svt;//on parcours la liste
        else
        {   //l'element est trouvee
            tmp=courant;
            //suppression au debut
            if(courant==L)
            {
               courant->svt->pred=NULL;
               L=courant->svt;
               courant=courant->svt;
               free(tmp);
            }
            else
            {
                courant->pred->svt=courant->svt;//au milieu de la liste
                if(courant->svt)
                {
                  courant->svt->pred=courant->pred;
                  courant=courant->svt;
                }
                free(tmp);
                }
        }
    }

    return ((LDC*)L);
}
///Fonction pour detruire la liste
void detruire_liste(LDC *L)
{
    LDC *tmp=L;
    while(tmp)
    {
       L=L->svt;//deplacer la tete de la liste avant de supprimer
       free(tmp);
       tmp=tmp->svt;//incrementation de tmp
    }
}
/// Fonction pour trier une liste doublement chaînée par sélection
LDC* Tri_liste(LDC* L)
{
    LDC *courant1, *courant2, *min;
    int aux;
    // Vérifier si la liste est vide
    if(!L)
    {
        printf("\nLa liste est vide");
        exit(-1);
    }
    // Parcourir la liste avec courant1
    for(courant1 = L; courant1->svt; courant1 = courant1->svt)
    {
        min = courant1;
        // Parcourir la liste à partir de courant2 pour trouver le minimum
        for(courant2 = courant1->svt; courant2; courant2 = courant2->svt)
            if (min->val > courant2->val)
                min = courant2;
        // Échanger la valeur de courant1 avec le minimum si nécessaire
        if (min != courant1)
        {
            aux = courant1->val;
            courant1->val = min->val;
            min->val = aux;
        }
    }
    return ((LDC*)L);
}\

//manipulation de la file a l'aide de tableau
// Fonction pour initialiser une file
int initi_Tfile(Tfile *file)
{
    if(!file)
    {
        printf("\nLa liste est vide");
        return ((int)0);
    }
    file->id =0;      // L'indice du premier élément est initialisé à 0
    file->NbElem =0;  // Le nombre d'éléments est initialisé à 0
    return((int)1);
}

// Fonction pour vérifier si la file est vide
int estvide_Tfile(Tfile file)
{
    return ((int)file.NbElem == 0);
}

// Fonction pour vérifier si la file est pleine
int estsature_Tfile(Tfile file)
{
    return ((int)file.NbElem == Max);
}

// Fonction pour ajouter un élément à la file (enfiler)
int enfiler_Tfile(Tfile* file, int ne)
{
      if(!file)
    {
       printf("\nErreur de memoire");
       return((int)(-1));
    }
    if(estsature_Tfile(*file))
        {
            printf("\nErreur, file pleine");
            return ((int)0);
        }
    int indice;
    //Calcul de l'indice où ajouter l'élément
    indice = (file->id + file->NbElem)%Max;
    file->Tab[indice] =ne;//insertion de la valeur
    file->NbElem++;//incrementation de nombre d'element
    return ((int)1);
}

// Fonction pour retirer un élément de la file (défiler)
int defiler_Tfile(Tfile *file, int *rec)
{
    if(!file)
    {
       printf("\nErreur de memoire");
       return((int)0);
    }
    //Récupération de l'élément au début de la file
    *rec =file->Tab[file->id];
    file->id++;//deplacer la tete de la file vers l'element suivant
    //Si on atteint la fin du tableau, revenir au début
    if (file->id ==Max) file->id = 0;
    file->NbElem--;//decrementation de NbElem
    return((int)1);
}

// Fonction pour afficher le contenu de la file
void afficher_Tfile(Tfile file)
{
    int i, indice;
    if(estvide_Tfile(file))
    {
      printf("\nLa file est vide");
      exit(-1);
    }
    if(estsature_Tfile(file))
        printf("\nLa file est pleine");
    printf("\nid = %d, NbElem = %d\n", file.id, file.NbElem);
    for (i=0; i<file.NbElem; i++)
    {
        //Calcul de l'indice de chaque élément a afficher
        indice =(file.id+i)% Max;
        printf("file[%d]=%d  ",i,file.Tab[indice]);
    }
    printf("\n");
}

///manipulation des files a l'aide des pointeurs
///allouer l'espace memoire pour une file
pt_file * Allouerfile()
{
   pt_file *f=(pt_file*)malloc(sizeof(pt_file));
   if(!f)//f==NULL
   {
      printf("\nErreur de memoire");
      exit(-1);//l'allocation n'est pas faite
   }
   return((pt_file*)f);
}

///initialisation de la file
int init_Pfile(pt_file *f)
{
   if(!f)
   {
      printf("\nErreur de memoire");
      return((int)0);
   }
   f->Debut=f->Fin=(Cellule*)NULL;
   f->taille=0;
   return((int)1);
}

///Tester si la file est vide
int estvide_Pfile(pt_file f)
{
    return((int)(f.taille==0));
}

///Fonction pour enfiler un element dans la file
void enfiler_Pfile(pt_file *F, int elem)
{
   //allocation memoire et remplissage du champs val
   Cellule *q=(Cellule*)malloc(sizeof(Cellule));
   if(!q) exit(-1);
   q->val=elem;
   if(!F)
   {
       printf("\nErruer de memoire");
       exit(-1);
   }
   if(estvide_Pfile(*F))
   {
     //on aura un seul element donc il sera pointé par les deux
     F->Fin=q;
     F->Debut=q;
   }
   else
   {
      F->Fin->svt=q;//insertion a la fin
      F->Fin=q;//mise a jour de dernier element
   }
   F->taille++;
}
///Fonction pour defiler un element dans la file
int defiler_Pfile(pt_file *F)
{
    if(!F)
    {
       printf("\nErruer de memoire");
       return((int)(-1));
    }
    if(estvide_Pfile(*F)) return((int)0);
    Cellule *esup=F->Debut;//esup pointe sur le debut
    if(F->Debut==F->Fin)//si on a un seule element
    {
       F->Debut=NULL;
       F->Fin=NULL;
    }
     else//au moins 2 elements
        F->Debut=F->Debut->svt;
    free(esup);//suppression...
    F->taille--;
    return((int)1);
}
///Fonction pour afficher la file
void afficher_Pfile(pt_file F)
{
    int t=F.taille,i;//declaration d'un variable qui presente la taile de la file
    if(estvide_Pfile(F))
    {
        printf("\nLfile est vide");
        exit(-1);
    }
    //une boucle pour ne pas depasser la taille
    for(i=1;i<=t;i++)
    {
       printf("(%d)->",F.Debut->val);//affichage du contemu de debut de la file
       int rec=F.Debut->val;//recuperation de la valeur car on va defiler puis enfiler
       if(defiler_Pfile(&F))//defilement et enfilement sont consecutifs
          enfiler_Pfile(&F,rec);
    }
    printf("\n");
}
///Fonction pour vider la file
void vider_Pfile(pt_file *F)
{
   if(!F)
    {
       printf("\nErruer de memoire");
       exit(-1);
    }
    //la boucle va s'arreter si la file est vide
    /*defiler_Pfile(pt_file *F) return -1:Erreur
                                        0:file vide
                                        1:defilement reussit*/
    while(defiler_Pfile(F));
}






int main()
{

    return 0;
}
