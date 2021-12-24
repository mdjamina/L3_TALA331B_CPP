/* codeCesar - chiffre un texte selon une variante du code de C�sar                                 *
 *   donn�es : un texte, enregistr� dans un fichier dont le nom est pass� � la ligne de commande    *
 *             un entier <= 26, decall, le d�calage appliqu� sur les lettres de l'alphabet latin    *
 *             standard                                                                             *
 *             un entier <= 10 , decald, le d�calage appliqu� sur les chiffres                      *
 *   r�sultat : le texte chiffr� de la mani�re suivante                                             *
 *              le chiffrement des lettres de l'alphabet latin standard se fait par un d�calage     *
 *              droite de taille decall,                                                            *
 *              celui des chiffres par un d�calage droite de taille decald                          *
 *              celui des lettres diacrit�es, ind�pendamment de la casse de la mani�re suivante     *
 *                       �  devient %                                                               *
 *                       ��������������  deviennent respectivement @#{}[]<>*&/|~$                   *
 *              celui des signes de ponctuation par remplacement : ainsi . devient � , devient �    *
 *              ; devient " et ainsi de suite
 *              aucun autre caract�re n'est chiffr�                                                 *
 *   exception : si aucun fichier contenant un texte n'est accessible, le programme s'interrompt    *
 *               imm�diatement                                                                      *
 */
#include <iostream>
#include <fstream>
#include <string>

#include "chiffreCesar.h"


using namespace std;


int main(int argc, char* argv[] )  
{
	
     /* contr�le des arguments � la ligne de commande */
     if ( argc < 2 )
     {
          cout << "***** Erreur " << endl;
          cout << "\tUTILISATION : " << argv[0] << " nom_du_fichier_�_traiter" << endl;
          return 10;
     }
     
     /* ouverture d'un flot d'entr�e sur le texte � traiter */
     ifstream fich_in(argv[1]);
     if ( !fich_in )
     {
          cout << "***** Erreur " << endl;
          cout << '\t' << argv[1] << " ne peut pas �tre ouvert" << endl;
          return 20;
     }
     
     /* chargement du texte en m�moire */
     string texte;
     getline(fich_in, texte, '\0');
     fich_in.close();
     
     // impression pour contr�le
     cout << "\n**********************************************************" << endl;
     cout << "texte charg� : " << endl;
     cout << texte << endl;
     cout << "\n**********************************************************" << endl;
     
     /* chiffrement du texte */
     
     // lecture des d�calages
     unsigned short nblec;

     // d�calage pour les lettres de l'alphabet latin standard
     nblec = 5;
     unsigned short decall;
     while(true)
     {
          cout << "\nQuel d�calage pour les lettres non diacrit�es ? " << endl;
          cout << "** Saisir un nombre inf�rieur ou �gal � 26 " << endl;
          
          cin >> decall;
          nblec--;
    
          if ( cin.fail() )
          {
               cout << "La donn�e saisie n'est pas un nombre" << endl; 
               cin.clear();
          }
          else if (cin.good() )
          {
               if ( decall <= 26 ) break;
          }
          
         if ( nblec == 0 )
         {
              decall = 26;
              cout << "D�calage par d�faut" << endl;
              break;
         }
         
         cout << "Vous n'avez pas saisi ce qui est demand� - Recommencez " << endl;
         cin.ignore(256, '\n');
     }
     
     cin.ignore(256, '\n');
     
     // d�calage pour les chiffres
     nblec = 5;
     unsigned short decald;
     while(true)
     {
          cout << "\nQuel d�calage pour les chiffres ? " << endl;
          cout << "** Attention. Le d�calage ne doit pas �tre sup�rieur � 10" << endl;
          
          cin >> decald;
          nblec--;
          if ( cin.fail() )
          {
               cout << "La donn�e saisie n'est pas un nombre" << endl; 
               cin.clear();
          }
          else if (cin.good() )
          {
               if ( decald <= 10 ) break;
          }
          
         if ( nblec == 0 )
         {
              decald = 10;
              cout << "D�calage par d�faut" << endl;
              break;
         }
        
         cout << "Vous n'avez pas saisi ce qui est demand� - Recommencez " << endl;
         cin.ignore(256, '\n');
     }     
     
     // op�ration de chiffrement
     string textecrypte = Chiffrement(texte,decall ,decald) ;
     string textedecrypte = DChiffrement(textecrypte,decall ,decald) ;
     
     cout << "\n**********************************************************" << endl;
     cout << "texte crypt� : " << endl;
     cout << textecrypte << endl;
     cout << "\n**********************************************************" << endl;

     cout << "\n**********************************************************" << endl;
     cout << "texte D�crypt� : " << endl;
     cout << textedecrypte << endl;
     cout << "\n**********************************************************" << endl;

     return 0;
     
}// main

