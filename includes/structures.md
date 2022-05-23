# Data types

## Structures

Here is the list of all the structures and their parameters

* [Main](#main-structures)
	* [t_data](#tdata)
	* [t_img](#timg)
	* [t_mlx_img](#tmlximg)
* [Utils](#utils-structures)
	* [t_point](#tpoint)

###	 Main structures

#### t_data

t_data is the main structure of the project.
It contains all the main variables
I might change `assets` to a new structure type later

| Type | Name | Utility |
| --- | --- | --- |
| `void *` | mlx_ptr | main mlx ptr |
| `void *` | mlx_win | window ptr for the mlx |
| [`t_img [assets_count]`](#timg) | assets | list of all assets |

Code definition:
```C
typedef struct	s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	assets[assets_count];
}	t_data;
```

#### t_img

Basic image structure

| Type | Name | Utility |
| --- | --- | --- |
| `void *` | img | ptr to the mlx img object |
| [`t_point`](#tpoint) | size | define the size of the image |

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
	int		bpp;
	int		line_length;
	int		endian;
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

## Enumerations

### t_assets

This is used to index the assets numbers like an id

Code definition:

```C
typedef enum e_assets	t_assets;
```
