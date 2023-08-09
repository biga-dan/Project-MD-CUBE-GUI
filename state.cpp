
#include "state.h"

State::State() {
    reset();
}

void State::reset() {
    cur_mass = 1.0;
    cur_rest = 1.0;
    cur_ks = 1.0;
    cur_kd = 1.0;
    fix_mass = false;
    show_spring = true;
    center_id = -1;
    for (int i = 0; i < BF_NUM; ++i)
        force_enabled[i] = false;
    cur_grav_val[FR_GRAV] = 10.0;
    cur_grav_val[FR_CMASS] = 5.0;
    cur_grav_val[FR_PTATTRACT] = 10.0;
    cur_grav_val[FR_WALL] = 10000.0;
    cur_misc_val[FR_GRAV] = 0.0;
    cur_misc_val[FR_CMASS] = 2.0;
    cur_misc_val[FR_PTATTRACT] = 0.0;
    cur_misc_val[FR_WALL] = 1.0;
    cur_visc = 0.0;
    cur_stick = 0.0;
    cur_dt = DEF_TSTEP;
    cur_prec = 1.0;
    adaptive_step = false;
    grid_snap = false;
    cur_gsnap = 20.0;
    w_top = true;
    w_left = true;
    w_right = true;
    w_bottom = true;
    collide = false;
}
