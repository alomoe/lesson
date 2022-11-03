import paho.mqtt.client as mqtt_client
import serial

broker="broker.emqx.io"
client = mqtt_client.Client()
client.connect(broker)
ser = serial.Serial("COM5", timeout=1)
initial = True
while True:
    if ser.in_waiting > 0:
        data = ser.read(1)
        client.publish('lab/alena21/photo/instant', data[0])
client.disconnect()