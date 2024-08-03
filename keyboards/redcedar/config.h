/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


// It may be possible for me to define these in the keyboard.json file by updating this mapping file,
// but I haven't tried it:
// /home/tim/qmk_firmware/data/mappings/info_config.hjson

// when using the PIO driver, you can use any GPIO and define SERIAL_USART_PIN_SWAP
// if using the SIO driver, you can only use UART capable pins, and cannot pin swap
// https://github.com/qmk/qmk_firmware/blob/master/docs/platformdev_rp2040.md#split-keyboard-support
// https://github.com/qmk/qmk_firmware/blob/master/docs/drivers/serial.md#usart-full-duplex
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP21 
#define SERIAL_USART_RX_PIN GP23
#define SERIAL_USART_PIN_SWAP