/* ************************************************************************** */
/*                                  Header                                    */
/*                                                                            */
/*                            abourenn - chacelas                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIENT_H
# define GRIENT_H
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <time.h>
# include <MLV/MLV_all.h>
# define LARG_WIN 1440.0
# define HAUT_WIN 720.0
# define VAL_MAX 80
# define BUT 100
# define TAILLE_NOM 25

typedef struct	parsing
{
	int		nb_flag;
	int		flag;
	char	*fichier;
}				parse;

typedef struct	grille_s
{
	int		max;
	int		coups;
	int		taille;
	int		somme;
	int		type_coups;
	int		coordonnee1[2];
	int		coordonnee2[2];
	int		**grille;
}				grille;

typedef struct	principal
{
	parse			entrer;
	grille			jeu;
	FILE			*fichier;
	int				error;
}				principal;


char	*change_path(char *dossier, char *path);
/* BUT    : Crée un nouveau path pour le fichier en rajoutant dossier juste   */
/*          avant le dernier le fichier du path                               */
/* PARAM  : dossier => la chainne de charactère contenant le nom du dossier   */
/*          path    => la chainne de charactère contenant le path du fichier  */
/* RETOUR : Renvoie la nouvelle chainne de charactère contenant le path du    */
/*          fichier                                                           */

char	*ft_itoa(int n);
/* BUT    : Convertie un entier en chaine de charactère                       */
/* PARAM  : Entier à convertir                                                */
/* RETOUR : Renvoie l'entier convertie ou NULL si il y a une erreur de malloc */

char	*ft_stradd(char *s, int c);
/* BUT    : Ajoute le charactère c à la fin de la chaine de charactère s      */
/* PARAM  : s => chaine de charactère à changer                               */
/*          c => charactère à ajouter                                         */
/* RETOUR : Renvoie la nouvelle chaine de charactère s avec le charactère c   */

char	*ft_strdup(char *s);
/* BUT    : Alloue une nouvelle chaîne de charactère dont le contenue est s   */
/* PARAM  : s => chaîne de charactère dont on veut copier le contenue         */
/* RETOUR : retourne la nouvelle chaîne de charactère créée                   */

char	*ft_strjoin(char *s1, char *s2, int boo);
/* BUT    : Crée une nouvelle chaine contenant la concaténation de s1 et s2 et*/
/*          peut libèrer l'espace mémoire de s1 et s2 si possible             */
/* PARAM  : s1  => première chaine de charactère                              */
/*          s2  => seconde chaine de charactère                               */
/*          boo => 0 libère aucune chaine, 1 libère s1, 2 libère s2 et libère */
/*                 toute les chaines avec 3                                   */
/* RETOUR : Renvoie la nouvelle chaine de charactère ou NULL si il y a un     */
/*          problème d'allocation mémoire                                     */

char	*ft_strstr(char *s1, char *s2);
/* BUT    : Cherche la première occurence de la chaine s2 dans la chaine s1   */
/* PARAM  : s1 => chaine de charactère botte de foin                          */
/*          s2 => chaine de charactère aiguille                               */
/* RETOUR : Renvoie l'adresse du premier charactère de l'occurence de s2 dans */
/*          s1 si il y a un occurence sinon renvoie NULL                      */

char	*ft_strsupp(char *s);
/* BUT    : Retire le dernier charactère de la chaine s                       */
/* PARAM  : Chaine de charactère que l'on veut modifier                       */
/* RETOUR : La nouvelle chaine de charactère s sans le dernier charactère     */


int		affiche_menu(principal *donnee);
/* BUT    : Appelle le menu approprié à la demande de l'utilisateur           */
/* PARAM  : L'adresse de la structure principale                              */
/* RETOUR : Renvoie 1 si une erreur lors du déroulement des fonctions appelées*/
/*          sinon 0                                                           */

int		fin_de_jeu_ASCII(principal *donnee);
/* BUT    : Demande à l'utilisateur si il veut enregistrer son score          */
/* PARAM  : l'adresse de la structure principale                              */
/* RETOUR : Renvoie 0 ou 1 si la fonction sauvegarde_score_ASCII rencontre un */
/*          problème                                                          */

int		fin_de_jeu_graphique(principal *donnee);
/* BUT    : Demande à l'utilisateur s'il veut enregistrer son score et        */
/*          l'enregistre si oui dans le fichier score.txt                     */
/* PARAM  : adresse de la structure principale                                */
/* RETOUR : Renvoie 1 si le fichier score.txt n'est pas accessible et 0 sinon */

int		ft_puterror(int type_error);
/* BUT    : Affiche le type d'erreur sur la sortie d'erreur                   */
/* PARAM  : type_error => entier décidant du type d'erreur                    */
/* RETOUR : 1 pour indiquer un problème sur le retour de la fonction main     */

int		ft_strchr(char *s1, char c);
/* BUT    : Cherche un charactère précis dans une chaîne donnée               */
/* PARAM  : s => chaîne de charactère dont on veut trouvé un charactère       */
/*          c => charactère que l'on veut retrouvé dans la chaîne             */
/* RETOUR : retourne l'indice si il y a une occurence dans la chaîne sinon -1 */

int		ft_strrchr(char *s1, char c);
/* BUT    : Cherche un charactère précis dans une chaîne donnée en commençant */
/*          par la fin de la chaine                                           */
/* PARAM  : s => chaîne de charactère dont on veut trouvé un charactère       */
/*          c => charactère que l'on veut retrouvé dans la chaîne             */
/* RETOUR : retourne l'indice si il y a une occurence dans la chaîne sinon -1 */

int		ft_strcmp(char *s1, char *s2);
/* BUT    : Détermine si les chaines de charactères sont identiques ou non    */
/* PARAM  : s1 => chaine de charactère à comparer                             */
/*          s2 => chaine de charactère à comparer                             */
/* RETOUR : Renvoi 0 si les chaines sont identiques sinon la diffèrence       */

int		ft_strlen(char *s);
/* BUT    : Calcule la taille d'une chaîne de charactère                      */
/* PARAM  : s => chaîne de charactère dont on veut connaître la taille        */
/* RETOUR : retourne la taille trouvé lors du parcours                        */

int		parsing_enter(char **av, int ac, principal *donnee);
/* BUT    : Informe la fonction main si les arguments reçus sont justes et    */
/*          sinon le type d'erreur trouvé                                     */
/* PARAM  : av     => tableau de chaîne de charactère contenant les arguments */
/*                    du programme                                            */
/*          ac     => taille du tableau av et nombre d'argument + 1           */
/*          donnee => adresse de la structure principale                      */
/* RETOUR : retourne 0 s'il y a une mauvaise option 1 s'il manque un argument */
/*          et -1 si l'allocation mémoire à échouer                           */

int		quitte_graphique(principal *donnee);
/* BUT    : Quitte la fenetre ainsi que le jeu tout en demandant à l'user si  */
/*          il veut sauvegarder sa partie                                     */
/* PARAM  : l'adresse de la structure principale                              */
/* RETOUR : Renvoie 1 si la sauvegarde échoue et 0 sinon                      */

int		sauvegarde_tab(principal *donnee);
/* BUT    : Sauvegarde la grille du jeu dans un fichier du dossier save       */
/* PARAM  : l'adresse de la structure principale                              */
/* RETOUR : Renvoie 1 si l'ouverture/création d'un fichier est impossible et 0*/
/*          sinon                                                             */

int		start_game(principal *donnee);
/* BUT    : Appelle les fonctions initialisants le jeu et le démarre si       */
/*          l'initialisation a réussi                                         */
/* PARAM  : adresse de la structure princiale                                 */
/* RETOUR : Renvoie le type d'erreur au programme principale pour informer    */
/*          l'utilisateur le type de problème rencontrer                      */

int		test_entrer_coord(principal *donnee);
/* BUT    : Test si les coordonnées entrer par l'utilisateur sont valides et  */
/*          affiche soit en ascii ou bien en gaphique si c'est faux           */
/* PARAM  : L'adresse de la structure principal                               */
/* RETOUR : Renvoi 1 s'il les coordonnées sont fausses et 0 sinon             */


void	conv_position_win_tab(principal *donnee, int boo);
/* BUT   : Converti la position du clique à une coordonnée de la grille du jeu*/
/* PARAM : donnee => adresse de la structure principale                       */
/*         boo    => entier étant soit 1 déterminant un conversion des        */
/*                   coordonnées de la première case et 0 pour la deuxième    */

void	delete_struct(principal *donnee);
/* BUT   : Libère l'espace mémoire si elle a été prise de la structure        */
/* PARAM : adresse de la structure principale                                 */

void	echangeEntier(int *a, int *b);
/* BUT : Echange les valeurs de deux entiers                                  */
/* PARAM : a => l'adresse du premier entier à échanger                        */
/*         b => l'adresse du second entier à échanger                         */

void	initialisation(principal *nw);
/* BUT    : Initialise la structure principal du programme                    */
/* PARAM  : L'adresse de la structure principal pour la pouvoir la modifier   */
/* RETOUR : Aucun retour car aucune erreur possible dans le déroulement de    */
/*          cette fonction et une modification par adresse                    */

void	joue_ASCII(principal *donnee);
/* BUT   : Demande les coordonnées des cases que veux selectionner            */
/*         l'utilisateur                                                      */
/* PARAM : adresse de la structure principal                                  */

void	remake_tab(principal *donnee, int ligne, int colonne);
/* BUT   : Descend d'un indice toute les valeurs de la colonne et le premier  */
/*         devient un entier aléatoire compris entre -max et max              */
/* PARAM : donnee  => adresse de la structure principale                      */
/*         ligne   => position de la ligne où débuter                         */
/*         colonne => position de la colonne qu'il faut modifier              */

void	scanborne(int *a, int min, int max);
/* BUT   : Demande à l'utilisateur un entier compris entre min et max         */
/* PARAM : a   => adresse de l'entier à saisir                                */
/*         min => entier minimum accepté                                      */
/*         max => entier maximum accepté                                      */

void	select_case(principal *donnee, int y, int x, int taille);
/* BUT    : Affiche en graphique un rectangle bleu pour afficher la case      */
/*          selectionner                                                      */
/* PARAM  : donnee => adresse de la structure principal                       */
/*          x      => coordonnée de l'abscisse de la case selectionnée        */
/*          y      => coordonnée de l'ordonnée de la case selectionnée        */
/*          taille => taille de la grille                                     */

void	select_ligne(principal *donnee);
/* BUT   : Permet de récupérer le segment selectionné par l'utilisateur       */
/*         et d'afficher ce segment en graphique ainsi que de le sommer       */
/* PARAM : L'adresse de la structure principale                               */

#endif
