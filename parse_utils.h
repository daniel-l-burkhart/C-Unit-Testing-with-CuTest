#ifndef PARSE_UTILS_H
#define PARSE_UTILS_H

#define NULL_INPUT (-1)
#define UNBALANCED_PARENS (-2)
#define UNSAFE_INPUT (-3)

/**
 * Calculates how deeply enclosed a string containing parentheses goes.  So, for example,
 * the string "(bob)" would have a depth of 1, "(joe(bob))" a depth of two, "(a(b(c)d)))"
 * a depth of 3, and so forth.  If there are two or more sets of parens at a particular
 * depth they are only counted once -- so this finds the maximum depth over all
 * possible paths.
 *
 * 
 *
 * @param text a string of text
 * @param length the length of the string of text (not including the terminating null char)
 * @returns the maximum depth of parentheses.  Returns NULL_INPUT if the input is NULL, 
 * 		UNBALANCED_PARENS if the parentheses (any of them) are not balanced, and
 *		UNSAFE_INPUT if text is not properly null-terminated.
 */
int find_parens_depth(char* text, unsigned int length);

#endif