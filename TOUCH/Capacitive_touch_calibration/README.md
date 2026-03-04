## Capacitive Display Touch Calibration

The ESP HMI uses a 7” TFT capacitive touch display with the TAMC_GT911 touch controller. After the display is set up, the touch feature may need calibration for accurate detection.

The GT911 communicates via I2C, and the code initializes the touchscreen by defining the SDA and SCL pins, along with optional interrupt (INT) and reset (RST) pins. The touchscreen object is created with the maximum raw X/Y values matching the display resolution, and the screen rotation is set according to the display orientation.

In the setup() function, serial communication and I2C are initialized, and the touchscreen driver is started. This prepares the system to read touch events accurately.

The loop() function continuously updates touch data using ts.read() and detects new touch events, printing the X and Y coordinates of valid touches to the Serial Monitor only once per touch. Touch release is detected to reset the touch status, and a small delay is added for stable operation.

For calibration, the user touches the four corners of the screen while monitoring the coordinates in the Serial Monitor. These values are then used to adjust mapping parameters such as TOUCH_MAP_X1, TOUCH_MAP_X2, TOUCH_MAP_Y1, and TOUCH_MAP_Y2 in the code.

Iterative adjustments ensure that the reported coordinates match the actual touch points, resulting in accurate and responsive capacitive touch functionality on the ESP HMI display.
