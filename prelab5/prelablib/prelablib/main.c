//*;UNIVERSIDAD DEL VALLE DE GUATEMALA
//;IE2023: PROGRAMACI�N DE MICROCONTROLADORES
//;prelab5.asm
//;AUTOR: Jose Andr�s Vel�squez Garc�a
//;PROYECTO: Contador binario de 4 bits
//;HARDWARE: ATMEGA328P
//;CREADO: 16/04/2024
//;�LTIMA MODIFICACI�N: 16/04/2024 10:54
//********************************
#include <avr/io.h>
#include "pwm_servo.h"

void setup() {
	// Inicializaci�n del PWM para el servo
	pwm_servo_init();
}

void loop() {
	// Mueve el servo de 0 a 180 grados con incrementos de 10 grados
	for (int angle = 0; angle <= 180; angle += 10) {
		pwm_servo_write(angle);
		delay(1000); // Espera 1 segundo antes de cambiar el �ngulo
	}
}

