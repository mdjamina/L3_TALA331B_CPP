// d�claration de sous-programmes repr�sentant des op�rations sur le type char
// ces sous-programmes sont d�finis dans le fichier classecar.cpp

#ifndef CLASSECAR_H
#define CLASSECAR_H

#include <cctype>
#include <string>

using std::string;

// exportation des noms de donn�es utilisables dans diff�rents programmes
// ces variables sont d�clar�es dans classecar.cpp
// lexique des caract�res vocaliques standards
extern const string voyelleASCIIMin;                 //"aeiouy"

// lexique des caract�res vocaliques diacrit�s utilis�s en fran�ais
extern const string voyelleDiacMin_fr;              //"���������������"
extern const string voyelleDiacMaj_fr;              //"��������Լ��ܾ�"
extern const string::size_type nvdiac_fr;           // nbre de letttres. voc. diacrit�s

// le caract�re consonantique diacrit� utilis� en fran�ais
extern char consonneDiacMin_fr;                    // �
extern char consonneDiacMaj_fr;                    // �

// lexique des signes de ponctuation
extern const string ponct;                         //".,;?!:\"'��";
extern const string::size_type nponct;             // nbre de signes de ponctuation




/* estponc -- v�rifie si un caract�re donn� est ou non un signe de ponctuation parmi ".,;?!:" *
 * donn�e : c, char, un caract�re quelconque                                                  *
 * retour : true si c est un signe de ponctuation, false sinon                                *
 */
bool estponc(char);

/* estVoyelle_fr -- asserte qu'un caract�re est un caract�re vocalique  utilis� dans l'�criture *
 *                  du fran�ais                                                                 *
 * donn�e : c, char, un caract�re quelconque                                                    *
 * retour : true si c est un caract�re vocalique utilis� en fran�ais               ,            *
 *             false sinon                                                                      *
 */
bool estVoyelle_fr(char );

/* estVoyelleAscii - asserte qu'un caract�re est un caract�re vocalique appartenant au *
 *                   jeu ascii                                                         *
 *   donn�e : c, char, un caract�re quelconque                                         *
 *   retour : true si c est un caract�re vocalique ascii, false sinon                  *
 */
bool estVoyelleAscii(char);

/* estVoyelleDiac_fr -- asserte qu'un caract�re est un caract�re vocalique diacrit� appartenant *
 *                   au jeu ISO-8859-15                                                         *
 * donn�e : c, char, un caract�re quelconque                                                    *
 * retour : true si c est un caract�re vocalique diacrit� appartenant � ISO-8859-15,            *
 *          false sinon                                                                         *
 */
bool estVoyelleDiac_fr(char );

/* estConsonneAscii  -- asserte qu'un caract�re est un caract�re consonantique            *
 *                   appartenant au jeu ascii                                             *
 * donn�e : c, char, un caract�re quelconque                                              *
 * retour : true si c est un caract�re consonantique appartenant au jeu ascii,            *
 *          false sinon                                                                   *
 */
bool estConsonneAscii(char );

/* estConsonneDiac_fr  -- asserte qu'un caract�re est un caract�re consonantique diacrit�  *
 *                   appartenant au jeu ISO-8859-15                                        *
 * donn�e : c, char, un caract�re quelconque                                               *
 * retour : true si c est un caract�re consonantique appartenant au jeu ISO-8859-15        *
 *          false sinon                                                                    *
 */
bool estConsonneDiac_fr(char );

/* estConsonne_fr -- asserte qu'un caract�re est un caract�re consonantique  utilis� dans l'�criture *
 *                  du fran�ais                                                                      *
 * donn�e : c, char, un caract�re quelconque                                                         *
 * retour : true si c est un caract�re consonantique utilis� en fran�ais                ,            *
 *             false sinon                                                                           *
 */
bool estConsonne_fr(char );

#endif
