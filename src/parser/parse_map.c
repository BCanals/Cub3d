/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 22:22:30 by bizcru            #+#    #+#             */
/*   Updated: 2026/10/04 11:55:35 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

// Tenim una array (directament a l'struct final que es llegirà

/* static int load_map
S'encarregarà de traspassar les línies de l'arxiu directament a l'struct final.
-Com ho fem per reservar suficient memòria?
Sabem que el mapa queda al final de l'arxiu, així que podem mirar si es pot copiar l'estat
de read, en plan com "guardar" des d'on estic llegint l'arxiu i passar-li un gnl sense perdre la referència.
Així puc comptar quantes línies em queden.
Pot haver-hi un error que siguin línies blanques a mig mapa, hauria de donar error.
Clarament hi haurà una funció count lines hahah que revisi això de les línies en blanc i digui quantes línies caldran.
Recordatori que una línia ja estarà carregada a l'struct de parseig.

Important fer-ho amb calloc i deixar una línia en blanc perquè el clean_array hi compta.
*/


/*
   static int check_map_chrs: funció fàcil que revisa si hi ha caràcters no permesos.
 */

// Funció/ns de la flood fill.

int	parse_map(void)
{
	printf("parsing map...\n");

	// load_map carrega el mapa null-terminadament
	// check_map_chrs comprova que tots els caracters siguin correctes
	// do the flood fill
	// done.
	return (1);
}

