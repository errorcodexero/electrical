ARDUINO_PATH = D:/Program\ Files\ \(x86\)/Arduino
ARDUINO_BUILDER_PATH = /cygdrive/d/Program\ Files\ \(x86\)/Arduino

ARDUINO_PORT = /dev/ttyS2

TARGET_DIR = $(shell cygpath -m $(CURDIR})/build)

all: frc2018_blinky_lights.ino
	@mkdir $(TARGET_DIR) 
	$(ARDUINO_PATH)/arduino-builder.exe \
	-compile \
	-hardware $(ARDUINO_PATH)/hardware \
	-tools $(ARDUINO_PATH)/hardware/tools \
	-tools $(ARDUINO_PATH)/tools-builder \
	-libraries $(ARDUINO_PATH)/libraries \
	-libraries "../libraries" \
	-fqbn arduino:avr:uno \
	-build-path $(TARGET_DIR) \
	-upload \
	frc2018_blinky_lights.ino

clean:
	rm -rf $(TARGET_DIR)

