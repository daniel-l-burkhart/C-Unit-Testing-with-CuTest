

/* This is auto-generated code. Edit at your own peril. */
#include <stdio.h>
#include <stdlib.h>

#include "CuTest.h"


extern void Test_null_input(CuTest*);
extern void Test_empty_input(CuTest*);
extern void Test_string_with_no_parens(CuTest*);
extern void Test_string_with_single_balanced_parens_and_nothing_in_them(CuTest*);
extern void Test_string_with_single_inverted_parens(CuTest*);
extern void Test_string_with_unsafe_input_should_return_negative3(CuTest*);
extern void Test_balanced_parens_with_text_between(CuTest*);
extern void Test_nested_balanced_parens(CuTest*);
extern void Test_nested_balanced_parens_with_text(CuTest*);


void RunAllTests(void) 
{
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();


    SUITE_ADD_TEST(suite, Test_null_input);
    SUITE_ADD_TEST(suite, Test_empty_input);
    SUITE_ADD_TEST(suite, Test_string_with_no_parens);
    SUITE_ADD_TEST(suite, Test_string_with_single_balanced_parens_and_nothing_in_them);
    SUITE_ADD_TEST(suite, Test_string_with_single_inverted_parens);
    SUITE_ADD_TEST(suite, Test_string_with_unsafe_input_should_return_negative3);
    SUITE_ADD_TEST(suite, Test_balanced_parens_with_text_between);
    SUITE_ADD_TEST(suite, Test_nested_balanced_parens);
    SUITE_ADD_TEST(suite, Test_nested_balanced_parens_with_text);

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
    CuStringDelete(output);
    CuSuiteDelete(suite);
}

int main(void)
{
    RunAllTests();
	return 0;
}

