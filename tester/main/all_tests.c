#include "unity_fixture.h"

static void	run_all_tests(void)
{
	RUN_TEST_GROUP(minishell);
}

int	main(int argc, const char *argv[])
{
	return (UnityMain(argc, argv, run_all_tests));
}
