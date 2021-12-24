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
#include "classecar.h"

using namespace std;

char Chiffrement(char);
char Chiffrement(char, unsigned short, char, char);
char ChiffrementPonc(char );

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
     cout << "texte crypt� : " << endl;
     cout << textecrypte << endl;
     cout << "\n**********************************************************" << endl;

     return 0;
     
}// main

/* =====================Chiffrement===================================== */
/* ChiffrementPonc  -- chiffre un caract�re de ponctuation                              *
 *    entr�e : c, char, un caract�re quelconque, le caract�re � chiffrer                *
 *    retour : un caract�re, l'�quivalent chiffr� de c si c est un caract�re            *
 *             de ponctuation, sinon c lui-m�me                                         *
 */
char ChiffrementPonc(char c)
{
//     const string ponct(".,;?!:\"'��"); // d�clar�s dans classecar.cpp
//     const str_size nponct = ponct.size();// et d�finis (export�s) par classecar.h 

     string::size_type indv;
     indv = ponct.find_first_of(c);
     if ( indv == string::npos )
     {
          return c;
     }
     
     return ponct[(nponct-1) - indv];
     
}//ChiffrementPonc

/* Chiffrement -- chiffre un caract�re s'il est diacrit�                 *
 *    entr�e : c, char, un caract�re quelconque, le caract�re � chiffrer *
 *    retour : un caract�re, l'�quivalent chiffr� de c si c est un       *
 *             diacrit�, sinon c lui-m�me                                *
 */
char Chiffrement(char c)
{
//   char consonneDiacMin('�');// d�clar�s dans caractere.cpp
//   char consonneDiacMaj('�');// et d�finis dans caractere.h 
     char ChiffreDiacC('%');

//   const string voyelleDiacMin_fr("��������������");// d�clar�s dans classecar.cpp
//   const string voyelleDiacMaj_fr("�����������پ�");// et d�finis (export�s) par classecar.h 
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
}//Chiffrement chiffrement des diacrit�s

/* Chiffrement -- chiffre un caract�re par d�calage circulaire                          *
 *    entr�e : c, char, un caract�re quelconque, le caract�re � chiffrer                *
 *             decal, unsigned short, le d�calage � pratiquer                           *
 *             pcar, char, le premier car. de l'alphabet pris en compte                 *
 *             dcar, char, le dernier car. de l'alphabet pris en compte                 *
 *    retour : un caract�re �quivalent � c, chiffr� selon decal ou c lui-m�me si c      *
 *             n'appartient pas � l'alphabet pris en compte                             *
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
}//Chiffrement chiffrement d'un caract�re
