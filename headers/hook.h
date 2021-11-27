#ifndef HOOK_H
# define HOOK_H

int	render_frame(void *param);
int	key_press(int key, void *param);
int	key_release(int key, void *param);
int	exit_program(void *param);

#endif /* HOOK_H */
