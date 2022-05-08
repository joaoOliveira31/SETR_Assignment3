#ifndef _PLACA_H
#define _PLACA_H

/* Refer to dts file */
#define GPIO0_NID DT_NODELABEL(gpio0) 

#define button1 0xb
#define button2 0xc
#define button3 0x18
#define button4 0x19

#define coin10 0x1C
#define coin20 0x1D
#define coin50 0x1E
#define coin100 0x1F

volatile int dcToggleFlag;
volatile int coinv;

void button1_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void button2_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void button3_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void button4_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void coin10_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void coin20_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void coin50_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void coin100_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins);

void InitConfig(void);

#endif