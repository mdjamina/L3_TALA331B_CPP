// d�finition de sous-programmes repr�sentant des op�rations sur le type char
// ces sous-programmes sont d�clar�s dans le fichier chiffreCesar.h

#include <iostream>
#include <fstream>
#include <string>

#include "chiffreCesar.h"

char ChiffreDiacC('%');

const string ChiffreDiacV("@#{}[]<>*&/|~$");

/* =====================d�Chiffrement===================================== */

/* DChiffrementPonc -- d�chiffre un caract�re de ponctuation *
* entr�e : c, char, un caract�re quelconque, le caract�re � chiffrer *
* retour : un caract�re, l'�quivalent chiffr� de c si c est un caract�re *
* de ponctuation, sinon c lui-m�me *
*/
char DChiffrementPonc(char c)
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
}//DChiffrementPonc


/* DChiffrement -- d�chiffre un caract�re chiffr� par d�calage circulaire *
* entr�e : c, char, un caract�re quelconque, le caract�re � d�chiffrer *
* decal, unsigned short, le d�calage qui a chiffr� c *
* pcar, char, le premier car. de l'alphabet pris en compte *
* dcar, char, le dernier car. de l'alphabet pris en compte *
* retour : un caract�re �quivalent � c, d�chiffr� selon decal ou c lui-m�me si c *
* n'appartient pas � l'alphabet pris en compte *
*/
char DChiffrement(char c, unsigned short decal, char pcar, char dcar )
{
     unsigned short lalpha = dcar - pcar + 1;
     if ( c - decal < pcar )
     {
          c = c - decal + lalpha;
     }
     else
     {
          c = c - decal;
     }
     return c;
}//DChiffrement d�chiffrement d'un caract�re


/* DChiffrement -- d�chiffre un caract�re s'il n�est pas un signe de ponctuation *
* ni un chiffre ni une lettre *
* entr�e : c, char, un caract�re quelconque, le caract�re � d�chiffrer *
* retour : un caract�re, l'�quivalent d�chiffr� de c si c �tait le chiffre *
* d'un caract�re diacrit�, c sinon *
*/
char DChiffrement(char c)
{
//   char consonneDiacMin('�');// d�clar�s dans caractere.cpp
//   char consonneDiacMaj('�');// et d�finis dans caractere.h 
     //char ChiffreDiacC('%');

//   const string voyelleDiacMin_fr("��������������");// d�clar�s dans classecar.cpp
//   const string voyelleDiacMaj_fr("�����������پ�");// et d�finis (export�s) par classecar.h 
    // const string      ChiffreDiacV("@#{}[]<>*&/|~$");
     
     if ( c == ChiffreDiacC )
     {
          return consonneDiacMin_fr;
     }

     string::size_type indv;
     indv = ChiffreDiacV.find_first_of(c);
     if ( indv != string::npos )
     {
          return voyelleDiacMin_fr[indv];
     }
     
     return c;     
}//DChiffrement d�chiffrement des diacrit�s

/* Dchiffrement -- d�chiffre un texte chiffr� par la fonction Chiffrement() qui *
* met en oeuvre une variante du chiffre de C�sar *
* entr�e : s, const string&, contient le texte � d�chiffrer *
* decall, unsigned short, le d�calage utilis� pour les lettres non diacrit�es*
* decald, unsigned short, le d�calage utilis� pour les chiffres *
* retour : un objet string contenant le texte d�chiffr� *
*/
string DChiffrement(const string& s, unsigned short decall, unsigned short decald)
{
	
	string textedecrypte;
     for (auto c : s)
     {
          char cc;
          if ( estponc(c) )
          {
               cc = DChiffrementPonc(c);                 
          }
          else if ( isdigit(c) )
          {
               cc = DChiffrement(c, decald, '0', '9');
          }
          else if ( isupper(c) )
          {
               cc = DChiffrement(c, decall, 'A', 'Z');
          }
          else if ( islower(c) )
          {
               cc = DChiffrement(c, decall, 'a', 'z');
          }
         /* else if ( c < '\0' )
          {
               cc = DChiffrement(c);
          }*/
          else
          {
               cc = DChiffrement(c);
          }
          
          textedecrypte += cc;
     }
	 
	 return textedecrypte;
	
}//DChiffrement



/* =====================Chiffrement===================================== */

/* Chiffrement - chiffre une cha�ne selon une variante du chiffre de C�sar *
* entr�e : s, const string&, la cha�ne � chiffrer *
* decall, unsigned short, la taille du d�calage pour les caract�res de l'alphabet standard *
* decald, unsigned short, la taille du d�calage pour les chiffres *
* retour : un objet, string, l'�quivalent de s chiffr�e *
* remarque : les signes de ponctuation et les lettres diacrit�es ne sont pas chiffr�s par d�calage *
* cf. sp�cification du programme
*/
string Chiffrement(const string& s, unsigned short decall, unsigned short decald)
{
	
	string textecrypte;
     for (auto c : s)
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
	 
	 return textecrypte;
	
}//Chiffrement


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
//     char ChiffreDiacC('%');

//   const string voyelleDiacMin_fr("��������������");// d�clar�s dans classecar.cpp
//   const string voyelleDiacMaj_fr("�����������پ�");// et d�finis (export�s) par classecar.h 
//     const string      ChiffreDiacV("@#{}[]<>*&/|~$");
     
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
