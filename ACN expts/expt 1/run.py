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
    app.run(host='::', port = 5000)
