/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:53:38 by vbonnard          #+#    #+#             */
/*   Updated: 2025/05/21 11:38:22 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// ---------------- Conversion functions --------------------------------------

/**
 * Convertit une chaîne de caractères en entier.
 *
 * @param nptr La chaîne de caractères à convertir.
 * @return La valeur entière représentée par la chaîne.
 */
int					ft_atoi(const char *nptr);

/**
 * Convertit un entier en chaîne de caractères.
 *
 * @param n L'entier à convertir.
 * @return La représentation sous forme de chaîne de l'entier.
 */
char				*ft_itoa(int n);

/**
 * Convertit un entier long en chaîne de caractères.
 *
 * @param n L'entier long à convertir.
 * @return La représentation sous forme de chaîne de l'entier long.
 */
char				*ft_litoa(long n);

// ---------------- Character type functions ----------------------------------
/**
 * Vérifie si le caractère donné est alphabétique.
 *
 * @param c Le caractère à vérifier.
 * @return 1 si le caractère est alphabétique, 0 sinon.
 */
int					ft_isalpha(int c);

/**
 * Vérifie si le caractère donné est un chiffre.
 *
 * @param c Le caractère à vérifier.
 * @return 1 si le caractère est un chiffre, 0 sinon.
 */
int					ft_isdigit(int c);

/**
 * Vérifie si le caractère donné est alphanumérique (lettre ou chiffre).
 *
 * @param c Le caractère à vérifier.
 * @return 1 si le caractère est alphanumérique, 0 sinon.
 */
int					ft_isalnum(int c);

/**
 * Vérifie si le caractère donné est un caractère ASCII valide.
 *
 * @param c Le caractère à vérifier.
 * @return 1 si le caractère est ASCII, 0 sinon.
 */
int					ft_isascii(int c);

/**
 * Vérifie si le caractère donné est imprimable (y compris l'espace).
 *
 * @param c Le caractère à vérifier.
 * @return 1 si le caractère est imprimable, 0 sinon.
 */
int					ft_isprint(int c);

/**
 * Convertit un caractère en majuscule.
 *
 * @param c Le caractère à convertir.
 * @return La version majuscule du caractère.
 */
int					ft_toupper(int c);

/**
 * Convertit un caractère en minuscule.
 *
 * @param c Le caractère à convertir.
 * @return La version minuscule du caractère.
 */
int					ft_tolower(int c);

// --------------- Input/Output functions -------------------------------------
/**
 * Écrit un caractère sur un descripteur de fichier.
 *
 * @param c Le caractère à écrire.
 * @param fd Le descripteur de fichier sur lequel écrire.
 */
void				ft_putchar_fd(char c, int fd);

/**
 * Écrit une chaîne de caractères sur un descripteur de fichier.
 *
 * @param s La chaîne de caractères à écrire.
 * @param fd Le descripteur de fichier sur lequel écrire.
 */
void				ft_putstr_fd(char *s, int fd);

/**
 * Écrit une chaîne de caractères suivie d'un
 * retour à la ligne sur un descripteur de fichier.
 *
 * @param s La chaîne de caractères à écrire.
 * @param fd Le descripteur de fichier sur lequel écrire.
 */
void				ft_putendl_fd(char *s, int fd);

/**
 * Écrit un entier sous forme de chaîne
 * de caractères sur un descripteur de fichier.
 *
 * @param n L'entier à écrire.
 * @param fd Le descripteur de fichier sur lequel écrire.
 */
void				ft_putnbr_fd(int n, int fd);

// --------------- List functions ---------------------------------------------
/**
 * Ajoute un nouveau nœud à la fin de la liste.
 *
 * @param lst Un pointeur sur la liste.
 * @param new Le nouveau nœud à ajouter.
 */
void				ft_lstadd_back(t_list **lst, t_list *new);

/**
 * Ajoute un nouveau nœud au début de la liste.
 *
 * @param lst Un pointeur sur la liste.
 * @param new Le nouveau nœud à ajouter.
 */
void				ft_lstadd_front(t_list **lst, t_list *new);

/**
 * Supprime tous les nœuds de la liste et libère la mémoire.
 *
 * @param lst Un pointeur sur la liste.
 * @param del Une fonction pour supprimer le contenu de chaque nœud.
 */
void				ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * Supprime un nœud de la liste et libère sa mémoire.
 *
 * @param lst Le nœud à supprimer.
 * @param del Une fonction pour supprimer le contenu du nœud.
 */
void				ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * Parcourt la liste en appliquant une fonction au contenu de chaque nœud.
 *
 * @param lst La liste à parcourir.
 * @param f La fonction à appliquer à chaque nœud.
 */
void				ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * Renvoie le dernier nœud de la liste.
 *
 * @param lst La liste à parcourir.
 * @return Le dernier nœud de la liste.
 */
t_list				*ft_lstlast(t_list *lst);

/**
 * Crée une nouvelle liste en appliquant une fonction
 * au contenu de chaque nœud de la liste d'origine.
 *
 * @param lst La liste à parcourir.
 * @param f La fonction à appliquer au contenu de chaque nœud.
 * @param del Une fonction pour supprimer le contenu des nœuds en cas d'erreur.
 * @return Une nouvelle liste avec le contenu transformé,
 * ou NULL en cas d'échec.
 */
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/**
 * Crée un nouveau nœud contenant le contenu donné.
 *
 * @param content Le contenu du nouveau nœud.
 * @return Le nouveau nœud, ou NULL en cas d'échec.
 */
t_list				*ft_lstnew(void *content);

/**
 * Renvoie la taille de la liste (nombre de nœuds).
 *
 * @param lst La liste à mesurer.
 * @return La taille de la liste.
 */
int					ft_lstsize(t_list *lst);

// --------------- Memory functions -------------------------------------------
/**
 * Remplit les 'n' premiers octets de la zone mémoire
 * pointée par 's' avec la valeur 'c'.
 *
 * @param s La zone mémoire à modifier.
 * @param c La valeur à copier.
 * @param n Le nombre d'octets à définir.
 * @return Un pointeur sur la zone mémoire.
 */
void				*ft_memset(void *s, int c, size_t n);

/**
 * Remplit les 'n' premiers octets de la zone mémoire
 * pointée par 's' avec des zéros.
 *
 * @param s La zone mémoire à effacer.
 * @param n Le nombre d'octets à mettre à zéro.
 */
void				ft_bzero(void *s, size_t n);

/**
 * Copie 'n' octets depuis la zone mémoire 'src' vers
 * la zone mémoire 'dest'.
 *
 * @param dest La zone mémoire de destination.
 * @param src La zone mémoire source.
 * @param n Le nombre d'octets à copier.
 * @return Un pointeur sur la zone mémoire de destination.
 */
void				*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * Copie 'n' octets depuis la zone mémoire 'src' vers la zone mémoire 'dest',
 * en gérant le chevauchement.
 *
 * @param dest La zone mémoire de destination.
 * @param src La zone mémoire source.
 * @param n Le nombre d'octets à copier.
 * @return Un pointeur sur la zone mémoire de destination.
 */
void				*ft_memmove(void *dest, const void *src, size_t n);

/**
 * Recherche la première occurrence du caractère 'c' dans la zone mémoire 's'.
 *
 * @param s La zone mémoire à parcourir.
 * @param c Le caractère à rechercher.
 * @param n Le nombre d'octets à analyser.
 * @return Un pointeur sur la première occurrence de 'c',
	ou NULL si non trouvée.
 */
void				*ft_memchr(const void *s, int c, size_t n);

/**
 * Compare les 'n' premiers octets de deux zones mémoires.
 *
 * @param s1 La première zone mémoire.
 * @param s2 La deuxième zone mémoire.
 * @param n Le nombre d'octets à comparer.
 * @return 0 si les zones sont égales, une valeur positive ou négative sinon.
 */
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * Alloue de la mémoire pour un tableau de 'nmemb'
 * éléments de 'size' octets chacun.
 *
 * @param nmemb Le nombre d'éléments.
 * @param size La taille de chaque élément.
 * @return Un pointeur sur la mémoire allouée.
 */
void				*ft_calloc(size_t nmemb, size_t size);

/**
 * Réalloue la mémoire pointée par 'ptr' pour une nouvelle taille.
 *
 * @param ptr Le pointeur vers la mémoire existante.
 * @param new_size La nouvelle taille de la mémoire.
 * @return Un pointeur sur la mémoire réallouée.
 */
void				*ft_realloc(void *ptr, size_t new_size);

// --------------- Number functions -------------------------------------------
/**
 * Renvoie le nombre de chiffres dans un entier long.
 *
 * @param n L'entier long.
 * @return Le nombre de chiffres.
 */
long				ft_long_size(long n);

/**
 * Renvoie le nombre de chiffres dans un entier.
 *
 * @param n L'entier.
 * @return Le nombre de chiffres.
 */
int					ft_int_size(int n);

// --------------- String functions -------------------------------------------
/**
 * @brief Calcule la longueur d'une chaîne de caractères.
 *
 * @param s La chaîne de caractères.
 * @return La longueur de la chaîne (ne compte pas le caractère nul '\0').
 */
size_t				ft_strlen(const char *s);

/**
 * @brief Copie une chaîne de caractères dans une autre,
 * en respectant une taille maximale.
 *
 * @param dst Le tampon de destination.
 * @param src La chaîne source à copier.
 * @param size La taille maximale à copier (inclut le caractère nul).
 * @return La longueur totale de la chaîne source.
 */
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Concatène une chaîne source à une chaîne de destination,
 * en respectant une taille maximale.
 *
 * @param dst La chaîne de destination.
 * @param src La chaîne source à concaténer.
 * @param size La taille maximale de la chaîne de destination.
 * @return La longueur totale de la chaîne que l'on a essayé de créer.
 */
size_t				ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Recherche la première occurrence d'un caractère dans une chaîne,
 * limitée aux n premiers caractères.
 *
 * @param s La chaîne à analyser.
 * @param c Le caractère à rechercher.
 * @param n Le nombre maximal de caractères à analyser.
 * @return Un pointeur sur la première occurrence de c dans la chaîne,
 * ou NULL si non trouvé.
 */
char				*ft_strnchr(const char *s, int c, size_t n);

/**
 * @brief Recherche la première occurrence d'un caractère dans une chaîne.
 *
 * @param s La chaîne à analyser.
 * @param c Le caractère à rechercher.
 * @return Un pointeur sur la première occurrence de c dans la chaîne,
 * ou NULL si non trouvé.
 */
char				*ft_strchr(const char *s, int c);

/**
 * @brief Duplique une sous-chaîne de taille limitée.
 *
 * Alloue et copie au maximum `size` octets depuis la chaîne source,
 * sans forcément s'arrêter sur `\0`. Fonction utile pour copier
 * des chaînes partielles.
 *
 * @param s Chaîne source.
 * @param size Nombre de caractères à dupliquer.
 * @return Pointeur vers la nouvelle chaîne, ou NULL en cas d'erreur.
 *
 * @note Cette fonction devrait idéalement être placée dans libft.
 */
char	*ft_strldup(const char *s, size_t size);

/**
 * @brief Recherche la dernière occurrence d'un caractère dans une chaîne.
 *
 * @param s La chaîne à analyser.
 * @param c Le caractère à rechercher.
 * @return Un pointeur sur la dernière occurrence de c dans la chaîne,
 * ou NULL si non trouvé.
 */
char				*ft_strrchr(const char *s, int c);

/**
 * @brief Compare deux chaînes de caractères.
 *
 * @param s1 La première chaîne à comparer.
 * @param s2 La deuxième chaîne à comparer.
 * @return Un entier négatif si s1 est inférieure à s2, 0 si elles sont égales,
 * un entier positif si s1 est supérieure à s2.
 */
int					ft_strcmp(const char *s1, const char *s2);

/**
 * @brief Compare les n premiers caractères de deux chaînes.
 *
 * @param s1 La première chaîne à comparer.
 * @param s2 La deuxième chaîne à comparer.
 * @param n Le nombre maximal de caractères à comparer.
 * @return Un entier négatif si les n premiers
 * caractères de s1 sont inférieurs à ceux de s2,
 * 0 s'ils sont égaux, un entier positif sinon.
 */
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Copie jusqu'à len caractères de la chaîne src vers dst.
 *
 * Cette fonction copie au maximum len caractères de la chaîne src vers dst.
 * Si src a moins de len caractères, le reste de dst est rempli avec des
 * caractères '\0'. Sinon, dst n'est pas terminé par un caractère nul.
 *
 * @param dst Le tampon de destination où le contenu doit être copié.
 * @param src La chaîne source à copier.
 * @param len Le nombre maximum de caractères à copier de src.
 * @return Un pointeur vers la chaîne de destination dst.
 */
char				*ft_strncpy(char *dst, const char *src, size_t len);

/**
 * @brief Duplique une chaîne de caractères jusqu'à une longueur spécifiée.
 *
 * Cette fonction alloue de la mémoire et crée une nouvelle chaîne de caractère
 * qui est une copie des `n` premiers caractères de la chaîne `s`. La nouvelle
 * chaîne est terminée par un caractère nul (`\0`).
 *
 * @param s La chaîne de caractères source à dupliquer.
 * @param n Le nombre maximum de caractères à dupliquer de la chaîne source.
 * @return Un pointeur vers la nouvelle chaîne de caractères dupliquée, ou NULL
 *         si l'allocation de mémoire échoue.
 */
char				*ft_strndup(const char *s, size_t n);

/**
 * @brief Recherche une sous-chaîne dans une chaîne,
 * limitée aux n premiers caractères.
 *
 * @param big La chaîne principale.
 * @param little La sous-chaîne à rechercher.
 * @param len Le nombre maximal de caractères à analyser.
 * @return Un pointeur sur la première occurrence de little dans big,
 * ou NULL si non trouvé.
 */
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

/**
 * @brief Crée une nouvelle chaîne qui est une copie de la chaîne donnée.
 *
 * @param s La chaîne à copier.
 * @return Un pointeur sur la nouvelle chaîne
 * allouée, ou NULL si l'allocation échoue.
 */
char				*ft_strdup(const char *s);

/**
 * @brief Extrait une sous-chaîne d'une chaîne, en commençant à un index donné.
 *
 * @param s La chaîne d'origine.
 * @param start L'index de départ de la sous-chaîne.
 * @param len La longueur de la sous-chaîne à extraire.
 * @return La sous-chaîne extraite, ou NULL si l'allocation échoue.
 */
char				*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Concatène deux chaînes de caractères dans une nouvelle allocation.
 *
 * Alloue une nouvelle chaîne contenant `s1` suivi de `s2`. Si un des deux
 * pointeurs est NULL, duplique l’autre. Ne libère pas les entrées.
 *
 * @param s1 Première chaîne à concaténer.
 * @param s2 Deuxième chaîne à concaténer.
 * @return Chaîne nouvellement allouée, ou NULL si erreur.
 *
 * @note À déplacer dans la libft.
 */
char				*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Supprime les caractères spécifiés dans un ensemble depuis une chaîne.
 *
 * @param s1 La chaîne à traiter.
 * @param set L'ensemble des caractères à supprimer.
 * @return La chaîne résultante, ou NULL si l'allocation échoue.
 */
char				*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Divise une chaîne en un tableau de
 * sous-chaînes séparées par un délimiteur.
 *
 * @param s La chaîne à diviser.
 * @param c Le caractère délimiteur.
 * @return Un tableau de sous-chaînes, ou NULL si l'allocation échoue.
 */
char				**ft_split(char const *s, char c);

/**
 * @brief Applique une fonction à chaque caractère
 * d'une chaîne pour retourner une nouvelle chaîne.
 *
 * @param s La chaîne à traiter.
 * @param f La fonction à appliquer à chaque caractère de la chaîne.
 * @return La chaîne résultante après l'application de la fonction,
 * ou NULL si l'allocation échoue.
 */
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applique une fonction à chaque caractère d'une chaîne,
 * en modifiant la chaîne sur place.
 *
 * @param s La chaîne à modifier.
 * @param f La fonction à appliquer à chaque caract����re de la chaîne.
 */
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

// --------------- Printf Defines ---------------------------------------------
// Boolean
# define FALSE 0
# define TRUE 1

// Flags
# define FLAG_MINUS '-'
# define FLAG_PLUS '+'
# define FLAG_SPACE ' '
# define FLAG_HASH '#'
# define FLAG_ZERO '0'

// Printf Structs
typedef struct s_format
{
	int				flag_minus;
	int				flag_plus;
	int				flag_space;
	int				flag_hash;
	int				flag_zero;
	int				width;
	int				precision;
	char			specifier;
}					t_format;

// --------------- Printf Functions -------------------------------------------
/**
 * Implémentation personnalisée de la fonction printf.
 *
 * @param format La chaîne de format spécifiant le format de sortie.
 * @param ... Les arguments variables
 * correspondant aux spécificateurs de format.
 * @return Le nombre total de caractères imprimés.
 */
int					ft_printf(const char *format, ...);

/**
 * Initialise la structure de formatage
 * en fonction de la chaîne de format donnée.
 *
 * @param ptr Un pointeur vers la chaîne de format.
 * @return Un pointeur vers la structure de format initialisée.
 */
t_format			*init_format(const char **ptr);

/**
 * Écrit un caractère sur la sortie standard et
 * renvoie le nombre de caractères imprimés.
 *
 * @param c Le caractère à imprimer.
 * @return Le nombre de caractères imprimés (toujours 1).
 */
int					ft_putchar_size(char c);

/**
 * Écrit une chaîne sur la sortie standard et
 * renvoie le nombre de caractères imprimés.
 *
 * @param str La chaîne à imprimer.
 * @return Le nombre de caractères imprimés.
 */
int					ft_putstr_size(char *str);

/**
 * Convertit un nombre en sa représentation hexadécimale sous forme de chaîne.
 *
 * @param nb Le nombre à convertir.
 * @param base La base à utiliser pour la
 * conversion (par exemple, "0123456789abcdef").
 * @return La représentation hexadécimale du nombre sous forme de chaîne.
 */
char				*convert_to_hexa(unsigned long long nb, char *base);

/**
 * Imprime un caractère avec le format spécifié et
 * renvoie le nombre de caractères imprimés.
 *
 * @param format La structure de formatage contenant
 * les informations de mise en forme.
 * @param c Le caractère à imprimer.
 * @return Le nombre de caractères imprimés.
 */
int					print_c(t_format *format, char c);

/**
 * Imprime une chaîne avec le format spécifié
 * et renvoie le nombre de caractères imprimés.
 *
 * @param format La structure de formatage
 * contenant les informations de mise en forme.
 * @param str La chaîne à imprimer.
 * @return Le nombre de caractères imprimés.
 */
int					print_s(t_format *format, char *str);

/**
 * Imprime une adresse de pointeur avec le format
 * spécifié et renvoie le nombre de caractères imprimés.
 *
 * @param format La structure de formatage contenant
 * les informations de mise en forme.
 * @param ptr Le pointeur à imprimer.
 * @return Le nombre de caractères imprimés.
 */
int					print_p(t_format *format, void *ptr);

/**
 * Imprime un entier ou un nombre décimal avec le format
 * spécifié et renvoie le nombre de caractères imprimés.
 *
 * @param format La structure de formatage
 * contenant les informations de mise en forme.
 * @param nb Le nombre à imprimer.
 * @return Le nombre de caractères imprimés.
 */
int					print_d_i(t_format *format, int nb);

/**
 * Imprime un entier non signé avec le format
 * spécifié et renvoie le nombre de caractères imprimés.
 *
 * @param format La structure de formatage
 * contenant les informations de mise en forme.
 * @param nb L'entier non signé à imprimer.
 * @return Le nombre de caractères imprimés.
 */
int					print_u(t_format *format, unsigned int nb);

/**
 * Imprime un nombre hexadécimal avec le format
 * spécifié et renvoie le nombre de caractères imprimés.
 *
 * @param format La structure de formatage
 * contenant les informations de mise en forme.
 * @param nb Le nombre à imprimer en hexadécimal.
 * @param is_upper Indique si les lettres
 * hexadécimales doivent être en majuscules.
 * @return Le nombre de caractères imprimés.
 */
int					print_x(t_format *format, unsigned long nb, int is_upper);

/**
 * Formate une chaîne en fonction de la largeur
 * et des drapeaux minus/zero pour le remplissage.
 *
 * @param str La chaîne à formater.
 * @param width La largeur totale pour remplir la chaîne.
 * @param has_minus Indique si le drapeau minus est présent.
 * @param has_zero Indique si le drapeau zero est présent.
 * @return La chaîne formatée avec le remplissage approprié.
 */
char				*formatted_width_minus_zero(char *str, int width,
						int has_minus, int has_zero);

/**
 * Formate une chaîne de nombre en fonction
 * de la précision et des drapeaux plus/espace.
 *
 * @param str La représentation sous forme de chaîne du nombre à formater.
 * @param precision La précision pour formater le nombre.
 * @param has_plus Indique si le drapeau plus est présent.
 * @param has_space Indique si le drapeau espace est présent.
 * @return La chaîne de nombre formatée avec
 * la précision et les drapeaux appropriés.
 */
char				*formatted_number_precision(char *str, int precision,
						int has_plus, int has_space);

// ----------------------------------------------------------------------------

/**
 * @brief Lis depuis le descripteur jusqu'à trouver un saut de ligne.
 *
 * Lis dans un tampon jusqu'à ce qu'un `\n` soit trouvé ou que `read`
 * retourne 0. Le contenu est stocké et concaténé dans `stash`.
 *
 * @param fd Descripteur de fichier à lire.
 * @param stash Chaîne contenant les données lues précédemment.
 * @return `stash` mis à jour avec les nouvelles données lues.
 */
char				*read_and_append(int fd, char *stash);

/**
 * @brief Extrait une ligne complète (terminée par '\n') depuis le stash.
 *
 * Copie les caractères depuis le début de `stash` jusqu’à (et incluant)
 * le premier `\n` trouvé. Alloue dynamiquement la nouvelle ligne.
 *
 * @param stash Chaîne contenant le contenu en attente de traitement.
 * @return Ligne extraite, ou NULL si aucune ligne complète.
 */
char				*extract_line(char *stash);

/**
 * @brief Coupe le `stash` en supprimant la ligne déjà extraite.
 *
 * Crée une nouvelle chaîne contenant le reste du `stash` après
 * la première ligne (celle extraite). Libère l’ancien `stash`.
 *
 * @param stash Chaîne contenant la ligne extraite + le reste.
 * @return Nouveau stash (le reste uniquement), ou NULL si vide.
 */
char				*trim_stash(char *stash);

/**
 * @brief Lit une ligne dans un fichier, comme le demande le projet 42.
 *
 * Fonction principale qui combine lecture, extraction et gestion de
 * la mémoire pour retourner une ligne à la fois depuis un fichier.
 *
 * @param fd Descripteur de fichier à lire.
 * @return Ligne lue (incluant '\n' si présent), ou NULL à EOF ou erreur.
 */
char				*get_next_line(int fd);

#endif
