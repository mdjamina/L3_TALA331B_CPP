// d�claration de sous-programmes repr�sentant des op�rations sur le type char
// ces sous-programmes sont d�finis dans le fichier classecar.cpp

#ifndef CHIFFRECESAR_H
#define CHIFFRECESAR_H

#include <cctype>
#include <string>
#include "classecar.h"


// exportation des noms de donn�es utilisables dans diff�rents programmes
// ces variables sont d�clar�es dans chiffreCesar.cpp
extern	char ChiffreDiacC;	//'%'

extern	const string ChiffreDiacV; //"@#{}[]<>*&/|~$"

using std::string;

/* =====================d�Chiffrement===================================== */


/* DChiffrementPonc -- d�chiffre un caract�re de ponctuation *
* entr�e : c, char, un caract�re quelconque, le caract�re � chiffrer *
* retour : un caract�re, l'�quivalent chiffr� de c si c est un caract�re *
* de ponctuation, sinon c lui-m�me *
*/
char DChiffrementPonc(char );


/* DChiffrement -- d�chiffre un caract�re chiffr� par d�calage circulaire *
* entr�e : c, char, un caract�re quelconque, le caract�re � d�chiffrer *
* decal, unsigned short, le d�calage qui a chiffr� c *
* pcar, char, le premier car. de l'alphabet pris en compte *
* dcar, char, le dernier car. de l'alphabet pris en compte *
* retour : un caract�re �quivalent � c, d�chiffr� selon decal ou c lui-m�me si c *
* n'appartient pas � l'alphabet pris en compte *
*/
char DChiffrement(char, unsigned short, char, char);


/* DChiffrement -- d�chiffre un caract�re s'il n�est pas un signe de ponctuation *
* ni un chiffre ni une lettre *
* entr�e : c, char, un caract�re quelconque, le caract�re � d�chiffrer *
* retour : un caract�re, l'�quivalent d�chiffr� de c si c �tait le chiffre *
* d'un caract�re diacrit�, c sinon *
*/
char DChiffrement(char );


/* Dchiffrement -- d�chiffre un texte chiffr� par la fonction Chiffrement() qui *
* met en oeuvre une variante du chiffre de C�sar *
* entr�e : s, const string&, contient le texte � d�chiffrer *
* decall, unsigned short, le d�calage utilis� pour les lettres non diacrit�es*
* decald, unsigned short, le d�calage utilis� pour les chiffres *
* retour : un objet string contenant le texte d�chiffr� *
*/
string DChiffrement(const string& , unsigned short , unsigned short );

/* =====================Chiffrement===================================== */


/* Chiffrement - chiffre une cha�ne selon une variante du chiffre de C�sar *
* entr�e : s, const string&, la cha�ne � chiffrer *
* decall, unsigned short, la taille du d�calage pour les caract�res de l'alphabet standard *
* decald, unsigned short, la taille du d�calage pour les chiffres *
* retour : un objet, string, l'�quivalent de s chiffr�e *
* remarque : les signes de ponctuation et les lettres diacrit�es ne sont pas chiffr�s par d�calage *
* cf. sp�cification du programme
*/
string Chiffrement(const string&, unsigned short, unsigned short);


/* Chiffrement -- chiffre un caract�re s'il est diacrit�                 *
 *    entr�e : c, char, un caract�re quelconque, le caract�re � chiffrer *
 *    retour : un caract�re, l'�quivalent chiffr� de c si c est un       *
 *             diacrit�, sinon c lui-m�me                                *
 */
char Chiffrement(char);

/* Chiffrement -- chiffre un caract�re par d�calage circulaire                          *
 *    entr�e : c, char, un caract�re quelconque, le caract�re � chiffrer                *
 *             decal, unsigned short, le d�calage � pratiquer                           *
 *             pcar, char, le premier car. de l'alphabet pris en compte                 *
 *             dcar, char, le dernier car. de l'alphabet pris en compte                 *
 *    retour : un caract�re �quivalent � c, chiffr� selon decal ou c lui-m�me si c      *
 *             n'appartient pas � l'alphabet pris en compte                             *
 */
char Chiffrement(char, unsigned short, char, char);

/* ChiffrementPonc  -- chiffre un caract�re de ponctuation                              *
 *    entr�e : c, char, un caract�re quelconque, le caract�re � chiffrer                *
 *    retour : un caract�re, l'�quivalent chiffr� de c si c est un caract�re            *
 *             de ponctuation, sinon c lui-m�me                                         *
 */
char ChiffrementPonc(char );

#endif
