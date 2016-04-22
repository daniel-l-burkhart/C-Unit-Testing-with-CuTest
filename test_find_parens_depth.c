#include <stdlib.h>
#include "CuTest.h"
#include "parse_utils.h"

/**
 * A NULL input string should result in NULL_INPUT being returned.
 */
void Test_null_input(CuTest* ct) {
	CuAssertIntEquals(ct, NULL_INPUT, find_parens_depth(NULL, 10));
}

/**
 * An empty string should result in zero being returned.
 */
void Test_empty_input(CuTest* ct) {
	CuAssertIntEquals(ct, 0, find_parens_depth("", 0));
}

/**
 * Case where there are no parentheses
 */
void Test_string_with_no_parens(CuTest* ct) {
	CuAssertIntEquals(ct, 0, find_parens_depth("joebob", 6));
}

/**
* Test case where "()" is passed to find_parens_depth()
*/
void Test_string_with_single_balanced_parens_and_nothing_in_them(CuTest* ct) {
	CuAssertIntEquals(ct, 1, find_parens_depth("()", 2));
}

/**
* Test case where a single set of unbalanced parens should return negative 2
*/
void Test_string_with_single_inverted_parens(CuTest* ct){
    CuAssertIntEquals(ct, -2, find_parens_depth(")(", 2));

}

/**
* Testing unsafe input constant by using incorrect length
*/
void Test_string_with_unsafe_input_should_return_negative3(CuTest* ct){
    CuAssertIntEquals(ct, -3, find_parens_depth("joebob", 8));
}

/**
* Balanced parens with text between them.
*/
void Test_balanced_parens_with_text_between(CuTest* ct){
    CuAssertIntEquals(ct, 1, find_parens_depth("(test)", 6));
}

/**
* Testing nested parens.
*/
void Test_nested_balanced_parens(CuTest* ct){
    CuAssertIntEquals(ct, 2, find_parens_depth("(())", 4));
}

/**
* Nested, balanced parens with text in between.
*/
void Test_nested_balanced_parens_with_text(CuTest* ct){
    CuAssertIntEquals(ct, 2, find_parens_depth("(a(b)c)", 7));
}
