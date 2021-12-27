/*
	==================================================
	Workshop #5 (Part-2):
	==================================================
	Name   : Aum Amitkumar Soni
	ID     : 150628204
	Email  : aasoni2@myseneca.ca
	Section: NFF
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX_PATH 70
#define MIN_PATH 10
#define MAX_LIVES 10
#define MIN_LIVES 1
#define MAX_MOVE 15
#define MIN_MOVE 3

struct PlayerInfo
{
	int num_lives;
	char character_symbol;
	int num_treasures;
	int positions[MAX_PATH];
};

struct GameInfo
{
	int max_num_move;
	int path_length;
	int bombs[MAX_PATH];
	int treasures[MAX_PATH];
	int next_move[MAX_MOVE];
};
int main()
{

	struct PlayerInfo player;
	struct GameInfo game;
	char character[] = "--------------------";
	//char save1 = '|', save2 = ' ', save3 = '-';
	char spaces[] = "                    ";
	//char spaces[MAX_PATH], dashes[MAX_PATH], character[MAX_PATH], numbers[MAX_PATH];
	int i, j, m = -1, treasures_found = 0, save, move_val;
	int valid_numoflives = 0, valid_pathlength = 0, valid_numofmoves = 0, valid_move = 0;

	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n\n");
	printf("PLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf("%c", &player.character_symbol);

	while (valid_numoflives == 0)
	{
		printf("Set the number of lives: ");
		scanf("%d", &player.num_lives);

		if (player.num_lives >= MIN_LIVES && player.num_lives <= MAX_LIVES)
		{
			valid_numoflives = 1;
		}

		else
		{
			printf("     Must be between 1 and 10!\n");
		}
	}

	printf("Player configuration set-up is complete\n\n");
	printf("GAME Configuration\n");
	printf("------------------\n");

	while (valid_pathlength == 0)
	{
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf("%d", &game.path_length);

		if (game.path_length <= MAX_PATH && game.path_length >= MIN_PATH && game.path_length % 5 == 0)
		{
			valid_pathlength = 1;
		}

		else
		{
			printf("     Must be a multiple of 5 and between 10-70!!!\n");
		}

	}

	while (valid_numofmoves == 0)
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &game.max_num_move);

		if (game.max_num_move >= MIN_MOVE && game.max_num_move <= MAX_MOVE)
		{
			valid_numofmoves = 1;
		}

		else
		{
			printf("    Value must be between 3 and 15\n");
		}
	}

	printf("\nBOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);

	for (i = 0; i < game.path_length; i = i + 5)
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);

		for (j = i; j < i + 5; j++)
		{
			scanf("%d", &game.bombs[j]);
		}
	}
	printf("BOMB placement set\n\n");
	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);

	for (i = 0; i < game.path_length; i = i + 5)
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);

		for (j = i; j < i + 5; j++)
		{
			scanf("%d", &game.treasures[j]);
		}
	}
	printf("TREASURE placement set\n\n");
	printf("GAME configuration set-up is complete...\n\n");
	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", player.character_symbol);
	printf("   Lives      : %d\n", player.num_lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");
	printf("Game:\n");
	printf("   Path Length: %d\n", game.path_length);
	printf("   Bombs      : ");
	for (i = 0; i < game.path_length; i++)
	{
		printf("%d", game.bombs[i]);
	}
	printf("\n");
	printf("   Treasure   : ");
	for (i = 0; i < game.path_length; i++)
	{
		printf("%d", game.treasures[i]);
	}

	printf("\n\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n\n");

	printf("  --------------------\n");
	printf("  |||||||||1|||||||||2\n");
	printf("  12345678901234567890\n");

	printf("+---------------------------------------------------+\n");
	printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.num_lives, treasures_found, game.max_num_move);
	printf("+---------------------------------------------------+\n");


	while (player.num_lives > 0 && game.max_num_move > 0)
	{
		++m;
		valid_move = 0;
		while (valid_move == 0)
		{

			printf("Next Move [1-20]: ");
			scanf("%d", &game.next_move[m]);
			move_val = game.next_move[m];
			if (move_val >= 1 && move_val <= game.path_length)
			{
				valid_move = 1;
			}

			else
			{
				printf("  Out of Range!!!\n");
			}
		}


		if (character[move_val - 1] == '.' || character[move_val - 1] == '!' || character[move_val - 1] == '&' || character[move_val - 1] == '$')
		{
			printf("\n===============> Dope! You've been here before!\n\n");
			save = move_val - 1;
			spaces[save] = player.character_symbol;
			printf("  %s\n", spaces);
			printf("  %s\n", character);
			printf("  |||||||||1|||||||||2\n");
			printf("  12345678901234567890\n");
			printf("+---------------------------------------------------+\n");
			printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.num_lives, treasures_found, game.max_num_move);
			printf("+---------------------------------------------------+\n");
			spaces[save] = (char)32;
		}


		else if ((game.bombs[move_val - 1] == 0) && (game.treasures[move_val - 1] == 0))
		{
			printf("\n===============> [.] ...Nothing found here... [.]\n\n");
			--game.max_num_move;
			if (player.num_lives == 0 || game.max_num_move == 0)
			{
				printf("No more LIVES remaining!\n\n");
			}
			save = move_val - 1;
			character[save] = '.';
			spaces[save] = player.character_symbol;
			printf("  %s\n", spaces);
			printf("  %s\n", character);
			printf("  |||||||||1|||||||||2\n");
			printf("  12345678901234567890\n");
			printf("+---------------------------------------------------+\n");
			printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.num_lives, treasures_found, game.max_num_move);
			printf("+---------------------------------------------------+\n");
			spaces[save] = (char)32;
		}


		else if ((game.bombs[move_val - 1] == 1) && (game.treasures[move_val - 1] == 1))
		{
			printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
			printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
			--game.max_num_move;
			++treasures_found;
			--player.num_lives;
			if (player.num_lives == 0 || game.max_num_move == 0)
			{
				printf("No more LIVES remaining!\n\n");
			}
			save = move_val - 1;
			character[save] = '&';
			spaces[save] = player.character_symbol;
			printf("  %s\n", spaces);
			printf("  %s\n", character);
			printf("  |||||||||1|||||||||2\n");
			printf("  12345678901234567890\n");
			printf("+---------------------------------------------------+\n");
			printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.num_lives, treasures_found, game.max_num_move);
			printf("+---------------------------------------------------+\n");
			spaces[save] = (char)32;
		}

		else if (game.bombs[move_val - 1] == 1)
		{
			printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
			--game.max_num_move;
			--player.num_lives;
			if (player.num_lives == 0 || game.max_num_move == 0)
			{
				printf("No more LIVES remaining!\n\n");
			}
			save = move_val - 1;
			character[save] = '!';
			spaces[save] = player.character_symbol;
			printf("  %s\n", spaces);
			printf("  %s\n", character);
			printf("  |||||||||1|||||||||2\n");
			printf("  12345678901234567890\n");
			printf("+---------------------------------------------------+\n");
			printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.num_lives, treasures_found, game.max_num_move);
			printf("+---------------------------------------------------+\n");
			spaces[save] = (char)32;
		}

		else
		{
			printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
			--game.max_num_move;
			++treasures_found;
			if (player.num_lives == 0 || game.max_num_move == 0)
			{
				printf("No more LIVES remaining!\n\n");
			}
			save = move_val - 1;
			character[save] = '$';
			spaces[save] = player.character_symbol;
			printf("  %s\n", spaces);
			printf("  %s\n", character);
			printf("  |||||||||1|||||||||2\n");
			printf("  12345678901234567890\n");
			printf("+---------------------------------------------------+\n");
			printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.num_lives, treasures_found, game.max_num_move);
			printf("+---------------------------------------------------+\n");
			spaces[save] = (char)32;
		}
	}

	printf("\n##################\n");
	printf("#   Game over!   #\n");
	printf("##################\n");

	printf("\nYou should play again and try to beat your score!");

	return 0;
}