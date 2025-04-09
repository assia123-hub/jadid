/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschalh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:31:50 by aschalh           #+#    #+#             */
/*   Updated: 2025/04/09 21:17:19 by aschalh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

char	**ft_split(char const *s, char c);
int		update_atoi(const char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
void	check_arguments(char *av);
void	check_double(t_list **a);
void	sa(t_list **lst);
void	sb(t_list **lst);
void	ss(t_list **lst, t_list **tls);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	add_node_last(t_list **lst, t_list *new);
void	ra(t_list **a);
void	rb(t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
int		wach_mertba(t_list **lst);
void	sort100(t_list **a, t_list **b);
int		return_number(t_list *lst);
void	sort_tab(int *k, int i);
int		*change_array(t_list **a);
int		search(int *k, t_list **a, int start, int end);
int		assia(int i, t_list **b);
t_list	*last_node(t_list *lst);
int		position(t_list **a, int i);
void	sort500(t_list **a, t_list **b);
t_list	*new_node(int content);
int		ft_isdigit(int c);
char	*join(char **av);
void	reverse_rotate(t_list **stack);
void	rotate(t_list **stack);
void	swap(t_list **stack);
void	check_errors(void);
void	range_update(int *s, int *e, int offset, int max);
void	push_a(t_list **a, t_list **b, int *tab, int mid);
void	push_b(t_list **a, t_list **b, int *tab);
void	sort_two(t_list **a);
void	sort_three(t_list **a);
void	sort_four_five(t_list **a, t_list **b);
void	sort_small(t_list **a, t_list **b);
void	check_digits(char *str);

#endif
