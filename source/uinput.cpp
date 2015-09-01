#include "uinput.h"


const char* try_to_find_uinput() {
  static const char* paths[] = {
    "/dev/uinput",
    "/dev/input/uinput",
    "/dev/misc/uinput"
  };
  const int num_paths = 3;
  int i;

  for (i = 0; i < num_paths; i++) {
    if (access(paths[i],F_OK) == 0) {
      return paths[i];
    }
  }
  return nullptr;
}

void uinput_destroy(int fd) {
  ioctl(fd, UI_DEV_DESTROY);
}

uinput::uinput() {
  filename = try_to_find_uinput();
  if (filename == nullptr) throw -1;

  gamepad_name = "Virtual Gamepad (MoltenGamepad)";
  keyboard_name = "Virtual Keyboard (MoltenGamepad)";
}

int uinput::make_gamepad() {
  static int abs[] = { ABS_X, ABS_Y, ABS_RX, ABS_RY};
  static int key[] = { BTN_SOUTH, BTN_EAST, BTN_NORTH, BTN_WEST, BTN_SELECT, BTN_MODE, BTN_START, BTN_TL, BTN_TL2, BTN_TR, BTN_TR2, BTN_DPAD_DOWN, BTN_DPAD_LEFT, BTN_DPAD_RIGHT, BTN_DPAD_UP,BTN_THUMBL, BTN_THUMBR};
  struct uinput_user_dev uidev;
  int fd;
  int i;
  //TODO: Read from uinput for rumble events?
  fd = open(filename, O_WRONLY | O_NONBLOCK);
  if (fd < 0) {
    perror("open uinput");
    return -1;
  }
  memset(&uidev, 0, sizeof(uidev));
  snprintf(uidev.name, UINPUT_MAX_NAME_SIZE, gamepad_name);
  uidev.id.bustype = BUS_USB;
  uidev.id.vendor = 0x1;
  uidev.id.product = 0x1;
  uidev.id.version = 1;

  ioctl(fd, UI_SET_EVBIT, EV_ABS);
  for (i = 0; i < 4; i++) {
    ioctl(fd, UI_SET_ABSBIT, abs[i]);
    uidev.absmin[abs[i]] = -32768;
    uidev.absmax[abs[i]] = 32768;
    uidev.absflat[abs[i]] = 4096;
  }

  ioctl(fd, UI_SET_EVBIT, EV_KEY);
  for (i = 0; i < 17; i++) {
    ioctl(fd, UI_SET_KEYBIT, key[i]);
  }

  write(fd, &uidev, sizeof(uidev));
  if (ioctl(fd, UI_DEV_CREATE) < 0)
    perror("uinput device creation");
  return fd;
}


int uinput::make_keyboard() {
  struct uinput_user_dev uidev;
  int fd;
  int i;

  //TODO: Read from uinput for rumble events?
  fd = open(filename, O_WRONLY | O_NONBLOCK);
  if (fd < 0) {
    perror("\nopen uinput");
    return -1;
  }
  memset(&uidev, 0, sizeof(uidev));
  snprintf(uidev.name, UINPUT_MAX_NAME_SIZE, keyboard_name);
  uidev.id.bustype = BUS_USB;
  uidev.id.vendor = 0x1;
  uidev.id.product = 0x1;
  uidev.id.version = 1;

  


  /*Just set all possible keys that come before BTN_MISC
   * This should cover all reasonable keyboard keys.*/
  ioctl(fd, UI_SET_EVBIT, EV_KEY);
  for (i = 2; i < BTN_MISC; i++) {
    ioctl(fd, UI_SET_KEYBIT, i);
  }
  for (i = KEY_OK; i < KEY_MAX; i++) {
    ioctl(fd, UI_SET_KEYBIT, i);
  }


  
  write(fd, &uidev, sizeof(uidev));
  if (ioctl(fd, UI_DEV_CREATE) < 0)
    perror("uinput device creation");
  return fd;
}

uinput::~uinput() {
}




