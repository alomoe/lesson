import time
import paho.mqtt.client as mqtt_client
import random
from statistics import mean
import serial

lst = []
ser = serial.Serial("COM5", timeout=1)
min = 100
max = 0

def on_message(client, userdata, message):
    global max
    global min
    data = message.payload
    topic = message.topic
    print(f"Received message on {topic}: {data}; min: {min}, max: {max}")
    if topic == "lab/alena21/photo/max":
        max = int(data)

    if topic == "lab/alena21/photo/min":
        min = int(data)

    if topic == "lab/alena21/photo/stream":
        if int(data) < (min + max) / 2:
            ser.write(bytearray([ord('1')]))
        else:
            ser.write(bytearray([ord('0')]))

broker = "broker.emqx.io"

client = mqtt_client.Client(f'lab_{random.randint(10000, 99999)}')
client.on_message = on_message

try:
    client.connect(broker)
except Exception:
    print('Failed to connect. Check network')
    exit()

client.loop_start()

print('Subscribing')
client.subscribe("lab/alena21/photo/stream")
client.subscribe("lab/alena21/photo/min")
client.subscribe("lab/alena21/photo/max")
time.sleep(600)
client.disconnect()
client.loop_stop()
print('Stop communication')