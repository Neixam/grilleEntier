/* ************************************************************************** */
/*                                                                            */
/*                                 error.c                                    */
/*                                                                            */
/* ************************************************************************** */

#include "grient.h"

int		ft_puterror(int type_error)
/*          Affiche le type d'erreur sur la sortie d'erreur                   */
/*                                                                            */
/*  PARAM  : -type_error => entier décidant du type d'erreur                  */
/*  RETOUR : 1 pour indiquer un problème sur le retour de la fonction main    */
{
	if (type_error == 1)
		fprintf(stderr, "Manque d'option: il faut obligatoirement 2 options compatibles et un nom de fichier\nusage: ./grilleEntier [-a] ou [-g] [-c] ou [-l] [FILE]\n");
	if (type_error == 0)
		fprintf(stderr, "Mauvaise option\nusage: ./grilleEntier [-agcl] [FILE]\n");
	if (type_error == -1)
		fprintf(stderr, "Impossible d'accéder à la mémoire verfier si l'accès est autorisé\n");
	return (1);
}
