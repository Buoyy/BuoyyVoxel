#ifndef BV_CORE_TIME_H
#define BV_CORE_TIME_H

/** Time elapsed since last frame */
extern float delta_time;

/** Time elapsed since start of application */
extern float elapsed_time;

/**
 * Updates the time variables. To be called every frame.
 */
void time_update(void);

#endif // BV_CORE_TIME_H

