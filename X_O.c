#include <stdio.h>
#include <stdlib.h>

char	ch[10] = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void	affichage()
{
	system("clear");
	int i = 1;
	puts(" _______________________________________________");
	while (i < 10)
	{
		if (i + 2 <= 10)
		{
			printf("|		|		|		|\n");
			printf("|	%c	|	%c	|	%c	|\n", ch[i] , ch[i + 1], ch[i + 2]);
			  puts("|_______________|_______________|_______________|");
		}
		i += 3;
	}
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
	if (ret_checker('X', 3))
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
		printf("\nPLAYER [%c]: PRINT A NUMBER : ", type);
		scanf("%d", &player);
		if (player <= 0 || player > 9)
			printf("\nERROR NUMBER");
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
				printf("\nPLACE INCORRECT");
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
	int cp = 1, ret = 0;
	affichage();
	while ((ret = checker()) == 0)
	{
		if (cp == 1)
			player(&cp, 'X');
		else if (cp == 2)
			player(&cp, 'O');
	}
	if (ret == 3)
		printf("PLAYER [X]: WON :D :D :D\n");
	else if (ret == 4)
		printf("PLAYER [O]: WON :D :D :D\n");
	else if (ret == 2)
		printf("PARTIE TERMINE :( :(\n");
}
