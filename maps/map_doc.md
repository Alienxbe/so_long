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