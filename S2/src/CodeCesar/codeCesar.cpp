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
#include "classecar.h"

using namespace std;

char Chiffrement(char);
char Chiffrement(char, unsigned short, char, char);
char ChiffrementPonc(char );

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
     string textecrypte;
     for (auto c : texte)
     {
          char cc;
          if ( estponc(c) )
          {
               cc = ChiffrementPonc(c);                 
          }
          else if ( isdigit(c) )
          {
               cc = Chiffrement(c, decald, '0', '9');
          }
          else if ( isupper(c) )
          {
               cc = Chiffrement(c, decall, 'A', 'Z');
          }
          else if ( islower(c) )
          {
               cc = Chiffrement(c, decall, 'a', 'z');
          }
          else if ( c < '\0' )
          {
               cc = Chiffrement(c);
          }
          else
          {
               cc = c;
          }
          
          textecrypte += cc;
     }
     cout << "\n**********************************************************" << endl;
     cout << "texte crypté : " << endl;
     cout << textecrypte << endl;
     cout << "\n**********************************************************" << endl;

     return 0;
     
}// main

/* =====================Chiffrement===================================== */
/* ChiffrementPonc  -- chiffre un caractère de ponctuation                              *
 *    entrée : c, char, un caractère quelconque, le caractère à chiffrer                *
 *    retour : un caractère, l'équivalent chiffré de c si c est un caractère            *
 *             de ponctuation, sinon c lui-même                                         *
 */
char ChiffrementPonc(char c)
{
//     const string ponct(".,;?!:\"'«»"); // déclarés dans classecar.cpp
//     const str_size nponct = ponct.size();// et définis (exportés) par classecar.h 

     string::size_type indv;
     indv = ponct.find_first_of(c);
     if ( indv == string::npos )
     {
          return c;
     }
     
     return ponct[(nponct-1) - indv];
     
}//ChiffrementPonc

/* Chiffrement -- chiffre un caractère s'il est diacrité                 *
 *    entrée : c, char, un caractère quelconque, le caractère à chiffrer *
 *    retour : un caractère, l'équivalent chiffré de c si c est un       *
 *             diacrité, sinon c lui-même                                *
 */
char Chiffrement(char c)
{
//   char consonneDiacMin('ç');// déclarés dans caractere.cpp
//   char consonneDiacMaj('Ç');// et définis dans caractere.h 
     char ChiffreDiacC('%');

//   const string voyelleDiacMin_fr("âàéèêëîïôûüùÿ½");// déclarés dans classecar.cpp
//   const string voyelleDiacMaj_fr("ÂÀÉÊÈÊÎÏÔÛÜÙ¾¼");// et définis (exportés) par classecar.h 
     const string      ChiffreDiacV("@#{}[]<>*&/|~$");
     
     if ( c == consonneDiacMin_fr || c == consonneDiacMaj_fr )
     {
          return ChiffreDiacC;
     }

     string::size_type indv;
     indv = voyelleDiacMin_fr.find_first_of(c);
     if ( indv != string::npos )
     {
          return ChiffreDiacV[indv];
     }
     
     indv = voyelleDiacMaj_fr.find_first_of(c);
     if ( indv != string::npos )
     {
          return ChiffreDiacV[indv];
     }
     return c;     
}//Chiffrement chiffrement des diacrités

/* Chiffrement -- chiffre un caractère par décalage circulaire                          *
 *    entrée : c, char, un caractère quelconque, le caractère à chiffrer                *
 *             decal, unsigned short, le décalage à pratiquer                           *
 *             pcar, char, le premier car. de l'alphabet pris en compte                 *
 *             dcar, char, le dernier car. de l'alphabet pris en compte                 *
 *    retour : un caractère équivalent à c, chiffré selon decal ou c lui-même si c      *
 *             n'appartient pas à l'alphabet pris en compte                             *
 */
char Chiffrement(char c, unsigned short decal, char pcar, char dcar )
{
     unsigned short lalpha = dcar - pcar + 1;
     if ( c + decal > dcar )
     {
          c = c + decal - lalpha;
     }
     else
     {
          c = c + decal;
     }
     return c;
}//Chiffrement chiffrement d'un caractère
