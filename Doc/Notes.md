# NOTES

## Usefull ideas I should keep for later

*	For rendering instead of refreshing all the tiles, only refresh the tiles between to point (Can be multiple positions). Should use a list. Maybe linked list because size is unkown. These zones are obviously where there is movement... Sooo how do I know when there is movement... Moving state... But What is moving ? Players, maybe pokemon on map... These are only entities. So there is no movement in tiles. How do I keep track of entities => Linked list
* Entity should be a struct with:
	* Position (`t_pos`)
	* Movement (`boolean`)
	* Maybe name (`char *`)
	* Maybe an id (`int`) or maybe index in the list is already the id (But what about if I remove an entity from the middle of the list ?)

* Entities list should be in struct `t_game`
* Two entities can overlap

* IF THERE IS AN ENTITYT LIST !!!! When I parse the map and read special character they should be added to the list as entities, so after that I can easily check the rules (1 player pos, at least 1 coin, at least 1 ending)



## What I should be doing RIGHT NOW

* Collision map verification (walls, ...)
* Maybe add entity system before because it can be usefull
