/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 3                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Chiffrement de messages                                         *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : MUNKH-ERDENE Dulguun                                         *
*                                                                             *
*  Nom-prénom2 : CORBILLE Iris                                                *
*                                                                             *                                                        *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : Chiffrement.h                                             *
*                                                                             *
******************************************************************************/

#ifndef CHIFFREMENT_H
#define CHIFFREMENT_H

#include <wchar.h>
#include <stdbool.h>

#define TAILLE_MAX 100

bool verifierTexte(wchar_t c[]);
void chiffrerCesar(wchar_t c[], int cle);
void dechiffrerCesar(wchar_t c[], int cle);
void chiffrerVigenere(wchar_t message[], wchar_t cle[]);
void dechiffrerVigenere(wchar_t message[], wchar_t cle[]);
void afficherMessage(wchar_t c[]);
void convertir(wchar_t text[]);

#endif