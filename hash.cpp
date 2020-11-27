#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int hash1::HASH(string cle)
{
    int index;
    int hashage = 0;

    cout << cle.length();
    //for sur le nombre de char de cle
    for(int i = 0; i< cle.length(); i++)
    {
        // pour chaque char je reccupere le code ascii et je l'ajoute a la somme
        hashage = hashage + (int)cle[i];
        cout << cle[i] << endl;
        cout << hashage << endl;
    }

    // modulo de la sommme des codes ascii sur tailleTableau

    index = hashage % tailleTableau;

    //index = 0;
    cout << index << endl;

    return index;
}

hash1::hash1(){
     for (int i = 0; i<tailleTableau; i++){
        HashTable[i] = new item;
        HashTable[i]->nom = "vide";
        HashTable[i]->tel = "vide";
        HashTable[i]->next = NULL;
     }
}
void hash1::ajouterItem(string nom, string tel)
{
    int index = HASH(nom);
    item hashItem;
    hashItem.nom = nom;
    hashItem.tel = tel;
    hashItem.next = NULL;
    if (HashTable[index]->nom == "vide")
    {
        HashTable[index] = hashItem;
    }
    else
    {
        item *next = HashTable[index]->next;
        while (next != NULL)
        {
            next = next->next;
        }
        next = &hashItem;
    }
}
void hash1::afficherItems()
{
    for (int index = 0; index < tailleTableau; index++)
    {
        afficherItemsDansIndex(index);
    }
};

void hash1::supprimerItem(string nom)
{
    int index = HASH(nom);
    if (HashTable[index]->nom == "vide")
    {
        return;
    }
    item *next = HashTable[index]->next;
    while (next != NULL)
    {   
        if (strcmp(next->nom, nom) == 0)
        {
            next= &(next->next)
        }
        next = next->next;
    }
}


void hash1::chercherItem(string nom)
{
    int index = HASH(nom);
    if (HashTable[index]->nom == "vide")
    {
        printf("Non trouvée!\n");
        return;
    }
    item *next = HashTable[index]->next;
    while (next != NULL)
    {   
        if (strcmp(next->nom, nom) == 0)
        {
            printf("Trouvée!\n");
            return;
        }
        next = next->next;
    }
    printf("Non trouvée!\n");
}
