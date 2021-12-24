// définition de sous-programmes représentant des opérations sur le type char
// ces sous-programmes sont déclarés dans le fichier classecar.h

#include <string>
#include "classecar.h"


using std::string;
typedef string::size_type str_size;

// lexique des caractères vocaliques standards
const string voyelleASCIIMin("aeiouy");

// lexique des caractères vocaliques diacrités utilisés en français
const string voyelleDiacMin_fr("àâéèêëîïô½ùûüÿ½");
const string voyelleDiacMaj_fr("ÀÂÉÈÊËÎÏÔ¼ÙÛÜ¾¼");
const string::size_type nvdiac_fr = voyelleDiacMin_fr.size();

// le caractère consonantique diacrité utilisé en français
char consonneDiacMin_fr('ç');
char consonneDiacMaj_fr('Ç');

// lexique des signes de ponctuation
const string ponct(".,;?!:\"'«»");
const string::size_type nponct = ponct.size();


/* estponc -- vérifie si un caractère donné est ou non un signe de ponctuation parmi ".,;?!:" *
 * donnée : c, char, un caractère quelconque                                                  *
 * retour : true si c est un signe de ponctuation, false sinon                                *
 */
bool estponc(char c)
{
     for (auto p : ponct )
     {
          if ( p == c ) return true;
     }
     return false;
}// estponc#include <cctype>

/* estVoyelleAscii - asserte qu'un caractère est un caractère vocalique appartenant au *
 *                   jeu ascii                                                         *
 *   donnée : c, char, un caractère quelconque                                         *
 *   retour : true si c est un caractère vocalique ascii, false sinon                  *
 */
bool estVoyelleAscii(char c)
{
     if ( !isalpha(c) ) return false;
     
     for (auto v : voyelleASCIIMin)
     {
          if ( tolower(c) == v ) return true;
          
      }// fin parcours des voyelles std
      
      return false;
}//estVoyelleAscii 

/* estVoyelleDiac_fr -- asserte qu'un caractère est un caractère vocalique diacrité appartenant *
 *                   au jeu ISO-8859-15                                                         *
 * donnée : c, char, un caractère quelconque                                                    *
 * retour : true si c est un caractère vocalique diacrité appartenant à ISO-8859-15,            *
 *          false sinon                                                                         *
 */
bool estVoyelleDiac_fr(char c)
{
     // lexique des caractères vocaliques diacrités utilisés en français
     
     if ( c > '\0' ) return false; // c appartient au répertoire ascci

     string::size_type i = 0;
     while(true)
     {// parcours du lexique des voyelles : énumération des caractères de voyelleDiacMin_fr et
      // voyelleDiacMaj_fr
          if ( i == nvdiac_fr ) return false; // le car. courant n'est pas un car. voc. diacrité
          
          if ( c == voyelleDiacMin_fr[i] || c ==voyelleDiacMaj_fr[i] ) return true;
          
          i++;
          
      }// fin parcours des voyelles diacritées

}//estVoyelleDiac_fr

/* estVoyelle_fr -- asserte qu'un caractère est un caractère vocalique  utilisé dans l'écriture *
 *                  du français                                                                 *
 * donnée : c, char, un caractère quelconque                                                    *
 * retour : true si c est un caractère vocalique utilisé en français               ,            *
 *             false sinon                                                                      *
 */
bool estVoyelle_fr(char c)
{
     return estVoyelleAscii(c) || estVoyelleDiac_fr(c);
}// estVoyelle_fr

/* estConsonneAscii  -- asserte qu'un caractère est un caractère consonantique            *
 *                   appartenant au jeu ascii                                             *
 * donnée : c, char, un caractère quelconque                                              *
 * retour : true si c est un caractère consonantique appartenant au jeu ascii,            *
 *          false sinon                                                                   *
 */
bool estConsonneAscii(char c)
{
     return isalpha(c) && !estVoyelleAscii(c);
}// estConsonneAscii

/* estConsonneDiac_fr  -- asserte qu'un caractère est un caractère consonantique diacrité  *
 *                   appartenant au jeu ISO-8859-15                                        *
 * donnée : c, char, un caractère quelconque                                               *
 * retour : true si c est un caractère consonantique appartenant au jeu ISO-8859-15        *
 *          false sinon                                                                    *
 */
bool estConsonneDiac_fr(char c)
{
     char consonneDiacMin_fr('ç'),
          consonneDiacMaj_fr('Ç');
     
     return (c==consonneDiacMin_fr) || (c==consonneDiacMaj_fr);
}// estConsonneDiac_fr

/* estConsonne_fr -- asserte qu'un caractère est un caractère consonantique  utilisé dans l'écriture *
 *                  du français                                                                      *
 * donnée : c, char, un caractère quelconque                                                         *
 * retour : true si c est un caractère consonantique utilisé en français                ,            *
 *             false sinon                                                                           *
 */
bool estConsonne_fr(char c)
{
     return estConsonneAscii(c) || estConsonneDiac_fr(c);
}// estVoyelle_fr
