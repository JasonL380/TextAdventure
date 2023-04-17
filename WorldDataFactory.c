/******************************************************************************
filename    WorldDataFactory.c
author      Justin Chambers
DP email    justin.chambers@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the WorldData factory, which creates the WorldData objects used
in this game.

This could be used to create default states as well as loaded state.

******************************************************************************/
#include "Source/WorldDataFactory.h" /* Function declarations */
#include "Source/WorldData.h" /* WorldData_Create, WorldData_SetRoom */
#include "Source/Room.h" /* Room_Create, Room_AddRoomExit, Room_GetItemList */
#include "Source/ItemList.h" /* ItemList_Add */
#include "Source/BrickFunctions.h" /* Brick_Build */
#include "Source/GoldPieceFunctions.h" /* GoldPiece_Build */
#include "Source/ExitDoorFunctions.h" /* ExitDoor_Build */



/******************************************************************************
	Build room TEMPLATE
    Use this example function to build additional rooms
******************************************************************************/
Room* RoomN_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	   include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/* Exits
	   add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */

	/* Items
	   add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/* Return the new room */
	return room;
}


Room* Room_Start_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	room = Room_Create("You have been trapped in a dungeon of riddles. There are three paths ahead of you, eahc with their own key. However, you must figure out the rule to proceed in each room.\n");

    Room_AddRoomExit(room, "north", 1);
    Room_AddRoomExitShortcut(room, "n", 1);

    ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/* return the new room */
	return room;
}


Room* Room1_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	room = Room_Create("This is room 1.  There is a large mirror here, and it shimmers as you approach.\n");

    Room_AddRoomExit(room, "through the mirror", 2);
    Room_AddRoomExitShortcut(room, "through mirror", 2);
    Room_AddRoomExitShortcut(room, "mirror", 2);

    Room_AddRoomExit(room, "south", 0);

    Room_AddRoomExitShortcut(room, "s", 0);

    ItemList_AddItem(Room_GetItemList(room), Brick_Build());

	/* return the new room */
	return room;
}


Room* Room2_Build()
{
	Room* room;

	room = Room_Create("This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n");

    Room_AddRoomExit(room, "east", 0);
    Room_AddRoomExitShortcut(room, "e", 0);

    ItemList_AddItem(Room_GetItemList(room), GoldPiece_Build());

	/* return the new room */
	return room;
}


/* TODO ADVANCED: Build room 3 */
/* TODO ADVANCED: Build room 4 */


/* ------------------------------------------------------- */
/* Create the world data for a new game */
/* ------------------------------------------------------- */
WorldData* CreateInitialWorldData()
{
	/* The new world data */
	WorldData* worldData;

	/* TODO REQUIRED: update room count to match the number of rooms you have created and added to the world
	   if this number doesn't match then your game will either crash or you will end up stuck in a broken room with no exits */
	int roomCount = 4;

	/* create the new WorldData object with 3 rooms */
	worldData = WorldData_Create("Welcome to my GAM100 Game!\n\n", roomCount);

	/* build each room and assign them to the world data */
	WorldData_SetRoom(worldData, 0, RoomN_Build());
    WorldData_SetRoom(worldData, 1, Room1_Build());
    WorldData_SetRoom(worldData, 2, Room2_Build());


	/* return the new object */
	return worldData;
}