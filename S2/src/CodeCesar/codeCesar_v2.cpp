/* codeCesar - chiffre un texte selon une variante du code de César                                 *
 *   données : un texte, enregistré dans un fichier dont le nom est passé à la ligne de commande    *
 *             un entier <= 26, decall, le décalage appliqué sur les lettres de l'alphabet latin    *
 *             standard                                                                             *
 *             un entier <= 10 , decald, le décalage appliqué sur les chiffres                      *
 *   résultat : le texte chiffré de la manière suivante                                             *
 *              le chiffrement des lettres de l'alphabet latin standard se fait par un décalage     *
 *              droite de taille decall,                                                            *
 *              celui des chiffres par un décalage droite de taille decald                          *
 *              celui des lettres diacritées, indépendamment de la casse de la manière suivante     *
 *                       ç  devient %                                                               *
 *                       âàéèêëîïôûüùÿ½  deviennent respectivement @#{}[]<>*&/|~$                   *
 *              celui des signes de ponctuation par remplacement : ainsi . devient » , devient «    *
 *              ; devient " et ainsi de suite
 *              aucun autre caractère n'est chiffré                                                 *
 *   exception : si aucun fichier contenant un texte n'est accessible, le programme s'interrompt    *
 *               immédiatement                                                                      *
 */
#include <iostream>
#include <fstream>
#include <string>

#include "chiffreCesar.h"


using namespace std;


int main(int argc, char* argv[] )  
{
	
     /* contrôle des arguments à la ligne de commande */
     if ( argc < 2 )
     {
          cout << "***** Erreur " << endl;
          cout << "\tUTILISATION : " << argv[0] << " nom_du_fichier_à_traiter" << endl;
          return 10;
     }
     
     /* ouverture d'un flot d'entrée sur le texte à traiter */
     ifstream fich_in(argv[1]);
     if ( !fich_in )
     {
          cout << "***** Erreur " << endl;
          cout << '\t' << argv[1] << " ne peut pas être ouvert" << endl;
          return 20;
     }
     
     /* chargement du texte en mémoire */
     string texte;
     getline(fich_in, texte, '\0');
     fich_in.close();
     
     // impression pour contrôle
     cout << "\n**********************************************************" << endl;
     cout << "texte chargé : " << endl;
     cout << texte << endl;
     cout << "\n**********************************************************" << endl;
     
     /* chiffrement du texte */
     
     // lecture des décalages
     unsigned short nblec;

     // décalage pour les lettres de l'alphabet latin standard
     nblec = 5;
     unsigned short decall;
     while(true)
     {
          cout << "\nQuel décalage pour les lettres non diacritées ? " << endl;
          cout << "** Saisir un nombre inférieur ou égal à 26 " << endl;
          
          cin >> decall;
          nblec--;
    
          if ( cin.fail() )
          {
               cout << "La donnée saisie n'est pas un nombre" << endl; 
               cin.clear();
          }
          else if (cin.good() )
          {
               if ( decall <= 26 ) break;
          }
          
         if ( nblec == 0 )
         {
              decall = 26;
              cout << "Décalage par défaut" << endl;
              break;
         }
         
         cout << "Vous n'avez pas saisi ce qui est demandé - Recommencez " << endl;
         cin.ignore(256, '\n');
     }
     
     cin.ignore(256, '\n');
     
     // décalage pour les chiffres
     nblec = 5;
     unsigned short decald;
     while(true)
     {
          cout << "\nQuel décalage pour les chiffres ? " << endl;
          cout << "** Attention. Le décalage ne doit pas être supérieur à 10" << endl;
          
          cin >> decald;
          nblec--;
          if ( cin.fail() )
          {
               cout << "La donnée saisie n'est pas un nombre" << endl; 
               cin.clear();
          }
          else if (cin.good() )
          {
               if ( decald <= 10 ) break;
          }
          
         if ( nblec == 0 )
         {
              decald = 10;
              cout << "Décalage par défaut" << endl;
              break;
         }
        
         cout << "Vous n'avez pas saisi ce qui est demandé - Recommencez " << endl;
         cin.ignore(256, '\n');
     }     
     
     // opération de chiffrement
     string textecrypte = Chiffrement(texte,decall ,decald) ;
     string textedecrypte = DChiffrement(textecrypte,decall ,decald) ;
     
     cout << "\n**********************************************************" << endl;
     cout << "texte crypté : " << endl;
     cout << textecrypte << endl;
     cout << "\n**********************************************************" << endl;

     cout << "\n**********************************************************" << endl;
     cout << "texte Décrypté : " << endl;
     cout << textedecrypte << endl;
     cout << "\n**********************************************************" << endl;

     return 0;
     
}// main

