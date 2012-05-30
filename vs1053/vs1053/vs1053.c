#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include <stdlib.h>
#include <string.h>

#include "vs1053/vs1053.h"
#include "spi/spi.h"

#if 0
static const uint8_t vs1053_patch_v1_95[] PROGMEM = {
  0x0007, 0x0001, 0x8300, 0x0006, 0x04c2, 0xb080, 0x1402, 0x0fdf, /*    0 */
  0xffc1, 0x0007, 0x9257, 0xb212, 0x3c00, 0x3d00, 0x4024, 0x0030, /*    8 */
  0x0297, 0x3f00, 0x0024, 0x0000, 0x0401, 0x000a, 0x1055, 0x0006, /*   10 */
  0x0017, 0x3f10, 0x3401, 0x000a, 0x2795, 0x3f00, 0x3401, 0x0001, /*   18 */
  0x4717, 0xf400, 0x55c0, 0x0000, 0x0817, 0xf400, 0x57c0, 0xc090, /*   20 */
  0x0024, 0x0006, 0x0297, 0x3f00, 0x0024, 0x0000, 0x0000, 0x0007, /*   28 */
  0x81d7, 0x3f10, 0x0024, 0x3f10, 0x0024, 0x0006, 0x01d7, 0x3f00, /*   30 */
  0x0024, 0x0000, 0x190d, 0x000f, 0xf94f, 0x0000, 0xca0e, 0x280f, /*   38 */
  0xe100, 0x0006, 0x2016, 0x0000, 0x0080, 0x0005, 0x4f92, 0x3009, /*   40 */
  0x2800, 0x2909, 0xf840, 0x3613, 0x0024, 0x0006, 0x0197, 0x0006, /*   48 */
  0xa115, 0xb080, 0x0024, 0x3f00, 0x3400, 0x0007, 0x8a57, 0x3700, /*   50 */
  0x0024, 0x4080, 0x0024, 0x0000, 0x0040, 0x2800, 0xcbd5, 0x0006, /*   58 */
  0xa2d7, 0x3009, 0x3c00, 0x0006, 0xa157, 0x3009, 0x1c00, 0x0006, /*   60 */
  0x01d7, 0x0000, 0x190d, 0x000a, 0x708f, 0x0000, 0xd4ce, 0x290b, /*   68 */
  0x1a80, 0x3f00, 0x184c, 0x0030, 0x0017, 0x4080, 0x1c01, 0x0000, /*   70 */
  0x0200, 0x2800, 0xc7d5, 0xb102, 0x0024, 0x0000, 0xca08, 0x2800, /*   78 */
  0xc7d5, 0x0000, 0xd0ce, 0x0011, 0x210f, 0x0000, 0x190d, 0x280f, /*   80 */
  0xcb00, 0x3613, 0x0024, 0x0006, 0xa115, 0x0006, 0x01d7, 0x37f0, /*   88 */
  0x1401, 0x6100, 0x1c01, 0x4012, 0x0024, 0x0000, 0x8000, 0x6010, /*   90 */
  0x0024, 0x34f3, 0x0400, 0x2800, 0xd398, 0x0000, 0x0024, 0x0000, /*   98 */
  0x8001, 0x6010, 0x3c01, 0x0000, 0x000d, 0x2811, 0x8259, 0x0000, /*   a0 */
  0x0024, 0x2a11, 0x2100, 0x0030, 0x0257, 0x3700, 0x0024, 0x4080, /*   a8 */
  0x0024, 0x0000, 0x0024, 0x2800, 0xd6d5, 0x0006, 0x0197, 0x0006, /*   b0 */
  0xa115, 0x3f00, 0x3400, 0x4d86, 0x0024, 0x0000, 0x190d, 0x2800, /*   b8 */
  0xdb15, 0x0014, 0x1b01, 0x0020, 0x480f, 0x0000, 0xd9ce, 0x2920, /*   c0 */
  0x41c0, 0x0000, 0x190d, 0x000a, 0x708f, 0x0000, 0xd4ce, 0x280a, /*   c8 */
  0xcac0, 0x0000, 0x190d, 0x0039, 0x324f, 0x0001, 0x16ce, 0x2820, /*   d0 */
  0x4a18, 0xb882, 0x0024, 0x2a20, 0x48c0, 0x003f, 0xfd00, 0xb700, /*   d8 */
  0x0024, 0x003f, 0xf901, 0x6010, 0x0024, 0x0014, 0x1b01, 0x280a, /*   e0 */
  0xc505, 0x0000, 0x190d, 0x0015, 0x59c0, 0x6fc2, 0x0024, 0x0000, /*   e8 */
  0x0024, 0x2800, 0xe595, 0x0000, 0x0024, 0x290c, 0x4840, 0x3613, /*   f0 */
  0x0024, 0x290c, 0x4840, 0x4086, 0x184c, 0x0000, 0x18c2, 0x6234, /*   f8 */
  0x0024, 0x0000, 0x1d02, 0x2800, 0xe115, 0x6234, 0x0024, 0x0030, /*  100 */
  0x0317, 0x2800, 0xe580, 0x3f00, 0x0024, 0x0000, 0x1d82, 0x2800, /*  108 */
  0xe3d5, 0x6234, 0x0024, 0x2912, 0x0d00, 0x4084, 0x184c, 0xf200, /*  110 */
  0x0024, 0x6200, 0x0024, 0x0006, 0x0017, 0xb080, 0x3c40, 0x2800, /*  118 */
  0xe580, 0x3f00, 0x0024, 0x0000, 0x0202, 0x2800, 0xe595, 0xa024, /*  120 */
  0x0024, 0xc020, 0x0024, 0x0030, 0x02d7, 0x2800, 0xe580, 0x3f00, /*  128 */
  0x0024, 0x000a, 0x8c8f, 0x0000, 0xe6ce, 0x000c, 0x0981, 0x280a, /*  130 */
  0x71c0, 0x002c, 0x9d40, 0x000a, 0x708f, 0x0000, 0xd4ce, 0x280a, /*  138 */
  0xc0d5, 0x0012, 0x5182, 0x6fd6, 0x0024, 0x003f, 0xfd81, 0x280a, /*  140 */
  0x8e45, 0xb710, 0x0024, 0xb710, 0x0024, 0x003f, 0xfc01, 0x6012, /*  148 */
  0x0024, 0x0000, 0x0101, 0x2800, 0xed95, 0xffd2, 0x0024, 0x48b2, /*  150 */
  0x0024, 0x4190, 0x0024, 0x0000, 0x190d, 0x2800, 0xed95, 0x0000, /*  158 */
  0x0024, 0x3613, 0x0024, 0x000a, 0xa40f, 0x290a, 0x6040, 0x0001, /*  160 */
  0x0c8e, 0x0000, 0x190d, 0x000a, 0x708f, 0x280a, 0xc0c0, 0x0000, /*  168 */
  0xd4ce, 0x2920, 0x0100, 0x0000, 0x0401, 0x0000, 0x0180, 0x2920, /*  170 */
  0x0200, 0x3613, 0x0024, 0x2920, 0x0280, 0x3613, 0x0024, 0x0000, /*  178 */
  0x0401, 0x2920, 0x0280, 0x4084, 0x984c, 0x0019, 0x9d01, 0x6212, /*  180 */
  0x0024, 0x001e, 0x5c01, 0x2800, 0xf215, 0x6012, 0x0024, 0x0000, /*  188 */
  0x0024, 0x2800, 0xf405, 0x0000, 0x0024, 0x001b, 0x5bc1, 0x6212, /*  190 */
  0x0024, 0x001b, 0xdd81, 0x2800, 0xf7d5, 0x6012, 0x0024, 0x0000, /*  198 */
  0x0024, 0x2800, 0xf7d5, 0x0000, 0x0024, 0x0000, 0x004d, 0x000a, /*  1a0 */
  0xbf4f, 0x280a, 0xb880, 0x0000, 0xf50e, 0x0020, 0xfb4f, 0x0000, /*  1a8 */
  0x190d, 0x0000, 0xfcce, 0x2920, 0x0480, 0x3009, 0x2bc1, 0x291a, /*  1b0 */
  0x8a40, 0x36e3, 0x0024, 0x0000, 0x190d, 0x000a, 0x708f, 0x280a, /*  1b8 */
  0xcac0, 0x0000, 0xd4ce, 0x0030, 0x0017, 0x3700, 0x4024, 0x0000, /*  1c0 */
  0x0200, 0xb102, 0x0024, 0x0000, 0x0024, 0x2800, 0xfbc5, 0x0000, /*  1c8 */
  0x0024, 0x0000, 0x00c0, 0x0005, 0x4f92, 0x3009, 0x2800, 0x2909, /*  1d0 */
  0xf840, 0x3613, 0x0024, 0x0006, 0x0197, 0x0006, 0xa115, 0xb080, /*  1d8 */
  0x0024, 0x3f00, 0x3400, 0x0000, 0x190d, 0x000a, 0x708f, 0x280a, /*  1e0 */
  0xc0c0, 0x0000, 0xd4ce, 0x0000, 0x004d, 0x0020, 0xfe0f, 0x2820, /*  1e8 */
  0xfb40, 0x0000, 0xfdce, 0x2800, 0xffd5, 0x0000, 0x0024, 0x3009, /*  1f0 */
  0x13c0, 0x6012, 0x0024, 0x0000, 0x0024, 0x2801, 0x0b85, 0x0000, /*  1f8 */
  0x0024, 0x3413, 0x0024, 0x34b0, 0x0024, 0x4080, 0x0024, 0x0000, /*  200 */
  0x0200, 0x2801, 0x02d5, 0xb882, 0x0024, 0x3453, 0x0024, 0x3009, /*  208 */
  0x13c0, 0x4080, 0x0024, 0x0000, 0x0200, 0x2801, 0x0b85, 0x0000, /*  210 */
  0x0024, 0xb882, 0x130c, 0x0000, 0x004d, 0x0021, 0x058f, 0x2821, /*  218 */
  0x0340, 0x0001, 0x03ce, 0x2801, 0x0655, 0x6012, 0x0024, 0x0000, /*  220 */
  0x0024, 0x2801, 0x0655, 0x0000, 0x0024, 0x34c3, 0x184c, 0xf400, /*  228 */
  0x4500, 0x2926, 0x8e80, 0x3e10, 0x110c, 0x36f3, 0x0024, 0x34c3, /*  230 */
  0x184c, 0x3410, 0x8024, 0x3430, 0xc024, 0x4d86, 0x0024, 0x0000, /*  238 */
  0x0200, 0x2922, 0x1885, 0x0001, 0x0a08, 0x0000, 0x0200, 0x3e10, /*  240 */
  0x8024, 0x2921, 0xca80, 0x3e00, 0xc024, 0x291a, 0x8a40, 0x0000, /*  248 */
  0x0024, 0x2922, 0x1880, 0x36f3, 0x0024, 0x0000, 0x004d, 0x0021, /*  250 */
  0x0ecf, 0x2821, 0x0bc0, 0x0001, 0x0b0e, 0x2800, 0xfcc0, 0x3c30, /*  258 */
  0x4024, 0x0000, 0x190d, 0x0000, 0x330e, 0x2821, 0x0f80, 0x0027, /*  260 */
  0x9e0f, 0x2901, 0x0e00, 0x3e01, 0xc024, 0x0001, 0x0c8e, 0x000a, /*  268 */
  0xa40f, 0x280a, 0xa4c0, 0x0000, 0x190d, 0x0020, 0xcd4f, 0x2820, /*  270 */
  0xc780, 0x0001, 0x0ece, 0xb070, 0x0024, 0x0000, 0x330e, 0x0027, /*  278 */
  0x9e0f, 0x2820, 0xcd80, 0x0000, 0x190d, 0x3613, 0x0024, 0x3e10, /*  280 */
  0xb803, 0x3e14, 0x3811, 0x3e11, 0x3805, 0x3e00, 0x3801, 0x0007, /*  288 */
  0xc390, 0x0006, 0xa011, 0x3010, 0x0444, 0x3050, 0x4405, 0x6458, /*  290 */
  0x0302, 0xff94, 0x4081, 0x0003, 0xffc5, 0x48b6, 0x0024, 0xff82, /*  298 */
  0x0024, 0x42b2, 0x0042, 0xb458, 0x0003, 0x4cd6, 0x9801, 0xf248, /*  2a0 */
  0x1bc0, 0xb58a, 0x0024, 0x6de6, 0x1804, 0x0006, 0x0010, 0x3810, /*  2a8 */
  0x9bc5, 0x3800, 0xc024, 0x36f4, 0x1811, 0x36f0, 0x9803, 0x283e, /*  2b0 */
  0x2d80, 0x0fff, 0xffc3, 0x2801, 0x28c0, 0x0000, 0x0024, 0x3413, /*  2b8 */
  0x0024, 0x2801, 0x1885, 0xf400, 0x4510, 0x2801, 0x1d00, 0x6894, /*  2c0 */
  0x13cc, 0x3000, 0x184c, 0x6090, 0x93cc, 0x38b0, 0x3812, 0x3004, /*  2c8 */
  0x4024, 0x0000, 0x0910, 0x3183, 0x0024, 0x3100, 0x4024, 0x6016, /*  2d0 */
  0x0024, 0x000c, 0x8012, 0x2801, 0x1b91, 0xb884, 0x104c, 0x6894, /*  2d8 */
  0x3002, 0x0000, 0x028d, 0x003a, 0x5e0f, 0x0001, 0x30ce, 0x2939, /*  2e0 */
  0xb0c0, 0x3e10, 0x93cc, 0x4084, 0x9bd2, 0x4282, 0x0024, 0x0000, /*  2e8 */
  0x0041, 0x2801, 0x1f05, 0x6212, 0x0024, 0x0000, 0x0040, 0x2801, /*  2f0 */
  0x2405, 0x000c, 0x8390, 0x2a01, 0x2780, 0x34c3, 0x0024, 0x3444, /*  2f8 */
  0x0024, 0x3073, 0x0024, 0x3053, 0x0024, 0x3000, 0x0024, 0x6092, /*  300 */
  0x098c, 0x0000, 0x0241, 0x2801, 0x2785, 0x32a0, 0x0024, 0x6012, /*  308 */
  0x0024, 0x0000, 0x0024, 0x2801, 0x2795, 0x0000, 0x0024, 0x3613, /*  310 */
  0x0024, 0x3001, 0x3844, 0x2920, 0x0580, 0x3009, 0x3852, 0xc090, /*  318 */
  0x9bd2, 0x2801, 0x2780, 0x3800, 0x1bc4, 0x000c, 0x4113, 0xb880, /*  320 */
  0x2380, 0x3304, 0x4024, 0x3800, 0x05cc, 0xcc92, 0x05cc, 0x3910, /*  328 */
  0x0024, 0x3910, 0x4024, 0x000c, 0x8110, 0x3910, 0x0024, 0x39f0, /*  330 */
  0x4024, 0x3810, 0x0024, 0x38d0, 0x4024, 0x3810, 0x0024, 0x38f0, /*  338 */
  0x4024, 0x34c3, 0x0024, 0x3444, 0x0024, 0x3073, 0x0024, 0x3063, /*  340 */
  0x0024, 0x3000, 0x0024, 0x4080, 0x0024, 0x0000, 0x0024, 0x2839, /*  348 */
  0x53d5, 0x4284, 0x0024, 0x3613, 0x0024, 0x2801, 0x2ac5, 0x6898, /*  350 */
  0xb804, 0x0000, 0x0084, 0x293b, 0x1cc0, 0x3613, 0x0024, 0x000c, /*  358 */
  0x8117, 0x3711, 0x0024, 0x37d1, 0x4024, 0x4e8a, 0x0024, 0x0000, /*  360 */
  0x0015, 0x2801, 0x2d85, 0xce9a, 0x0024, 0x3f11, 0x0024, 0x3f01, /*  368 */
  0x4024, 0x000c, 0x8197, 0x408a, 0x9bc4, 0x3f15, 0x4024, 0x2801, /*  370 */
  0x2fc5, 0x4284, 0x3c15, 0x6590, 0x0024, 0x0000, 0x0024, 0x2839, /*  378 */
  0x53d5, 0x4284, 0x0024, 0x0000, 0x0024, 0x2801, 0x1758, 0x458a, /*  380 */
  0x0024, 0x2a39, 0x53c0, 0x003e, 0x2d4f, 0x283a, 0x5ed5, 0x0001, /*  388 */
  0x100e, 0x000c, 0x4653, 0x0000, 0x0246, 0xffac, 0x0c01, 0x48be, /*  390 */
  0x0024, 0x4162, 0x4546, 0x6642, 0x4055, 0x3501, 0x8024, 0x0000, /*  398 */
  0x0087, 0x667c, 0x4057, 0x000c, 0x41d5, 0x283a, 0x62d5, 0x3501, /*  3a0 */
  0x8024, 0x667c, 0x1c47, 0x3701, 0x8024, 0x283a, 0x62d5, 0xc67c, /*  3a8 */
  0x0024, 0x0000, 0x0024, 0x283a, 0x62c5, 0x0000, 0x0024, 0x2a3a, /*  3b0 */
  0x5ec0, 0x3009, 0x3851, 0x3e14, 0xf812, 0x3e12, 0xb817, 0x3e11, /*  3b8 */
  0x8024, 0x0006, 0x0293, 0x3301, 0x8024, 0x468c, 0x3804, 0x0006, /*  3c0 */
  0xa057, 0x2801, 0x3cc4, 0x0006, 0x0011, 0x469c, 0x0024, 0x3be1, /*  3c8 */
  0x8024, 0x2801, 0x3cd5, 0x0006, 0xc392, 0x3311, 0x0024, 0x33f1, /*  3d0 */
  0x2844, 0x3009, 0x2bc4, 0x0030, 0x04d2, 0x3311, 0x0024, 0x3a11, /*  3d8 */
  0x0024, 0x3201, 0x8024, 0x003f, 0xfc04, 0xb64c, 0x0fc4, 0xc648, /*  3e0 */
  0x0024, 0x3a01, 0x0024, 0x3111, 0x1fd3, 0x6498, 0x07c6, 0x868c, /*  3e8 */
  0x2444, 0x0023, 0xffd2, 0x3901, 0x8e06, 0x0030, 0x0551, 0x3911, /*  3f0 */
  0x8e06, 0x3961, 0x9c44, 0xf400, 0x44c6, 0xd46c, 0x1bc4, 0x36f1, /*  3f8 */
  0xbc13, 0x2801, 0x4655, 0x36f2, 0x9817, 0x002b, 0xffd2, 0x3383, /*  400 */
  0x188c, 0x3e01, 0x8c06, 0x0006, 0xa097, 0x3009, 0x1c12, 0x3213, /*  408 */
  0x0024, 0x468c, 0xbc12, 0x002b, 0xffd2, 0xf400, 0x4197, 0x2801, /*  410 */
  0x4344, 0x3713, 0x0024, 0x2801, 0x4385, 0x37e3, 0x0024, 0x3009, /*  418 */
  0x2c17, 0x3383, 0x0024, 0x3009, 0x0c06, 0x468c, 0x4197, 0x0006, /*  420 */
  0xa052, 0x2801, 0x4584, 0x3713, 0x2813, 0x2801, 0x45c5, 0x37e3, /*  428 */
  0x0024, 0x3009, 0x2c17, 0x36f1, 0x8024, 0x36f2, 0x9817, 0x36f4, /*  430 */
  0xd812, 0x2100, 0x0000, 0x3904, 0x5bd1, 0x2a01, 0x368e, 0x3e11, /*  438 */
  0x7804, 0x0030, 0x0257, 0x3701, 0x0024, 0x0013, 0x4d05, 0xd45b, /*  440 */
  0xe0e1, 0x0007, 0xc795, 0x2801, 0x4dd5, 0x0fff, 0xff45, 0x3511, /*  448 */
  0x184c, 0x4488, 0xb808, 0x0006, 0x8a97, 0x2801, 0x4d85, 0x3009, /*  450 */
  0x1c40, 0x3511, 0x1fc1, 0x0000, 0x0020, 0xac52, 0x1405, 0x6ce2, /*  458 */
  0x0024, 0x0000, 0x0024, 0x2801, 0x4d81, 0x68c2, 0x0024, 0x291a, /*  460 */
  0x8a40, 0x3e10, 0x0024, 0x2921, 0xca80, 0x3e00, 0x4024, 0x36f3, /*  468 */
  0x0024, 0x3009, 0x1bc8, 0x36f0, 0x1801, 0x3601, 0x5804, 0x3e13, /*  470 */
  0x780f, 0x3e13, 0xb808, 0x0008, 0x9b0f, 0x0001, 0x508e, 0x2908, /*  478 */
  0x9300, 0x0000, 0x004d, 0x36f3, 0x9808, 0x2000, 0x0000, 0x36f3, /*  480 */
  0x580f, 0x0006, 0xc610, 0x0007, 0x81d7, 0x3710, 0x0024, 0x3700, /*  488 */
  0x4024, 0x0034, 0x0002, 0x0000, 0x01c3, 0x6dc6, 0x8001, 0xff32, /*  490 */
  0x4043, 0x48b2, 0x0024, 0xffa6, 0x0024, 0x40b2, 0x0024, 0xb386, /*  498 */
  0x4142, 0x0000, 0x0106, 0x2914, 0xaa80, 0xad66, 0x0024, 0x6c96, /*  4a0 */
  0x0024, 0x0000, 0x0201, 0xf1d6, 0x0024, 0x61de, 0x0024, 0x0006, /*  4a8 */
  0xc612, 0x2801, 0x5641, 0x0006, 0xc713, 0x4c86, 0x0024, 0x2912, /*  4b0 */
  0x1180, 0x0006, 0xc351, 0x0006, 0x0210, 0x2912, 0x0d00, 0x3810, /*  4b8 */
  0x984c, 0xf200, 0x2043, 0x2808, 0xa000, 0x3800, 0x0024, 0x0007, /*  4c0 */
  0x0001, 0x802e, 0x0006, 0x0002, 0x2801, 0x4740, 0x0007, 0x0001, /*  4c8 */
  0x8050, 0x0006, 0x009c, 0x3e12, 0x3800, 0x3e00, 0xb804, 0x0030, /*  4d0 */
  0x0015, 0x0008, 0x0002, 0x3511, 0x184c, 0xb428, 0x1402, 0x0000, /*  4d8 */
  0x8004, 0x2910, 0x0195, 0x0000, 0x1488, 0xb428, 0x0024, 0x0006, /*  4e0 */
  0x0095, 0x2800, 0x1f45, 0x3e13, 0x780e, 0x3e11, 0x7803, 0x3e13, /*  4e8 */
  0xf806, 0x3e01, 0xf801, 0x3510, 0x8024, 0x3510, 0xc024, 0x0000, /*  4f0 */
  0x0021, 0xf2d6, 0x1444, 0x4090, 0x1745, 0x0000, 0x0022, 0xf2ea, /*  4f8 */
  0x4497, 0x2400, 0x1b00, 0x6090, 0x1c46, 0xfe6c, 0x0024, 0xcdb6, /*  500 */
  0x1c46, 0xfe6c, 0x0024, 0xceba, 0x1c46, 0x4d86, 0x3442, 0x0000, /*  508 */
  0x09c7, 0x2800, 0x1c85, 0xf5d4, 0x3443, 0x6724, 0x0024, 0x4e8a, /*  510 */
  0x3444, 0x0000, 0x0206, 0x2800, 0x1dc5, 0xf5e8, 0x3705, 0x6748, /*  518 */
  0x0024, 0xa264, 0x9801, 0xc248, 0x1bc7, 0x0030, 0x03d5, 0x3d01, /*  520 */
  0x0024, 0x36f3, 0xd806, 0x3601, 0x5803, 0x36f3, 0x0024, 0x36f3, /*  528 */
  0x580e, 0x0007, 0x8257, 0x3700, 0x8024, 0xf224, 0x0024, 0x0000, /*  530 */
  0x0024, 0x2800, 0x21d1, 0x3600, 0x9844, 0x2900, 0x2780, 0x0000, /*  538 */
  0x2248, 0x2911, 0xf140, 0x0000, 0x0024, 0x0030, 0x0057, 0x3700, /*  540 */
  0x0024, 0xf200, 0x4595, 0x0fff, 0xfe02, 0xa024, 0x164c, 0x8000, /*  548 */
  0x17cc, 0x3f00, 0x0024, 0x3500, 0x0024, 0x0021, 0x6d82, 0xd024, /*  550 */
  0x44c0, 0x0006, 0xa402, 0x2800, 0x2695, 0xd024, 0x0024, 0x0000, /*  558 */
  0x0000, 0x2800, 0x2695, 0x000b, 0x6d57, 0x3009, 0x3c00, 0x36f0, /*  560 */
  0x8024, 0x36f2, 0x1800, 0x2000, 0x0000, 0x0000, 0x0024, 0x0007, /*  568 */
  0x0001, 0x8030, 0x0006, 0x0002, 0x2800, 0x1400, 0x0007, 0x0001, /*  570 */
  0x809e, 0x0006, 0x0040, 0x3e14, 0x7810, 0x3e13, 0xb80d, 0x3e13, /*  578 */
  0xf80a, 0x3e10, 0xb803, 0x3e11, 0x3805, 0x3e11, 0xb807, 0x3e14, /*  580 */
  0xf801, 0x0001, 0x000a, 0x0006, 0xc4d5, 0xbf8e, 0x9442, 0x3e01, /*  588 */
  0x9403, 0x0006, 0xa017, 0x0023, 0xffd1, 0x0000, 0x0053, 0x3281, /*  590 */
  0xf806, 0x4091, 0x2d64, 0x2400, 0x2d00, 0x4efa, 0x9c10, 0xf1eb, /*  598 */
  0x6061, 0xfe55, 0x2f66, 0x5653, 0x2d64, 0x48b2, 0xa201, 0x4efa, /*  5a0 */
  0xa201, 0x36f3, 0x3c10, 0x36f4, 0xd801, 0x36f1, 0x9807, 0x36f1, /*  5a8 */
  0x1805, 0x36f0, 0x9803, 0x36f3, 0xd80a, 0x36f3, 0x980d, 0x2000, /*  5b0 */
  0x0000, 0x36f4, 0x5810, 0x0007, 0x0001, 0x80be, 0x0006, 0x001c, /*  5b8 */
  0x3e12, 0xb817, 0x3e14, 0xf812, 0x3e01, 0xb811, 0x0007, 0x9717, /*  5c0 */
  0x0020, 0xffd2, 0x0030, 0x11d1, 0x3111, 0x8024, 0x3704, 0xc024, /*  5c8 */
  0x3b81, 0x8024, 0x3101, 0x8024, 0x3b81, 0x8024, 0x3f04, 0xc024, /*  5d0 */
  0x2808, 0x4800, 0x36f1, 0x9811, 0x0007, 0x0001, 0x8028, 0x0006, /*  5d8 */
  0x0002, 0x2a00, 0x2f8e, 0x0007, 0x0001, 0x8032, 0x0006, 0x0002, /*  5e0 */
  0x2800, 0x38c0, 0x0007, 0x0001, 0x80cc, 0x0006, 0x002e, 0x36f3, /*  5e8 */
  0x0024, 0x3009, 0x3848, 0x3e14, 0x3811, 0x3e00, 0x0024, 0x0000, /*  5f0 */
  0x4000, 0x0001, 0x0010, 0x2915, 0x94c0, 0x0001, 0xcc11, 0x36f0, /*  5f8 */
  0x0024, 0x2927, 0x9e40, 0x3604, 0x1811, 0x3613, 0x0024, 0x3e14, /*  600 */
  0x3811, 0x3e00, 0x0024, 0x0000, 0x4000, 0x0001, 0x0010, 0x2915, /*  608 */
  0x94c0, 0x0001, 0xcc11, 0x36f0, 0x0024, 0x36f4, 0x1811, 0x3009, /*  610 */
  0x1808, 0x2000, 0x0000, 0x0000, 0x190d, 0x0007, 0x0001, 0x80e3, /*  618 */
  0x0006, 0x0172, 0x3e12, 0xb817, 0x3e12, 0x3815, 0x3e05, 0xb814, /*  620 */
  0x3625, 0x0024, 0x0000, 0x800a, 0x3e10, 0x3801, 0x3e10, 0xb803, /*  628 */
  0x3e11, 0x3805, 0x3e11, 0xb807, 0x3e14, 0x3811, 0x0006, 0xa090, /*  630 */
  0x2912, 0x0d00, 0x3e14, 0xc024, 0x4088, 0x8000, 0x4080, 0x0024, /*  638 */
  0x0007, 0x90d1, 0x2800, 0x3e85, 0x0000, 0x0024, 0x0007, 0x9051, /*  640 */
  0x3100, 0x4024, 0x4100, 0x0024, 0x3900, 0x0024, 0x0007, 0x90d1, /*  648 */
  0x0004, 0x0000, 0x31f0, 0x4024, 0x6014, 0x0400, 0x0007, 0x9051, /*  650 */
  0x2800, 0x4291, 0x4080, 0x0024, 0x0000, 0x0000, 0x2800, 0x4245, /*  658 */
  0x0000, 0x0024, 0x0007, 0x9053, 0x3300, 0x0024, 0x4080, 0x0024, /*  660 */
  0x0000, 0x0000, 0x2800, 0x4298, 0x0000, 0x0024, 0x3900, 0x0024, /*  668 */
  0x3200, 0x504c, 0x6410, 0x0024, 0x3cf0, 0x0000, 0x4080, 0x0024, /*  670 */
  0x0006, 0xc691, 0x2800, 0x5b05, 0x0000, 0x1001, 0x0007, 0x9051, /*  678 */
  0x3100, 0x0024, 0x6012, 0x0024, 0x0006, 0xc6d0, 0x2800, 0x4fc9, /*  680 */
  0x003f, 0xe000, 0x0006, 0xc693, 0x3900, 0x0c00, 0x3009, 0x0001, /*  688 */
  0x6014, 0x0024, 0x0007, 0x1ad0, 0x2800, 0x4fd5, 0x3009, 0x0000, /*  690 */
  0x4080, 0x0024, 0x0000, 0x0301, 0x2800, 0x4945, 0x4090, 0x0024, /*  698 */
  0x0000, 0x0024, 0x2800, 0x4a55, 0x0000, 0x0024, 0x3009, 0x0000, /*  6a0 */
  0xc012, 0x0024, 0x2800, 0x4fc0, 0x3009, 0x2001, 0x3009, 0x0000, /*  6a8 */
  0x6012, 0x0024, 0x0000, 0x0024, 0x2800, 0x4c55, 0x0000, 0x0024, /*  6b0 */
  0x0000, 0x0380, 0x2800, 0x4fc0, 0x3009, 0x2000, 0x0000, 0x0341, /*  6b8 */
  0x6012, 0x0024, 0x0000, 0x0024, 0x2800, 0x4e55, 0x0000, 0x0024, /*  6c0 */
  0x0000, 0x03c0, 0x2800, 0x4fc0, 0x3009, 0x2000, 0x0000, 0x0381, /*  6c8 */
  0x6012, 0x0024, 0x0000, 0x00c0, 0x2800, 0x4fd5, 0x0000, 0x0024, /*  6d0 */
  0x3009, 0x2000, 0x0006, 0xa090, 0x3009, 0x0000, 0x4080, 0x0024, /*  6d8 */
  0x0000, 0x0081, 0x2800, 0x5455, 0x0007, 0x8c13, 0x3300, 0x104c, /*  6e0 */
  0xb010, 0x0024, 0x0002, 0x8001, 0x2800, 0x5705, 0x34f0, 0x0024, /*  6e8 */
  0x2800, 0x5440, 0x0000, 0x0024, 0x3009, 0x0000, 0x6090, 0x0024, /*  6f0 */
  0x3009, 0x2000, 0x2900, 0x0b80, 0x3009, 0x0405, 0x0006, 0xc6d1, /*  6f8 */
  0x0006, 0xc690, 0x3009, 0x0000, 0x3009, 0x0401, 0x6014, 0x0024, /*  700 */
  0x0006, 0xc351, 0x2800, 0x5311, 0x0006, 0xa093, 0xb880, 0x0024, /*  708 */
  0x2800, 0x6380, 0x3009, 0x2c00, 0x4040, 0x0024, 0x6012, 0x0024, /*  710 */
  0x0006, 0xc6d0, 0x2800, 0x6398, 0x0006, 0xc693, 0x3009, 0x0c00, /*  718 */
  0x3009, 0x0001, 0x6014, 0x0024, 0x0006, 0xc350, 0x2800, 0x6381, /*  720 */
  0x0000, 0x0024, 0x6090, 0x0024, 0x3009, 0x2c00, 0x3009, 0x0005, /*  728 */
  0x2900, 0x0b80, 0x0000, 0x6388, 0x3009, 0x0400, 0x4080, 0x0024, /*  730 */
  0x0003, 0x8000, 0x2800, 0x6385, 0x0000, 0x0024, 0x6400, 0x0024, /*  738 */
  0x0000, 0x0081, 0x2800, 0x6389, 0x0007, 0x8c13, 0x3300, 0x0024, /*  740 */
  0xb010, 0x0024, 0x0006, 0xc650, 0x2800, 0x6395, 0x0001, 0x0002, /*  748 */
  0x3413, 0x0000, 0x3009, 0x0401, 0x4010, 0x8406, 0x0000, 0x0281, /*  750 */
  0xa010, 0x13c1, 0x4122, 0x0024, 0x0000, 0x03c2, 0x6122, 0x8002, /*  758 */
  0x462c, 0x0024, 0x469c, 0x0024, 0xfee2, 0x0024, 0x48be, 0x0024, /*  760 */
  0x6066, 0x8400, 0x0006, 0xc350, 0x2800, 0x6381, 0x0000, 0x0024, /*  768 */
  0x4090, 0x0024, 0x3009, 0x2400, 0x2900, 0x0b80, 0x3009, 0x0005, /*  770 */
  0x2912, 0x0d00, 0x3613, 0x0024, 0x3a00, 0x0024, 0x36f4, 0xc024, /*  778 */
  0x36f4, 0x1811, 0x36f1, 0x9807, 0x36f1, 0x1805, 0x36f0, 0x9803, /*  780 */
  0x36f0, 0x1801, 0x3405, 0x9014, 0x36f3, 0x0024, 0x36f2, 0x1815, /*  788 */
  0x2000, 0x0000, 0x36f2, 0x9817, 0x000a, 0x0001, 0x0300,
};

#define VS1053_PATCH vs1053_patch_v1_95
#endif

#if 0
static const uint8_t vs1053_ima_patch_v1_0[] PROGMEM = {
  0x0007, 0x0001, 0x8010, 0x0006, 0x001c, 0x3e12, 0xb817, 0x3e14, /*    0 */
  0xf812, 0x3e01, 0xb811, 0x0007, 0x9717, 0x0020, 0xffd2, 0x0030, /*    8 */
  0x11d1, 0x3111, 0x8024, 0x3704, 0xc024, 0x3b81, 0x8024, 0x3101, /*   10 */
  0x8024, 0x3b81, 0x8024, 0x3f04, 0xc024, 0x2808, 0x4800, 0x36f1, /*   18 */
  0x9811, 0x0007, 0x0001, 0x8028, 0x0006, 0x0002, 0x2a00, 0x040e,
};
#endif

#define VS1053_XCS_SHARED
#define VS1053_SPI_TRANSACTIONS
/* #define VS1053_SPI_HIGHEST_SPEED */

// CLK freq = 12.288MHz[FREQ=0/default] * 3.5[MULT=4] = 43.008MHz
#define VS1053_CLKI_43008KHZ  0x9800

#define VS1053_CLKI_SPEED_KHZ 43008UL

#if !defined(VS1053_XCS_SHARED)
#define VS1053_XDCS_DDR    DDRA
#define VS1053_XDCS_PORT   PORTA
#define VS1053_XDCS_BIT    0
#endif

#define VS1053_DREQ_DDR    DDRA
#define VS1053_DREQ_PORT   PINA
#define VS1053_DREQ_PU     PORTA
#define VS1053_DREQ_BIT    1

#define VS1053_XRES_DDR    DDRA
#define VS1053_XRES_PORT   PORTA
#define VS1053_XRES_BIT    2

#define VS1053_XCS_DDR     DDRA
#define VS1053_XCS_PORT    PORTA
#define VS1053_XCS_BIT     3

#define VS1053_DATA_CHUNK_SIZE 32

#if defined(VS1053_XCS_SHARED)
#define VS1053_MODE_REG_VALUE (0                \
            | (1<<VS1053_SCI_REG_MODE_SDINEW)   \
            | (1<<VS1053_SCI_REG_MODE_SDISHARE) \
            | (1<<VS1053_SCI_REG_MODE_RESET))
#else
#define VS1053_MODE_REG_VALUE (0                \
            | (1<<VS1053_SCI_REG_MODE_SDINEW)   \
            | (1<<VS1053_SCI_REG_MODE_RESET))
#endif

#define VS1053_PARAMETRIC_ADDRESS 0x1E02
#define VS1053_PARAMETRIC_VERSION 0x0003

struct vs1053_parametric {
    /* configs are not cleared between files */
    uint16_t version;       /* 0x1E02      structure version */
    uint16_t config1;       /* 0x1E03      ---- ---- ppss RRRR PS mode, SBR mode, Reverb */
    uint16_t playSpeed;     /* 0x1E04      0,1 = normal speed, 2 = twice, 3 = three times etc. */
    uint16_t byteRate;      /* 0x1E05      average byterate */
    uint16_t endFillByte;   /* 0x1E06      byte value to send after file sent */
    uint16_t reserved[16];  /* 0x1E07..15  file byte offsets */
    uint32_t jumpPoints[8]; /* 0x1E16..25  file byte offsets */
    uint16_t latestJump;    /* 0x1E26      index to lastly updated jumpPoint */
    uint32_t positionMsec;  /* 0x1E27-28   play position, if known (WMA, Ogg Vorbis) */
    int16_t resync;         /* 0x1E29      > 0 for automatic m4a, ADIF, WMA resyncs */
    union {
        struct {
            uint32_t curPacketSize;
            uint32_t packetSize;
        } wma;
        struct {
            uint16_t sceFoundMask;   /* 0x1E2a   SCE's found since last clear */
            uint16_t cpeFoundMask;   /* 0x1E2b   CPE's found since last clear */
            uint16_t lfeFoundMask;   /* 0x1E2c   LFE's found since last clear */
            uint16_t playSelect;     /* 0x1E2d   0 = first any, initialized at aac init */
            int16_t dynCompress;     /* 0x1E2e   -8192=1.0, initialized at aac init */
            int16_t dynBoost;        /* 0x1E2f   8192=1.0, initialized at aac init */
            uint16_t sbrAndPsStatus; /* 0x1E30   1=SBR, 2=upsample, 4=PS, 8=PS active */
        } aac;
        struct {
            uint32_t bytesLeft;
        } midi;
        struct {
            int16_t gain; /* 0x1E2a proposed gain offset in 0.5dB steps, default = -12 */
        } vorbis;
    } i;
};

#define VS1053_PARAMETRIC_ENDFILLBYTE_ADDRESS (VS1053_PARAMETRIC_ADDRESS + __builtin_offsetof(struct vs1053_parametric, endFillByte))
#define VS1053_PARAMETRIC_VERSION_ADDRESS     (VS1053_PARAMETRIC_ADDRESS + __builtin_offsetof(struct vs1053_parametric, version))

#define min(a,b) ((a) < (b) ? (a) : (b))

static inline void vs1053_wait_data_request(void)
{
    while (!(VS1053_DREQ_PORT & (1<<VS1053_DREQ_BIT)));
}

static inline void vs1053_enable_cs(void)
{
    _delay_us(2*(1000./(double)VS1053_CLKI_SPEED_KHZ)); // tXCS  : 2 CLKI
    VS1053_XCS_PORT &= ~(1 << VS1053_XCS_BIT);
    _delay_us(0.005); // tXCSS : 5 ns
}

static inline void vs1053_disable_cs(void)
{
    _delay_us(1000./(double)VS1053_CLKI_SPEED_KHZ); // tXCSH : 1 CLKI
    VS1053_XCS_PORT |= 1 << VS1053_XCS_BIT;
}

#if !defined(VS1053_XCS_SHARED)
static inline void vs1053_enable_dcs(void)
{
    VS1053_XDCS_PORT &= ~(1 << VS1053_XDCS_BIT);
}

static inline void vs1053_disable_dcs(void)
{
    VS1053_XDCS_PORT |= 1 << VS1053_XDCS_BIT;
}
#else
static inline void vs1053_enable_dcs(void)
{
}

static inline void vs1053_disable_dcs(void)
{
}
#endif

static inline void
__vs1053_write_register(vs1053_sci_reg_t reg, uint16_t value)
{
#if !defined(VS1053_SPI_TRANSACTIONS)
    spi_write(0x2); // vs1053 write command
    spi_write(reg);

    spi_write(value >> 8);
    spi_write(value);
#else
    {
        uint8_t out[4] = {0x2, reg, (value>>8)&0xFF, value&0xFF};
        spi_transfer_t xfer = {.in = NULL, .out = out, .len = 4};
        spi_transfer(&xfer);
    }
#endif
}

void vs1053_write_register(vs1053_sci_reg_t reg, uint16_t value)
{
    vs1053_wait_data_request();

    vs1053_enable_cs();
    __vs1053_write_register(reg, value);
    vs1053_disable_cs();
}

static inline void
__vs1053_read_register(vs1053_sci_reg_t reg, uint16_t *value)
{
#if !defined(VS1053_SPI_TRANSACTIONS)
    {
        uint8_t c;

        spi_write(0x3); // vs1053 read command
        spi_write(reg);

        spi_read(&c);
        *value = c << 8;
        spi_read(&c);
        *value |= c;
    }
#else
    {
        uint8_t in[4], out[4] = {0x3, reg, 0xff, 0xff};
        spi_transfer_t xfer = {.in = in, .out = out, .len = 4};
        spi_transfer(&xfer);
        *value = in[2] << 8 | in[3];
    }
#endif
}


void vs1053_read_register(vs1053_sci_reg_t reg, uint16_t *value)
{
    vs1053_wait_data_request();

    vs1053_enable_cs();
    __vs1053_read_register(reg, value);
    vs1053_disable_cs();
}

static void vs1053_read_ram(uint16_t addr, uint8_t count, uint16_t *value)
{
    vs1053_enable_cs();

    /* internal pointer is autoincremented */
    vs1053_wait_data_request();
    __vs1053_write_register(VS1053_SCI_REG_WRAMADDR, addr);

    while (count) {
        vs1053_wait_data_request();
        __vs1053_read_register(VS1053_SCI_REG_WRAM, value);
        --count;
        ++value;
    }

    vs1053_disable_cs();
}

static void vs1053_write_ram(uint16_t addr, uint8_t count, uint16_t *value)
{
    vs1053_enable_cs();

    /* internal pointer is autoincremented */
    vs1053_wait_data_request();
    __vs1053_write_register(VS1053_SCI_REG_WRAMADDR, addr);

    while (count) {
        vs1053_wait_data_request();
        __vs1053_write_register(VS1053_SCI_REG_WRAM, *value);
        --count;
        ++value;
    }

    vs1053_disable_cs();
}

void vs1053_soft_reset(void)
{
    vs1053_write_register(VS1053_SCI_REG_MODE, VS1053_MODE_REG_VALUE);

    _delay_ms(1);
    vs1053_wait_data_request();
}

static void vs1053_load_patch(const uint8_t *patch, uint16_t size)
{
    uint16_t i;

    while (i < size) {
        uint16_t addr, n, val;
        addr = pgm_read_byte_near(patch[i]), ++i;
        n = pgm_read_byte_near(patch[i]), ++i;

        if (n & 0x8000) { /* write the next word n times to register addr */
            n &= 0x7FFF;
            val = pgm_read_byte_near(patch[i]), ++i;
            while (n--)
                vs1053_write_register(addr, val);
        } else { /* write next n words to register addr */
            while (n--) {
                val = pgm_read_byte_near(patch[i]), ++i;
                vs1053_write_register(addr, val);
            }
        }
    }
}

void vs1053_setup(void)
{
    VS1053_XRES_DDR  |= 1 << VS1053_XRES_BIT;
    VS1053_XRES_PORT &= ~(1 << VS1053_XRES_BIT);

#if !defined(VS1053_XCS_SHARED)
    VS1053_XDCS_DDR  |= 1 << VS1053_XDCS_BIT;
    VS1053_XDCS_PORT |= 1 << VS1053_XDCS_BIT;
#endif

    VS1053_XCS_DDR  |= 1 << VS1053_XCS_BIT;
    VS1053_XCS_PORT |= 1 << VS1053_XCS_BIT;

    VS1053_DREQ_DDR  &= ~(1 << VS1053_DREQ_BIT);
    /* VS1053_DREQ_PU   |= 1 << VS1053_DREQ_BIT; */

    spi_enable();
    spi_setup(SPI_MODE0, spi_speed_to_clkdiv(1000000UL), SPI_BIT_ORDER_MSB_FIRST);

    VS1053_XRES_PORT &= ~(1 << VS1053_XRES_BIT);
    _delay_ms(1);
    VS1053_XRES_PORT |= 1 << VS1053_XRES_BIT;
    _delay_ms(10);

    vs1053_soft_reset();

    vs1053_write_register(VS1053_SCI_REG_VOL, 0xffff);    /* switch analog off */
    _delay_ms(1);
    vs1053_write_register(VS1053_SCI_REG_AUDATA,10);      /* 10Hz : slow sample rate for slow analog part startup */
    vs1053_write_register(VS1053_SCI_REG_VOL, 0xfefe);    /* switch analog on, silence */
    vs1053_write_register(VS1053_SCI_REG_AUDATA, 44101);  /* 44.1kHz stereo */

#if 0
    vs1053_write_register(VS1053_SCI_REG_VOL, 0x2020);    /* initial volume = 0x20*(-0.5) = -16dB */
#endif
    vs1053_write_register(VS1053_SCI_REG_VOL, 0x0000); /* max vol */

#if VS1053_CLKI_SPEED_KHZ == 43008UL
    vs1053_write_register(VS1053_SCI_REG_CLOCKF, VS1053_CLKI_43008KHZ);
#else
#error Unsupported VS1053 CLK speed
#endif
    _delay_ms(100);
    vs1053_wait_data_request();

#if defined(VS1053_PATCH)
    vs1053_load_patch(VS1053_PATCH, sizeof(VS1053_PATCH));
#endif

#if defined(VS1053_SPI_HIGHEST_SPEED)
    // max SDI clock freq is CLKI/7
    spi_setup(SPI_MODE0, spi_speed_to_clkdiv((VS1053_CLKI_SPEED_KHZ*1000UL)/7UL), SPI_BIT_ORDER_MSB_FIRST);
#endif
}

static inline
void vs1053_push_chunk(const uint8_t *data, uint8_t len)
{
#if !defined(VS1053_SPI_TRANSACTIONS)
    uint8_t i;

    for (i=0;i<len;++i)
        spi_write(data[i]);
#else
    {
        spi_transfer_t xfer = {.in = NULL, .out = data, .len = len};
        spi_transfer(&xfer);
    }
#endif
}

static void vs1053_push_byte(uint8_t b, uint16_t count)
{
    uint8_t c[VS1053_DATA_CHUNK_SIZE];

    memset(c, b, VS1053_DATA_CHUNK_SIZE);

    while (count) {
        uint8_t l = min(count, VS1053_DATA_CHUNK_SIZE);

        vs1053_wait_data_request();

        vs1053_push_chunk(c, l);

        count -= l;
    }
}

void vs1053_play(vs1053_audio_feeder_t feeder, void *priv)
{
    uint8_t *data;
    uint16_t len;
    uint16_t efb;
    uint8_t l, last;

    vs1053_enable_dcs();

    for (;;) {
        last = feeder(&data, &len, priv);

        while (len) {
            l = min(len, VS1053_DATA_CHUNK_SIZE);

            vs1053_wait_data_request();

            vs1053_push_chunk(data, l);

            len -= l;
            data += l;
        }

        if (last)
            break;
    }

    vs1053_disable_dcs();

    vs1053_read_ram(VS1053_PARAMETRIC_ENDFILLBYTE_ADDRESS, 1, &efb);

    vs1053_enable_dcs();
    vs1053_push_byte(efb, 2052);
    vs1053_disable_dcs();

    vs1053_write_register(VS1053_SCI_REG_MODE,
            VS1053_MODE_REG_VALUE | (1<<VS1053_SCI_REG_MODE_CANCEL));

    l = 0;
    for (;;) {
        uint16_t mode;

        vs1053_enable_dcs();
        vs1053_push_byte(efb, 32);
        vs1053_disable_dcs();

        vs1053_read_register(VS1053_SCI_REG_MODE, &mode);

        if (!(mode&(1<<VS1053_SCI_REG_MODE_CANCEL)))
            break;

        l += 32;
        if (l >= 2048/32) {
            vs1053_soft_reset();
            break;
        }
    }
}

struct vs1053_pgm_feeder_priv {
    const uint8_t *data;
    uint16_t len;
    uint8_t buffer[VS1053_DATA_CHUNK_SIZE];
};

static uint8_t vs1053_pgm_feeder(uint8_t **data, uint16_t *len, void *priv)
{
    struct vs1053_pgm_feeder_priv *p = priv;
    uint8_t l = min(p->len, VS1053_DATA_CHUNK_SIZE);

    memcpy_P(p->buffer, p->data, l);

    p->data += l;
    p->len -= l;

    *data = p->buffer;
    *len = l;

    return (p->len == 0);
}

void vs1053_play_pgm(const uint8_t *data, uint16_t len)
{
    struct vs1053_pgm_feeder_priv p = {.data = data, .len = len};

    vs1053_play(vs1053_pgm_feeder, &p);
}

struct vs1053_ram_feeder_priv {
    const uint8_t *data;
    uint16_t len;
    uint8_t buffer[VS1053_DATA_CHUNK_SIZE];
};

static uint8_t vs1053_ram_feeder(uint8_t **data, uint16_t *len, void *priv)
{
    struct vs1053_pgm_feeder_priv *p = priv;

    *data = (uint8_t *)p->data;
    *len = p->len;

    return 1;
}

void vs1053_play_ram(const uint8_t *data, uint16_t len)
{
    struct vs1053_ram_feeder_priv p = {.data = data, .len = len};

    vs1053_play(vs1053_ram_feeder, &p);
}

void vs1053_set_volume(idBm_t left, idBm_t right)
{
    /* volume register = -dBm/-0.5 */
    uint16_t vol;

    if (left > 0xFE/2)
        vol = 0xFE << 8;
    else
        vol = left << (1+8);

    if (right > 0xFE/2)
        vol |= 0xFE;
    else
        vol |= right << 1;

    vs1053_write_register(VS1053_SCI_REG_VOL, vol);
}

void vs1053_play_sine(uint8_t pitch)
{
    vs1053_write_register(VS1053_SCI_REG_MODE,
            VS1053_MODE_REG_VALUE | (1<<VS1053_SCI_REG_MODE_TESTS));

    vs1053_wait_data_request();

    vs1053_enable_dcs();

#if !defined(VS1053_SPI_TRANSACTIONS)
    spi_write(0x53);
    spi_write(0xEF);
    spi_write(0x6E);
    spi_write(pitch);

    spi_write(0);
    spi_write(0);
    spi_write(0);
    spi_write(0);
#else
    {
        uint8_t out[8] = {0x53, 0xEF, 0x6E, pitch, 0x0, 0x0, 0x0, 0x0};
        spi_transfer_t xfer = {.in = NULL, .out = out, .len = 8};
        spi_transfer(&xfer);
    }
#endif

    vs1053_disable_dcs();
}
