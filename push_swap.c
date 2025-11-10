/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:37:16 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/10 14:41:50 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Indices ordenados --> bit (x) == 1 -> B, else A. B --> A
bits = 0;
while ((max_index >> bits) != 0)
	bitss++;
//Si  (n >> i) & 1 --> pb
//Si  (n >> i) & 0 --> ra
//Despues, pa hasta vaciar B y i+++