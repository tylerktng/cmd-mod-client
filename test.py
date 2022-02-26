import serial
# https://stackoverflow.com/questions/12090503/listing-available-com-ports-with-python
# WSL DOES NOT WORK WELL!

if __name__ == '__main__':
	with serial.Serial('COM3', 9600, timeout=None) as s:
		while True:
			x = s.read(1)
			print(x)