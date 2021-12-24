// déclaration de sous-programmes représentant des opérations sur le type char
// ces sous-programmes sont définis dans le fichier classecar.cpp

#ifndef CHIFFRECESAR_H
#define CHIFFRECESAR_H

#include <cctype>
#include <string>
#include "classecar.h"


// exportation des noms de données utilisables dans différents programmes
// ces variables sont déclarées dans chiffreCesar.cpp
extern	char ChiffreDiacC;	//'%'

extern	const string ChiffreDiacV; //"@#{}[]<>*&/|~$"

using std::string;

/* =====================déChiffrement===================================== */


/* DChiffrementPonc -- déchiffre un caractère de ponctuation *
* entrée : c, char, un caractère quelconque, le caractère à chiffrer *
* retour : un caractère, l'équivalent chiffré de c si c est un caractère *
* de ponctuation, sinon c lui-même *
*/
char DChiffrementPonc(char );


/* DChiffrement -- déchiffre un caractère chiffré par décalage circulaire *
* entrée : c, char, un caractère quelconque, le caractère à déchiffrer *
* decal, unsigned short, le décalage qui a chiffré c *
* pcar, char, le premier car. de l'alphabet pris en compte *
* dcar, char, le dernier car. de l'alphabet pris en compte *
* retour : un caractère équivalent à c, déchiffré selon decal ou c lui-même si c *
* n'appartient pas à l'alphabet pris en compte *
*/
char DChiffrement(char, unsigned short, char, char);


/* DChiffrement -- déchiffre un caractère s'il n’est pas un signe de ponctuation *
* ni un chiffre ni une lettre *
* entrée : c, char, un caractère quelconque, le caractère à déchiffrer *
* retour : un caractère, l'équivalent déchiffré de c si c était le chiffre *
* d'un caractère diacrité, c sinon *
*/
char DChiffrement(char );


/* Dchiffrement -- déchiffre un texte chiffré par la fonction Chiffrement() qui *
* met en oeuvre une variante du chiffre de César *
* entrée : s, const string&, contient le texte à déchiffrer *
* decall, unsigned short, le décalage utilisé pour les lettres non diacritées*
* decald, unsigned short, le décalage utilisé pour les chiffres *
* retour : un objet string contenant le texte déchiffré *
*/
string DChiffrement(const string& , unsigned short , unsigned short );

/* =====================Chiffrement===================================== */


/* Chiffrement - chiffre une chaîne selon une variante du chiffre de César *
* entrée : s, const string&, la chaîne à chiffrer *
* decall, unsigned short, la taille du décalage pour les caractères de l'alphabet standard *
* decald, unsigned short, la taille du décalage pour les chiffres *
* retour : un objet, string, l'équivalent de s chiffrée *
* remarque : les signes de ponctuation et les lettres diacritées ne sont pas chiffrés par décalage *
* cf. spécification du programme
*/
string Chiffrement(const string&, unsigned short, unsigned short);


/* Chiffrement -- chiffre un caractère s'il est diacrité                 *
 *    entrée : c, char, un caractère quelconque, le caractère à chiffrer *
 *    retour : un caractère, l'équivalent chiffré de c si c est un       *
 *             diacrité, sinon c lui-même                                *
 */
char Chiffrement(char);

/* Chiffrement -- chiffre un caractère par décalage circulaire                          *
 *    entrée : c, char, un caractère quelconque, le caractère à chiffrer                *
 *             decal, unsigned short, le décalage à pratiquer                           *
 *             pcar, char, le premier car. de l'alphabet pris en compte                 *
 *             dcar, char, le dernier car. de l'alphabet pris en compte                 *
 *    retour : un caractère équivalent à c, chiffré selon decal ou c lui-même si c      *
 *             n'appartient pas à l'alphabet pris en compte                             *
 */
char Chiffrement(char, unsigned short, char, char);

/* ChiffrementPonc  -- chiffre un caractère de ponctuation                              *
 *    entrée : c, char, un caractère quelconque, le caractère à chiffrer                *
 *    retour : un caractère, l'équivalent chiffré de c si c est un caractère            *
 *             de ponctuation, sinon c lui-même                                         *
 */
char ChiffrementPonc(char );

#endif
