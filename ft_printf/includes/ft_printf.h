/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:19:37 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/26 22:12:29 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# define NO_ALLOC_MODE 0
# define ALLOC_MODE 1
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_flag
{
	char		precision;
	char		width;
	long		v_precision;
	long		v_width;
	char		space;
	char		minus;
	char		plus;
	char		zero;
	char		hashtag;
	char		blank;
	char		identifier;
	char		is_positive;
	char		zero_value;
	const char	*flag_end_index;
}	t_flag;

int			ft_printf(const char *format, ...) \
__attribute__ ((format (printf, 1, 2)));
char		*_pf_add_hashtag_option(t_flag *flag, char **s);
char		*_pf_add_plus_option(t_flag *flag, char **s);
char		*_pf_add_blank_option(t_flag *flag, char **s);
char		*_pf_add_flag_characters_options(t_flag *flag, char **s);
char		*_pf_add_padding_build_hex(t_flag *flag, char **s, char *padding);
char		*_pf_add_padding_build_signed_int(char **s, char *padding);
char		*_pf_add_padding_build(t_flag *flag, char **s, char *padding);
char		*_pf_build_padding(t_flag *flag, char *s, char **padding);
char		*_pf_add_padding(t_flag *flag, char **s);
int			_pf_is_hex_shape(t_flag *flag);
char		*_pf_build_precision(t_flag *flag, char *s);
char		*_pf_add_precision_build(char **s, char *build);
char		*_pf_add_precision(t_flag *flag, char **s);
char		*_pf_convert_int(t_flag *flag, int n);
char		*_pf_convert_unsigned_int(t_flag *flag, unsigned int n);
char		*_pf_convert_char(t_flag *flag, unsigned char c);
char		*_pf_convert_string(char *s);
char		*_pf_convert_perc(void);
char		*_pf_convert_addr(t_flag *flag, unsigned long n);
char		*_pf_convert_hex(t_flag *flag, unsigned int n);
char		*_pf_convert_octal(t_flag *flag, unsigned int n);
char		*_pf_convert_argument(t_flag *flag, va_list ap, char **s);
char		*_pf_add_hex_prefix(t_flag *flag, char **s);
const char	*_pf_convert_main(const char *format, va_list ap, size_t *total);
int			_pf_parse_leading_symbol(const char **to_parse);
void		_pf_parse_flag_characters(const char **to_parse_addr, t_flag *flag);
void		_pf_parse_width_specs(const char **to_parse_addr, t_flag *flag);
void		_pf_parse_precision_specs(const char **to_parse_addr, t_flag *flag);
int			_pf_parse_type_specifier(const char **to_parse, t_flag *flag);
size_t		_pf_print_then_advance(const char *format, size_t *total);
t_flag		*_pf_free_flag_structure(t_flag **flag);
t_flag		*_pf_init_flag_structure(void);
t_flag		*_pf_parse_flag_directives(const char *to_parse, char mode);
const char	*_pf_post_conversion_job(t_flag *flag, char *cvarg, size_t *total);
char		*_pf_add_minus_sign_back(t_flag *flag, char **s);

#endif
