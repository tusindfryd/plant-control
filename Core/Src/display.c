#include "display.h"

I2C_HandleTypeDef hi2c1;

const unsigned char bg[] = { 0x0f, 0x1e, 0x02, 0x04, 0x90, 0x20, 0x3c, 0x78,
		0x08, 0x12, 0x40, 0x80, 0xf1, 0xe0, 0x20, 0x49, 0x18, 0xe3, 0x02, 0x08,
		0x88, 0x20, 0x63, 0x8c, 0x08, 0x22, 0x20, 0x81, 0x8e, 0x30, 0x20, 0x88,
		0x10, 0x41, 0x03, 0x10, 0x84, 0x60, 0x41, 0x04, 0x0c, 0x42, 0x11, 0x81,
		0x04, 0x10, 0x31, 0x08, 0x10, 0x41, 0x01, 0xe0, 0x83, 0xc0, 0x41, 0x04,
		0x07, 0x82, 0x0f, 0x01, 0x04, 0x10, 0x1e, 0x08, 0xf0, 0x41, 0xe0, 0x20,
		0x82, 0x03, 0xc1, 0x07, 0x80, 0x82, 0x08, 0x0f, 0x04, 0x1e, 0x02, 0x08,
		0x88, 0x42, 0x30, 0x20, 0x82, 0x06, 0x21, 0x08, 0xc0, 0x82, 0x08, 0x18,
		0x84, 0x23, 0x02, 0x08, 0x04, 0x44, 0x10, 0x31, 0xc6, 0x04, 0x11, 0x10,
		0x40, 0xc7, 0x18, 0x10, 0x44, 0x41, 0x03, 0x1c, 0x02, 0x48, 0x10, 0x1e,
		0x3c, 0x04, 0x09, 0x20, 0x40, 0x78, 0xf0, 0x10, 0x24, 0x81, 0x01, 0xe3,
		0x00, 0xe0, 0x10, 0x00, 0x00, 0x04, 0x03, 0x80, 0x40, 0x00, 0x00, 0x10,
		0x0e, 0x01, 0x00, 0x00, 0x81, 0xf0, 0x20, 0x00, 0x00, 0x02, 0x07, 0xc0,
		0x80, 0x00, 0x00, 0x08, 0x1f, 0x02, 0x00, 0x00, 0xff, 0xff, 0xe0, 0x00,
		0x00, 0x03, 0xff, 0xff, 0x80, 0x00, 0x00, 0x0f, 0xff, 0xfe, 0x00, 0x00,
		0x81, 0xf0, 0x20, 0x00, 0x00, 0x02, 0x07, 0xc0, 0x80, 0x00, 0x00, 0x08,
		0x1f, 0x02, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x00, 0x00, 0x04, 0x03, 0x80,
		0x40, 0x00, 0x00, 0x10, 0x0e, 0x01, 0x00, 0x00, 0x02, 0x48, 0x10, 0x1e,
		0x3c, 0x04, 0x09, 0x20, 0x40, 0x78, 0xf0, 0x10, 0x24, 0x81, 0x01, 0xe3,
		0x04, 0x44, 0x10, 0x31, 0xc6, 0x04, 0x11, 0x10, 0x40, 0xc7, 0x18, 0x10,
		0x44, 0x41, 0x03, 0x1c, 0x88, 0x42, 0x30, 0x20, 0x82, 0x06, 0x21, 0x08,
		0xc0, 0x82, 0x08, 0x18, 0x84, 0x23, 0x02, 0x08, 0xf0, 0x41, 0xe0, 0x20,
		0x82, 0x03, 0xc1, 0x07, 0x80, 0x82, 0x08, 0x0f, 0x04, 0x1e, 0x02, 0x08,
		0x10, 0x41, 0x01, 0xe0, 0x83, 0xc0, 0x41, 0x04, 0x07, 0x82, 0x0f, 0x01,
		0x04, 0x10, 0x1e, 0x08, 0x10, 0x41, 0x03, 0x10, 0x84, 0x60, 0x41, 0x04,
		0x0c, 0x42, 0x11, 0x81, 0x04, 0x10, 0x31, 0x08, 0x18, 0xe3, 0x02, 0x08,
		0x88, 0x20, 0x63, 0x8c, 0x08, 0x22, 0x20, 0x81, 0x8e, 0x30, 0x20, 0x88,
		0x0f, 0x1e, 0x02, 0x04, 0x90, 0x20, 0x3c, 0x78, 0x08, 0x12, 0x40, 0x80,
		0xf1, 0xe0, 0x20, 0x49, 0x00, 0x00, 0x02, 0x01, 0xc0, 0x20, 0x00, 0x00,
		0x08, 0x07, 0x00, 0x80, 0x00, 0x00, 0x20, 0x1c, 0x00, 0x00, 0x01, 0x03,
		0xe0, 0x40, 0x00, 0x00, 0x04, 0x0f, 0x81, 0x00, 0x00, 0x00, 0x10, 0x3e,
		0x00, 0x00, 0x01, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x07, 0xff, 0xff, 0x00,
		0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x01, 0x03, 0xe0, 0x40, 0x00, 0x00,
		0x04, 0x0f, 0x81, 0x00, 0x00, 0x00, 0x10, 0x3e, 0x00, 0x00, 0x02, 0x01,
		0xc0, 0x20, 0x00, 0x00, 0x08, 0x07, 0x00, 0x80, 0x00, 0x00, 0x20, 0x1c,
		0x0f, 0x1e, 0x02, 0x04, 0x90, 0x20, 0x3c, 0x78, 0x08, 0x12, 0x40, 0x80,
		0xf1, 0xe0, 0x20, 0x49, 0x18, 0xe3, 0x02, 0x08, 0x88, 0x20, 0x63, 0x8c,
		0x08, 0x22, 0x20, 0x81, 0x8e, 0x30, 0x20, 0x88, 0x10, 0x41, 0x03, 0x10,
		0x84, 0x60, 0x41, 0x04, 0x0c, 0x42, 0x11, 0x81, 0x04, 0x10, 0x31, 0x08,
		0x10, 0x41, 0x01, 0xe0, 0x83, 0xc0, 0x41, 0x04, 0x07, 0x82, 0x0f, 0x01,
		0x04, 0x10, 0x1e, 0x08, 0xf0, 0x41, 0xe0, 0x20, 0x82, 0x03, 0xc1, 0x07,
		0x80, 0x82, 0x08, 0x0f, 0x04, 0x1e, 0x02, 0x08, 0x88, 0x42, 0x30, 0x20,
		0x82, 0x06, 0x21, 0x08, 0xc0, 0x82, 0x08, 0x18, 0x84, 0x23, 0x02, 0x08,
		0x04, 0x44, 0x10, 0x31, 0xc6, 0x04, 0x11, 0x10, 0x40, 0xc7, 0x18, 0x10,
		0x44, 0x41, 0x03, 0x1c, 0x02, 0x48, 0x10, 0x1e, 0x3c, 0x04, 0x09, 0x20,
		0x40, 0x78, 0xf0, 0x10, 0x24, 0x81, 0x01, 0xe3, 0x00, 0xe0, 0x10, 0x00,
		0x00, 0x04, 0x03, 0x80, 0x40, 0x00, 0x00, 0x10, 0x0e, 0x01, 0x00, 0x00,
		0x81, 0xf0, 0x20, 0x00, 0x00, 0x02, 0x07, 0xc0, 0x80, 0x00, 0x00, 0x08,
		0x1f, 0x02, 0x00, 0x00, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x03, 0xff, 0xff,
		0x80, 0x00, 0x00, 0x0f, 0xff, 0xfe, 0x00, 0x00, 0x81, 0xf0, 0x20, 0x00,
		0x00, 0x02, 0x07, 0xc0, 0x80, 0x00, 0x00, 0x08, 0x1f, 0x02, 0x00, 0x00,
		0x00, 0xe0, 0x10, 0x00, 0x00, 0x04, 0x03, 0x80, 0x40, 0x00, 0x00, 0x10,
		0x0e, 0x01, 0x00, 0x00, 0x02, 0x48, 0x10, 0x1e, 0x3c, 0x04, 0x09, 0x20,
		0x40, 0x78, 0xf0, 0x10, 0x24, 0x81, 0x01, 0xe3, 0x04, 0x44, 0x10, 0x31,
		0xc6, 0x04, 0x11, 0x10, 0x40, 0xc7, 0x18, 0x10, 0x44, 0x41, 0x03, 0x1c,
		0x88, 0x42, 0x30, 0x20, 0x82, 0x06, 0x21, 0x08, 0xc0, 0x82, 0x08, 0x18,
		0x84, 0x23, 0x02, 0x08, 0xf0, 0x41, 0xe0, 0x20, 0x82, 0x03, 0xc1, 0x07,
		0x80, 0x82, 0x08, 0x0f, 0x04, 0x1e, 0x02, 0x08, 0x10, 0x41, 0x01, 0xe0,
		0x83, 0xc0, 0x41, 0x04, 0x07, 0x82, 0x0f, 0x01, 0x04, 0x10, 0x1e, 0x08,
		0x10, 0x41, 0x03, 0x10, 0x84, 0x60, 0x41, 0x04, 0x0c, 0x42, 0x11, 0x81,
		0x04, 0x10, 0x31, 0x08, 0x18, 0xe3, 0x02, 0x08, 0x88, 0x20, 0x63, 0x8c,
		0x08, 0x22, 0x20, 0x81, 0x8e, 0x30, 0x20, 0x88, 0x0f, 0x1e, 0x02, 0x04,
		0x90, 0x20, 0x3c, 0x78, 0x08, 0x12, 0x40, 0x80, 0xf1, 0xe0, 0x20, 0x49,
		0x00, 0x00, 0x02, 0x01, 0xc0, 0x20, 0x00, 0x00, 0x08, 0x07, 0x00, 0x80,
		0x00, 0x00, 0x20, 0x1c, 0x00, 0x00, 0x01, 0x03, 0xe0, 0x40, 0x00, 0x00,
		0x04, 0x0f, 0x81, 0x00, 0x00, 0x00, 0x10, 0x3e, 0x00, 0x00, 0x01, 0xff,
		0xff, 0xc0, 0x00, 0x00, 0x07, 0xff, 0xff, 0x00, 0x00, 0x00, 0x1f, 0xff,
		0x00, 0x00, 0x01, 0x03, 0xe0, 0x40, 0x00, 0x00, 0x04, 0x0f, 0x81, 0x00,
		0x00, 0x00, 0x10, 0x3e, 0x00, 0x00, 0x02, 0x01, 0xc0, 0x20, 0x00, 0x00,
		0x08, 0x07, 0x00, 0x80, 0x00, 0x00, 0x20, 0x1c, 0x0f, 0x1e, 0x02, 0x04,
		0x90, 0x20, 0x3c, 0x78, 0x08, 0x12, 0x40, 0x80, 0xf1, 0xe0, 0x20, 0x49,
		0x18, 0xe3, 0x02, 0x08, 0x88, 0x20, 0x63, 0x8c, 0x08, 0x22, 0x20, 0x81,
		0x8e, 0x30, 0x20, 0x88, 0x10, 0x41, 0x03, 0x10, 0x84, 0x60, 0x41, 0x04,
		0x0c, 0x42, 0x11, 0x81, 0x04, 0x10, 0x31, 0x08, 0x10, 0x41, 0x01, 0xe0,
		0x83, 0xc0, 0x41, 0x04, 0x07, 0x82, 0x0f, 0x01, 0x04, 0x10, 0x1e, 0x08,
		0xf0, 0x41, 0xe0, 0x20, 0x82, 0x03, 0xc1, 0x07, 0x80, 0x82, 0x08, 0x0f,
		0x04, 0x1e, 0x02, 0x08, 0x88, 0x42, 0x30, 0x20, 0x82, 0x06, 0x21, 0x08,
		0xc0, 0x82, 0x08, 0x18, 0x84, 0x23, 0x02, 0x08, 0x04, 0x44, 0x10, 0x31,
		0xc6, 0x04, 0x11, 0x10, 0x40, 0xc7, 0x18, 0x10, 0x44, 0x41, 0x03, 0x1c,
		0x02, 0x48, 0x10, 0x1e, 0x3c, 0x04, 0x09, 0x20, 0x40, 0x78, 0xf0, 0x10,
		0x24, 0x81, 0x01, 0xe3, 0x00, 0xe0, 0x10, 0x00, 0x00, 0x04, 0x03, 0x80,
		0x40, 0x00, 0x00, 0x10, 0x0e, 0x01, 0x00, 0x00, 0x81, 0xf0, 0x20, 0x00,
		0x00, 0x02, 0x07, 0xc0, 0x80, 0x00, 0x00, 0x08, 0x1f, 0x02, 0x00, 0x00,
		0xff, 0xff, 0xe0, 0x00, 0x00, 0x03, 0xff, 0xff, 0x80, 0x00, 0x00, 0x0f,
		0xff, 0xfe, 0x00, 0x00, 0x81, 0xf0, 0x20, 0x00, 0x00, 0x02, 0x07, 0xc0,
		0x80, 0x00, 0x00, 0x08, 0x1f, 0x02, 0x00, 0x00 };

const unsigned char garfield1_128x64[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
		0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x02, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x88, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12,
		0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x09, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1,
		0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x01, 0x0b, 0xa1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x1e, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
		0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x09, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x90, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22,
		0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x02, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x80, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x08, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31,
		0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x29, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x48, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19,
		0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf0, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f,
		0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x08, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x20, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
		0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x08, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
		0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };

extern uint16_t WS9527_Reading;
bool menu_open = false;
extern volatile uint16_t positions;

void Splash() {
	ssd1306_Init();
	ssd1306_DrawBitmap(0, 0, bg, 128, 64, White);
	for (uint8_t i = 0; i < 11; i++) {
		ssd1306_DrawRectangle(0 + i, 20 + i, SSD1306_WIDTH - i, 43 - i, Black);
	}
	ssd1306_UpdateScreen();
}

void DisplayMeasurements() {
	ssd1306_SetCursor(0, 27);
	char moisture_data[21];
	if (WS9527_Reading < 10) {
		sprintf(moisture_data, "Soil moisture: %01d%%  ", WS9527_Reading);
		ssd1306_WriteString(moisture_data, Font_7x10, White);
	} else if (WS9527_Reading < 100) {
		sprintf(moisture_data, "Soil moisture: %02d%% ", WS9527_Reading);
		ssd1306_WriteString(moisture_data, Font_7x10, White);
	} else {
		sprintf(moisture_data, "Soil moisture: %03d%%", WS9527_Reading);
		ssd1306_WriteString(moisture_data, Font_7x10, White);
	}
	ssd1306_UpdateScreen();
}

void OpenMenu() {
	menu_open = true;
	ssd1306_Fill(Black);
	ssd1306_SetCursor(0, 0);
	ssd1306_WriteString("Set soil moisture value", Font_7x10,
			(positions % 3 == 0) ? Black : White);
	ssd1306_SetCursor(0, 11);
	ssd1306_WriteString("Run the pump", Font_7x10,
			(positions % 3 == 1) ? Black : White);
	ssd1306_SetCursor(0, 64 - 10);
	ssd1306_WriteString("< Back", Font_7x10,
			(positions % 3 == 2) ? Black : White);
	ssd1306_UpdateScreen();
}

void CloseMenu() {
	menu_open = false;
	ssd1306_Fill(Black);
	ssd1306_DrawBitmap(0, 0, bg, 128, 64, White);
	for (uint8_t i = 0; i < 11; i++) {
		ssd1306_DrawRectangle(0 + i, 20 + i, SSD1306_WIDTH - i, 43 - i, Black);
	}
	DisplayMeasurements();
}
