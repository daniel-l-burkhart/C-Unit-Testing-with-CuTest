#include <string.h>
#include <stdlib.h>

#include "parse_utils.h"

int find_parens_depth(char* text, unsigned int length) {
	int max_depth = 0;
	int current_depth = 0;
	int is_null_terminated = 0;
	int i;

	// the null char case
	if (text == NULL) {
		return NULL_INPUT;
	}

	// the empty string case
	if (text[0] == '\0' || length == 0) {
		return 0;
	}

	// checking for proper null-termination
	// this is somewhat relaxed in the sense that length could
	// be longer than the text AS LONG AS there is a null char
	// at or before text[length]
	for (i = 0; i <= length; i++) {
		if (text[i] == '\0') {
			is_null_terminated = 1;
			break;
		}
	}

	if (!is_null_terminated) {
		return UNSAFE_INPUT;
	}

	
	// counting parens
	for (i = 0; i < length; i++) {
		if (text[i] == '(') {
			current_depth++;
		} else if (text[i] == ')') {
			current_depth--;
		}

		if (current_depth > max_depth) {
			max_depth = current_depth;
		}
	}

	if (current_depth != 0) {
		return UNBALANCED_PARENS;
	}

	return max_depth;
}
