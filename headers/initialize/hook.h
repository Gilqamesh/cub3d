#ifndef HOOK_H
# define HOOK_H

int	key_press(int key, void *param);
int	key_release(int key, void *param);
int	exit_program(void *param);
int	mouse_release(int button, int x, int y, void *param);
int	mouse_press(int button, int x, int y, void *param);

#endif /* HOOK_H */
