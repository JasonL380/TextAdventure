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
#include "Source/CircleKeyFunctions.h" /* Circle_Key_Build */
#include "Source/SquareKeyFunctions.h" /* Square_Key_Build */
#include "Source/TriKeyFunctions.h" /* Tri_Key_Build */
#include "Source/ExitDoorFunctions.h" /* ExitDoor_Build */
#include "Source/MatchFunctions.h" 



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

	room = Room_Create("You have been trapped in a dungeon of riddles. There are three paths ahead of you, each with their own key. However, you must figure out the rule to proceed in each room. Return here once you've obtained the keys and use them.\n");

	Room_AddRoomExit(room, "s", 12);

    Room_AddRoomExit(room, "southwest", 1);
    Room_AddRoomExitShortcut(room, "sw", 1);

    ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	Room_AddRoomExit(room, "east", 7);
	Room_AddRoomExitShortcut(room, "e", 7);

	/* return the new room */
	return room;
}


Room* Path_1_1_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	room = Room_Create("This room has 2 pillars on one side and 2 on the other and a locked door in front of you. Perhaps the pillars hold the key?\n");

    Room_AddRoomExitShortcut(room, "4", 10);
    Room_AddRoomExitShortcut(room, "four", 10);

    Room_AddRoomExit(room, "north", 0);
    Room_AddRoomExitShortcut(room, "n", 0);

	/* return the new room */
	return room;
}

Room* Path_11_mid_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	room = Room_Create("The door opens in front of you.\n");

	Room_AddRoomExit(room, "south", 2);
	Room_AddRoomExitShortcut(room, "s", 2);

	Room_AddRoomExit(room, "north", 0);
	Room_AddRoomExitShortcut(room, "n", 0);

	/* return the new room */
	return room;
}

Room* Path_1_2_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	room = Room_Create("This next room has 4 pillars on one side and 3 on the other, and once again a locked door in front.\n");

	Room_AddRoomExitShortcut(room, "12", 11);
	Room_AddRoomExitShortcut(room, "twelve", 11);

	Room_AddRoomExit(room, "north", 1);
	Room_AddRoomExitShortcut(room, "n", 1);

	/* return the new room */
	return room;
}

Room* Path_12_mid_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	room = Room_Create("The door opens in front of you.\n");

	Room_AddRoomExit(room, "south", 3);
	Room_AddRoomExitShortcut(room, "s", 3);

	Room_AddRoomExit(room, "north", 1);
	Room_AddRoomExitShortcut(room, "n", 1);

	/* return the new room */
	return room;
}

Room* Path_1_3_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	room = Room_Create("This final room has 6 pillars on one side, 7 on the other, and a circular gem locked in a cage, one of the three keys.\n");

	Room_AddRoomExitShortcut(room, "42", 12);
	Room_AddRoomExitShortcut(room, "forty two", 12);

	Room_AddRoomExit(room, "north", 2);
	Room_AddRoomExitShortcut(room, "n", 2);

	/* return the new room */
	return room;
}

Room* Path_13_mid_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	room = Room_Create("The cage opens in front of you, revealing the key.\n");

	Room_AddRoomExit(room, "north", 2);
	Room_AddRoomExitShortcut(room, "n", 2);

	ItemList_AddItem(Room_GetItemList(room), Circle_Key_Build());
	ItemList_AddItem(Room_GetItemList(room), Tri_Key_Build());

	/* return the new room */
	return room;
}

Room* Path_2_1_Build()
{
	Room* room;

	room = Room_Create("This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n");

    Room_AddRoomExit(room, "east", 0);
    Room_AddRoomExitShortcut(room, "e", 0);

    ItemList_AddItem(Room_GetItemList(room), GoldPiece_Build());

	/* return the new room */
	return room;
}

Room* Path_2_2_Build()
{
	Room* room;

	room = Room_Create("This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n");

	Room_AddRoomExit(room, "east", 0);
	Room_AddRoomExitShortcut(room, "e", 0);

	ItemList_AddItem(Room_GetItemList(room), GoldPiece_Build());

	/* return the new room */
	return room;
}

Room* Path_2_3_Build()
{
	Room* room;

	room = Room_Create("This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n");

	Room_AddRoomExit(room, "east", 0);
	Room_AddRoomExitShortcut(room, "e", 0);

	ItemList_AddItem(Room_GetItemList(room), GoldPiece_Build());

	/* return the new room */
	return room;
}


Room* Path_3_1_Build()
{
	Room* room;

	room = Room_Create("You enter a dark room with an unlit torch on the wall.\n");

	Room_AddRoomExit(room, "west", 0);
	Room_AddRoomExitShortcut(room, "west", 0);

	Room_AddRoomExitShortcut(room, "5", 13);

	ItemList_AddItem(Room_GetItemList(room), Match_Build());

	/* return the new room */
	return room;
}

Room* Answer_3_1_Build()
{
	Room* room;

	room = Room_Create("The back wall mysteriously crumbles.\n");

	Room_AddRoomExit(room, "west", 7);
	Room_AddRoomExitShortcut(room, "west", 7);

	Room_AddRoomExit(room, "east", 8);
	Room_AddRoomExitShortcut(room, "e", 8);

	/* return the new room */
	return room;
}

Room* Path_3_2_Build()
{
	Room* room;

	room = Room_Create("You enter a dark room with an unlit torch on the wall.\n");

	Room_AddRoomExit(room, "west", 7);
	Room_AddRoomExitShortcut(room, "w", 7);

	Room_AddRoomExitShortcut(room, "16", 14);

	ItemList_AddItem(Room_GetItemList(room), Match_Build());

	/* return the new room */
	return room;
}

Room* Answer_3_2_Build()
{
	Room* room;

	room = Room_Create("The back wall mysteriously crumbles.\n");

	Room_AddRoomExit(room, "west", 8);
	Room_AddRoomExitShortcut(room, "w", 8);

	Room_AddRoomExit(room, "east", 9);
	Room_AddRoomExitShortcut(room, "e", 9);

	/* return the new room */
	return room;
}

Room* Path_3_3_Build()
{
	Room* room;

	room = Room_Create("You enter a dark room with an unlit torch on the wall.\n");

	Room_AddRoomExit(room, "west", 8);
	Room_AddRoomExitShortcut(room, "w", 8);

	Room_AddRoomExitShortcut(room, "8", 15);

	ItemList_AddItem(Room_GetItemList(room), Match_Build());

	/* return the new room */
	return room;
}

Room* Answer_3_3_Build()
{
	Room* room;

	room = Room_Create("\n");
	// add text for key and add key item
	ItemList_AddItem(Room_GetItemList(room), Square_Key_Build());

	Room_AddRoomExit(room, "east", 8);
	Room_AddRoomExitShortcut(room, "e", 8);

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
	int roomCount = 16;

	/* create the new WorldData object with 3 rooms */
	worldData = WorldData_Create("Welcome to my GAM100 Game!\n\n", roomCount);

	/* build each room and assign them to the world data */
	WorldData_SetRoom(worldData, 0, Room_Start_Build());

    WorldData_SetRoom(worldData, 1, Path_1_1_Build());
	WorldData_SetRoom(worldData, 2, Path_1_2_Build());
	WorldData_SetRoom(worldData, 3, Path_1_3_Build());

	WorldData_SetRoom(worldData, 4, Path_2_1_Build());
	WorldData_SetRoom(worldData, 5, Path_2_2_Build());
	WorldData_SetRoom(worldData, 6, Path_2_3_Build());

	WorldData_SetRoom(worldData, 7, Path_3_1_Build());
	WorldData_SetRoom(worldData, 8, Path_3_2_Build());
	WorldData_SetRoom(worldData, 9, Path_3_3_Build());

	WorldData_SetRoom(worldData, 10, Path_11_mid_Build());
	WorldData_SetRoom(worldData, 11, Path_12_mid_Build());
	WorldData_SetRoom(worldData, 12, Path_13_mid_Build());

	//WorldData_SetRoom(worldData, 13, Answer_2_1_Build());
	//WorldData_SetRoom(worldData, 14, Answer_2_2_Build());
	//WorldData_SetRoom(worldData, 15, Answer_2_3_Build());

	WorldData_SetRoom(worldData, 13, Answer_3_1_Build());
	WorldData_SetRoom(worldData, 14, Answer_3_2_Build());
	WorldData_SetRoom(worldData, 15, Answer_3_3_Build());


	/* return the new object */
	return worldData;
}