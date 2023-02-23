USER = TGuimbert
KEYBOARD = boardsource/lulu/rp2040
COMPILED_KEYMAP_LOCATION = qmk_firmware/.build/boardsource_lulu_rp2040_TGuimbert
COMPILED_KEYMAP = $(COMPILED_KEYMAP_LOCATION ).elf $(COMPILED_KEYMAP_LOCATION ).hex $(COMPILED_KEYMAP_LOCATION ).map $(COMPILED_KEYMAP_LOCATION ).uf2 

.PHONY: lint flash clean

all: compile

qmk_firmware:
	git submodule update --init --recursive

link: qmk_firmware/keyboards/boardsource/lulu/keymaps/TGuimbert/
qmk_firmware/keyboards/boardsource/lulu/keymaps/TGuimbert/: qmk_firmware
	mkdir $@
	ln -s $(shell pwd)/lulu/* $@

lint: lulu/config.h lulu/keymap.c link
	qmk lint --keyboard $(KEYBOARD) --keymap $(USER)

compile: $(COMPILED_KEYMAP)
$(COMPILED_KEYMAP)&: lulu/config.h lulu/keymap.c link lint
	qmk compile --keyboard $(KEYBOARD) --keymap $(USER)

# Doesn't work, qmk does not pick up the keyboard in bootloader
# flash: compile
# 	qmk flash --keyboard $(KEYBOARD) --keymap $(USER)

clean:
	rm -rf qmk_firmware/.build
