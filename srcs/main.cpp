/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:00:48 by nakoriko          #+#    #+#             */
/*   Updated: 2026/03/25 12:04:13 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Status: row


int main(int ac, char **av) {

	if (ac != 3) {
		//1.check port e passwd
	}
	//2.parse_args(**av: port + password);
	//3. create server: socket (gets fd) + bind(set the port) + listen(starts waiting mode) - ALL NON blocks)
	//4. run server (loop + server actions + clients actions(parse commands))
	return 0;
}