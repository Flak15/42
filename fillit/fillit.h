#define BUFF_SIZE 8
#define ERR_EXT 
char			*read_tet(int fd);
int				check_right(unsigned short tet, int i);
int				check_left(unsigned short tet, int i);
int				check_bottom(unsigned short tet, int i);
void			render_f(unsigned long *tets, int i);
unsigned long	proccess(unsigned long *field, unsigned long *tets, int index, int f_size);
