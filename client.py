import serial
import serial.tools.list_ports
# https://stackoverflow.com/questions/12090503/listing-available-com-ports-with-python
# WSL DOES NOT WORK WELL!
import csv
import struct

filename = 'WindlessSimSanitized.csv'
csv_buffer = []

with open(filename) as csvfile: #, newline=''
	csv_reader = csv.reader(csvfile, delimiter = ',') #delimiter=' ', quotechar='|'
	for row in csv_reader:
		if row[0][0] == '#':
			continue
		#print(', '.join(row))
		#store in buffer
		# when storing in buffer, should be stored floats rather than strings
		float_row = []
		for string in row:
			float_row.append(float(string))
		
		csv_buffer.append(float_row)


# would be cool to automatically select the port instead of doing it manually
# that is what this code attempts
port_to_use = ""
ports = serial.tools.list_ports.comports(include_links=False)
print("Ports available: ")
for port in ports:
    print(port.device, end=' ')

if len(ports) == 1:
	print('')
	print("Using the only available port, " + ports[0].device)
	
	port_to_use = ports[0].device
else:
	port_to_use = input("There are multiple ports, which do you want to use?").strip().upper()

# send 0 if GPS, 1 if CMDs

#if __name__ == '__main__':
with serial.Serial(port_to_use, 9600, timeout=None) as s:
	#x = s.read(1) # we don't need to read anything rn, we are just writing
	#print(x)
	for row in csv_buffer:
		s.write(0) # sends the byte 0 to signify that this is GPS data, not a CMD
		for datapoint in row:
			s.write( bytearray(struct.pack("f", datapoint)) )
		