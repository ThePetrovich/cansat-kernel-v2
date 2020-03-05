/*
 * io.c
 *
 * Created: 13.02.2020 19:32:11
 *  Author: Admin
 */ 

#include <boot/boot.h>
#include <dev/basic/gpio.h>
#include <hal/hal.h>

//0 - OUTPUT, 1 - INPUT, 2 - INPUT_PULLUP
void gpio_pinMode(uint8_t pin, uint8_t value)
{
	uint8_t nvalue = !value;
	if (pin < 8) {
		hal_WRITE_BIT(DDRA, pin, nvalue);
	} else if (pin < 16) {
		hal_WRITE_BIT(DDRB, (pin - 8), nvalue);
	} else if (pin < 24) {
		hal_WRITE_BIT(DDRC, (pin - 160), nvalue);
	} else if (pin < 32) {
		hal_WRITE_BIT(DDRD, (pin - 24), nvalue);
	} else if (pin < 40) {
		hal_WRITE_BIT(DDRE, (pin - 32), nvalue);
	} else if (pin < 48) {
		hal_WRITE_BIT(DDRF, (pin - 40), nvalue);
	} else if (pin < 53) {
		hal_WRITE_BIT(DDRG, (pin - 48), nvalue);
	} else {
		return;
	}
	if(value == INPUT_PULLUP)
	gpio_digitalWrite(pin, HIGH);
	return;
}

void gpio_digitalWrite(uint8_t pin, uint8_t value)
{
	if (pin < 8){
		hal_WRITE_BIT(PORTA, pin, value);
		return;
	} else if (pin < 16) {
		hal_WRITE_BIT(PORTB, (pin - 8), value);
		return;
	} else if (pin < 24) {
		hal_WRITE_BIT(PORTC, (pin - 16), value);
		return;
	} else if (pin < 32) {
		hal_WRITE_BIT(PORTD, (pin - 24), value);
		return;
	} else if (pin < 40) {
		hal_WRITE_BIT(PORTE, (pin - 32), value);
		return;
	} else if (pin < 48) {
		hal_WRITE_BIT(PORTF, (pin - 40), value);
		return;
	} else if (pin < 53) {
		hal_WRITE_BIT(PORTG, (pin - 48), value);
		return;
	} else {
		return;
	}
}

uint8_t gpio_digitalRead(uint8_t pin)
{
	if (pin < 8)
	return hal_CHECK_BIT(PINA, pin);
	else if (pin < 16)
	return hal_CHECK_BIT(PINB, (pin - 8));
	else if (pin < 24)
	return hal_CHECK_BIT(PINC, (pin - 16));
	else if (pin < 32)
	return hal_CHECK_BIT(PIND, (pin - 24));
	else if (pin < 40)
	return hal_CHECK_BIT(PINE, (pin - 32));
	else if (pin < 48)
	return hal_CHECK_BIT(PINF, (pin - 40));
	else if (pin < 53)
	return hal_CHECK_BIT(PING, (pin - 48));
	else {
		return 0xFF;
	}
}