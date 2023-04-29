/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:45:43 by osabir            #+#    #+#             */
/*   Updated: 2023/03/31 15:06:35 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_tools
{
	int		check_null_and_line_y;
	int		line_y;
	int		line_x;
	int		plyer_x;
	int		plyer;
	int		plyer_x2;
	int		plyer_y2;
	int		plyer_y;
	int		door_x;
	int		door_y;
	int		door_1;
	int		coin;
	int		width;
	int		height;
	int		enemy2_x;
	int		enemy2_y;
	int		enemyy;
	void	*mlx;
	void	*mlx_win;
	void	*hero1;
	void	*hero2;
	void	*hero3;
	void	*hero4;
	void	*wall;
	void	*space;
	void	*door2;
	void	*door1;
	void	*enemy;
	void	*coins;
	char	*map_befor_split;
	char	**map;
	char	**map_to_valid_path;
	char	**map_to_valid_path2;

}t_tools;

int			looking_for_one_part2(char *s);
void		looking_for_one_part1(t_tools *help);
void		finder_door_plyer_coin(t_tools *help);
void		count_line_of_map(t_tools *help);
void		check_first_line_and_last(t_tools *help);
void		draw_the_window(t_tools *help);
void		get_the_image_xpm(t_tools *help);
char		**ft_split(char const *s, char c);
char		*get_next_line(int fd);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
void		func_move_hero_part1(int key, t_tools *help);
void		func_move_hero_part2(int key, t_tools *help);
void		move_the_hero(int x, int y, int i, t_tools *help);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_memset(void *b, int c, size_t len);
void		check_valid_path_part_1(t_tools *help, int y, int x);
void		check_valid_path_part_2(char **map2, t_tools *help);
void		check_valid_path_part_3(t_tools *help, int y, int x);
int			key_hook1(int key, t_tools *help);
void		check_double_new_line(t_tools *help);
char		*get_next_line_work(char *file_num, t_tools *help);
void		check_map_end_wth_ber(char *file_num);
char		*check_maps_nume(char *file_num, char *s);
void		ft_free_all(char **str);
void		check_everthing(char *s, t_tools *help);
void		check_line_x_and_y(t_tools *help);
void		errror(char *tmp, char *long_str);
void		if_image_not_there(t_tools *help);
void		key_esc(t_tools *help);
void		loser(t_tools *help);
void		check_valid_path_part_v1(t_tools *help, int y, int x);
void		check_valid_path_part_v2(char **map2, t_tools *help);
void		map_not_valid(void);
void		hero_up(t_tools *help, int x, int y);
void		hero_down(t_tools *help, int x, int y);
void		hero_left(t_tools *help, int x, int y);
void		hero_raghit(t_tools *help, int x, int y);
void		error_newline(void);
int			ft_putstr(char *s);
void		ft_putnbr(int n);
void		ft_putchar(char c);
void		ft__error(t_tools *help);

#endif