import serial
import pyrebase
import uuid

firebaseConfig = {
  "apiKey": "AIzaSyAc660pJf1gd2_nIz_rgv9gHL5SoSAwS_s",
  "authDomain": "esp32cambianch.firebaseapp.com",
  "projectId": "esp32cambianch",
  "storageBucket": "esp32cambianch.appspot.com",
  "messagingSenderId": "969186346205",
  "appId": "1:969186346205:web:5006955235652a76720734",
  "databaseURL": "https://esp32cambianch-default-rtdb.firebaseio.com/values",
}

ser = serial.Serial('COM5') # Porta em que está conectada a serial
ser.baudrate = 115200 # Baudrate da serial
ser.timeout = 0.01 * 500
firebase = pyrebase.initialize_app(firebaseConfig)
db = firebase.database()

print("Iniciando Leitura...")

while 1:
    try:
        bytesParaSeremLidos = ser.in_waiting
        value = ser.read(bytesParaSeremLidos)
        value = value.decode("utf-8")
        print("Valor: ", value)
        db.update({"Valor": int(value), "Teste": "teste"})
    except Exception as e:
        print("Erro ao salvar valor: ", e)
        ser.close()
    

ser.close()