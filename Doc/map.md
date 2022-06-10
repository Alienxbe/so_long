# Documentation for map format

There is two main format for the map files :
* [Basic Encoding Rules](#basic-encoding-rules) (`.ber`)
* [Advanced Encoding Rules](#advanced-encoding-rules) (`.aer`)

The major difference between the two format is the freedom of creation that you obatain with the advanced one.

## Basic Encoding Rules
e

## Advanced Encoding Rules

* This require the devlopement of a modified `ft_atoi`

Parameters format:
> [.id_size][.layer_count]

### Encoding

Single dimensional array of `int`:
```C
typedef int	*t_tab;
```
---
But if there is mulitple layer it should be encoded as an array of single dimensional array of `int`
```C
typedef int	**t_tab;
```
---
2 Solutions to this problem : 

1.
	Using a `void *` type and cast it every time you are using it
	```C
	typedef void	*t_tab;
	```

2.
	Always using a two-dimensional array but this method allways require a malloc even if there is just one layer
	```C
	typedef int	**t_tab;
	```

## Collisions

### Collision map (default and used for .ber files)
This map is by default generated like this :
* Every 0's are transparent blocks (you can go throught them)
* Every other blocks are solid blocks (They are basicly walls)

### Collision map (created manually and only for .aer files)

The part where the collision map is defined must be at the end of the file followed by a `\n` and it must start with `#COL`

These are the only accepted `states`:
* `T`: Transparent
* `S`: Solid

### Option 1:
Define blocks tile_id manually at the end of the tile map file
ex:
```
5555
5015
5005
5555

#COL
5:	S
0:	T
1:	S
```
**format** : `tile_id:(whitespaces)(state)` (You can use as many whitespace as you want)
</b>
**IF NOT STATE IS DEFINED IT USE THE DEFAULT RULE**

### Option 2:
Define state map directly at the end of the tile map file
ex:
```
5555
5015
5005
5555

#COL
1111
1011
1001
1001
```
The state map has to follow the same dimensions as the tile's one
This format is way less usefull because you have to write the map again
