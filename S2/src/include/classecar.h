// déclaration de sous-programmes représentant des opérations sur le type char
// ces sous-programmes sont définis dans le fichier classecar.cpp

#ifndef CLASSECAR_H
#define CLASSECAR_H

#include <cctype>
#include <string>

using std::string;

// exportation des noms de données utilisables dans différents programmes
// ces variables sont déclarées dans classecar.cpp
// lexique des caractères vocaliques standards
extern const string voyelleASCIIMin;                 //"aeiouy"

// lexique des caractères vocaliques diacrités utilisés en français
extern const string voyelleDiacMin_fr;              //"àâéèêëîïô½ùûüÿ½"
extern const string voyelleDiacMaj_fr;              //"ÀÂÉÈÊËÎÏÔ¼ÙÛÜ¾¼"
extern const string::size_type nvdiac_fr;           // nbre de letttres. voc. diacrités

// le caractère consonantique diacrité utilisé en français
extern char consonneDiacMin_fr;                    // ç
extern char consonneDiacMaj_fr;                    // Ç

// lexique des signes de ponctuation
extern const string ponct;                         //".,;?!:\"'«»";
extern const string::size_type nponct;             // nbre de signes de ponctuation




/* estponc -- vérifie si un caractère donné est ou non un signe de ponctuation parmi ".,;?!:" *
 * donnée : c, char, un caractère quelconque                                                  *
 * retour : true si c est un signe de ponctuation, false sinon                                *
 */
bool estponc(char);

/* estVoyelle_fr -- asserte qu'un caractère est un caractère vocalique  utilisé dans l'écriture *
 *                  du français                                                                 *
 * donnée : c, char, un caractère quelconque                                                    *
 * retour : true si c est un caractère vocalique utilisé en français               ,            *
 *             false sinon                                                                      *
 */
bool estVoyelle_fr(char );

/* estVoyelleAscii - asserte qu'un caractère est un caractère vocalique appartenant au *
 *                   jeu ascii                                                         *
 *   donnée : c, char, un caractère quelconque                                         *
 *   retour : true si c est un caractère vocalique ascii, false sinon                  *
 */
bool estVoyelleAscii(char);

/* estVoyelleDiac_fr -- asserte qu'un caractère est un caractère vocalique diacrité appartenant *
 *                   au jeu ISO-8859-15                                                         *
 * donnée : c, char, un caractère quelconque                                                    *
 * retour : true si c est un caractère vocalique diacrité appartenant à ISO-8859-15,            *
 *          false sinon                                                                         *
 */
bool estVoyelleDiac_fr(char );

/* estConsonneAscii  -- asserte qu'un caractère est un caractère consonantique            *
 *                   appartenant au jeu ascii                                             *
 * donnée : c, char, un caractère quelconque                                              *
 * retour : true si c est un caractère consonantique appartenant au jeu ascii,            *
 *          false sinon                                                                   *
 */
bool estConsonneAscii(char );

/* estConsonneDiac_fr  -- asserte qu'un caractère est un caractère consonantique diacrité  *
 *                   appartenant au jeu ISO-8859-15                                        *
 * donnée : c, char, un caractère quelconque                                               *
 * retour : true si c est un caractère consonantique appartenant au jeu ISO-8859-15        *
 *          false sinon                                                                    *
 */
bool estConsonneDiac_fr(char );

/* estConsonne_fr -- asserte qu'un caractère est un caractère consonantique  utilisé dans l'écriture *
 *                  du français                                                                      *
 * donnée : c, char, un caractère quelconque                                                         *
 * retour : true si c est un caractère consonantique utilisé en français                ,            *
 *             false sinon                                                                           *
 */
bool estConsonne_fr(char );

#endif
