#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "BrickFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */
#include "EggFunctions.h" /* Egg_Build */


/* Helper: The action performed when the key is taken. */
void Tri_Key_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the key might be used, whenever it is picked up. */
	printf("The key feels smooth in your hand.\n");
}


/* Helper: The action performed when the key is used. */
void Tri_Key_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* key; /* The key in the player's inventory */

	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the key out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the key - inform the user of the problem and take no action */
		printf("You must have the key before you can use it.\n");
		return;
	}

	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 0)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("You cannot use the key here.\n");
		return;
	}

	/* check if the cage has already been broken and scored */
	if (GameFlags_IsInList(gameState->gameFlags, "triKeyUsed"))
	{
		/* the player already used the key - inform the user of the problem and take no action */
		printf("You already used the key.\n");
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

		/* Find the key in the player's inventory - it should be there, since we are in the Inventory context */
		key = ItemList_FindItem(gameState->inventory, "TriKey");

		/* Remove the key from the user's inventory - they won't need it again */
		gameState->inventory = ItemList_Remove(gameState->inventory, key);

		/* Tell the user what they did */
		printf("You hold out the key and it crumbles in your hands.\n");

		/* Add to the player's score */
		GameState_ChangeScore(gameState, 100);

		/* the gold piece has not been scored, so mark the flag */
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "triKeyUsed");
		if (GameFlags_IsInList(gameState->gameFlags, "circleKeyUsed") && GameFlags_IsInList(gameState->gameFlags, "squareKeyUsed") && GameFlags_IsInList(gameState->gameFlags, "triKeyUsed"))
		{
			GameState_EndGame(gameState, "As all the keys turn to dust on the floor, the exit opens and you run out, escaping the dungeon.\n");
		}
	}
}


/* Build a "key" object */
Item* Tri_Key_Build()
{
	/* Create a "key" item, using the functions defined in this file */
	return Item_Create("tri key", "A small smooth gem, completely transparent", true, Tri_Key_Use, Tri_Key_Take, NULL);
}