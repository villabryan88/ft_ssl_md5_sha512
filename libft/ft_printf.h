/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:32:06 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/02 15:58:27 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <libft.h>

typedef struct			s_arg
{
	char				type;
	char				null;
	char				left;
	char				plus;
	char				space;
	char				hash;
	char				zero;
	int					width;
	int					prec;
	char				h;
	char				l;
	char				bigl;
	char				ll;
	char				hh;
	char				base;
	char				*string;
	long long			value;
}						t_arg;

typedef union			u_float
{
	double				flt;
	unsigned long long	num;
	unsigned char		byte[8];
}						t_float;

typedef union			u_ldblfloat
{
	long double			ldbl;
	unsigned long long	num[2];
	unsigned char		byte[16];
}						t_ldblfloat;

int						count_args(char *s);
int						parse_args(char *s, t_arg *list, va_list ap);
char					*ft_itoa_base(long long n, t_arg *arg);
int						ft_printf(char *s, ...);
int						is_spec(char c);
int						flip_flags(char **c, t_arg *arg);
char					*ft_strjoin_free(char *s1, char *s2, int f1, int f2);
int						pop_args(char *s, char *new, t_arg *list);
char					*flt(t_arg *arg, va_list ap);
void					multiply_two(char **s);
void					divide_two(char **s);
char					*main_logic(unsigned long long val, int base,
									int prec, int sign);
char					*di(t_arg *arg, int base, va_list ap);
char					*oux(t_arg *arg, int base, va_list ap);
void					adj_width(t_arg *arg);
void					do_hash(t_arg *arg);
int						cont_make_string(t_arg *arg, va_list ap);
void					multiply_two(char **s);
void					divide_two(char **s);
void					round_up(char **s);
void					float_width_hash(t_arg *arg, int neg);
void					format_float(t_arg *arg);
int						double_sign(t_arg *arg, int neg);
int						is_dioux(char c);
void					do_prec(t_arg *arg);
int						is_di(char c);
#endif
