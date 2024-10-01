//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/daniel/Stuff/Linux_Stuff/Project_Neo/source/danc.cpp                                                ***//
//***     Header Created: Tue Oct 01 2024                                                                                  ***//
//***     Author: Daniel Haddington at <haddingtondaniel5@gmail.com>                                                       ***//
//***     Copyright (c) 2024 Daniel Haddington                                                                             ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//


# include "../includes/program.hpp"

//-----------------------------------------------------------------------------------------------------------------------------

// {

unsigned long		dc_strlen(const char *c)
{
	unsigned long i;

	i = 0;
	while (c[i])
	{
		i++;
	}
	return (i);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

static char	*dc_malloc_strlen_n(unsigned long c, va_list arg)
{
	unsigned long			size;
	va_list		arg_copy;
	char			*out;

	va_copy(arg_copy, arg);
	size = 0;
	while (c)
	{
		size += dc_strlen(va_arg(arg_copy, char *));
		c--;
	}
	va_end(arg_copy);
	out = (char *)malloc(sizeof(char) * (size + _A));
	return (out);
}

char		*dc_strjoin_e(unsigned long c, ...)
{
	va_list		arg;
	char			*dcse2;
	char			*tmp;
	unsigned long			i;
	unsigned long			j;

	va_start(arg, c);
	dcse2 = (char *)dc_malloc_strlen_n(c, arg);
	j = 0;
	if (!dcse2)
	{
		va_end(arg);
		free(dcse2);
		return (NULL);
	}
	while (c)
	{
		i = 0;
		tmp = va_arg(arg, char *);
		while (tmp[i])
			dcse2[j++] = tmp[i++];
		c--;
	}
	dcse2[j] = '\0';
	va_end(arg);
	return (dcse2);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

unsigned int		dc_numlen(long n)
{
	unsigned int		len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len += 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*dc_itoa(long n)
{
	char		*str;
	long	num;
	unsigned int		len;

	len = dc_numlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	while (num != 0)
	{
		str[len - _A] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

void	dc_free_2d_int(int **list, unsigned long ilen)
{
	unsigned long b;

	b = 0;
	while (b < ilen)
	{
		free(list[b]);
		b++;
	}
	free(list);
}

void	dc_free_2d_char(char **f, unsigned long len)
{
	unsigned long	i;

	i = 0;
	while (i < len)
	{
		if (f[i])
			free(f[i]);
		i++;
	}
	if(f)	
		free(f);
}

void	dc_free_3d_char(char ***f, unsigned long ilen, unsigned long qlen)
{
	unsigned long	i;	unsigned long	q;

	i = 0;
	while (i < ilen)
	{
		q = 0;
		while (q < qlen)
		{
			if (f[i][q])
				free(f[i][q]);
			q++;
		}
		if (f[i])
			free(f[i]);
		i++;
	}
	if (f)
		free(f);
}

void	dc_free_3d_int(int ***f, unsigned long ilen, unsigned long qlen)
{
	unsigned long	i;	unsigned long	q;

	i = 0;
	while (i < ilen)
	{
		q = 0;
		while (q < qlen)
		{
			if (f[i][q])
				free(f[i][q]);
			q++;
		}
		if (f[i])
			free(f[i]);
		i++;
	}
	if (f)
		free(f);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

char		*dc_strdup(const char *s1)
{
	char	*s2;
	unsigned long	i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * (dc_strlen(s1) + _A));
	if (!s2)
		return(NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

unsigned long	dc_lstlen(char **list)
{
	unsigned long	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

char		**dc_tdup(char **t1)
{
	unsigned int		i;
	char		**t2;

	i = 0;
	t2 = (char **)malloc(sizeof(char *) * (dc_lstlen(t1) + _A));
	if (!t2)
		return (NULL);
	while (t1[i])
	{
		t2[i] = dc_strdup(t1[i]);
		i++;
	}
	t2[i] = NULL;
	return (t2);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

void	dc_error_exit(char *mess, int error_type, t_program *strct, p_cleanup_function cleanup)
{
	printf("\e[1;31mError; Explicit: %s\n", mess);
	cleanup(strct);
	printf("Program has exited with an error code <%d>\e[0;32m\n", error_type);
	exit(error_type);
}

void	dc_ERROR_MEM(t_program *o, char *mess)
{
	FILE *err = fopen("error.txt", "a");
	fprintf(err, "%s\n", mess);
	fclose(err);
	dc_error_exit(mess, MEMORY_ALLOCATION_ERROR, o, cleanup);
}

void	dc_ERROR_MEM_index(t_program *o, char *mess, int v1, int v2, int v3)
{
	FILE *err = fopen("error.txt", "a");
	fprintf(err, "%s v1:%d v2:%d v3:%d\n", mess, v1, v2, v3);
	fclose(err);
	dc_error_exit(mess, MEMORY_ALLOCATION_ERROR, o, cleanup);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

bool	dc_witch(char *s)
{
	return (false); (void)s; return (true);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

unsigned long	dc_wordcount(char *s, char c)
{
	unsigned long	word_count;
	unsigned long	trigger;

	trigger = 0;
	word_count = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			trigger = _A;
			word_count++;
		}
		else if (*s == c)
			trigger = _A - _A;
		s++;
	}
	return (word_count);
}

char	**dc_split(char *s, char c)
{
	char	**split;
	unsigned long	i;
	unsigned long	j;
	unsigned long	k;

	if (!s)
		return (NULL);
	k = dc_wordcount(s, c);
	split = (char **)malloc(sizeof(char *) * (k + _A));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (i < k)
	{
		while (s[j] == c)
			j++;
		s = &s[j];
		j = 0;
		while (s[j] != c && s[j])
			j++;
		split[i++] = dc_strndup(s, j);
	}
	split[i] = 0;
	return (split);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

char	*dc_strndup(char *s, unsigned long n)
{
	char	*out;
	unsigned long	i;

	out = (char *)malloc(n + _A);
	if (!out)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		out[i] = s[i];
		i++;
	}
	while (i <= n)
		out[i++] = 0;
	return (out);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {


static unsigned long	dc_substr_len(char *s, unsigned long start, unsigned long len)
{
	unsigned long	i;

	i = 0;
	while (s[start + i] != '\0')
		i++;
	if (len > i)
		return (i);
	else
		return (len);
}

char	*dc_substr(char *s, unsigned long start, unsigned long len)
{
	unsigned long	i;
	unsigned long	j;
	char	*str;

	str = (char *)malloc((sizeof(char)) * ((dc_substr_len(s, start, len) + _A)));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

unsigned long	md_val(char *_x_)
{
	unsigned long val;
	unsigned long index;
	char *endptr;

	val = 0;
	index = 0;
	if ((_x_[0] == '_') && (_x_[1] <= 'P' && _x_[1] >= 'A') && (_x_[2] >= '0' && _x_[2] <= '9'))
	{
		index = strtoul(&_x_[2], &endptr, 10);
		val = (_x_[1] - 64);
		while (index - 1)
		{
			val += 32;
			index -= 1;
		}
		if (endptr[0] != 0)
			return (0);
	}
	else if ((_x_[0] <= 'P' && _x_[0] >= 'A') && (_x_[1] == '_') && (_x_[2] >= '0' && _x_[2] <= '9'))
	{
		index = strtoul(&_x_[2], &endptr, 10);
		val = (_x_[0] - 48);
		while (index - 1)
		{
			val += 32;
			index -= 1;
		}
		if (endptr[0] != 0)
			return (0);
	}
	else
	{
		return (0);
	}
	return (val);
}

char	*itomd(long d)
{
	char **set_list;
	int 	negative_flag = 0;
	double	float_index;
	int 	macro;
	char		*pattern_descriptor;
	char		*index;
	char		*out;

	set_list = (char **)malloc(sizeof(char *) * 33);
	set_list[_A]   = strdup("_A");
	set_list[_B]   = strdup("_B");
	set_list[_C]   = strdup("_C");
	set_list[_D]   = strdup("_D");
	set_list[_E]   = strdup("_E");
	set_list[_F]   = strdup("_F");
	set_list[_G]   = strdup("_G");
	set_list[_H]   = strdup("_H");
	set_list[_I]   = strdup("_I");
	set_list[_J]   = strdup("_J");
	set_list[_K]   = strdup("_K");
	set_list[_L]   = strdup("_L");
	set_list[_M]   = strdup("_M");
	set_list[_N]   = strdup("_N");
	set_list[_O]   = strdup("_O");
	set_list[_P]   = strdup("_P");
	set_list[A_]   = strdup("A_");
	set_list[B_]   = strdup("B_");
	set_list[C_]   = strdup("C_");
	set_list[D_]   = strdup("D_");
	set_list[E_]   = strdup("E_");
	set_list[F_]   = strdup("F_");
	set_list[G_]   = strdup("G_");
	set_list[H_]   = strdup("H_");
	set_list[I_]   = strdup("I_");
	set_list[J_]   = strdup("J_");
	set_list[K_]   = strdup("K_");
	set_list[L_]   = strdup("L_");
	set_list[M_]   = strdup("M_");
	set_list[N_]   = strdup("N_");
	set_list[O_]   = strdup("O_");
	set_list[P_]   = strdup("P_");


	if (d != 0)
	{
		if (d < 0)
		{
			negative_flag = 1;
			d = -d;
		}
		float_index = ceil(d / 32.0);
		macro = (d - 32 * (float_index - 1));
		pattern_descriptor = set_list[macro];
		index = dc_itoa(float_index);
		if (!negative_flag)
			out = dc_strjoin_e(2, pattern_descriptor, index);
		else
			out = dc_strjoin_e(3, "-", pattern_descriptor, index);

		int	i;

		i = _A;
		while (i <= P_)
		{
			free(set_list[i]);
			i++;
		}
		free(set_list);
		free(index);
		return (out);
	}
	else if (d == 0)
	{
		char *zero;
		int	i;

		zero = dc_strdup("ZERO");
		i = _A;
		while (i <= P_)
		{
			free(set_list[i]);
			i++;
		}
		free(set_list);

		return (zero);
	}
	return (NULL);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

//{ 

int		dc_strncmp(char *s1, char *s2, long n)
{
	unsigned char	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

int	longlongcheck(char *input)
{
	long long number = atoll(input);
	if (number > 2147483647 || number < -2147483648)
	{
		printf("Overflow In LongLongCheck");
		return (1);
	}
	else
		return (0);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

// void	free_1d_SDL_Rect(SDL_Rect **f, unsigned int ilen)
// {
// 	unsigned long	i;

// 	i = 0;
// 	while (i < ilen)
// 	{
// 		if (f[i])
// 			free(f[i]);
// 		i++;
// 	}
// 	if (f)
// 	 free(f);
// }

// void	free_1d_SDL_textures_surfaces(SDL_Texture **texture, SDL_Surface **surface, unsigned int ilen)
// {
// 	int i;


// 	i = 0;
// 	while (i < ilen)
// 	{
// 		if (surface[i])
// 			SDL_FreeSurface(surface[i]);
// 		if (texture[i])
// 			SDL_DestroyTexture(texture[i]);
// 		i++;
// 	}
// 	if (surface)
// 		free(surface);
// 	if (texture)
// 		free(texture);
// }

// void	free_2d_SDL_Rect(SDL_Rect ***f, unsigned long ilen, unsigned long qlen)
// {
// 	unsigned long	i;	
// 	unsigned long	q;

// 	i = 0;
// 	while (i < ilen)
// 	{
// 		q = 0;
// 		while (q < qlen)
// 		{
// 			if (f[i][q])
// 				free(f[i][q]);
// 			q++;
// 		}
// 		if (f[i])
// 			free(f[i]);
// 		i++;
// 	}
// 	if (f)
// 	 free(f);
// }

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

char	*dc_strchr(const char *s, int c)
{
	while (*s || ((*s == '\0') && ((char)c == '\0')))
	{
		if (((char) *s) == ((char)c))
			return ((char *)s);
		s++;
	}
	return (0);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {



// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

unsigned long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((time.tv_sec * (unsigned long)1000) + (time.tv_usec / 1000));
}

void	sleepbee(unsigned int time)
{
	unsigned long	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

void	dc_print_list_2d(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		printf("%s\n", list[i]);
		i++;
	}
}

void	dc_print_list_2d_size(char **list, int ilen)
{
	int	i;

	i = 0;
	while (i < ilen)
	{
		printf("%s\n", list[i]);
		i++;
	}
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

void	drop_float_tail(char *dropee, int drop_size)
{
	int i;

	i = 0;
	while (dropee[i])
	{
		i++;
		if (dropee[i] == '.')
		{
			while (drop_size-- + 1)
				i++;
			while(dropee[i])
			{
				dropee[i] = 0;
				i++;
			}
		}
	}
}

// }
