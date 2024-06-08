# so_long

This project is a very small 2D game.
Its purpose is to make you work with textures, sprites,
and some other very basic gameplay elements.

## parsing

<p align="center">
<img src="https://media.giphy.com/media/mTSyzp4bHx86C5peai/giphy.gif" style="width:500px">
</p>

First thing first we start with the map name it must end with ".ber" .berrrr or .berber not valid.\
now that we know that the map name is right we read from the file, of course, don't forget to check if there is a file with that name in the first place, you can use your get_next_line, I use a small version hhhhhh, when reading is finished in my case the map will be in one string.\
the lines are separated with '\n' now we do the split with '\n'. Finally our map is in two demotion.\
talking about demotion we have to check if the map is a rectangle(square is a rectangle a perfect one) just by checking the length of the lines to be equal.\
Now that our map is in perfect shape we check the borders of the map it must have only walls '1' every map[0][i] and map[the map width][i] equal '1' and map[i][0] map[i][the map width] equal '1'.\
then check the element at least one collectible 'C' and only one player 'P' and one exit 'E' and nothing else.\
that set we finish parsing.\
the last error to check is whether there is a path in the game where the player 'P' collects all the coins 'C' and exits 'E'.\
I use a recursive function to check every direction and the base case is '1' and 'E' if map[i][j] == 'C' increment the count of the coins and overwrite with '1' else overwrite with '1'.\
At the end, if the count of the coins is equal to the number of the coins and you reach the exit it's a valide map and versa versa.

## minilibx

The minilibx is a small C library used for rendering graphics, primarily used by 42 students. As the name implies, this library is built on top of the X Window System API, to provide a much simpler programming interface suited for beginners. Indeed, no X knowledge is needed at all to render graphics properly using this kind of library.

if you already have the mlx in your machine you can use include the header <mlx.h> and compile with this flags: -lmlx -framework OpenGL -framework AppKit.
or you can download another version and generate a file .A from it and compile with is like this 
$(CC) $(CFLAGS) -framework OpenGL -framework AppKit $(OBJ) $(LIBFT) minilibx_opengl/libmlx.a -o $(NAME)

there is good documentation about minilibx:\
Getting started with the minilibx : https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx. \
Pixel drawing with the minilibx : https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx. \
Managing events with the minilibx : https://aurelienbrabant.fr/blog/events-with-the-minilibx. 


https://github.com/ism417/so_long_42/assets/153442539/53a2b1e6-2e4b-45c3-9862-fbaea13498a8
