#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "MatchFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */


/* Helper: The action performed when the brick is taken. */
void Match_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	printf("You feel the flimsy match roll in your hand.\n");

	if (GameFlags_IsInList(gameState->gameFlags, "matchUsed"))
	{
		gameState->gameFlags = GameFlags_Remove(gameState->gameFlags, "matchUsed");
	}
}


/* Helper: The action performed when the match is used. */
void Match_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* match; /* The match in the player's inventory */

	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the match out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the match - inform the user of the problem and take no action */
		printf("You must have the match before you can use it.\n");
		return;
	}

	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 7 && gameState->currentRoomIndex != 8 && gameState->currentRoomIndex != 9)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("You cannot use the match here.\n");
		return;
	}

	/* check if the match has already been used */
	if (GameFlags_IsInList(gameState->gameFlags, "matchUsed"))
	{
		/* the player already used the match - inform the user of the problem and take no action */
		printf("You already used the match here.\n");
		return;
	}
	else
	{
		/* get the current room */
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

		/* get the list of items in the current room */
		roomItemsPtr = Room_GetItemList(room);
		if (roomItemsPtr == NULL)
		{
			return; /* take no action, as something is wrong - we should always have an item list */
		}

		/* Find the match in the player's inventory - it should be there, since we are in the Inventory context */
		match = ItemList_FindItem(gameState->inventory, "match");

		/* Remove the match from the user's inventory - they won't need it again */
		gameState->inventory = ItemList_Remove(gameState->inventory, match);


		if (gameState->currentRoomIndex == 7)
		{
			printf("You use the match to light the torch and the room illuminates with light. You see an old piece of parchment paper on the back wall and sketched markings on the side walls. The parchment paper reads \"To find the answer, your must find the change.\" The north wall has 6 visible markings and the south wall has 1.\n");
			Room_SetDescription(room, "You are in a room lit by a torch with an old piece of parchment paper on the back wall and sketches markings on the side walls. The parchment paper reads \"To find the answer, your must find the change.\" The north wall has 6 visible markings and the south wall has 1.\n");
		}
		else if (gameState->currentRoomIndex == 8)
		{
			printf("You use the match to light the torch and the room illuminates with light. You see an old piece of parchment paper on the back wall and sketched markings on the side walls. The parchment paper reads \"The answer will give you power.\" The north wall has 2 visible markings and the south wall has 4.\n");
			Room_SetDescription(room, "You are in a room lit by a torch with an old piece of parchment paper on the back wall and sketches markings on the side walls. The parchment paper reads \"The answer will give you power.\" The north wall has 2 visible markings and the south wall has 4.\n");
		}
		else if (gameState->currentRoomIndex == 9)
		{
			printf("You use the match to light the torch and the room illuminates with light. You see an old piece of parchment paper on the back wall and sketched markings on the side walls. The parchment paper reads \"The answer rests in the balance.\" The north wall has 9 visible markings and the south wall has 7.\n");
			Room_SetDescription(room, "You are in a room lit by a torch with an old piece of parchment paper on the back wall and sketches markings on the side walls. The parchment paper reads \"The answer rests in the balance.\" The north wall has 9 visible markings and the south wall has 7.\n");
		}
		/* Tell the user what they did */
		//printf("You use the match to light the torch and the room illuminates with light. You see an old piece of parchment paper on the back wall and sketched markings on the side walls.\n");

		/* Update the room description to reflect the change in the room */
		//Room_SetDescription(room, "You are in a room lit by a torch with an old piece of parchment paper on the back wall and sketches markings on the side walls.\n");

		/* Add to the player's score */
		GameState_ChangeScore(gameState, 10);

		/* mark the flag */
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "matchUsed");
	}
}


/* Build a "match" object */
Item* Match_Build()
{
	/* Create a "match" item, using the functions defined in this file */
	return Item_Create("match", "A small match", true, Match_Use, Match_Take, NULL);
}