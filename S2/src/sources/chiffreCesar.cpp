// définition de sous-programmes représentant des opérations sur le type char
// ces sous-programmes sont déclarés dans le fichier chiffreCesar.h

#include <iostream>
#include <fstream>
#include <string>

#include "chiffreCesar.h"

char ChiffreDiacC('%');

const string ChiffreDiacV("@#{}[]<>*&/|~$");

/* =====================déChiffrement===================================== */

/* DChiffrementPonc -- déchiffre un caractère de ponctuation *
* entrée : c, char, un caractère quelconque, le caractère à chiffrer *
* retour : un caractère, l'équivalent chiffré de c si c est un caractère *
* de ponctuation, sinon c lui-même *
*/
char DChiffrementPonc(char c)
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
}//DChiffrementPonc


/* DChiffrement -- déchiffre un caractère chiffré par décalage circulaire *
* entrée : c, char, un caractère quelconque, le caractère à déchiffrer *
* decal, unsigned short, le décalage qui a chiffré c *
* pcar, char, le premier car. de l'alphabet pris en compte *
* dcar, char, le dernier car. de l'alphabet pris en compte *
* retour : un caractère équivalent à c, déchiffré selon decal ou c lui-même si c *
* n'appartient pas à l'alphabet pris en compte *
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
}//DChiffrement déchiffrement d'un caractère


/* DChiffrement -- déchiffre un caractère s'il n’est pas un signe de ponctuation *
* ni un chiffre ni une lettre *
* entrée : c, char, un caractère quelconque, le caractère à déchiffrer *
* retour : un caractère, l'équivalent déchiffré de c si c était le chiffre *
* d'un caractère diacrité, c sinon *
*/
char DChiffrement(char c)
{
//   char consonneDiacMin('ç');// déclarés dans caractere.cpp
//   char consonneDiacMaj('Ç');// et définis dans caractere.h 
     //char ChiffreDiacC('%');

//   const string voyelleDiacMin_fr("âàéèêëîïôûüùÿ½");// déclarés dans classecar.cpp
//   const string voyelleDiacMaj_fr("ÂÀÉÊÈÊÎÏÔÛÜÙ¾¼");// et définis (exportés) par classecar.h 
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
}//DChiffrement déchiffrement des diacrités

/* Dchiffrement -- déchiffre un texte chiffré par la fonction Chiffrement() qui *
* met en oeuvre une variante du chiffre de César *
* entrée : s, const string&, contient le texte à déchiffrer *
* decall, unsigned short, le décalage utilisé pour les lettres non diacritées*
* decald, unsigned short, le décalage utilisé pour les chiffres *
* retour : un objet string contenant le texte déchiffré *
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

/* Chiffrement - chiffre une chaîne selon une variante du chiffre de César *
* entrée : s, const string&, la chaîne à chiffrer *
* decall, unsigned short, la taille du décalage pour les caractères de l'alphabet standard *
* decald, unsigned short, la taille du décalage pour les chiffres *
* retour : un objet, string, l'équivalent de s chiffrée *
* remarque : les signes de ponctuation et les lettres diacritées ne sont pas chiffrés par décalage *
* cf. spécification du programme
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
//     char ChiffreDiacC('%');

//   const string voyelleDiacMin_fr("âàéèêëîïôûüùÿ½");// déclarés dans classecar.cpp
//   const string voyelleDiacMaj_fr("ÂÀÉÊÈÊÎÏÔÛÜÙ¾¼");// et définis (exportés) par classecar.h 
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
