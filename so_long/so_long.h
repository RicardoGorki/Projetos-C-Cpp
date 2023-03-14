#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "../libc/libc.h"
# include "../my_printf/my_printf.h"
# include "../get_next_line/get_next_line.h"
# include "fcntl.h"
# include "string.h"

# define HEIGHT 64
# define WIDTH 64

# define FLOOR "./assets/objects/floor.xpm"
# define WALL "./assets/objects/wall.xpm"
# define CAT "./assets/collection/collection.xpm"
# define LEAVE "./assets/objects/leave.xpm"
# define CHARACTER "./assets/character/character.xpm"

typedef struct s_vars {
	void	*img;
	int		get_collection;
	int		p_count;
	int		e_count;
	int		height;
	int		width;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*map_arg;
	char	*arg_path;
	char	**map;
	char	**map_temp;
	int		map_size;
	int		line;
	int		column;
	int		move_count;
	char	*relative_path;
	int		img_width;
	int		img_height;
}				t_vars;

int		close_press_x(t_vars *s_vars);
int		check_extension(char *map_name);
int		free_map(char **map, int line);
int		check_valid_player(t_vars *s_vars, char **map);
int		get_position(char *str, char c);
int		check_blocks(t_vars *s_vars, char c);
int		create_map(t_vars *s_vars, char *arg_map);
int		render_map(t_vars *s_vars, int lines);
int		key_hook_pressed(int keycode, t_vars *s_vars);
int		check_move(t_vars *s_vars, char c);
int		move(t_vars *s_vars, int keycode);
int		valid_map_size(t_vars *s_vars);
int		valid_map(t_vars *s_vars);
int		valid_map_wall(t_vars *s_vars);
int		check_validations(t_vars *s_vars);
int		count_players_exists(t_vars *s_vars);
int		valid_content(t_vars *s_vars);
int		check_size(t_vars *s_vars);
char	**player_location(t_vars *s_vars);
char	**check_content(t_vars *s_vars, char**map, int line);
char	**create_temp_map(t_vars *s_vars);
void	get_size_map(t_vars *s_vars, char *arg_map);
void	msg_close_game(t_vars *s_vars, char *msg);
void	msg_win_game(t_vars *s_vars, char *msg);
void	find_valid_path(t_vars *s_vars, char c);
void	v_neg_path(t_vars *s_vars, char **map, int l_pos, int c_pos);
void	v_pos_gpath(t_vars *s_vars, char **map, int l_pos, int c_pos);
void	h_proliferation_path(t_vars *s_vars, char **map, int l_pos, int c_pos);
void	v_proliferation_path(t_vars *s_vars, char **map, int l_pos, int c_pos);
void	neg_contamination(t_vars *s_vars, char **map, int l_pos, int c_pos);
void	pos_contamination(t_vars *s_vars, char **map, int l_pos, int c_pos);
void	contamination_path(t_vars *s_vars, char **map, int l_pos, int c_pos);
void	display_move(t_vars *s_vars);
void	put_image(t_vars *s_vars, char *relative_path, int lines, int column);
void	destroy_put_walk(t_vars *s_vars, int keycode);
void	msg_error(char *msg);
void	msg_error_map(t_vars *s_vars, char *msg);

#endif
