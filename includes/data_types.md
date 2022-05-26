# Data types

## Structures

Here is the list of all the structures and their parameters

* [Main](#main-structures)
	* [t_data](#t_data)
	* [t_game](#t_game)
	* [t_player](#t_player)
	* [t_assets](#t_assets)
	* [t_asset](#t_asset)
	* [t_img](#t_img)
	* [t_mlx_img](#t_mlx_img)
* [Utils](#utils-structures)
	* [t_point](#t_point)
	* [t_area](#t_area)

###	 Main structures

#### t_data

t_data is the main structure of the project.
It contains all the main variables

| Type | Name | Utility |
| --- | --- | --- |
| `void *` | mlx_ptr | main mlx ptr |
| `void *` | mlx_win | window ptr for the mlx |
| `int [MAX_KEY]` | key | list of all the [keybind](#t_key_list) |
| `t_game` | game | |
| `t_assets` | assets | |

Code definition:
```C
typedef struct	s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	int		key[MAX_KEY];
	t_game		game;
	t_assets	assets;
}	t_data;
```

#### t_game

Structure that contain all the main variables about the game

| Type | Name | Utility |
| --- | --- | --- |
| [`t_player`](#t_player) | player | player structure |

Code definition:
```C
typedef struct	s_game
{
	t_player	player;
}	t_game;
```

#### t_player

Structure that contain all the main variables about the player

| Type | Name | Utility |
| --- | --- | --- |
| [`t_point`](#t_point) | pos | position of the player |
| `int` | rot | rotation of the player (range: `0 -> 3`) |
| `int` | frame | animation frame (range: `0 -> 3`) |

Code definition:
```C
typedef struct	s_player
{
	t_point	pos;
	int	rot;
	int	frame;
}	t_player;
```

#### t_assets

Not really a usefull struc. But help the code to be more readable

| Type | Name | Utility |
| --- | --- | --- |
| [`t_asset`](#t_asset) | tiles |  |
| [`t_asset`](#t_asset) | player |  |

Code definition:
```C
typedef struct	s_assets
{
	t_asset	tiles;
	t_asset	player;
}	t_assets;
```

#### t_asset

Structure that is returned after loading a new asset_sheet

| Type | Name | Utility |
| --- | --- | --- |
| [`t_img *`](#t_img) | img | list of `t_img` |
| `int` | count | number of element |

Code definition:
```C
typedef struct	s_asset
{
	int	count;
	t_img	*list;
}	t_asset;
```

#### t_img

Basic image structure

| Type | Name | Utility |
| --- | --- | --- |
| `void *` | img | ptr to the mlx img object |
| [`t_point`](#t_point) | size | define the size of the image |

Code definition:

```C
typedef struct	s_img
{
	void	*img;
	t_point	size;
}	t_img;
```

#### t_mlx_img

More complex image structure to allow mlx to write manually on the image

| Type | Name | Utility |
| --- | --- | --- |
| `void *` | img | ptr to the mlx object |
| `char *` | addr | obscure mlx |
| `int` | bpp | obscure mlx |
| `int` | line_length | obscure mlx |
| `int` | endian | obscure mlx |

Code definition:

```C
typedef struct	s_mlx_img
{
	void	*img;
	char	*addr;
	int	bpp;
	int	line_length;
	int	endian;
}	t_mlx_img;
```

### Utils structures

#### t_point

This structure represent a point or any size that is represented on a two-dimensionnal plane

| Type | Name | Utility |
| --- | --- | --- |
| `int` | x | abscissa value |
| `int` | y | ordinate value |

Code definition:

```C
typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;
```

#### t_area

This structure represent an area on a two-dimensionnal plane

| Type | Name | Utility |
| --- | --- | --- |
| `t_point` | p1 | first point |
| `t_point` | p2 | second point |

Code definition:

```C
typedef struct	s_area
{
	t_point	p1;
	t_point	p2;
}	t_area;
```

## Enumerations

### t_assets

**this enum is almost obselete !**

This is used to index the assets numbers like an id

Code definition:

```C
typedef enum e_assets	t_assets;
```

### t_key_list

This is used to bind the keys because Linux and MacOS don't have the same key_id

Code definition:

```C
typedef enum e_key_list	t_key_list;
```
