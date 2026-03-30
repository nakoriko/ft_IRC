/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:33:12 by nakoriko          #+#    #+#             */
/*   Updated: 2026/03/30 18:00:45 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NAT
#include "../../include/Server.hpp"
#include "../../include/Client.hpp"
#include "../../include/Commands.hpp"

//joint to channel

void cmd_join (Server &server, Client &client, const std::vector<std::string> &params, const std::string &trailing) {
	(void) server;
	(void) client;
	(void) params;
	(void) trailing;
	//1. Check params (se vuoo - inviare il messaggio)
	//2. Get channel name (dal params)
	//3. Check o create (server._channels)
	//4. Se il canale si crea - client diventa operatore
	//5. Check modes of channel (bools in channel) e se condizioni di client e channel corrispondono
	//6. Add cliente in channel channel->addMember(&client) e addOperator(&client) - se e' nuovo
	//7. Eliminare dal _invited (channel->removeFromInvited(client.getNickname)) - INVITE puo essere utilizzato finche non e stato fatto JOIN
	//8. Inviare mesaggio al client
	//9. Aggiornarre tutti ( a parte client esistente), che c'e un nuovo membro (channel->broadcast())
	//10. Inviare tema di canale al cliente
	//11. Inviare elenco di member (forse no)
}