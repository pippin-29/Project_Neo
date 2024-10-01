//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/danielle/Stuff/Programs/Eternity/includes/eternity_function.h                                       ***//
//***     Project: /media/danielle/Stuff/Programs/Eternity                                                                 ***//
//***     Header Created: Thu Aug 15 2024                                                                                  ***//
//***     Author: Daniel Haddington [Danielle] at <danielle.sh.md@gmail.com>                                               ***//
//***     Copyright (c) 2024 Daniel Haddington [Danielle]                                                                  ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//

#pragma once

// CLEANUP_C
void				cleanup(t_program *c);

// DANC_C
unsigned long		dc_strlen(const char *c); 						// counts string
char				*dc_strjoin_e(unsigned long c, ...);			// variable number string joiner
unsigned int		dc_numlen(long n);
char				*dc_itoa(long n);								// integer to ascii
void				dc_free_2d_int(int **list, unsigned long ilen);
void				dc_free_2d_char(char **f, unsigned long len);	// frees 2d char array
void				dc_free_3d_char(char ***f, unsigned long ilen, unsigned long qlen);
char				*dc_strdup(const char *s1); 					// creates pointer and replicates the reference
unsigned long		dc_lstlen(char **list);							// returns length of 2d list
char				**dc_tdup(char **t1);							// creates pointer to pointer array and replicates all references
void				dc_error_exit(char *mess, 						// Assign verbose message for clear error determination
						int error_type,								// Assign error code for terminal output on error
							t_program *strct, 						// Assign custom cleanup for strct {o - in this program} with type 
								p_cleanup_function cleanup);		// t_cleanup_function (void) for technical presentation and debugging
void				dc_ERROR_MEM(t_program *o, char *mess);			// calls dc_error_exit with memory allocation specific message, assigns the error to error.txt in project root
void				dc_ERROR_MEM_index(t_program *o,				// same as above, assigns index specific variables or any chosen numbers ro later review to error.txt 
						char *mess,											
							int v1,
								int v2,
									int v3);
bool				dc_bool(char *s);								// checks if bool returns false -> returns true
unsigned long		dc_wordcount(char *s, char c);					// for dc_split, counts words.
char				**dc_split(char *s, char c);					// takes string as input and splits into tokens based on delimiter c
char				*dc_strndup(char *s, unsigned long n);			// creates a pointer and replicates the reference up to size n
char				*dc_substr(char *s, unsigned long start, unsigned long len);		// grabs a section of a string from start to (start + len)
bool				dc_is_operator_mdcalc(char * s);				// checks string for operator in mdcalc program
bool				is_multiplier_p(char *operation);
bool				is_divider_p(char *operation);
bool				is_modulo_p(char *operation);
bool				is_adder_p(char *operation);
bool				is_subtracter_p(char *operation);
bool				dc_is_digit(char c);							// checks if a charachter is a digit
bool				dc_is_md_val(char *_x_);						// checks if the first two letters of a string is an md value
double				dc_find_result_mdcalc(int tkount, ...);			// takes a set of positive integers in md string form and operators {+, -, /, *} and calculates result
unsigned long		md_val(char *_x_);								// Converts md-number to unsigned long int
char				*itomd(long d);									// Converts signed integer to md-number string
int					dc_strncmp(char *s1, char *s2, long n);			// compares two strings up to n and returns comparison.															
int					longlongcheck(char *input);						// checks for overflow of a signed int within a long long, returns (1) for overflow
char				*dc_strchr(const char *s, int c);				// finds a character in a string, left to right, returns a pointer to the string at the characters position
unsigned long		get_time(void);
void				sleepbee(unsigned int time);
void				dc_print_list_2d(char **list);					// prints a 2d list of characters that have been null terminated
void				dc_print_list_2d_size(char **list, int ilen);	// prints a 2d list of characters to size
void				drop_float_tail(char *dropee, int drop_size);	// drops the tail of a float up to drop_size, with no rounding, a precision floor?

// GAME_C
void				draw_game(t_program *c);

// INIT_C
void				init_(t_program *c);

// MENU_C
void 				draw_menu(t_program *c);