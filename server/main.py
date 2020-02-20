from flask import Flask, render_template
from flask_socketio import SocketIO

app = Flask(__name__)
app.config['SECRET_KEY'] = 'vnkdjnfjknfl1232#'
socketio = SocketIO(app)


@app.route('/')
def sessions():
    return render_template('session.html')


def messageReceived(methods=['GET', 'POST']):
    print('message was received!!!')


@socketio.on('add user')
def handle_adduser(json, methods=['GET', 'POST']):
    print('ADD USER received my event: ' + str(json))
    socketio.emit('login', json, callback=messageReceived)

@socketio.on('login')
def handle_login(json, methods=['GET', 'POST']):
    print('LOGIN received my event: ' + str(json))
    socketio.emit('login', json, callback=messageReceived)

@socketio.on('my event')
def handle_my_custom_event(json, methods=['GET', 'POST']):
    print('received my event: ' + str(json))
    socketio.emit('my response', json, callback=messageReceived)


if __name__ == '__main__':
    socketio.run(app, debug=True)
