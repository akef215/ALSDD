#ifndef LISTE_H
#define LISTE_H
#include <stdio.h>
#include <stdlib.h>
// Structure
struct maillon{
  int val;
  struct maillon *adr;
};
struct dmaillon{
  int val;
  struct dmaillon *left;
  struct dmaillon *right;
};
// Prototypes :
  void Allocate(struct maillon **p);
  void Free(struct maillon *p);
  void Ass_val(struct maillon *p, int v);
  void Ass_adr(struct maillon *p, struct maillon *q);
  int Value(struct maillon p);
  struct maillon* Next(struct maillon p);
  void MakeList(struct maillon **head, int n);
  void DisplayList(struct maillon *head, int n); 
  struct maillon * Concat(struct maillon **head1, struct maillon *head2);
  int Length(struct maillon *head); 
  int MostOccured(struct maillon *head);
  int frequence(struct maillon *head, int V);
  struct maillon * AccessV(struct maillon *head, int v, struct maillon **p);
  struct maillon * AccessP(struct maillon *head, int pos, struct maillon **p);
// Les fonctions
// Role : Acceder a un element d'une liste avec sa position
struct maillon * AccessP(struct maillon *head, int pos, struct maillon **p) {
  int i=1;
  (*p) = head;
  while (((*p)!=NULL) && (i<pos)) {
    (*p) = Next((*(*p)));
    i++;
  }
  return (*p);
}
// Role : Acceder a un element d'une liste avec sa valeure
struct maillon * AccessV(struct maillon *head, int v, struct maillon **p) {
  (*p) = head;
  while (((*p)!=NULL) && (Value((*(*p)))!=v)) {
    (*p) = Next((*(*p)));
  }
  return (*p);
}
// Role : Calcule la frequence d'un entier dans la liste
int frequence(struct maillon *head, int V) {
  struct maillon *p;
  int cpt=0;
  p = head;
  while (p!=NULL) {
    if (Value((*p))==V) {
      cpt++;
    } 
    p = Next((*p));
  }
  return cpt;
}
// Role : Renvoie la valeur qui a le plus grand nombre d'occurence
int MostOccured(struct maillon *head) {
  struct maillon *p;
  int val, j=0, cpt, max;
  max = 0; //represente la frequence maximale
  p = head;
  while (p!=NULL) {
    val = Value((*p));
    if (frequence(head, val) > max) {
      max = frequence(head, val);
      j = val; //represente la valeur qui a le plus grand nombre d'occurence
    }
    p = Next((*p)); 
  }
  return j;
  // NB : Dans le cas d'une liste vide la valeur 0 sera renvoyé faut afficher la frequence aussi
}
// Role : Donner le nombre de maillon d'une liste
int Length(struct maillon *head) {
  struct maillon *p;
  int cpt;
  cpt = 0;
  p = head;
  while (p != NULL) {
    cpt++;
    p = Next(*p);
  }
  return cpt;
}
// Role : Concatiner deux listes
struct maillon * Concat(struct maillon **head1, struct maillon *head2) {
  struct maillon *p;
  if ((*head1)==NULL) (*head1) = head2;
  else {
    p = (*head1);
    while (Next((*p))!=NULL) {
      p = Next((*p));
    }
    Ass_adr(p, head2);
  }
  return (*head1);
}
// Role : Allouer un espace memoire pour le maillon
void Allocate(struct maillon **p) {
  (*p) = malloc(sizeof(struct maillon));
}
// Role : Desallouer l'espace memoire occupé par le maillon
void Free(struct maillon *p) {
  free(p);
}
// Role : Remplir le champ valeur du maillon
void Ass_val(struct maillon *p, int v) {
  (*p).val = v;
}
// Role : Lier le maillon p avec le maillon q
void Ass_adr(struct maillon *p, struct maillon *q) {
  (*p).adr = q;
}
// Role : Donner la valeur du maillon
int Value(struct maillon p) {
  return p.val;
}
// Role : Donner le pointeur du maillon
struct maillon* Next(struct maillon p) {
  return p.adr;
}
// Role : Creer une liste de n elements
void MakeList(struct maillon **head, int n) {
  struct maillon *p, *q;
  int v, i;
  if (n>=1) {
    Allocate(&p);
    (*head) = p;
    printf("Veuillez entrer la valeur du premier maillon : ");
    scanf("%d", &v);
    Ass_val(p, v);
    Ass_adr(p, NULL);
    for (i=2;i<=n;i++) {
      Allocate(&q);
      Ass_adr(p, q);
      printf("Veuillez entrer la valeur du %d-ieme maillon : ", i);
      scanf("%d", &v);
      Ass_val(q, v);
      Ass_adr(q, NULL);
      p = q;
    }
  }
  else {
    (*head) = NULL;
  }
}
// Role : Afficher les premiers n elements d'une liste
void DisplayList(struct maillon *head, int n) {
  struct maillon *p;
  int i;
  p = head;
  for (i=0;i<n;i++) {
    printf("L\'element d\'ordre %d est %d\n", i+1, p->val);
    p = Next((*p));
  }
}
#endif
// Fin de la bibliotheque
