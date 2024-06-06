#include "shell.h"

/**
 * _exit_ - generates program exit status
 *
 * @cmd_input: the combination of command inputed
 * @arg_num: The number of arguments called
 * @file_name: The name of the program
 *
 * Return: int, exit status
 */

int _exit_(char *cmd_input, char *file_name, int *arg_num)
{
	char *params_arr[5], *token, *ss = NULL;
	int i, n;
	char error_msg[50], count_str[10];

	/*params_arr = malloc(5 * sizeof(char *));*/
	if (params_arr == NULL)
		return (-9);
	token = __strt(cmd_input, " ", &ss);
	for (i = 0; token != NULL && i < 2; i++)
	{
		params_arr[i] = token;
		token = __strt(NULL, " ", &ss);
	}
	params_arr[i] = NULL;
	if (i < 2)
	{
		/*free(params_arr);*/
		return (0);
	}
	n = str_to_int(params_arr[1]);
	if (n < 0)
	{
		_itoa(*arg_num, count_str);
		_strcpy(error_msg, file_name);
		__strcat(error_msg, ": ");
		__strcat(error_msg, count_str);
		__strcat(error_msg, ": ");
		__strcat(error_msg, params_arr[0]);
		__strcat(error_msg, ": Illegal number: ");
		__strcat(error_msg, params_arr[1]);
		__strcat(error_msg, "\n");
		write(STDERR_FILENO, error_msg, _strlen(error_msg));
		/*free(params_arr);*/
		return (-9);
	}
	/*free(params_arr);*/
	return (n);
}
