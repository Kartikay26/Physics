"""
Server Backend
"""

# import physics

from flask import *
from flask_socketio import SocketIO

app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret!'
socketio = SocketIO(app)

@socketio.on('reload_file')
def reload_file():
	global f
	f = open("data.txt").readlines()
	return 1

@socketio.on('ping')
def ping(*data):
	return "pong: " + str(data)

@socketio.on('data')
def send_data():
	return univ[request.sid].data()

@socketio.on('saved_data')
def send_saved_data(i):
	global f
	i -= 30
	if i < 0:
		i = 0
	if i>=len(f):
		f = open("data.txt").readlines()
		return "restart"
	else:
		return eval(f[i])

if __name__ == '__main__':
	socketio.run(app, port=5000, debug=True)
