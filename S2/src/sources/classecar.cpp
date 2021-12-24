// d�finition de sous-programmes repr�sentant des op�rations sur le type char
// ces sous-programmes sont d�clar�s dans le fichier classecar.h

#include <string>
#include "classecar.h"


using std::string;
typedef string::size_type str_size;

// lexique des caract�res vocaliques standards
const string voyelleASCIIMin("aeiouy");

// lexique des caract�res vocaliques diacrit�s utilis�s en fran�ais
const string voyelleDiacMin_fr("���������������");
const string voyelleDiacMaj_fr("��������Լ��ܾ�");
const string::size_type nvdiac_fr = voyelleDiacMin_fr.size();

// le caract�re consonantique diacrit� utilis� en fran�ais
char consonneDiacMin_fr('�');
char consonneDiacMaj_fr('�');

// lexique des signes de ponctuation
const string ponct(".,;?!:\"'��");
const string::size_type nponct = ponct.size();


/* estponc -- v�rifie si un caract�re donn� est ou non un signe de ponctuation parmi ".,;?!:" *
 * donn�e : c, char, un caract�re quelconque                                                  *
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

/* estVoyelleAscii - asserte qu'un caract�re est un caract�re vocalique appartenant au *
 *                   jeu ascii                                                         *
 *   donn�e : c, char, un caract�re quelconque                                         *
 *   retour : true si c est un caract�re vocalique ascii, false sinon                  *
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

/* estVoyelleDiac_fr -- asserte qu'un caract�re est un caract�re vocalique diacrit� appartenant *
 *                   au jeu ISO-8859-15                                                         *
 * donn�e : c, char, un caract�re quelconque                                                    *
 * retour : true si c est un caract�re vocalique diacrit� appartenant � ISO-8859-15,            *
 *          false sinon                                                                         *
 */
bool estVoyelleDiac_fr(char c)
{
     // lexique des caract�res vocaliques diacrit�s utilis�s en fran�ais
     
     if ( c > '\0' ) return false; // c appartient au r�pertoire ascci

     string::size_type i = 0;
     while(true)
     {// parcours du lexique des voyelles : �num�ration des caract�res de voyelleDiacMin_fr et
      // voyelleDiacMaj_fr
          if ( i == nvdiac_fr ) return false; // le car. courant n'est pas un car. voc. diacrit�
          
          if ( c == voyelleDiacMin_fr[i] || c ==voyelleDiacMaj_fr[i] ) return true;
          
          i++;
          
      }// fin parcours des voyelles diacrit�es

}//estVoyelleDiac_fr

/* estVoyelle_fr -- asserte qu'un caract�re est un caract�re vocalique  utilis� dans l'�criture *
 *                  du fran�ais                                                                 *
 * donn�e : c, char, un caract�re quelconque                                                    *
 * retour : true si c est un caract�re vocalique utilis� en fran�ais               ,            *
 *             false sinon                                                                      *
 */
bool estVoyelle_fr(char c)
{
     return estVoyelleAscii(c) || estVoyelleDiac_fr(c);
}// estVoyelle_fr

/* estConsonneAscii  -- asserte qu'un caract�re est un caract�re consonantique            *
 *                   appartenant au jeu ascii                                             *
 * donn�e : c, char, un caract�re quelconque                                              *
 * retour : true si c est un caract�re consonantique appartenant au jeu ascii,            *
 *          false sinon                                                                   *
 */
bool estConsonneAscii(char c)
{
     return isalpha(c) && !estVoyelleAscii(c);
}// estConsonneAscii

/* estConsonneDiac_fr  -- asserte qu'un caract�re est un caract�re consonantique diacrit�  *
 *                   appartenant au jeu ISO-8859-15                                        *
 * donn�e : c, char, un caract�re quelconque                                               *
 * retour : true si c est un caract�re consonantique appartenant au jeu ISO-8859-15        *
 *          false sinon                                                                    *
 */
bool estConsonneDiac_fr(char c)
{
     char consonneDiacMin_fr('�'),
          consonneDiacMaj_fr('�');
     
     return (c==consonneDiacMin_fr) || (c==consonneDiacMaj_fr);
}// estConsonneDiac_fr

/* estConsonne_fr -- asserte qu'un caract�re est un caract�re consonantique  utilis� dans l'�criture *
 *                  du fran�ais                                                                      *
 * donn�e : c, char, un caract�re quelconque                                                         *
 * retour : true si c est un caract�re consonantique utilis� en fran�ais                ,            *
 *             false sinon                                                                           *
 */
bool estConsonne_fr(char c)
{
     return estConsonneAscii(c) || estConsonneDiac_fr(c);
}// estVoyelle_fr
