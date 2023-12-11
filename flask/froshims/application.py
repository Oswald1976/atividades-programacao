from flask import Flask, render_template, request

app =  Flask(__name__)

SPORTS =    [
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
        return render_template("error.html", message="")
    sport = request.form.get("sport")
    if not sport:
        return render_template("error.html")
    if sport not in SPORTS:
        return render_template("error.html")

    return render_template("register.html")
