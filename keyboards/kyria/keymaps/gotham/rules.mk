CONSOLE_ENABLE	       = no
MOUSEKEY_ENABLE        = no
ENCODER_ENABLE         = yes
RGBLIGHT_ENABLE        = yes
OLED_DRIVER_ENABLE     = yes
THUMBSTICK_ENABLE  	   = yes
SPLIT_TRANSPORT        = custom
OLED_ANIMATIONS_ENABLE = yes

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
	SRC += oled_utils.c
	ifeq ($(strip $(OLED_ANIMATIONS_ENABLE)), yes)
		OPT_DEFS += -DOLED_ANIMATIONS_ENABLE
		SRC += lib/lib8tion/lib8tion.c
		SRC += oled_animations/*.c
	endif
endif

ifeq ($(strip $(ENCODER_ENABLE)), yes)
	SRC += encoder_utils.c
endif

ifeq ($(strip $(THUMBSTICK_ENABLE)), yes)
    POINTING_DEVICE_ENABLE = yes
    OPT_DEFS += -DTHUMBSTICK_ENABLE
	SRC += analog.c
	SRC += thumbstick.c
endif

ifeq ($(strip $(SPLIT_TRANSPORT)), custom)
	OPT_DEFS += -DCUSTOM_TRANSPORT
	QUANTUM_SRC += transport_custom.c
	# Functions added via QUANTUM_LIB_SRC are only included in the final binary if they're called.
	# Unused functions are pruned away, which is why we can add multiple drivers here without bloat.
	ifeq ($(PLATFORM),AVR)
		QUANTUM_LIB_SRC += i2c_master.c \
							i2c_slave.c
	endif

	SERIAL_DRIVER ?= bitbang
	ifeq ($(strip $(SERIAL_DRIVER)), bitbang)
		QUANTUM_LIB_SRC += serial.c
	else
		QUANTUM_LIB_SRC += serial_$(strip $(SERIAL_DRIVER)).c
	endif
endif

