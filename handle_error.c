/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:38:45 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/14 12:53:29 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//No puede tener duplicados el stack_a, tampoco entradas ivalidas (letras, simbolos, etc), argumentos no enteros, superiores a INT_MAX o inferiores a INT_MIN.
//Todo ello debe imprimir un Error \n
//Tengo que separar los printfs de las operaciones, meter un parametro mas o hacer una funcion interna extra.
//If A is ordered, no hacer nada.
//If A <= 5 crear sort_small_stack, else radix sort.
//Cambiar el printf por mi ft_printf

int duplicate(int c, t_node **stack)
{
    t_node *temp;

    temp = *stack;
    while (temp)
    {
        if (c == temp->value)
            return (1);
        temp = temp->next;
    }
    return (0);
}

int checker(t_node **stack)
{
    t_node  *temp;
    t_node  *next;

    temp = *stack;
    while (temp)
    {
        next = temp->next;
        while (next)
        {
            if (temp->value == next->value)
                return (1);
            next = next->next;
        }
        temp = temp->next;
    }
    return (0);
}

int is_ordered(t_node *stack)
{
    t_node  *temp;

    temp = stack;
    while (temp && temp->next)
    {
        if (temp->value > temp->next->value)
        {
            
            return (0);
        }
        temp = temp->next;
    }
    return (1);
}
//menor a mayor