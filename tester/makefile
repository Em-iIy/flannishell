CC = gcc
#CFLAGS = -Wall -Wextra -Werror

TESTEXE = test_exec

UNITY_CONFIG_DEFINES = 	-D UNITY_OUTPUT_COLOR \
						-D UNITY_FIXTURE_NO_EXTRAS

UNITY_INCL = 	-I./unity/src/ \
				-I./unity/extras/fixture/src

EXEC_SRC = ../src/executor/
LXR_SRC = ../src/lexer/
PRS_SRC = ../src/parser/
ENV_SRC = ../src/environment/
BLT_SRC = ../src/builtins/
LIBFT_SRC = ../src/libft/

TEST_FILES = 	unity/src/unity.c \
				unity/extras/fixture/src/unity_fixture.c \
				main/all_tests.c \
				main/all_tests_runner.c \
				test_minishell.c \
				$(EXEC_SRC)executor.c \
				$(EXEC_SRC)executor_utils.c \
				$(EXEC_SRC)cmd_finder.c \
				$(EXEC_SRC)io_redirector.c \
				$(BLT_SRC)ft_echo.c \
				$(LXR_SRC)lexer.c \
				$(LXR_SRC)lexer_token.c \
				$(LXR_SRC)lexer_token_utils.c \
				$(LXR_SRC)lexer_token_del.c \
				$(LXR_SRC)lexer_token_print.c \
				$(LXR_SRC)free_lexer.c \
				$(PRS_SRC)parser.c \
				$(PRS_SRC)parser_utils.c \
				$(PRS_SRC)parse_io.c \
				$(PRS_SRC)parse_io_utils.c \
				$(PRS_SRC)parse_cmd.c \
				$(PRS_SRC)parse_cmd_utils.c \
				$(PRS_SRC)parse_str.c \
				$(PRS_SRC)parse_quote.c \
				$(PRS_SRC)parse_dquote.c \
				$(PRS_SRC)parse_expand.c \
				$(PRS_SRC)free_parser.c \
				$(ENV_SRC)environment.c \
				$(ENV_SRC)environment_get.c \
				$(ENV_SRC)environment_add.c \
				$(ENV_SRC)environment_unset.c \
				$(ENV_SRC)environment_utils.c \

LIBFT = $(LIBFT_SRC)libft.a

# Test object files
TEST_OBJ_DIR = test_obj
TEST_OBJ_FILES= $(TEST_FILES:%.c=$(TEST_OBJ_DIR)/%.o)

# Create test executable
test: $(TEST_OBJ_DIR) $(TESTEXE)

# Create and run test executable
test_run: test
	@./$(TESTEXE) -v

# Create test_obj directory
$(TEST_OBJ_DIR):
	mkdir -p $@

# Unit tests
$(TESTEXE): $(TEST_OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ -I../inc -I$(LIBFT_SRC) $(LIBFT)

$(TEST_OBJ_FILES): $(TEST_OBJ_DIR)/%.o : %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(UNITY_CONFIG_DEFINES) $(UNITY_INCL) -c $< -o $@ -I../inc -I$(LIBFT_SRC)

$(LIBFT):
	make -C $(LIBFT_SRC)

clean:
	rm -rf $(TEST_OBJ_DIR)

fclean: clean
	rm -f $(TESTEXE)

re: fclean all

.PHONY = test clean fclean re