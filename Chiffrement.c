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
*  Nom du fichier : Chiffrement.c                                             *
*                                                                             *
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

#define TAILLE_MAX 100

bool verifierTexte(wchar_t c[]);
void chiffrerCesar(wchar_t c[], int cle);
void dechiffrerCesar(wchar_t c[], int cle);
void chiffrerVigenere(wchar_t message[], wchar_t cle[]);
void dechiffrerVigenere(wchar_t message[], wchar_t cle[]);
void afficherMessage(wchar_t c[]);
void convertir(wchar_t text[]);


int main() {
    setlocale(LC_ALL, "");
    wchar_t c[TAILLE_MAX];
    int cleCesar;
    wchar_t cleVigenere[TAILLE_MAX];
    wchar_t algoChoisi[TAILLE_MAX];

    wprintf(L"Entrez votre message :\n");
    fgetws(c, TAILLE_MAX, stdin);
    c[wcscspn(c, L"\n")] = 0;
    convertir(c); 

    if (verifierTexte(c)) {
        wprintf(L"Choisissez l'algorithme de cryptage : ecrivez \"Cesar\" ou \"Vigenere\" :");
        fgetws(algoChoisi, TAILLE_MAX, stdin);
        algoChoisi[wcscspn(algoChoisi, L"\n")] = 0;
        if (wcscmp(algoChoisi, L"Cesar") == 0 || wcscmp(algoChoisi, L"cesar") == 0 || wcscmp(algoChoisi, L"César") == 0 || wcscmp(algoChoisi, L"césar") == 0)  { 
            wprintf(L"Entrez maintenant la cle de cryptage :\n");
            wscanf(L"%d", &cleCesar);
            while (getwchar() != L'\n');

            chiffrerCesar(c,cleCesar); 
            wprintf(L"texte chiffre: ");
            afficherMessage(c);

            dechiffrerCesar(c,cleCesar);
            wprintf(L"texte dechiffre: ");
            afficherMessage(c);

        } else if (wcscmp(algoChoisi, L"Vigenere") == 0 || wcscmp(algoChoisi, L"vigenere") == 0 || wcscmp(algoChoisi, L"Vigenère") == 0 || wcscmp(algoChoisi, L"vigenère") == 0) {
            wprintf(L"Entrez maintenant la clé de cryptage :\n");
            fgetws(cleVigenere, 100, stdin);
            cleVigenere[wcscspn(cleVigenere, L"\n")] = 0;
            convertir(cleVigenere);

            chiffrerVigenere(c,cleVigenere); 
            wprintf(L"texte chiffre: ");
            afficherMessage(c);

            dechiffrerVigenere(c,cleVigenere);
            wprintf(L"texte dechiffre: ");
            afficherMessage(c);

        } else {
            wprintf(L"La methode de cryptage est invalide.");
        }
    }
}

bool verifierTexte(wchar_t c[]) {
    for (int i = 0; c[i] != L'\0'; i++) {
        if (!((c[i] >= L'A' && c[i] <= L'Z') || (c[i] >= L'a' && c[i] <= L'z') || c[i] == L' ')) {
            wprintf(L"Le message est invalide.\n");
            return false;
        }
    }
    return true;
}

void convertir(wchar_t text[] ) {
    wchar_t tabAccents[]   = L"ÀÁÂÄàáâäÈÉÊËèéêëÌÍÎÏìíîïÒÓÔÖòóôöÙÚÛÜùúûüÝŸýÿÇç";
    wchar_t tabconvertir[] = L"AAAAaaaaEEEEeeeeIIIIiiiiOOOOooooUUUUuuuuYYyyCc";

    for (int i = 0; i < wcslen(text); i++ ) {
        int a = 0;
        for (int j = 0; j < wcslen(tabAccents) && a == 0; j++){
            if (text[i] == tabAccents[j]){
                text[i] = tabconvertir[j];
                a = 1;
            } 
        }
    }
}

void chiffrerCesar(wchar_t c[], int cle) {
    wchar_t Maj[] = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    wchar_t Min[] = L"abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < wcslen(c); i++) {
        int a = 0;
        for (int j = 0; j < 26 && a == 0; j++){
            if (c[i] == Maj[j]){
                c[i] = Maj[(j + cle + 26) % 26];
                a = 1;
            } else if(c[i]== Min[j]) {
                c[i] = Min[(j + cle + 26) % 26];
                a = 1;
            }
        }
    }
}

void dechiffrerCesar(wchar_t c[], int cle) {
    wchar_t Maj[] = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    wchar_t Min[] = L"abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < wcslen(c); i++) {
        int a = 0;
        for(int j=0; j < 26 && a == 0; j++) {
            if(c[i] == Maj[j]) {
                c[i] = Maj[(j - cle + 26) % 26];
                a = 1;
            }
            else if(c[i]==Min[j]){
                c[i] = Min[(j - cle + 26) % 26];
                a = 1;
            }
        }
    }
}

void chiffrerVigenere(wchar_t message[], wchar_t cle[]) {
    wchar_t maj[] = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    wchar_t min[] = L"abcdefghijklmnopqrstuvwxyz";
    int tabMessage[TAILLE_MAX];
    int tabCle[TAILLE_MAX];
    int tabRes[TAILLE_MAX];
    int lenMessage = wcslen(message);
    int lenCle = wcslen(cle);

    for(int i = 0; i < lenMessage; i++) {
        for (int j=0; j< wcslen(maj); j++) {
            if (message[i] == maj[j] || message[i] == min[j]) {
                tabMessage[i] = j;
            } 
        }
    }

    for (int i = 0; i < lenCle; i++) {
        for (int j=0; j<wcslen(maj); j++) {
            if (cle[i] == maj[j] || cle[i] == min[j]) {
                tabCle[i] = j;
            }
        }

    } 

    if (lenMessage > lenCle) {
        for (int i= lenCle; i < lenMessage; i++) {
            tabCle[i] = tabCle[i-wcslen(cle)];

        }
    }

    for (int i=0; i< lenMessage; i++) {
        tabRes[i] = (tabMessage[i] + tabCle[i]) % 26;
    }

    for (int i=0; i< lenMessage; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = maj[tabRes[i]];
        } else if (message[i] >= 'a' && message[i] <= 'z')  {
            message[i] = min[tabRes[i]];
        }
    }
}

void dechiffrerVigenere(wchar_t messageCodé[], wchar_t cle[]) {
    wchar_t maj[] = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    wchar_t min[] = L"abcdefghijklmnopqrstuvwxyz";
    int tabMessage[TAILLE_MAX];
    int tabCle[TAILLE_MAX];
    int tabRes[TAILLE_MAX];

    int lenMessage = wcslen(messageCodé);
    int lenCle = wcslen(cle);

    for(int i = 0; i < lenMessage; i++) {
        for (int j=0; j< wcslen(maj); j++) {
            if (messageCodé[i] == maj[j] || messageCodé[i] == min[j]) {
                tabMessage[i] = j;
            } 
        }
    }

    for (int i = 0; i < lenCle; i++) {
        for (int j=0; j<wcslen(maj); j++) {
            if (cle[i] == maj[j] || cle[i] == min[j]) {
                tabCle[i] = j;
            }
        }

    } 

    if (lenMessage > lenCle) {
        for (int i= lenCle; i < lenMessage; i++) {
            tabCle[i] = tabCle[i-wcslen(cle)];

        }
    }

    for (int i=0; i< lenMessage; i++) {
        tabRes[i] = (tabMessage[i] - tabCle[i] + 26) % 26;
    }

    for (int i=0; i< lenMessage; i++) {
        if (messageCodé[i] >= 'A' && messageCodé[i] <= 'Z') {
            messageCodé[i] = maj[tabRes[i]];
        } else if (messageCodé[i] >= 'a' && messageCodé[i] <= 'z')  {
            messageCodé[i] = min[tabRes[i]];
        }
    }
}

void afficherMessage(wchar_t c[]) {
    wprintf(L"%ls\n", c);
}
