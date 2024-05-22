from flask import render_template
from app import app
import serial
import time

arduino = serial.Serial(port='COM5',   baudrate=9600, timeout=.1)


def write_read(x):
    arduino.write(bytes(x,   'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return   data
    
@app.route('/')
@app.route('/index')
def index():
    while True:
        
        num={'S'}
        return render_template('index.html', title='Home',val=num)
        num = {'onoff'}
        value   = write_read('A')
    


