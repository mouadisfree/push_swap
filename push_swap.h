/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:40:33 by mokatfi           #+#    #+#             */
/*   Updated: 2025/04/01 18:32:54 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				index;
	int				content;
	struct s_list	*next;
}					t_list;

typedef struct s_list2
{
	int				max_index;
	int				middle;
	int				start;
	int				end;
	int				offset;
	int				chunk;
}					t_list2;

void				putting_max_index_at_top(t_list **b, int index);
void				pushing_back_to_a(t_list **a, t_list **b, t_list2 val);
void				expanding_chunk(t_list2 *val);
void				checking_stack_a(t_list **a, t_list **b, t_list2 val);
void				sorting_100(t_list **a, t_list **b);
void				putting_max_index_at_top_ff(t_list **b, int index);
void				pushing_back_to_a_ff(t_list **a, t_list **b, t_list2 val);
void				checking_stack_a_ff(t_list **a, t_list **b, t_list2 val);
void				expanding_chunk_ff(t_list2 *val);
void				sorting_500(t_list **a, t_list **b);
void				sorting_4_20(t_list **a, t_list **b);
int					get_max_index_position_in_b(t_list *b, int max);
int					get_last_index_in_a(t_list *a);
t_list				*minimum_unindexed_value(t_list *a);
void				ranking_values(t_list *a);
void				ft_putstr(char *s);
size_t				ft_strlen(const char *s);
int					ft_lstsize(t_list *stack);
int					checking_if_sorted(t_list *a);
void				ft_ra(t_list **a, int k);
void				ft_rra(t_list **a, int k);
void				ft_pa(t_list **a, t_list **b);
void				ft_rrb(t_list **b, int k);
void				ft_rb(t_list **b, int k);
void				ft_sb(t_list *b, int k);
void				ft_sa(t_list *a, int k);
void				ft_pb(t_list **a, t_list **b);
void				ft_error(char *a);
long				ft_atoi(char *str);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(int content);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					count_word(char const *str, char c);
char				**ft_split(char const *s, char c);
int					get_minimum_value(t_list *stack);
int					get_minimum_index(t_list *a, int min);
void				sorting_2(t_list **a);
void				sorting_3_extra(t_list **a);
void				sorting_3(t_list **a);
int					ft_checking_double(t_list **a, int i);
void				checking_sign(char *s, t_list **a);
void				putting_to_stack(char **av, int i, t_list **a, char **s);
void				free_stack(t_list **stack);
void				ft_choosing_sorting_function(t_list **a, t_list **b);
void				ft_calling_nodes(t_list **a, char **s, char *c);

#endif