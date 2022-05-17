#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>
#include <sys/printk.h>
#include <sys/__assert.h>
#include <string.h>
#include <timing/timing.h>
#include <stdio.h>
#include <string.h>
#include "placa.h"

static struct gpio_callback button1_cb_data;
static struct gpio_callback button2_cb_data;
static struct gpio_callback button3_cb_data;
static struct gpio_callback button4_cb_data;

static struct gpio_callback coin10_cb_data;
static struct gpio_callback coin20_cb_data;
static struct gpio_callback coin50_cb_data;
static struct gpio_callback coin100_cb_data;

volatile int dcToggleFlag = 0;
volatile int coinv = 0;


void button1_pressed(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
        dcToggleFlag=1;
}

void button2_pressed(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
        dcToggleFlag=2;
}
void button3_pressed(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
        dcToggleFlag=3;
}
void button4_pressed(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
        dcToggleFlag=4;
}

void coin10_pressed(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
        dcToggleFlag=5;
        coinv = 10;
}
void coin20_pressed(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
        dcToggleFlag=5;
        coinv = 20;
}
void coin50_pressed(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
        dcToggleFlag=5;
        coinv = 50;
}
void coin100_pressed(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{

        dcToggleFlag=5;
        coinv = 100;
}

void InitConfig(void){
      /* Local vars */    
    const struct device *gpio0_dev;         /* Pointer to GPIO device structure */
    int ret=0;                              /* Generic return value variable */


    /* Bind to GPIO 0 */
    gpio0_dev = device_get_binding(DT_LABEL(GPIO0_NID));
    if (gpio0_dev == NULL) {
        printk("Failed to bind to GPIO0\n\r");        
	return;
    }
    else {
        printk("Bind to GPIO0 successfull \n\r");        
    }
    
        ret = gpio_pin_configure(gpio0_dev, button1, GPIO_INPUT | GPIO_PULL_UP);
    if (ret < 0) {
        printk("gpio_pin_configure() failed with error %d\n\r", ret);        
	return;
    }
   ret = gpio_pin_configure(gpio0_dev, button2, GPIO_INPUT | GPIO_PULL_UP);
    if (ret < 0) {
        printk("gpio_pin_configure() failed with error %d\n\r", ret);        
	return;
    }
    ret = gpio_pin_configure(gpio0_dev, button3, GPIO_INPUT | GPIO_PULL_UP);
    if (ret < 0) {
        printk("gpio_pin_configure() failed with error %d\n\r", ret);        
	return;
    }
    ret = gpio_pin_configure(gpio0_dev, button4, GPIO_INPUT | GPIO_PULL_UP);
    if (ret < 0) {
        printk("gpio_pin_configure() failed with error %d\n\r", ret);        
	return;
    }

    /* Configure coins */
    ret = gpio_pin_configure(gpio0_dev, coin10, GPIO_INPUT | GPIO_PULL_UP);
    if (ret < 0) {
        printk("gpio_pin_configure() failed with error %d\n\r", ret);        
	return;
    }
    ret = gpio_pin_configure(gpio0_dev, coin20, GPIO_INPUT | GPIO_PULL_UP);
    if (ret < 0) {
        printk("gpio_pin_configure() failed with error %d\n\r", ret);        
	return;
    }
    ret = gpio_pin_configure(gpio0_dev, coin50, GPIO_INPUT | GPIO_PULL_UP);
    if (ret < 0) {
        printk("gpio_pin_configure() failed with error %d\n\r", ret);        
	return;
    }
    ret = gpio_pin_configure(gpio0_dev, coin100, GPIO_INPUT | GPIO_PULL_UP);
    if (ret < 0) {
        printk("gpio_pin_configure() failed with error %d\n\r", ret);        
	return;
    }
    
    	ret = gpio_pin_interrupt_configure(gpio0_dev,button1,GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		return;
	}
    	ret = gpio_pin_interrupt_configure(gpio0_dev,button2,GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		return;
	}
    	ret = gpio_pin_interrupt_configure(gpio0_dev,button3,GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		return;
	}
     	ret = gpio_pin_interrupt_configure(gpio0_dev,button4,GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		return;
	}

    	ret = gpio_pin_interrupt_configure(gpio0_dev,coin10,GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		return;
	}
    	ret = gpio_pin_interrupt_configure(gpio0_dev,coin20,GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		return;
	}
    	ret = gpio_pin_interrupt_configure(gpio0_dev,coin50,GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		return;
	}
     	ret = gpio_pin_interrupt_configure(gpio0_dev,coin100,GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		return;
	}

	gpio_init_callback(&button1_cb_data, button1_pressed, BIT(button1));
	gpio_add_callback(gpio0_dev, &button1_cb_data);

	gpio_init_callback(&button2_cb_data, button2_pressed, BIT(button2));
	gpio_add_callback(gpio0_dev, &button2_cb_data);

        gpio_init_callback(&button3_cb_data, button3_pressed, BIT(button3));
	gpio_add_callback(gpio0_dev, &button3_cb_data);

        gpio_init_callback(&button4_cb_data, button4_pressed, BIT(button4));
	gpio_add_callback(gpio0_dev, &button4_cb_data);    

	gpio_init_callback(&coin10_cb_data, coin10_pressed, BIT(coin10));
	gpio_add_callback(gpio0_dev, &coin10_cb_data);

	gpio_init_callback(&coin20_cb_data, coin20_pressed, BIT(coin20));
	gpio_add_callback(gpio0_dev, &coin20_cb_data);

	gpio_init_callback(&coin50_cb_data, coin50_pressed, BIT(coin50));
	gpio_add_callback(gpio0_dev, &coin50_cb_data);

	gpio_init_callback(&coin100_cb_data, coin100_pressed, BIT(coin100));
	gpio_add_callback(gpio0_dev, &coin100_cb_data);

	/* Task init code */
    printk("Vending Machine \n");

        return;
}
