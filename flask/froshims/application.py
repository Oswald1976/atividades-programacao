from cs50 import SQL
from flask import Flask, redirect, render_template, request
from flask_mail import Mail, Message

app =  Flask(__name__)
app.config["MAIL_DEFAULT_SENDER"] = os.ge
db = SQL("sqlite:///froshims.db")

SPORTS =    [
            "DogdeBall",
            "Flag Football",
            "Soccer",
            "Volleyball",
            "Frisbee"
            ]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    if not name:
        return render_template("error.html", message="Nome Ausente")
    sport = request.form.get("sport")
    if not sport:
        return render_template("error.html", message="Escolha o Esporte")
    if sport not in SPORTS:
        return render_template("error.html", message="Esporte não Listado")

    db.execute("INSERT INTO registrants (name, sport) VALUES (?, ?)", name, sport)

    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=registrants)
