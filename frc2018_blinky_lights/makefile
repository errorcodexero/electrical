ARDUINO_SOURCE = $(abspath C:/Program\ Files\ \(x86\)/Arduino/hardware)


frc2018_blinky_lights: frc2018_blinky_lights.ino
	"/cygdrive/c/Program Files (x86)/Arduino/arduino-builder.exe" \
	-compile \
	-hardware $(ARDUINO_SOURCE)/hardware \
	-tools $(ARDUINO_SOURCE)/hardware/tools \
	-tools $(ARDUINO_SOURCE)/tools-builder \
	-libraries "C:/Program Files (x86)/Arduino/libraries" \
	-libraries "../libraries" \
	-fqbn arduino:avr:uno \
	-build-path build \
	frc2018_blinky_lights.ino
