#include "unity_fixture.h"

TEST_GROUP_RUNNER(minishell)
{
	RUN_TEST_CASE(minishell, pwd);
	//RUN_TEST_CASE(minishell, one_pipe);
}
