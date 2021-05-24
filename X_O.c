#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define GREEN	"\e[1;32m"
# define RED	"\e[0;31m"
# define WHITE	"\033[0m"
# define BLUE	"\e[0;34m"
# define YEL	"\e[0;33m"
# define MAG	"\e[0;35m"
# define CYN	"\e[0;36m"

char	ch[10] = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

char	*nbr_with_clr(char c)
{
	char *str;
	str = strdup("\033[0mX\e[0;33m");
	str[4] = c;
	return str;
}

char	*check_char(char c)
{
	if (c == 'X')
		return "\e[0;35mX\e[0;33m";
	else if (c == 'O')
		return "\e[0;36mO\e[0;33m";
	else
		return nbr_with_clr(c);
	return NULL;
}

void	affichage()
{
	system("clear");
	int i = 1;
	printf("%s _______________________________________________\n", YEL);
	while (i < 10)
	{
		if (i + 2 <= 10)
		{
			printf("|		|		|		|\n");
			printf("|	%s	|	%s	|	%s	|\n", check_char(ch[i]) , check_char(ch[i + 1]), check_char(ch[i + 2]));
			printf("|_______________|_______________|_______________|\n");
		}
		i += 3;
	}
	printf("%s", WHITE);
}

int		ret_checker(char type, int ret)
{
	if (ch[1] == type && ch[2] == type && ch[3] == type)
		return ret;
	if (ch[4] == type && ch[5] == type && ch[6] == type)
		return ret;
	if (ch[7] == type && ch[8] == type && ch[9] == type)
		return ret;
	if (ch[1] == type && ch[4] == type && ch[7] == type)
		return ret;
	if (ch[2] == type && ch[5] == type && ch[8] == type)
		return ret;
	if (ch[3] == type && ch[6] == type && ch[9] == type)
		return ret;
	if (ch[1] == type && ch[5] == type && ch[9] == type)
		return ret;
	if (ch[3] == type && ch[5] == type && ch[7] == type)
		return ret;
	return 0;
}

int		checker()
{
	int i,
		ret = 0;
	if (ret_checker('X', 3))
		return 3;
	if (ret_checker('O', 3))
		return 4;
	i = 0;
	while (ch[++i])
		if (ch[i] >= '1' && ch[i] <= '9')
			return 0;
	return 2;
}

int		get_value(char type)
{
	int player;
	do{
		if (type == 'X')
			printf("%s\nPLAYER[%c]: PRINT A NUMBER : %s", MAG, type, WHITE);
		else if (type == 'O')
			printf("%s\nPLAYER[%c]: PRINT A NUMBER : %s", CYN, type, WHITE);
		scanf("%d", &player);
		if (player <= 0 || player > 9)
			printf("%s\nERROR NUMBER%s", RED, WHITE);
	} while (player <= 0 || player > 9);
	return player;
}

void	player(int *cp, char type)
{
	int player;
	player = get_value(type);
	if (ch[player] == 'O' || ch[player] == 'X')
	{
		do
		{
			if (ch[player] == 'O' || ch[player] == 'X')
				printf("%s\nPLACE INCORRECT%s", RED, WHITE);
			player = get_value(type);
		} while (ch[player] == 'O' || ch[player] == 'X');
	}
	ch[player] = type;
	affichage();
	if (*cp == 1)
		*cp = 2;
	else if (*cp == 2)
		*cp = 1;
}

int		main()
{
	int cp = 1,  ret = 0;
	affichage();
	while ((ret = checker()) == 0)
	{
		if (cp == 1)
			player(&cp, 'X');
		else if (cp == 2)
			player(&cp, 'O');
	}
	if (ret == 3)
		printf("%sPLAYER[%sX%s]: WON :D :D :D%s\n", GREEN, MAG, GREEN, WHITE);
	else if (ret == 4)
		printf("%sPLAYER[%sO%s]: WON :D :D :D\n%s", GREEN, CYN, GREEN, WHITE);
	else if (ret == 2)
		printf("%sPARTIE TERMINE NO WINNER :( :(\n%s", BLUE, WHITE);
}
