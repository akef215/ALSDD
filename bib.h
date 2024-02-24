#ifndef BIB_H
#define BIB_H
#include <stdio.h>
#define MAX 100
// Prototypes
  int Permut(int *x, int *y);
  int DECAL1D(int *T, int *Tai, int p, int n);
  int TriInsert(int *T, int Tai);
  int ExtSV(int T[MAX], int a1, int a2, int SV[MAX], int *Tai);
  void SupprimerT(int *T, int *Tai, int V, int *flag);
  void SupprimerN(int *T, int *Tai, int V, int *flag);
  int Fusion(int *T1, int Tai1, int *T2, int Tai2,int *T, int *Tai);
  int indMin(int *T, int a1, int a2, int *ind);
  int TriSel(int *T, int Tai);
  int InsertT(int *T, int *Tai, int V);
  int InsertN(int *T, int *Tai, int V);
  int BinRech(int *T, int Tai, int V, int *ind);
  int SeqRech(int *T, int Tai, int V, int *ind);
  int ECRIRE1D(int *T, int Tai);
  int LECT1D(int *T, int *Tai);
  int max(int *T, int Tai, int *V);
  int min(int *T, int Tai, int *V);
  int Inter(int *T1, int Tai1, int *T2, int Tai2, int *T, int *Tai);
  int Diff(int *T1, int Tai1, int *T2, int Tai2, int *T, int *Tai);
  int InsertV(int *T, int *Tai, int V, int V1);
  int indMax(int *T, int a1, int a2, int *ind);
// Les fonctions
// Insere une valeure V1 apres une valeure donnée V si elle existe (la fonction retourne si la valeure V existe dans le vecteur ou pas)
int InsertV(int *T, int *Tai, int V, int V1) {
  int found, ind;
    found = SeqRech(T, (*Tai), V, &ind);
    if (found==0) {
      printf("\nLa valeur n\'existe pas\n");
    }
    else {
      DECAL1D(T, Tai, ind,1);
      T[ind+1] = V1;
    }
    return found; 
}
// Generer la difference de deux vecteurs
int Diff(int *T1, int Tai1, int *T2, int Tai2, int *T, int *Tai) {
  int found1, found2, found3, i, e, ind1, ind2, ind, k=0;
  for (i=0;i<Tai1;i++) {
      e = T1[i];
      found1 = SeqRech(T1, Tai1, e, &ind1);
      found2 = SeqRech(T2, Tai2, e, &ind2);
      found3 = SeqRech(T, k, e, &ind);
      if ((found1==1) && (found2==0) && (found3==0)) {
        T[k] = e;
        k++;
      }
    }
  (*Tai) = k;  
}
// Generer l'intersection de deux vecteurs
int Inter(int *T1, int Tai1, int *T2, int Tai2, int *T, int *Tai) {
  int found, found3, i, e, ind1, ind, a=Tai2, k=0;
  if (Tai1>Tai2) {
    a=Tai1;
  }
  for (i=0;i<a;i++) {
    e = T1[i];
    found = SeqRech(T2, Tai2, e, &ind1);
    found3 = SeqRech(T, k, e, &ind);
    if ((found==1) && (found3==0)) {
      T[k] = e;
      k++;
    }
  }
  (*Tai) = k;  
}
// Role : Renvoyer le manimum d'un vecteur
int min(int *T, int Tai, int *V) {
  int i;
  (*V) = T[0];
  for (i=1;i<Tai;i++) {
    if (T[i] <= (*V)) {
      (*V) = T[i];
    }
  }
}
// Role : Renvoyer le maximum d'un vecteur
int max(int *T, int Tai, int *V) {
  int i;
  (*V) = T[0];
  for (i=1;i<Tai;i++) {
    if (T[i] >= (*V)) {
      (*V) = T[i];
    }
  }
}
// Role : Permute les valeurs de deux variables
int Permut(int *x, int *y) {
  int Tmp;
  Tmp = *x;
  *x = *y;
  *y = Tmp;
}
// Role : Decaler un vecteur de n positions a partir de l'indice p
int DECAL1D(int *T, int *Tai, int p, int n) {
  int i, j;
  for (j=0; j<n; j++) {
    for (i=p+1; i<(*Tai); i++) {
      Permut(&T[i], &T[(*Tai)]);
    }
    (*Tai) = (*Tai)+1;
  }
}
// Tri par insertion
int TriInsert(int *T, int Tai) {
  int i, j, stop;
  for (i=1; i<Tai; i++) {
    j=i-1;
    stop = 0;
    while ((j>=0) && (stop == 0)) {
      if (T[j]<=T[j+1]) {
        stop = 1;
      }
      else {
        Permut(&T[j],&T[j+1]);
        j--;
      }
    }
  }
}
// Role : Extraire un sous vecteur compris entre les deux indices a1 et a2
int ExtSV(int T[MAX], int a1, int a2, int SV[MAX], int *Tai) {
  int i;
  (*Tai) = a2-a1+1;
  for (i = a1; i <= a2; i++)
  {
    SV[i-a1] = T[i];
  }
}
// Supprimer un element V d'un vecteur trié (s'il existe)
void SupprimerT(int *T, int *Tai, int V, int *flag) {
  int i, ind=-1;
  for (i=0;i<(*Tai);i++) {
    if (T[i] == V) {
      ind = i;
    }
  }
  if (ind != -1) {
    for (i=ind;i<(*Tai);i++) {
    Permut(&T[i], &T[i+1]);
    }
    (*Tai)--;
    (*flag) = 1; //pour dire que l'element V se trouve bel et bien dans le vecteur
  }
  else {
    printf("l\'element ne se trouve pas dans le vecteur !!");
    (*flag) = 0; //pour dire que l'element ne se trouve pas dedans
  }
}
// Supprimer un element V d'un vecteur non trié (s'il existe)
void SupprimerN(int *T, int *Tai, int V, int *flag) {
  int i, ind=-1;
  for (i=0;i<(*Tai);i++) {
    if (T[i] == V) {
      ind = i;
    }
  }
  if (ind != -1) {
    Permut(&T[(*Tai)-1], &T[ind]);
    (*Tai)--;
    (*flag) = 1; //pour dire que l'element V se trouve bel et bien dans le vecteur
  }
  else {
    printf("l\'element ne se trouve pas dans le vecteur !!");
    (*flag) = 0; //pour dire que l'element ne se trouve pas dedans
  }
}
// Role : Obtenir un vecteur trié a partir de deux vecteurs triés
int Fusion(int *T1, int Tai1, int *T2, int Tai2,int *T, int *Tai) {
  int i=0,j=0,k=0, a;
  while (i<Tai1 && j<Tai2) {
    if (T1[i]<=T2[j]) {
      T[k] = T1[i];
      i++;
    }
    else {
      T[k] = T2[j];
      j++;
    }
    k++;
  }
  while (j<Tai2) {
      T[k] = T2[j];
      j++;
      k++;
  }
  while (i<Tai1) {
      T[k] = T1[i];
      i++;
      k++;
  }
  (*Tai) = k;
}
// Role : Donner l'indice du miaximum d'un intervalle d'un vecteur
int indMax(int *T, int a1, int a2, int *ind) {
  int i, max=T[a1];
  (*ind) = 0;
  for (i=a1; i<a2 ;i++) {
    if (max<=T[i]) {
      max = T[i];
      (*ind) = i;
    }
  }
  return (*ind);
}
// Role : Donner l'indice du minimum d'un intervalle d'un vecteur
int indMin(int *T, int a1, int a2, int *ind) {
  int i, min=T[a1];
  (*ind) = 0;
  for (i=a1; i<a2 ;i++) {
    if (T[i]<=min) {
      min = T[i];
      (*ind) = i;
    }
  }
  return (*ind);
}
// Role : Tri par selection
int TriSel(int *T, int Tai) {
  int i, ind;
  for (i=0; i<Tai ;i++) {
    indMin(T, i, Tai, &ind);
    Permut(&T[ind], &T[i]);
  }
}
// Role : Inserer un element dans un vecteur trié
int InsertT(int *T, int *Tai, int V) {
  int i=0;
  if ((V>=T[0]) && (V<T[(*Tai)-1])) {
    while (i<(*Tai)) {
      if (T[i] >= V) {
        DECAL1D(T, Tai, i-1, 1);
        T[i] = V;
        break;     
      }
      i++;
    }
  }
  if (V<T[0]) {
    DECAL1D(T, Tai, 0, 1);
    T[1] = V;
    Permut(&T[0], &T[1]);
  }
  if (V > T[(*Tai)-1]) {
    DECAL1D(T, Tai, (*Tai)-1, 1);
    T[(*Tai)-1] = V;
  }
}
// Role : Inserer un element dans un vecteur non trié
int InsertN(int *T, int *Tai, int V) {
  T[(*Tai)]=V;
  (*Tai)++;
}
// Role : Rechercher une valeur dans un vecteur trié et donner son indice si elle y est
int BinRech(int *T, int Tai, int V, int *ind) {
  int i=0, found=0, down=0, up=Tai, mid;
  while ((found == 0) && (down<=up))
  {
    mid = (up+down)/2;
    if (T[mid] == V) {
      found = 1;
      (*ind) = mid;
      break;
    }
    if (V < T[mid]) {
      up = mid-1;
    }
    if (V > T[mid]) {
      down = mid+1;
    }
  }
  return found;
}
// Role : Rechercher une valeur dans un vecteur qui n'est pas trié et donner son indice si elle y est
int SeqRech(int *T, int Tai, int V, int *ind) {
  int i=0, found=0;
  while (i<Tai)
  {
    if (*(T+i)==V)
    {
      found = 1;
      (*ind) = i;
      break;
    }
    i++;
  }
  return found;
}
// Afficher un vecteur
int ECRIRE1D(int *T, int Tai) {
  int i;
  for (i=0; i<Tai; i++) 
  {
    printf(" | %d | ", T[i]);
  }
}
// Lire un vecteur
int LECT1D(int *T, int *Tai) {
  int i;
  printf("Entrer la taille du vecteur : ");
  scanf("%d", Tai);
  for (i=0; i<(*Tai); i++)
  {
    printf("T[%d] = ", i);
    scanf("%d", &T[i]);
  }
}
#endif
