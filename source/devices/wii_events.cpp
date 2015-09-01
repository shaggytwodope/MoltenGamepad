
#define EVNAME(X) X,"X"

struct wiimote_event {
  int id;
  const char* name;
  const char* descr;
};

enum wii_keys {
wm_a,
wm_b,
wm_plus,
wm_minus,
wm_1,
wm_2,
wm_home,
wm_left,
wm_right,
wm_down,
wm_up,

nk_a,
nk_b,
nk_plus,
nk_minus,
nk_1,
nk_2,
nk_home,
nk_left,
nk_right,
nk_down,
nk_up,
nk_c,
nk_z,

cc_a,
cc_b,
cc_x,
cc_y,
cc_plus,
cc_minus,
cc_home,
cc_left,
cc_right,
cc_up,
cc_down,
cc_l,
cc_zl,
cc_r,
cc_zr
};
wiimote_event wiimote_events_keys[][2] = {
{EVNAME(wm_a),"Wiimote A button"},
{EVNAME(wm_b),"Wiimote B button"},
{EVNAME(wm_plus),"Wiimote + button"},
{EVNAME(wm_minus),"Wiimote - button"},
{EVNAME(wm_1),"Wiimote 1 button"},
{EVNAME(wm_2),"Wiimote 2 button"},
{EVNAME(wm_home),"Wiimote home button"},
{EVNAME(wm_left),"Wiimote Dpad left"},
{EVNAME(wm_right),"Wiimote Dpad right"},
{EVNAME(wm_up),"Wiimote Dpad up"},
{EVNAME(wm_down),"Wiimote Dpad down"},

{EVNAME(nk_a),"Wiimote A button with Nunchuk"},
{EVNAME(nk_b),"Wiimote B button with Nunchuk"},
{EVNAME(nk_plus),"Wiimote + button with Nunchuk"},
{EVNAME(nk_minus),"Wiimote - button with Nunchuk"},
{EVNAME(nk_1),"Wiimote 1 button with Nunchuk"},
{EVNAME(nk_2),"Wiimote 2 button with Nunchuk"},
{EVNAME(nk_home),"Wiimote home button with Nunchuk"},
{EVNAME(nk_left),"Wiimote Dpad left with Nunchuk"},
{EVNAME(nk_right),"Wiimote Dpad right with Nunchuk"},
{EVNAME(nk_up),"Wiimote Dpad up with Nunchuk"},
{EVNAME(nk_down),"Wiimote Dpad down with Nunchuk"},
{EVNAME(nk_c),"Nunchuk C button"},
{EVNAME(nk_z),"Nunchuk Z button"},

{EVNAME(cc_a),"Classic Controller A button"},
{EVNAME(cc_b),"Classic Controller B button"},
{EVNAME(cc_x),"Classic Controller X button"},
{EVNAME(cc_y),"Classic Controller Y button"},
{EVNAME(cc_left),"Classic Controller Dpad left"},
{EVNAME(cc_right),"Classic Controller Dpad right"},
{EVNAME(cc_up),"Classic Controller Dpad up"},
{EVNAME(cc_down),"Classic Controller Dpad down"},
{EVNAME(cc_plus),"Classic Controller + button"},
{EVNAME(cc_minus),"Classic Controller - button"},
{EVNAME(cc_home),"Classic Controller Home button"},
{EVNAME(cc_l),"Classic Controller L button"},
{EVNAME(cc_zl),"Classic Controller ZL button"},
{EVNAME(cc_r),"Classic Controller R button"},
{EVNAME(cc_zr),"Classic Controller ZR button"},

{-1,nullptr, nullptr}
};

enum wii_abs {
wm_accel_x,
wm_accel_y,
wm_accel_z,

nk_wm_accel_x,
nk_wm_accel_y,
nk_wm_accel_z,
nk_accel_x,
nk_accel_y,
nk_accel_z,

cc_left_x,
cc_left_y,
cc_right_x,
cc_right_y
};

wiimote_event wiimote_events_axes[] = {
{EVNAME(wm_accel_x),"Wiimote X acceleration (long axis)"},
{EVNAME(wm_accel_y),"Wiimote Y acceleration ((+) <--> (-) axis)"},
{EVNAME(wm_accel_z),"Wiimote Z acceleration (top <--> bottom axis)"},

{EVNAME(nk_wm_accel_x),"Wiimote X acceleration with Nunchuk"},
{EVNAME(nk_wm_accel_y),"Wiimote Y acceleration with Nunchuk"},
{EVNAME(nk_wm_accel_z),"Wiimote Z acceleration with Nunchuk"},
{EVNAME(nk_accel_x),"Nunchuk X acceleration"},
{EVNAME(nk_accel_y),"Nunchuk Y acceleration"},
{EVNAME(nk_accel_z),"Nunchuk Z acceleration"},

{EVNAME(cc_left_x),"Classic Controller Left Stick X"},
{EVNAME(cc_left_y),"Classic Controller Left Stick Y"},
{EVNAME(cc_right_x),"Classic Controller Right Stick X"},
{EVNAME(cc_right_y),"Classic Controller Right Stick Y"},

{-1,nullptr, nullptr}
};
