import os

from cs50 import SQL
from flask import Flask, redirect, render_template, request
from flask_mail import Mail, Message

app =  Flask(__name__)
app.config["MAIL_DEFAULT_SENDER"] = "obonussi@hotmail.com" #os.getenv("MAIL_DEFAULT_SENDER")
app.config["MAIL_PASSWORD"] = "Mascarado1!" #os.getenv("MAIL_PASSWORD")
app.config["MAIL_PORT"] = 25
app.config["MAIL_SERVER"] = "smtp.live.com."
app.config["MAIL_USE_TLS"] = True
app.config["MAIL_USERNAME"] = os.getenv("MAIL_USERNAME")
app.config["MAIL_USE_TLS"] = True
mail = Mail(app)

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
    email = request.form.get("email")
    if not email:
        return render_template("error.html", message="E-mail Ausente")
    name = request.form.get("name")
    if not name:
        return render_template("error.html", message="Nome Ausente")
    sport = request.form.get("sport")
    if not sport:
        return render_template("error.html", message="Escolha o Esporte")
    if sport not in SPORTS:
        return render_template("error.html", message="Esporte não Listado")

    db.execute("INSERT INTO registrants (name, sport) VALUES (?, ?)", name, sport)

    message = Message(name+", You are registered ! in" + sport, recipients=[email])
    mail.send(message)

    return render_template("register.html")

# @app.route("/registrants")
# def registrants():
#   registrants = db.execute("SELECT * FROM registrants")
#    return render_template("registrants.html", registrants=registrants)
