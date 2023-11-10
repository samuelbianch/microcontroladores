from serial import Serial
import time
import matplotlib.pyplot as plt


# USB PORT
portName = 'COM6'

# Create Serial object:
ser = Serial(portName) # Also opens the port during object creation
ser.close() # To set parameters

# Change settings for Arduino default Serial.begin:
ser.baudrate=115200
ser.port=portName
ser.bytesize=8
ser.parity='N'
ser.stopbits=1
ser.timeout=0.1


# Open port
ser.open()

ser.reset_input_buffer()
val=[]

while True:
    try:
        N=ser.in_waiting        
        data=ser.readline(-1) 
        data=float(data.decode())        
    except KeyboardInterrupt:
        break
    except Exception as e:
        pass
    else:
        print(data)
        val.append(data)
    finally:
        if len(val)>500:
            break

ser.close()

plt.figure(figsize=(12,3))
plt.plot(val)
plt.show()