/*
 * prelab5ex.c
 *
 * Created: 16/04/2024 11:42:57
 * Author : josea
 */ 
#ifndef PWM_SERVO_H
#define PWM_SERVO_H

#include <avr/io.h>

// Define los pines y registros necesarios para el PWM
#define PWM_PIN 9 // Cambia este valor según el pin que uses para el PWM
#define PWM_REG OCR1A // Registro de salida comparativa para el PWM

void pwm_servo_init() {
	// Configura el pin como salida
	DDRB |= (1 << PB1); // PB1 es el pin 9 en el ATmega328P

	// Configura el modo de operación del Timer1 para PWM
	TCCR1A |= (1 << COM1A1) | (1 << WGM11);
	TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS11); // Configura el prescaler a 8

	// Establece el TOP para el PWM (20ms para control de servo estándar)
	ICR1 = 39999; // Frecuencia de 50 Hz (20ms)
}

void pwm_servo_write(uint16_t angle) {
	// Convierte el ángulo deseado a valor de registro para el PWM (1000 a 2000)
	uint16_t duty_cycle = 1000 + (angle * 11) / 20; // Mapeo lineal del ángulo a duración del pulso

	// Limita el valor del ciclo de trabajo entre 1000 y 2000
	if (duty_cycle < 1000) {
		duty_cycle = 1000;
		} else if (duty_cycle > 2000) {
		duty_cycle = 2000;
	}

	// Escribe el ciclo de trabajo al registro del PWM
	PWM_REG = duty_cycle;
}

#endif
