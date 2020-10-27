from flask import Flask, render_template
import json

app = Flask(__name__)

def loadInfo():
    with open("data/info.json") as f:
        info = json.load(f)
    return info

@app.route('/')
def homepage():
    return render_template("homepage.html", info = loadInfo())

if __name__ == '__main__':
    app.run(host = '127.0.0.1', port = 5000, ssl_context = ('crts/server.crt', 'crts/server.key'))
